/*
  ==============================================================================

    BottomPanel.h
    Created: 17 Sep 2019 10:53:37am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

class BottomPanel
:   public PanelBase
{
public:
    BottomPanel(JackelAudioProcessor* inProcessor);
    ~BottomPanel();
    
    void paint(Graphics& g) override;
    
private:
    
};
