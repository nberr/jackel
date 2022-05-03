/*
  ==============================================================================

    PresetPanel.h
    Created: 25 Apr 2022 6:07:29pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

//==============================================================================
class PresetPanel
:   public PanelBase
{
public:
    //==============================================================================
    PresetPanel(JackelAudioProcessor* processor);
    ~PresetPanel();
    
    //==============================================================================
    //void paint(juce::Graphics& g) override;
    void resized() override;
    
    
private:
    //==============================================================================
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PresetPanel)
};
