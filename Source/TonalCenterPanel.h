/*
  ==============================================================================

    TonalCenterPanel.h
    Created: 24 Sep 2019 11:23:57am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"
#include "JackelParameters.h"
#include "JackelParameterSpinner.h"
#include "TranslationPanel.h"

class TonalCenterPanel
:   public PanelBase
{
public:
    TonalCenterPanel(JackelAudioProcessor* inProcessor, TranslationPanel* inTranslationPanel);
    ~TonalCenterPanel();
    
    void paint(Graphics& g) override;
    
    void updateToggleState (Button* button, String name);
    
private:
    std::unique_ptr<ArrowButton> mUpButton;
    std::unique_ptr<ArrowButton> mDownButton;
    
    std::unique_ptr<Label> mBoxLabel;
    std::unique_ptr<Label> mDisplayLabel;
    
    TextButton mTCButtons[NUM_TONAL_CENTERS];
    
    std::unique_ptr<JackelParameterSpinner> mSpinner;
    std::unique_ptr<GroupComponent> mTCButtonGroup;
    
    float* mTonalCenterParameter;
    TranslationPanel* mTranslationPanel;
    
};
