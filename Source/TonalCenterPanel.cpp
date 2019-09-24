/*
  ==============================================================================

    TonalCenterPanel.cpp
    Created: 24 Sep 2019 11:23:57am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "TonalCenterPanel.h"

TonalCenterPanel::TonalCenterPanel(JackelAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(TC_BOX_WIDTH, TC_BOX_HEIGHT);
}

TonalCenterPanel::~TonalCenterPanel()
{
    
}

void TonalCenterPanel::paint(Graphics& g)
{
    PanelBase::paint(g);
}

