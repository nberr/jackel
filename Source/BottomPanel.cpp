/*
  ==============================================================================

    BottomPanel.cpp
    Created: 17 Sep 2019 10:53:37am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "BottomPanel.h"

BottomPanel::BottomPanel(JackelAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(BOTTOM_PANEL_WIDTH, BOTTOM_PANEL_HEIGHT);
    
    mTCPanel = std::make_unique<TonalCenterPanel>(inProcessor);
    mTCPanel->setTopLeftPosition(20, 20);
    addAndMakeVisible(*mTCPanel);
    
    mTranslationPanel = std::make_unique<TranslationPanel>(inProcessor);
    mTranslationPanel->setTopLeftPosition(20 + TC_BOX_WIDTH + 20, 20);
    addAndMakeVisible(*mTranslationPanel);
}

BottomPanel::~BottomPanel()
{
    
}

void BottomPanel::paint(Graphics& g)
{
    PanelBase::paint(g);
    
    g.drawRect(20, SIDE_PANEL_HEIGHT - MIDI_KB_HEIGHT - 20, MIDI_KB_WIDTH, MIDI_KB_HEIGHT);
}
