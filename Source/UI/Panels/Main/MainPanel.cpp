/*
  ==============================================================================

    MainPanel.cpp
    Created: 25 Apr 2022 6:07:35pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "MainPanel.h"

//==============================================================================
MainPanel::MainPanel(JackelAudioProcessor* processor)
:   PanelBase(processor),
    tonalCenterAttachment(processor->parameters, "TonalCenterID", tonalCenterSlider),
    octaveAttachment(processor->parameters, "OctaveID", octaveSlider)
{
    inputMidiKeyboard = &processor->inputMidiKeyboard;
    outputMidiKeyboard = &processor->outputMidiKeyboard;
    
    addAndMakeVisible(tcComponent);
    
    tonalCenterSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    tonalCenterSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    addAndMakeVisible(tonalCenterSlider);
    
    octaveSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    addAndMakeVisible(octaveSlider);
    
    addAndMakeVisible(inputMidiKeyboard);
    addAndMakeVisible(outputMidiKeyboard);
}

MainPanel::~MainPanel()
{
    
}

//==============================================================================
void MainPanel::paint(juce::Graphics& g)
{
 
}

void MainPanel::resized()
{
    octaveSlider.setSize(300, 25);
    octaveSlider.setCentrePosition(getWidth()*0.5f, getHeight()*0.1f);
    
    tonalCenterSlider.setSize(200, 200);
    tonalCenterSlider.setCentrePosition(getWidth()*0.5f, getHeight()*0.4f);
    
    tcComponent.setBounds(tonalCenterSlider.getBounds());
    
    inputMidiKeyboard->setSize(getWidth()-40, 60);
    inputMidiKeyboard->setCentrePosition(getWidth()*0.5f, getHeight()*0.73f);
    
    outputMidiKeyboard->setSize(getWidth()-40, 60);
    outputMidiKeyboard->setCentrePosition(getWidth()*0.5f, getHeight()*0.9f);
}
