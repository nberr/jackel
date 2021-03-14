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
    
    mOctavePanel = std::make_unique<OctavePanel>(inProcessor);
    // TODO: change magic number
    mOctavePanel->setTopLeftPosition(LARGE_BUFFER, MEDIUM_BUFFER);
    //addAndMakeVisible(*mOctavePanel);
    
    mKeyboardComponent = inKeyboardComponent;
    mKeyboardComponent->setTopLeftPosition(5, 5);
    addAndMakeVisible(mKeyboardComponent);
}

BottomPanel::~BottomPanel()
{

}
