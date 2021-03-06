/*
  ==============================================================================

    MidiController.h
    Created: 18 Sep 2019 12:05:03pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class MidiController
:   private MidiKeyboardStateListener,
    private MidiInputCallback
{
public:
    MidiController(JackelAudioProcessor* inProcessor);
    ~MidiController();
    
    virtual void handleNoteOn (MidiKeyboardState* source, int midiChannel, int midiNoteNumber, float velocity) override;
    virtual void handleNoteOff (MidiKeyboardState* source, int midiChannel, int midiNoteNumber, float velocity) override;
    virtual void handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message) override;
    
    MidiKeyboardComponent* getKeyboardComponent();
    ComboBox* getComboBox();
    void setMidiInput (int index);
    
private:
     JackelAudioProcessor* mProcessor;
    
    std::unique_ptr<MidiKeyboardComponent> mKeyboardComponent;
    MidiKeyboardState mKeyboardState;
    
    AudioDeviceManager deviceManager;
    std::unique_ptr<ComboBox> mMidiInputDevs;
    int lastInputIndex = 0;
    
    Range<int> mValidMidi;
};
