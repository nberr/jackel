/*
  ==============================================================================

    TopPanel.h
    Created: 17 Sep 2019 10:53:31am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

class TopPanel
:   public PanelBase
{
public:
    TopPanel(JackelAudioProcessor* inProcessor, ComboBox* inMidiInputDevs);
    ~TopPanel();
    
    void paint(Graphics& g) override;
    
private:
    ComboBox* mMidiInputDevs;
    Label mMidiInputLabel;
};
