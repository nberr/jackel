/*
  ==============================================================================

    MidiProcessor.cpp
    Created: 20 Sep 2019 4:54:27pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "MidiProcessor.h"

MidiProcessor::MidiProcessor(AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    
}

MidiProcessor::~MidiProcessor()
{
    
}

MidiBuffer MidiProcessor::process(MidiMessage m, int time)
{
    MidiBuffer processedMidi;
    
    
    
    return processedMidi;
}

int MidiProcessor::get_negative(float center, int note)
{
    float polar = note - center;
    int newNote = (center - polar < 0) ? ((int)(center - polar + 12)) % 12 :
    ((int)(center - polar)) % 12;
    
    return newNote;
}
