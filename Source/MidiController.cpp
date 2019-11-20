/*
  ==============================================================================

    MidiController.cpp
    Created: 18 Sep 2019 12:05:03pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "MidiController.h"

#include "InterfaceDefines.h"
#include "MidiFunctions.h"

MidiController::MidiController(JackelAudioProcessor* inProcessor)
{
    mProcessor = inProcessor;
    
    mKeyboardComponent = std::make_unique<MidiKeyboardComponent>(mKeyboardState, MidiKeyboardComponent::horizontalKeyboard);
    
    mKeyboardComponent->setSize(MIDI_KB_WIDTH, MIDI_KB_HEIGHT);
    mKeyboardComponent->setTopLeftPosition(LARGE_BUFFER, LARGE_BUFFER + OCTAVE_HEIGHT);
    
    mKeyboardState.addListener(this);
    
    mMidiInputDevs = std::make_unique<ComboBox>();
    
    mMidiInputDevs->setTextWhenNoChoicesAvailable ("No MIDI Inputs Enabled");
    auto midiInputs = MidiInput::getDevices();
    mMidiInputDevs->addItemList (midiInputs, 1);
    mMidiInputDevs->onChange = [this] { setMidiInput (mMidiInputDevs->getSelectedItemIndex()); };

    // find the first enabled device and use that by default
    for (auto midiInput : midiInputs)
    {
        if (deviceManager.isMidiInputEnabled (midiInput))
        {
            setMidiInput (midiInputs.indexOf (midiInput));
            break;
        }
    }

    // if no enabled devices were found just use the first one in the list
    if (mMidiInputDevs->getSelectedId() == 0)
        setMidiInput (0);
    
    mMidiInputDevs->setSize(MIDI_DEV_CB_WIDTH, MIDI_DEV_CB_HEIGHT);
    mMidiInputDevs->setTopLeftPosition(LARGE_BUFFER + LOGO_WIDTH + LARGE_BUFFER, LARGE_BUFFER + MEDIUM_BUFFER);
    
    mValidMidi.setStart(0);
    mValidMidi.setEnd(128);
}

MidiController::~MidiController()
{
    mKeyboardState.removeListener(this);
}

void MidiController::handleNoteOn (MidiKeyboardState* source, int midiChannel, int midiNoteNumber, float velocity)
{
    
}

void MidiController::handleNoteOff (MidiKeyboardState* source, int midiChannel, int midiNoteNumber, float velocity)
{
    
}

/*
 *  This function handles the visual aspect of the midi messages
 */
void MidiController::handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message)
{
    // use the same algorithm in MidiProcessor to hanle notes on/off
    // MidiMessage m;
    // mKeyboardState.processNextMidiEvent (message);
    
    const int tonalCenter = *(mProcessor->parameters.getRawParameterValue("TonalCenter"));
    const int octave = *(mProcessor->parameters.getRawParameterValue("Octave"));
    
    // convert the original note to it's negative value
    const int oldNote = message.getNoteNumber();
    const int newNote = getNegative(oldNote, tonalCenter, octave);
    
    // check if the generated note is within range. edges of the piano
    // may be cut off and nothing happens
    if (!mValidMidi.contains(newNote))
    {
        return;
    }
    
    if (message.isNoteOn())
    {
        
            // add the new midi note. keep the original channel and velocity
            // add the new midi note
            MidiMessage m = MidiMessage::noteOn (message.getChannel(), newNote, message.getVelocity());
            m.setTimeStamp (Time::getMillisecondCounterHiRes() * 0.001);
            
            mKeyboardState.processNextMidiEvent(m);
        
    }
    else if (message.isNoteOff())
    {
        MidiMessage m = MidiMessage::noteOff (message.getChannel(), newNote, message.getVelocity());
        m.setTimeStamp (Time::getMillisecondCounterHiRes() * 0.001);
        
        mKeyboardState.processNextMidiEvent(m);
    }
    else
    {
        mKeyboardState.processNextMidiEvent(message);
    }
}

MidiKeyboardComponent* MidiController::getKeyboardComponent()
{
    return &*mKeyboardComponent;
}

ComboBox* MidiController::getComboBox()
{
    return &*mMidiInputDevs;
}

void MidiController::setMidiInput (int index)
{
    auto list = MidiInput::getDevices();

    deviceManager.removeMidiInputCallback (list[lastInputIndex], this);

    auto newInput = list[index];

    if (! deviceManager.isMidiInputEnabled (newInput))
        deviceManager.setMidiInputEnabled (newInput, true);

    deviceManager.addMidiInputCallback (newInput, this);
    mMidiInputDevs->setSelectedId (index + 1, dontSendNotification);

    lastInputIndex = index;
}
