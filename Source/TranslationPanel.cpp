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

