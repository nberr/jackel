/*
  ==============================================================================

    DeviceSelectorPanel.h
    Created: 18 Nov 2019 7:35:31pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

class DeviceSelectorPanel
:   public PanelBase
{
public:
    DeviceSelectorPanel(JackelAudioProcessor* inProcessor);
    ~DeviceSelectorPanel();
    
    void paint(Graphics& g) override;
private:
    
};
