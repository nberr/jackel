/*
  ==============================================================================

    MenuPanel.h
    Created: 25 Apr 2022 6:07:09pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

//==============================================================================
class MenuPanel
:   public PanelBase
{
public:
    //==============================================================================
    MenuPanel(JackelAudioProcessor* processor);
    ~MenuPanel();
    
    //==============================================================================
    //void paint(juce::Graphics& g) override;
    void resized() override;
    
    
private:
    //==============================================================================
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MenuPanel)
};
