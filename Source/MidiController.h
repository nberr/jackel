/*
  ==============================================================================

    MidiController.h
    Created: 18 Sep 2019 12:05:03pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class MidiController
:   public MidiKeyboardStateListener
{
public:
    MidiController();
    ~MidiController();
    
    MidiKeyboardComponent* getMidiKeyboardComponent();
    
    virtual void handleNoteOn (MidiKeyboardState* source,
                               int midiChannel, int midiNoteNumber, float velocity) override;
    
    virtual void handleNoteOff (MidiKeyboardState* source,
                                int midiChannel, int midiNoteNumber, float velocity) override;
    
private:
    MidiKeyboardState mMidiKbState;
    MidiKeyboardComponent mMidiKbComponent;
    
};
