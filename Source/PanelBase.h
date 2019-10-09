/*
  ==============================================================================

    PanelBase.h
    Created: 17 Sep 2019 10:53:16am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

#include "InterfaceDefines.h"
#include "PluginProcessor.h"
#include "JackelLookAndFeel.h"

class PanelBase
:   public Component
{
public:
    PanelBase(JackelAudioProcessor* inProcessor);
    ~PanelBase();
    
    void paint(Graphics& g) override;
    
private:
    JackelAudioProcessor* mProcessor;
};
