/*
  ==============================================================================

    MidiController.cpp
    Created: 18 Sep 2019 12:05:03pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "MidiController.h"

#include "InterfaceDefines.h"

MidiController::MidiController()
{
    mKeyboardComponent = std::make_unique<MidiKeyboardComponent>(mKeyboardState, MidiKeyboardComponent::horizontalKeyboard);
    
    mKeyboardComponent->setSize(MIDI_KB_WIDTH, MIDI_KB_HEIGHT);
    mKeyboardComponent->setTopLeftPosition(20, SIDE_PANEL_HEIGHT - MIDI_KB_HEIGHT - 20);
    
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
    mMidiInputDevs->setTopLeftPosition(MIDI_DEV_LB_WIDTH + 40, 25);
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

void MidiController::handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message)
{
    const ScopedValueSetter<bool> scopedInputFlag (isAddingFromMidiInput, true);
    mKeyboardState.processNextMidiEvent (message);
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
