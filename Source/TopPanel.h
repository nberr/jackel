/*
  ==============================================================================

    TopPanel.h
    Created: 17 Sep 2019 10:53:31am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

#include "LogoPanel.h"
#include "PresetPanel.h"

class TopPanel
:   public PanelBase
{
public:
    TopPanel(JackelAudioProcessor* inProcessor);
    ~TopPanel();
    
private:
    
    Label mMidiInputLabel;
    
    std::unique_ptr<LogoPanel> mLogoPanel;
    std::unique_ptr<PresetPanel> mPresetPanel;
    
    // TODO: add logo here
};
