/*
  ==============================================================================

    OutputPanel.cpp
    Created: 9 Mar 2021 9:55:35pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "OutputPanel.h"

OutputPanel::OutputPanel(JackelAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(OUTPUT_CHORD_WIDTH, OUTPUT_CHORD_HEIGHT);
}

OutputPanel::~OutputPanel()
{
    
}
