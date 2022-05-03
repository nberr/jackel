/*
  ==============================================================================

    MidiProcessor.cpp
    Created: 20 Apr 2022 1:09:37pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "MidiProcessor.h"

//==============================================================================
MidiProcessor::MidiProcessor()
{

}

MidiProcessor::~MidiProcessor()
{
    
}

void MidiProcessor::setParameters(MidiProcessorParameters parameters)
{
    params = parameters;
}

//==============================================================================
void MidiProcessor::processBlock(juce::MidiBuffer& midiBuffer, int bufferSize)
{
    if (midiBuffer.isEmpty()) {
        return;
    }
    
    juce::MidiBuffer processedMidi;
    
    for (auto const metadata : midiBuffer) {
        
        auto const msg = metadata.getMessage();
        const int negative_note = getNegativeNote(msg.getNoteNumber());
        
        if (msg.isNoteOn()) {
            processedMidi.addEvent(juce::MidiMessage::noteOn(1, negative_note, msg.getVelocity()), msg.getTimeStamp());
        }
        else if (msg.isNoteOff()) {
            processedMidi.addEvent(juce::MidiMessage::noteOff(1, negative_note, msg.getVelocity()), msg.getTimeStamp());
        }
        
    }
    
    midiBuffer.swapWith(processedMidi);
}

//==============================================================================
int MidiProcessor::getNegativeNote(int note)
{
    return (2 * (((params.octave+2) * 12) + params.tonal_center + 3.5)) - note;
}
