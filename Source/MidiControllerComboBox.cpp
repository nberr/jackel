/*
  ==============================================================================

    MidiControllerComboBox.cpp
    Created: 18 Sep 2019 11:39:40am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "MidiControllerComboBox.h"

MidiControllerComboBox::MidiControllerComboBox()
{
    lastInputIndex = 0;
    
    this->setTextWhenNoChoicesAvailable ("No MIDI Inputs Enabled");
    auto midiInputs = MidiInput::getDevices();
    this->addItemList (midiInputs, 1);
    this->onChange = [this] { setMidiInput (this->getSelectedItemIndex()); };
    
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
    if (this->getSelectedId() == 0)
        setMidiInput (0);
}

MidiControllerComboBox::~MidiControllerComboBox()
{
    
}

void MidiControllerComboBox::setMidiInput (int index)
{
    auto list = MidiInput::getDevices();
    
    deviceManager.removeMidiInputCallback (list[lastInputIndex], this);
    
    auto newInput = list[index];
    
    if (! deviceManager.isMidiInputEnabled (newInput))
        deviceManager.setMidiInputEnabled (newInput, true);
    
    deviceManager.addMidiInputCallback (newInput, this);
    this->setSelectedId (index + 1, dontSendNotification);
    
    lastInputIndex = index;
}

void MidiControllerComboBox::handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message)
{
    
}
