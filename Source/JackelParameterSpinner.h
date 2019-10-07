/*
  ==============================================================================

    JackelParameterDoubleButton.h
    Created: 5 Oct 2019 8:11:37am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"

class JackelParameterSpinner
:   public Component
{
public:
    JackelParameterSpinner(AudioProcessorValueTreeState& stateToControl,
                           const String& parameterID,
                           const String& parameterLabel);
    ~JackelParameterSpinner();
    
    int getIndex();
    
    void paint(Graphics& g) override;
    
private:
    JackelAudioProcessor* mProcessor;
    
    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> mAttachmentUp;
    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> mAttachmentDown;
    
    std::unique_ptr<ArrowButton> mButtonUp;
    std::unique_ptr<ArrowButton> mButtonDown;
    std::unique_ptr<Label> mParamDisplay;
    
    // does value wrap around to 0
    bool wrap = true;
    // buttons on left or right of text
    int buttonLocation = 0;
    
    // for placement
    int width;
    int height;
    int x;
    int y;
    int textWidth;
    
    int index;
    int numItems;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(JackelParameterSpinner)
};
