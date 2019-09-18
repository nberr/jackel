/*
  ==============================================================================

    TopPanel.h
    Created: 17 Sep 2019 10:53:31am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

#include "MidiController.h"

class TopPanel
:   public PanelBase
{
public:
    TopPanel(JackelAudioProcessor* inProcessor);
    ~TopPanel();
    
    void paint(Graphics& g) override;
    
private:
    std::unique_ptr<MidiController> mMidiController;
};
