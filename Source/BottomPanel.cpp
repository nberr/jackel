/*
  ==============================================================================

    BottomPanel.cpp
    Created: 17 Sep 2019 10:53:37am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "BottomPanel.h"

BottomPanel::BottomPanel(JackelAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(BOTTOM_PANEL_WIDTH, BOTTOM_PANEL_HEIGHT);
}

BottomPanel::~BottomPanel()
{
    
}

void BottomPanel::paint(Graphics& g)
{
    PanelBase::paint(g);
}
