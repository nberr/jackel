/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "PluginProcessor.h"
#include "MenuPanel.h"
#include "PresetPanel.h"
#include "MainPanel.h"
#include "SidePanel.h"

class PanelBase;

//==============================================================================
class JackelAudioProcessorEditor
:   public juce::AudioProcessorEditor
{
public:
    JackelAudioProcessorEditor (JackelAudioProcessor&);
    ~JackelAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    JackelAudioProcessor& audioProcessor;
    
    //==============================================================================
    MenuPanel menuPanel;
    PresetPanel presetPanel;
    MainPanel mainPanel;
    SidePanel sidePanel;
    
    std::vector<PanelBase *> panels = {
        &menuPanel,
        &presetPanel,
        &mainPanel,
        &sidePanel
    };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JackelAudioProcessorEditor)
};
