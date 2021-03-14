/*
  ==============================================================================

    PresetPanel.h
    Created: 9 Mar 2021 9:16:15pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

class PresetPanel
:   public PanelBase,
    public juce::Button::Listener,
    public juce::ComboBox::Listener
{
public:
    PresetPanel(JackelAudioProcessor *inProcessor);
    ~PresetPanel();
    
    //void paint(juce::Graphics& g) override;
        
    void buttonClicked(juce::Button*) override;
    void comboBoxChanged(juce::ComboBox* comboBoxThatHasChanged) override;
private:
    JackelAudioProcessor *mProcessor;
    
    void displaySaveAsPopup();
        
    void updatePresetComboBox();
        
    std::unique_ptr<juce::ComboBox> mPresetDisplay;
        
    std::unique_ptr<juce::TextButton> mNewPreset, mSavePreset, mPreviousPreset, mNextPreset;
};
