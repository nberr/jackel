/*
  ==============================================================================

    InputPanel.cpp
    Created: 9 Mar 2021 9:55:29pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "InputPanel.h"

InputPanel::InputPanel(JackelAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(INPUT_CHORD_WIDTH, INPUT_CHORD_HEIGHT);
}

InputPanel::~InputPanel()
{
    
}
