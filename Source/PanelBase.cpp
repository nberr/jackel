/*
  ==============================================================================

    PanelBase.cpp
    Created: 17 Sep 2019 10:53:16am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "PanelBase.h"

PanelBase::PanelBase(JackelAudioProcessor* inProcessor)
{
    mProcessor = inProcessor;
}

PanelBase::~PanelBase()
{
    
}

void PanelBase::paint(Graphics& g) {
    g.setColour(JackelColour_Base2);
    g.fillAll();
    
    g.setColour(JackelColour_Base1);
    g.drawRoundedRectangle(0, 0, getWidth(), getHeight(), 4, 8);
}
