/*
  ==============================================================================

    DeviceSelectorPanel.cpp
    Created: 18 Nov 2019 7:35:31pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "DeviceSelectorPanel.h"

DeviceSelectorPanel::DeviceSelectorPanel(JackelAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(DEVICE_SELECT_WIDTH, DEVICE_SELECT_HEIGHT);
}

DeviceSelectorPanel::~DeviceSelectorPanel()
{
    
}
