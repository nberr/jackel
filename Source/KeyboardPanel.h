/*
  ==============================================================================

    KeyboardPanel.h
    Created: 18 Nov 2019 7:35:02pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

class KeyboardPanel
:   public PanelBase
{
public:
    KeyboardPanel(JackelAudioProcessor* inProcessor);
    ~KeyboardPanel();
    
    void paint(Graphics& g) override;
private:
    
};
