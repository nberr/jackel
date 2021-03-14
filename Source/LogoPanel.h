/*
  ==============================================================================

    LogoPanel.h
    Created: 14 Mar 2021 12:28:09am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

class LogoPanel
:   public PanelBase
{
public:
    LogoPanel(JackelAudioProcessor* inProcessor);
    ~LogoPanel();
    
private:
    
    // TODO: add logo here
    std::unique_ptr<juce::TextButton> mLogo;
    std::unique_ptr<juce::TextButton> mJackel;
};
