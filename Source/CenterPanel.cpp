/*
  ==============================================================================

    CenterPanel.cpp
    Created: 18 Nov 2019 7:28:24pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "CenterPanel.h"

CenterPanel::CenterPanel(JackelAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(CENTER_PANEL_WIDTH, CENTER_PANEL_HEIGHT);
    
    mTranslationPanel = std::make_unique<TranslationPanel>(inProcessor);
    mTranslationPanel->setTopLeftPosition(LARGE_BUFFER + TONAL_CENTER_WIDTH + LARGE_BUFFER, MEDIUM_BUFFER);
    addAndMakeVisible(*mTranslationPanel);
    
    mTCPanel = std::make_unique<TonalCenterPanel>(inProcessor, &*mTranslationPanel);
    mTCPanel->setTopLeftPosition(LARGE_BUFFER, MEDIUM_BUFFER);
    addAndMakeVisible(*mTCPanel);
    
    
}

CenterPanel::~CenterPanel()
{
    
}

void CenterPanel::paint(Graphics& g)
{
    
}
