/*
  ==============================================================================

    MainPanel.h
    Created: 17 Sep 2019 10:53:22am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

#include "TopPanel.h"
#include "BottomPanel.h"

class MainPanel
:   public PanelBase
{
public:
    MainPanel(JackelAudioProcessor* inProcessor);
    ~MainPanel();
    
private:
    std::unique_ptr<TopPanel> mTopPanel;
    std::unique_ptr<BottomPanel> mBottomPanel;
    
};
