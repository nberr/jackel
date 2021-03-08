/*
  ==============================================================================

    MainPanel.cpp
    Created: 17 Sep 2019 10:53:22am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "MainPanel.h"

MainPanel::MainPanel(JackelAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(MAIN_PANEL_WIDTH + TRANSLATION_WIDTH, MAIN_PANEL_HEIGHT);
    
    mMidiController = std::make_unique<MidiController>(inProcessor);
    
    mTopPanel = std::make_unique<TopPanel>(inProcessor, mMidiController->getComboBox());
    mTopPanel->setTopLeftPosition(0, 0);
    addAndMakeVisible(*mTopPanel);
    
    mCenterPanel = std::make_unique<CenterPanel>(inProcessor);
    mCenterPanel->setTopLeftPosition(0, 90);
    addAndMakeVisible(*mCenterPanel);
    
    mBottomPanel = std::make_unique<BottomPanel>(inProcessor, mMidiController->getKeyboardComponent());
    mBottomPanel->setTopLeftPosition(0, 300);
    addAndMakeVisible(*mBottomPanel);
}

MainPanel::~MainPanel()
{
    
}
