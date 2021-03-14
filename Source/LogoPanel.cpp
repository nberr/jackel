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
}

LogoPanel::~LogoPanel()
{
    
}
