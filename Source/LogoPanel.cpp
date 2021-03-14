/*
  ==============================================================================

    LogoPanel.cpp
    Created: 14 Mar 2021 12:28:09am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "LogoPanel.h"

LogoPanel::LogoPanel(JackelAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(LOGO_PANEL_WIDTH, LOGO_PANEL_HEIGHT);
    
    mJackel = std::make_unique<juce::TextButton>();
    mJackel->setSize(JACKEL_WIDTH, JACKEL_HEIGHT);
    addAndMakeVisible(*mJackel);
    
    mLogo = std::make_unique<juce::TextButton>();
    mLogo->setSize(LOGO_WIDTH, LOGO_HEIGHT);
    mLogo->setBounds(JACKEL_WIDTH + PRESET_DISPLAY_WIDTH, 0, LOGO_WIDTH, LOGO_HEIGHT);
    addAndMakeVisible(*mLogo);
}

LogoPanel::~LogoPanel()
{
    
}
