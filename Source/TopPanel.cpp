/*
  ==============================================================================

    TopPanel.cpp
    Created: 17 Sep 2019 10:53:31am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "TopPanel.h"

TopPanel::TopPanel(JackelAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    
    mMidiController = std::make_unique<MidiController>();
    addAndMakeVisible(mMidiController->getMidiKeyboardComponent());
    
    mMidiControllerComboBox = std::make_unique<MidiControllerComboBox>();
    mMidiControllerComboBox->setBounds(((TOP_PANEL_WIDTH * 0.2) / 2) + 20, 1, BOTTOM_PANEL_WIDTH - 40, 35);
    addAndMakeVisible(*mMidiControllerComboBox);
}

TopPanel::~TopPanel()
{
    
}

void TopPanel::paint(Graphics& g)
{
    PanelBase::paint(g);
}
