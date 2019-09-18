/*
  ==============================================================================

    TopPanel.h
    Created: 17 Sep 2019 10:53:31am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

class TopPanel
:   public PanelBase,
    public MidiKeyboardStateListener
{
public:
    TopPanel(JackelAudioProcessor* inProcessor);
    ~TopPanel();
    
    void paint(Graphics& g) override;
    
    virtual void handleNoteOn (MidiKeyboardState* source,
                               int midiChannel, int midiNoteNumber, float velocity) override;
    
    virtual void handleNoteOff (MidiKeyboardState* source,
                                int midiChannel, int midiNoteNumber, float velocity) override;
    
private:
    MidiKeyboardState mMidiKbState;
    MidiKeyboardComponent mMidiKbComponent;
    
};
