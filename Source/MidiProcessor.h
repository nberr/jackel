/*
  ==============================================================================

    MidiProcessor.h
    Created: 20 Sep 2019 4:54:27pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include <unordered_map>

#include "JuceHeader.h"

static String Centers[12] = {
    "C",
    "Db",
    "D",
    "Eb",
    "E",
    "F",
    "Gb",
    "G",
    "Ab",
    "A",
    "Bb",
    "B"
};

class MidiProcessor
{
public:
    MidiProcessor(AudioBuffer<float>& buffer, MidiBuffer& midiMessages);
    ~MidiProcessor();
    
    MidiBuffer process(MidiMessage m, int time);
    
    int get_negative(float center, int note);
    
private:
    std::unordered_map<int, int> mNoteMap;
    
};
