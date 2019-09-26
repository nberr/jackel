/*
  ==============================================================================

    TonalCenterPanel.cpp
    Created: 24 Sep 2019 11:23:57am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "TonalCenterPanel.h"

TonalCenterPanel::TonalCenterPanel(JackelAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(TC_BOX_WIDTH, TC_BOX_HEIGHT);
    
    mBoxLabel = std::make_unique<Label>();
    mBoxLabel->setText("Tonal Center", dontSendNotification);
    mBoxLabel->setColour(Label::textColourId, Colours::black);
    mBoxLabel->setJustificationType(Justification::centred);
    mBoxLabel->setBounds((TC_BOX_WIDTH / 2) - (TC_LABEL_WIDTH / 2), MEDIUM_BUFFER, TC_LABEL_WIDTH, TC_LABEL_HEIGHT);
    addAndMakeVisible(*mBoxLabel);
    
    mUpButton = std::make_unique<ArrowButton>("UpArrow", 0.75, Colours::black);
    mUpButton->setBounds(0, 0, TC_BUTTON_WIDTH, TC_BUTTON_HEIGHT);
    //addAndMakeVisible(*mUpButton);
    
    mDownButton = std::make_unique<ArrowButton>("DownArrow", 0.25, Colours::black);
    mDownButton->setBounds(20, 0, TC_BUTTON_WIDTH, TC_BUTTON_HEIGHT);
    //addAndMakeVisible(*mDownButton);
}

TonalCenterPanel::~TonalCenterPanel()
{
    
}

void TonalCenterPanel::paint(Graphics& g)
{
    PanelBase::paint(g);
    
    // top button
    g.drawRect(TC_DISPLAY_WIDTH + (2 * MEDIUM_BUFFER), TC_LABEL_HEIGHT + (2 * MEDIUM_BUFFER), TC_BUTTON_DISPLAY_WIDTH, TC_BUTTON_DISPLAY_HEIGHT);
    
    // bottom button
    g.drawRect(TC_DISPLAY_WIDTH + (2 * MEDIUM_BUFFER), TC_LABEL_HEIGHT + (3 * MEDIUM_BUFFER) + TC_BUTTON_DISPLAY_HEIGHT, TC_BUTTON_DISPLAY_WIDTH, TC_BUTTON_DISPLAY_HEIGHT);
    
    // tonal center display
    g.drawRect(MEDIUM_BUFFER, TC_LABEL_HEIGHT + (2 * MEDIUM_BUFFER), TC_DISPLAY_WIDTH, TC_DISPLAY_HEIGHT);
}

