/*
  ==============================================================================

    CenterPanel.h
    Created: 18 Nov 2019 7:28:24pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

#include "TonalCenterPanel.h"
#include "TranslationPanel.h"

class CenterPanel
:   public PanelBase
{
public:
    CenterPanel(JackelAudioProcessor* inProcessor);
    ~CenterPanel();
    
    void paint(Graphics& g) override;
    
private:
    std::unique_ptr<TonalCenterPanel> mTCPanel;
    std::unique_ptr<TranslationPanel> mTranslationPanel;
};
