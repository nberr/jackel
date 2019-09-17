/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

#include "MainPanel.h"

//==============================================================================
/**
*/
class JackelAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    JackelAudioProcessorEditor (JackelAudioProcessor&);
    ~JackelAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    JackelAudioProcessor& processor;
    
    std::unique_ptr<MainPanel> mMainPanel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JackelAudioProcessorEditor)
};
