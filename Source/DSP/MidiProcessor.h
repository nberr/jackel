/*
  ==============================================================================

    MidiProcessor.h
    Created: 20 Apr 2022 1:09:37pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

struct MidiProcessorParameters {
    int tonal_center;
    int octave;
};

//==============================================================================
class MidiProcessor
{
public:
    //==============================================================================
    MidiProcessor();
    ~MidiProcessor();
    
    void setParameters(MidiProcessorParameters parameters);
    
    //==============================================================================
    void processBlock(juce::MidiBuffer& midiBuffer, int bufferSize);

private:
    //==============================================================================
    int getNegativeNote(int note);
    
    //==============================================================================
    MidiProcessorParameters params;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidiProcessor)
};
