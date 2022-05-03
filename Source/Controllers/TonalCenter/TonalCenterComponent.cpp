/*
  ==============================================================================

    TonalCenterComponent.cpp
    Created: 26 Apr 2022 3:09:20pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "TonalCenterComponent.h"

//==============================================================================
TonalCenterComponent::TonalCenterComponent()
{
    
}

TonalCenterComponent::~TonalCenterComponent()
{
    
}

//==============================================================================
void TonalCenterComponent::paint(juce::Graphics& g)
{
    g.setColour(juce::Colours::green);
    g.drawRect(getLocalBounds());
}

void TonalCenterComponent::resized()
{
    
}
