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
    
    int button_x = 15;
    int button_y = 10;
    int button_w = 55;
    int button_h = 25;
    
    mNewPreset = std::make_unique<juce::TextButton>();
    mNewPreset->setButtonText("NEW");
    mNewPreset->setBounds(button_x, button_y, button_w, button_h);
    mNewPreset->addListener(this);
    addAndMakeVisible(*mNewPreset);
    
    button_x = button_x + button_w;
    
    mSavePreset = std::make_unique<juce::TextButton>();
    mSavePreset->setButtonText("SAVE");
    mSavePreset->setBounds(button_x, button_y, button_w, button_h);
    mSavePreset->addListener(this);
    addAndMakeVisible(*mSavePreset);
    
    button_x = button_x + button_w;
    
    mSaveAsPreset = std::make_unique<juce::TextButton>();
    mSaveAsPreset->setButtonText("SAVE AS");
    mSaveAsPreset->setBounds(button_x, button_y, button_w, button_h);
    mSaveAsPreset->addListener(this);
    addAndMakeVisible(*mSaveAsPreset);
    
    const int comboBox_w = 200;
    const int comboBox_x = PRESET_PANEL_WIDTH*0.5 - comboBox_w*0.5;
    
    mPresetDisplay = std::make_unique<juce::ComboBox>();
    mPresetDisplay->setBounds(comboBox_x, button_y, comboBox_w, button_h);
    mPresetDisplay->addListener(this);
    addAndMakeVisible(*mPresetDisplay);
    
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
    else if (b == &*mSaveAsPreset)
    {
        displaySaveAsPopup();
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
