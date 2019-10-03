/*
  ==============================================================================

    MidiProcessor.h
    Created: 20 Sep 2019 4:54:27pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class MidiProcessor
{
public:
    MidiProcessor();
    ~MidiProcessor();
    
    void process(MidiMessage message, int time, MidiBuffer* processedMidi);
    
private:
    Range<int> mValidMidi;
};
