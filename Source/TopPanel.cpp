/*
  ==============================================================================

    TopPanel.cpp
    Created: 17 Sep 2019 10:53:31am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "TopPanel.h"

#include "MidiProcessor.h"

TopPanel::TopPanel(JackelAudioProcessor* inProcessor, ComboBox* inMidiInputDevs)
:   PanelBase(inProcessor)
{
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    
    mMidiInputDevs = inMidiInputDevs;
    mMidiInputDevs->setColour(ComboBox::backgroundColourId, JackelColour_Base3);
    mMidiInputDevs->setColour(ComboBox::textColourId, JackelColour_Base1);
    mMidiInputDevs->setColour(ComboBox::arrowColourId, JackelColour_Base1);
    mMidiInputDevs->setColour(mMidiInputDevs->getRootMenu()->backgroundColourId, JackelColour_Base3);
    mMidiInputDevs->setColour( mMidiInputDevs->getRootMenu()->textColourId, JackelColour_Base1);
    
    addAndMakeVisible(mMidiInputDevs);
    
    /*
    mMidiInputLabel.setBounds(20, 25, MIDI_DEV_LB_WIDTH, MIDI_DEV_LB_HEIGHT);
    mMidiInputLabel.setText("Midi device:", dontSendNotification);
    mMidiInputLabel.setColour(Label::textColourId, Colours::black);
    addAndMakeVisible(mMidiInputLabel);
     */
}

TopPanel::~TopPanel()
{
    
}

void TopPanel::paint(Graphics& g)
{
    PanelBase::paint(g);
}
