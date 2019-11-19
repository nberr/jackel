/*
  ==============================================================================

    CenterPanel.h
    Created: 18 Nov 2019 7:28:24pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

class CenterPanel
:   public PanelBase
{
public:
    CenterPanel(JackelAudioProcessor* inProcessor);
    ~CenterPanel();
    
    void paint(Graphics& g) override;
    
private:
    
};
