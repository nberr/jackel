/*
  ==============================================================================

    OctavePanel.cpp
    Created: 8 Nov 2019 11:15:20am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "OctavePanel.h"

OctavePanel::OctavePanel(JackelAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(OCTAVE_WIDTH, OCTAVE_HEIGHT);
}
OctavePanel::~OctavePanel()
{
    
}

void OctavePanel::paint(Graphics& g)
{
    
}
