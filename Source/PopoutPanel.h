/*
  ==============================================================================

    SidePanel.h
    Created: 9 Mar 2021 9:28:01pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

#include "TranslationPanel.h"

class PopoutPanel
:   public PanelBase
{
public:
    PopoutPanel(JackelAudioProcessor* inProcessor);
    ~PopoutPanel();
    
    std::unique_ptr<TranslationPanel> mTranslationPanel;
    
private:
    
};
