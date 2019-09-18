/*
  ==============================================================================

    TopPanel.cpp
    Created: 17 Sep 2019 10:53:31am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "TopPanel.h"

TopPanel::TopPanel(JackelAudioProcessor* inProcessor)
:   PanelBase(inProcessor),
    mMidiKbComponent(mMidiKbState, MidiKeyboardComponent::Orientation::horizontalKeyboard)
{
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    
    mMidiKbComponent.setBounds(1, TOP_MENU_HEIGHT, PIANO_WIDTH - 2, PIANO_HEIGHT);
    addAndMakeVisible(mMidiKbComponent);
    mMidiKbState.addListener (this);
}

TopPanel::~TopPanel()
{
    mMidiKbState.removeListener(this);
}

void TopPanel::paint(Graphics& g)
{
    PanelBase::paint(g);
}

void TopPanel::handleNoteOn (MidiKeyboardState* source,
                           int midiChannel, int midiNoteNumber, float velocity)
{
    
}

void TopPanel::handleNoteOff (MidiKeyboardState* source,
                              int midiChannel, int midiNoteNumber, float velocity)
{
    
}
