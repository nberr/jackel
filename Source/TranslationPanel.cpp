/*
  ==============================================================================

    TranslationPanel.cpp
    Created: 24 Sep 2019 11:24:09am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "TranslationPanel.h"

TranslationPanel::TranslationPanel(JackelAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(MAPPED_BOX_WIDTH, MAPPED_BOX_HEIGHT);
    
    mOGLabel = std::make_unique<Label>();
    mOGLabel->setText("Original", dontSendNotification);
    mOGLabel->setColour(Label::textColourId, Colours::black);
    mOGLabel->setJustificationType(Justification::centred);
    mOGLabel->setBounds(LARGE_BUFFER,
                        MEDIUM_BUFFER,
                        OG_LABEL_WIDTH,
                        OG_LABEL_HEIGHT);
    addAndMakeVisible(*mOGLabel);
    
    mOGDisplayLabel = std::make_unique<Label>();
    
    mNegLabel = std::make_unique<Label>();
    mNegLabel->setText("Negative", dontSendNotification);
    mNegLabel->setColour(Label::textColourId, Colours::black);
    mNegLabel->setJustificationType(Justification::centred);
    mNegLabel->setBounds(LARGE_BUFFER + OG_DISPLAY_WIDTH + (MAPPED_BOX_WIDTH - (MAPPED_BOX_WIDTH * 0.8)),
                        MEDIUM_BUFFER,
                        NEG_LABEL_WIDTH,
                        NEG_LABEL_HEIGHT);
    addAndMakeVisible(*mNegLabel);
    
    mNegDisplayLabel = std::make_unique<Label>();
}

TranslationPanel::~TranslationPanel()
{
    
}

void TranslationPanel::paint(Graphics& g)
{
    PanelBase::paint(g);
    
    // original box
    g.drawRect(LARGE_BUFFER,
               OG_LABEL_HEIGHT,
               OG_DISPLAY_WIDTH,
               OG_DISPLAY_HEIGHT);
    
    // translated box
    g.drawRect(LARGE_BUFFER + OG_DISPLAY_WIDTH + (MAPPED_BOX_WIDTH - (MAPPED_BOX_WIDTH * 0.8)),
               NEG_LABEL_HEIGHT,
               NEG_DISPLAY_WIDTH,
               NEG_DISPLAY_HEIGHT);
}

