/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

#include "InterfaceDefines.h"

//==============================================================================
JackelAudioProcessorEditor::JackelAudioProcessorEditor (JackelAudioProcessor& p)
:   AudioProcessorEditor (&p),
    audioProcessor (p),
    menuPanel(&p),
    presetPanel(&p),
    mainPanel(&p),
    sidePanel(&p)
{
    setSize (JackelGUI::width, JackelGUI::height);
    
    for (auto panel : panels) {
        addAndMakeVisible(panel);
    }
}

JackelAudioProcessorEditor::~JackelAudioProcessorEditor()
{
}

//==============================================================================
void JackelAudioProcessorEditor::paint (juce::Graphics& g)
{
    
}

void JackelAudioProcessorEditor::resized()
{
    menuPanel.setBounds(0, 0, JackelGUI::MenuPanelGUI::width, JackelGUI::MenuPanelGUI::height);
    presetPanel.setBounds(menuPanel.getRight(), 0, JackelGUI::PresetPanelGUI::width, JackelGUI::PresetPanelGUI::height);
    mainPanel.setBounds(menuPanel.getRight(), presetPanel.getBottom(), JackelGUI::MainPanelGUI::width, JackelGUI::MainPanelGUI::height);
}
