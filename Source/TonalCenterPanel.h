/*
  ==============================================================================

    TonalCenterPanel.h
    Created: 24 Sep 2019 11:23:57am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"
#include "JackelParameterSpinner.h"

class TonalCenterPanel
:   public PanelBase
{
public:
    TonalCenterPanel(JackelAudioProcessor* inProcessor);
    ~TonalCenterPanel();
    
    void paint(Graphics& g) override;
    
private:
    std::unique_ptr<ArrowButton> mUpButton;
    std::unique_ptr<ArrowButton> mDownButton;
    
    std::unique_ptr<Label> mBoxLabel;
    std::unique_ptr<Label> mDisplayLabel;
    
    std::unique_ptr<JackelParameterSpinner> mSpinner;
    
};
