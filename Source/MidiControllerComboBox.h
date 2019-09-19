/*
  ==============================================================================

    MidiControllerComboBox.h
    Created: 18 Sep 2019 11:39:40am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class MidiControllerComboBox
:   public ComboBox,
    public MidiInputCallback
{
public:
    MidiControllerComboBox();
    ~MidiControllerComboBox();
    
    void setMidiInput (int index);
    
    virtual void handleIncomingMidiMessage (MidiInput* source,
                                            const MidiMessage& message) override;
    
private:
    AudioDeviceManager deviceManager;
    Label midiInputListLabel;
    int lastInputIndex;
    bool isAddingFromMidiInput = false;
    
};
