/*
  ==============================================================================

    MidiProcessor.cpp
    Created: 20 Sep 2019 4:54:27pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "MidiProcessor.h"

#include "MidiFunctions.h"

MidiProcessor::MidiProcessor()
{
    // set the range of valid midi notes
    // start range is inclusive, end range is exclusive
    mValidMidi.setStart(0);
    mValidMidi.setEnd(128);
}

MidiProcessor::~MidiProcessor()
{

}

void MidiProcessor::process(MidiMessage message, int time, MidiBuffer* processedMidi)
{
    // TODO: grab this value from the parameter
    const int tonalCenter = 0;
    
    // convert the original note to it's negative value
    const int oldNote = message.getNoteNumber();
    const int newNote = getNegative(oldNote, tonalCenter);
    
    if (message.isNoteOn())
    {
        // check if the generated note is within range. edges of the piano
        // may be cut off and nothing happens
        if (mValidMidi.contains(newNote)){
            // add the new midi note. keep the original channel and velocity
            
            
            processedMidi->addEvent(MidiMessage::noteOn (message.getChannel(),
                                                         newNote,
                                                         message.getVelocity()),
                                    time);
        }
    }
    else if (message.isNoteOff())
    {
        processedMidi->addEvent(MidiMessage::noteOff(message.getChannel(),
                                                     newNote,
                                                     message.getVelocity()),
                                time);
        
    }
}
