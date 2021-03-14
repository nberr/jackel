/*
  ==============================================================================

    OctavePanel.h
    Created: 8 Nov 2019 11:15:20am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

class OctavePanel
:   public PanelBase
{
public:
    OctavePanel(JackelAudioProcessor* inProcessor);
    ~OctavePanel();
    
    void updateToggleState(Button* button, String name);
    
private:
    TextButton buttons[11];
    std::unique_ptr<GroupComponent> mOctaveGroup;
    
    float* mOctaveParameter;
};
