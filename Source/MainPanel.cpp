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
    
    mTopPanel = std::make_unique<TopPanel>(inProcessor);
    mTopPanel->setTopLeftPosition(0, 0);
    addAndMakeVisible(*mTopPanel);
    
    mBottomPanel = std::make_unique<BottomPanel>(inProcessor);
    mBottomPanel->setTopLeftPosition((TOP_PANEL_WIDTH * 0.2) / 2, TOP_PANEL_HEIGHT);
    addAndMakeVisible(*mBottomPanel);
}

MainPanel::~MainPanel()
{
    
}