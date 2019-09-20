/*
  ==============================================================================

    MidiController.cpp
    Created: 18 Sep 2019 12:05:03pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "MidiController.h"

#include "InterfaceDefines.h"

MidiController::MidiController()
:   mMidiKbComponent(mMidiKbState, MidiKeyboardComponent::Orientation::horizontalKeyboard)
{
    mMidiKbComponent.setBounds(20, TOP_MENU_HEIGHT + 130, PIANO_WIDTH - 40, PIANO_HEIGHT);
    mMidiKbState.addListener (this);
}

MidiController::~MidiController()
{
    mMidiKbState.removeListener(this);
}

MidiKeyboardComponent* MidiController::getMidiKeyboardComponent()
{
    return &mMidiKbComponent;
}

void MidiController::handleNoteOn (MidiKeyboardState* source, int midiChannel, int midiNoteNumber, float velocity)
{
    
}

void MidiController::handleNoteOff (MidiKeyboardState* source, int midiChannel, int midiNoteNumber, float velocity)
{
    
}
