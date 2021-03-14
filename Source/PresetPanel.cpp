/*
  ==============================================================================

    PresetPanel.cpp
    Created: 9 Mar 2021 9:16:15pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "PresetPanel.h"

#include "PresetPanel.h"

PresetPanel::PresetPanel(JackelAudioProcessor *inProcessor)
:   PanelBase(inProcessor)
{
    setSize(PRESET_PANEL_WIDTH, PRESET_PANEL_HEIGHT);
    
    mProcessor = inProcessor;
    
    mNewPreset = std::make_unique<juce::TextButton>("NEW");
    mNewPreset->setSize(PRESET_NEW_WIDTH, PRESET_NEW_HEIGHT);
    mNewPreset->setTopLeftPosition((PRESET_PANEL_WIDTH * 0.5) - (PRESET_TOTAL_WIDTH * 0.5), (PRESET_PANEL_HEIGHT * 0.5) - (PRESET_DISPLAY_HEIGHT * 0.5));
    mNewPreset->addListener(this);
    addAndMakeVisible(*mNewPreset);
    
    mPreviousPreset = std::make_unique<juce::TextButton>("<");
    mPreviousPreset->setSize(PRESET_PREV_WIDTH, PRESET_PREV_HEIGHT);
    mPreviousPreset->setTopLeftPosition((PRESET_PANEL_WIDTH * 0.5) - (PRESET_TOTAL_WIDTH * 0.5) + PRESET_NEW_WIDTH, (PRESET_PANEL_HEIGHT * 0.5) - (PRESET_DISPLAY_HEIGHT * 0.5));
    mPreviousPreset->addListener(this);
    addAndMakeVisible(*mPreviousPreset);
    
    mPresetDisplay = std::make_unique<juce::ComboBox>();
    mPresetDisplay->setSize(PRESET_DISPLAY_WIDTH, PRESET_DISPLAY_HEIGHT);
    mPresetDisplay->setTopLeftPosition((PRESET_PANEL_WIDTH * 0.5) - (PRESET_DISPLAY_WIDTH * 0.5), (PRESET_PANEL_HEIGHT * 0.5) - (PRESET_DISPLAY_HEIGHT * 0.5));
    mPresetDisplay->addListener(this);
    addAndMakeVisible(*mPresetDisplay);
    
    mNextPreset = std::make_unique<juce::TextButton>(">");
    mNextPreset->setSize(PRESET_PREV_WIDTH, PRESET_PREV_HEIGHT);
    mNextPreset->setTopLeftPosition((PRESET_PANEL_WIDTH * 0.5) - (PRESET_TOTAL_WIDTH * 0.5) + PRESET_NEW_WIDTH + PRESET_PREV_WIDTH + PRESET_DISPLAY_WIDTH, (PRESET_PANEL_HEIGHT * 0.5) - (PRESET_DISPLAY_HEIGHT * 0.5));
    mNextPreset->addListener(this);
    addAndMakeVisible(*mNextPreset);
    
    mSavePreset = std::make_unique<juce::TextButton>("SAVE");
    mSavePreset->setSize(PRESET_SAVE_WIDTH, PRESET_SAVE_HEIGHT);
    mSavePreset->setTopLeftPosition((PRESET_PANEL_WIDTH * 0.5) - (PRESET_TOTAL_WIDTH * 0.5) + PRESET_NEW_WIDTH + PRESET_PREV_WIDTH + PRESET_DISPLAY_WIDTH + PRESET_NEXT_WIDTH, (PRESET_PANEL_HEIGHT * 0.5) - (PRESET_DISPLAY_HEIGHT * 0.5));
    mSavePreset->addListener(this);
    addAndMakeVisible(*mSavePreset);
    
    
    
   
    

    
    
    
    
    //updatePresetComboBox();
}

PresetPanel::~PresetPanel()
{
    
}

void PresetPanel::buttonClicked(juce::Button* b)
{
    JackelPresetManager* presetManager = mProcessor->getPresetManager();
    
    if (b == &*mNewPreset)
    {
        presetManager->createNewPreset();
        updatePresetComboBox();
    }
    else if (b == &*mSavePreset)
    {
        presetManager->savePreset();
    }
}

void PresetPanel::comboBoxChanged(juce::ComboBox* comboBoxThatHasChanged)
{
    if (comboBoxThatHasChanged == &*mPresetDisplay)
    {
        JackelPresetManager* presetManager = mProcessor->getPresetManager();
        const int index = mPresetDisplay->getSelectedItemIndex();
        
        presetManager->loadPreset(index);
    }
}

void PresetPanel::displaySaveAsPopup()
{
    JackelPresetManager* presetManager = mProcessor->getPresetManager();
    
    juce::String currentPresetName = presetManager->getCurrentPresetName();
    
    juce::AlertWindow window("Save As", "Please enter a name for your Preset", juce::AlertWindow::NoIcon);
    window.centreAroundComponent(this, getWidth(), getHeight());
    window.addTextEditor("presetName", currentPresetName, "preset name: ");
    
    window.addButton("Confirm", 1);
    window.addButton("Cancel", 0);
    
    if (window.runModalLoop())
    {
        juce::String presetName = window.getTextEditor("presetName")->getText();
        presetManager->saveAsPreset(presetName);
        
        updatePresetComboBox();
    }
}

void PresetPanel::updatePresetComboBox()
{
    JackelPresetManager* presetManager = mProcessor->getPresetManager();
    juce::String presetName = presetManager->getCurrentPresetName();
    
    mPresetDisplay->clear(juce::dontSendNotification);
    
    const int numPresets = presetManager->getNumberOfPresets();
    for (int i = 0; i < numPresets; i++)
    {
        mPresetDisplay->addItem(presetManager->getPresetName(i), i+1);
    }
    
    mPresetDisplay->setText(presetManager->getCurrentPresetName());
}
