/*
  ==============================================================================

    TonalCenterPanel.cpp
    Created: 24 Sep 2019 11:23:57am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "TonalCenterPanel.h"

TonalCenterPanel::TonalCenterPanel(JackelAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(TC_BOX_WIDTH, TC_BOX_HEIGHT);
    
    mSpinner = std::make_unique<JackelParameterSpinner>(inProcessor->parameters, "TonalCenter", "Tonal Center");
    mSpinner->setBounds(0, 0, TC_BOX_WIDTH , TC_BOX_HEIGHT);
    addAndMakeVisible(*mSpinner);
}

TonalCenterPanel::~TonalCenterPanel()
{
    
}

void TonalCenterPanel::paint(Graphics& g)
{
    // PanelBase::paint(g);
    g.setColour(JackelColour_Lighter);
    g.fillAll();
    
    g.setColour(JackelColour_Darker);
    g.drawRoundedRectangle(0, 0, getWidth(), getHeight(), 4, 8);
}

