/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

#include "MainPanel.h"
#include "PopoutPanel.h"
#include "JackelLookAndFeel.h"

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
    std::unique_ptr<PopoutPanel> mPopoutPanel;
    std::unique_ptr<juce::TextButton> mPopoutButton; // TODO: maybe change this to a shape later
    bool mPopoutShow = true;
    
    std::unique_ptr<JackelLookAndFeel> mLookAndFeel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JackelAudioProcessorEditor)
};
