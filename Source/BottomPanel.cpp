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
    mOctavePanel->setTopLeftPosition(LARGE_BUFFER, 310);
    addAndMakeVisible(*mOctavePanel);
    
    mKeyboardComponent = inKeyboardComponent;
    addAndMakeVisible(mKeyboardComponent);
}

BottomPanel::~BottomPanel()
{

}

void BottomPanel::paint(Graphics& g)
{
    //PanelBase::paint(g);
    g.setColour(JackelColour_Light);
    g.fillAll();
    
    g.setColour(JackelColour_Darker);
    g.drawRoundedRectangle(0, 0, getWidth(), getHeight(), 4, 8);
    
}
