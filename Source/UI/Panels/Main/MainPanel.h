/*
  ==============================================================================

    MainPanel.h
    Created: 25 Apr 2022 6:07:35pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

#include "TonalCenterComponent.h"

//==============================================================================
class MainPanel
:   public PanelBase
{
public:
    //==============================================================================
    MainPanel(JackelAudioProcessor* processor);
    ~MainPanel();
    
    //==============================================================================
    void paint(juce::Graphics& g) override;
    void resized() override;
    
    
private:
    //==============================================================================
    juce::Slider tonalCenterSlider;
    juce::AudioProcessorValueTreeState::SliderAttachment tonalCenterAttachment;
    
    TonalCenterComponent tcComponent;
    
    juce::Slider octaveSlider;
    juce::AudioProcessorValueTreeState::SliderAttachment octaveAttachment;
    
    juce::MidiKeyboardComponent *inputMidiKeyboard;
    juce::MidiKeyboardComponent *outputMidiKeyboard;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainPanel)
};
