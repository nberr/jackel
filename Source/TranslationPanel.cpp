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
}

TranslationPanel::~TranslationPanel()
{
    
}

void TranslationPanel::paint(Graphics& g)
{
    PanelBase::paint(g);
}

