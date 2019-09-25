/*
  ==============================================================================

    BottomPanel.cpp
    Created: 17 Sep 2019 10:53:37am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "BottomPanel.h"

BottomPanel::BottomPanel(JackelAudioProcessor* inProcessor, MidiKeyboardComponent* inKeyboardComponent)
:   PanelBase(inProcessor)
{
    setSize(BOTTOM_PANEL_WIDTH, BOTTOM_PANEL_HEIGHT);
    
    mTCPanel = std::make_unique<TonalCenterPanel>(inProcessor);
    mTCPanel->setTopLeftPosition(20, 20);
    addAndMakeVisible(*mTCPanel);
    
    mTranslationPanel = std::make_unique<TranslationPanel>(inProcessor);
    mTranslationPanel->setTopLeftPosition(20 + TC_BOX_WIDTH + 20, 20);
    addAndMakeVisible(*mTranslationPanel);
    
    mKeyboardComponent = inKeyboardComponent;
    addAndMakeVisible(mKeyboardComponent);
    
}

BottomPanel::~BottomPanel()
{

}

void BottomPanel::paint(Graphics& g)
{
    PanelBase::paint(g);
}
