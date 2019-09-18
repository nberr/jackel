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
    mMidiKbComponent.setBounds(1, TOP_MENU_HEIGHT, PIANO_WIDTH - 2, PIANO_HEIGHT);
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
