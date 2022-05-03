/*
  ==============================================================================

    PanelBase.cpp
    Created: 25 Apr 2022 6:06:13pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "PanelBase.h"

//==============================================================================
PanelBase::PanelBase(JackelAudioProcessor* processor)
{
    this->processor = processor;
}

PanelBase::~PanelBase()
{
    
}

//==============================================================================
void PanelBase::paint(juce::Graphics& g)
{
    g.setColour(juce::Colours::black);
    g.fillAll();
    
    g.setColour(juce::Colours::green);
    g.drawRect(getLocalBounds());
}
