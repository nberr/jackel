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
    setSize(TRANSLATION_WIDTH, TRANSLATION_HEIGHT);
    
    mTranslationGroup = std::make_unique<GroupComponent>("Translation", "Translation");
    // TODO:match look and feel
    mTranslationGroup->setColour(GroupComponent::textColourId, Colours::black);
    mTranslationGroup->setBounds(0, 0, getWidth(), getHeight());
    addAndMakeVisible(*mTranslationGroup);
    
}

TranslationPanel::~TranslationPanel()
{
    
}

void TranslationPanel::paint(Graphics& g)
{
    //PanelBase::paint(g);
    
    
}

