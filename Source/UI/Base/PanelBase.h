/*
  ==============================================================================

    PanelBase.h
    Created: 25 Apr 2022 6:06:13pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "PluginProcessor.h"

//==============================================================================
class PanelBase
:   public juce::Component
{
public:
    //==============================================================================
    PanelBase(JackelAudioProcessor* processor);
    ~PanelBase();
    
    //==============================================================================
    void paint(juce::Graphics& g) override;
    
protected:
    //==============================================================================
    JackelAudioProcessor *processor;
    
};
