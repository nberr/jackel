/*
  ==============================================================================

    DeviceSelectorPanel.cpp
    Created: 18 Nov 2019 7:35:31pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "DeviceSelectorPanel.h"

DeviceSelectorPanel::DeviceSelectorPanel(JackelAudioProcessor* inProcessor, ComboBox* inMidiInputDevs)
:   PanelBase(inProcessor)
{
    setSize(DEVICE_SELECT_WIDTH, DEVICE_SELECT_HEIGHT);
    
    mMidiInputDevs = inMidiInputDevs;
    mMidiInputDevs->setColour(ComboBox::backgroundColourId, JackelColour_Lighter);
    mMidiInputDevs->setColour(ComboBox::textColourId, JackelColour_Darker);
    mMidiInputDevs->setColour(ComboBox::arrowColourId, JackelColour_Darker);
    
    mMidiInputDevs->setSize(PRESET_TOTAL_WIDTH, PRESET_DISPLAY_HEIGHT);
    mMidiInputDevs->setTopLeftPosition((DEVICE_SELECT_WIDTH * 0.5) - (PRESET_TOTAL_WIDTH * 0.5), (DEVICE_SELECT_HEIGHT * 0.5) - (PRESET_DISPLAY_HEIGHT * 0.5));
    
    addAndMakeVisible(mMidiInputDevs);
}

DeviceSelectorPanel::~DeviceSelectorPanel()
{
    
}
