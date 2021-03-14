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
    
    mDeviceSelectorPanel = std::make_unique<DeviceSelectorPanel>(inProcessor);
    addAndMakeVisible(*mDeviceSelectorPanel);
    
    mTCPanel = std::make_unique<TonalCenterPanel>(inProcessor, &*mTranslationPanel);
    mTCPanel->setTopLeftPosition((CENTER_PANEL_WIDTH * 0.5) - (TONAL_CENTER_WIDTH * 0.5), (CENTER_PANEL_HEIGHT * 0.5) - (TONAL_CENTER_HEIGHT * 0.5));
    addAndMakeVisible(*mTCPanel);
    
    mInputPanel = std::make_unique<InputPanel>(inProcessor);
    mInputPanel->setTopLeftPosition((mTCPanel->getX() * 0.5) - (INPUT_CHORD_WIDTH * 0.5), (CENTER_PANEL_HEIGHT * 0.5) - (INPUT_CHORD_HEIGHT * 0.5));
    addAndMakeVisible(*mInputPanel);
    
    mOutputPanel = std::make_unique<OutputPanel>(inProcessor);
    mOutputPanel->setTopLeftPosition((mTCPanel->getX() + TONAL_CENTER_WIDTH + mInputPanel->getX()), (CENTER_PANEL_HEIGHT * 0.5) - (OUTPUT_CHORD_HEIGHT * 0.5));
    addAndMakeVisible(*mOutputPanel);
    
    
    mOctavePanel = std::make_unique<OctavePanel>(inProcessor);
    mOctavePanel->setTopLeftPosition(0, CENTER_PANEL_HEIGHT - OCTAVE_SELECT_HEIGHT);
    addAndMakeVisible(*mOctavePanel);
    
    
    
    
    
    mTranslationPanel = std::make_unique<TranslationPanel>(inProcessor);
    mTranslationPanel->setTopLeftPosition(MAIN_PANEL_WIDTH, MEDIUM_BUFFER);
    //addAndMakeVisible(*mTranslationPanel);
    
}

CenterPanel::~CenterPanel()
{
    
}
