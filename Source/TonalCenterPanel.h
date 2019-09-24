/*
  ==============================================================================

    TonalCenterPanel.h
    Created: 24 Sep 2019 11:23:57am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

class TonalCenterPanel
:   public PanelBase
{
public:
    TonalCenterPanel(JackelAudioProcessor* inProcessor);
    ~TonalCenterPanel();
    
    void paint(Graphics& g) override;
    
private:
    
    
};
