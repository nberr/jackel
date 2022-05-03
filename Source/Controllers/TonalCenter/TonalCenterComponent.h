/*
  ==============================================================================

    TonalCenterComponent.h
    Created: 26 Apr 2022 3:09:20pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
class TonalCenterComponent
:   public juce::Component
{
public:
    //==============================================================================
    TonalCenterComponent();
    ~TonalCenterComponent();
    
    //==============================================================================
    void paint(juce::Graphics& g) override;
    void resized() override;
    
private:
    //==============================================================================
    //juce::Array<juce::ShapeButton> tonalCenterButtons;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TonalCenterComponent)
};
