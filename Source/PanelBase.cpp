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
    g.setColour(Colours::white);
    g.fillAll();
    
    g.setColour(Colours::black);
    g.drawRoundedRectangle(0, 0, getWidth(), getHeight(), 4, 2);
}
