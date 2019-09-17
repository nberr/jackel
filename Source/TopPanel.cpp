/*
  ==============================================================================

    TopPanel.cpp
    Created: 17 Sep 2019 10:53:31am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "TopPanel.h"

TopPanel::TopPanel(JackelAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
}

TopPanel::~TopPanel()
{
    
}

void TopPanel::paint(Graphics& g)
{
    PanelBase::paint(g);
    
}
