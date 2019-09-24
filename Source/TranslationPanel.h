/*
  ==============================================================================

    TranslationPanel.h
    Created: 24 Sep 2019 11:24:09am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

class TranslationPanel
:   public PanelBase
{
public:
    TranslationPanel(JackelAudioProcessor* inProcessor);
    ~TranslationPanel();
    
    void paint(Graphics& g) override;
    
private:
    
    
};
