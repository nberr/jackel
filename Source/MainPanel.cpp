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
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    mMidiController = std::make_unique<MidiController>(inProcessor);
    
    mTopPanel = std::make_unique<TopPanel>(inProcessor);
    addAndMakeVisible(*mTopPanel);
    
    mCenterPanel = std::make_unique<CenterPanel>(inProcessor, mMidiController->getComboBox());
    mCenterPanel->setTopLeftPosition(0, TOP_PANEL_HEIGHT);
    addAndMakeVisible(*mCenterPanel);
    
    mBottomPanel = std::make_unique<BottomPanel>(inProcessor, mMidiController->getKeyboardComponent());
    mBottomPanel->setTopLeftPosition(0, TOP_PANEL_HEIGHT + CENTER_PANEL_HEIGHT);
    addAndMakeVisible(*mBottomPanel);
}

MainPanel::~MainPanel()
{
    
}
