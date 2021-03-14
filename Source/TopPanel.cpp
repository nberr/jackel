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
    
    mLogoPanel = std::make_unique<LogoPanel>(inProcessor);
    addAndMakeVisible(*mLogoPanel);
    
    mPresetPanel = std::make_unique<PresetPanel>(inProcessor);
    mPresetPanel->setTopLeftPosition(0, LOGO_PANEL_HEIGHT);
    addAndMakeVisible(*mPresetPanel);
    
    mMidiInputDevs = inMidiInputDevs;
    mMidiInputDevs->setColour(ComboBox::backgroundColourId, JackelColour_Lighter);
    mMidiInputDevs->setColour(ComboBox::textColourId, JackelColour_Darker);
    mMidiInputDevs->setColour(ComboBox::arrowColourId, JackelColour_Darker);
    
    //addAndMakeVisible(mMidiInputDevs);
    
}

TopPanel::~TopPanel()
{
    
}
