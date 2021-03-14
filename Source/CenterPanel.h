/*
  ==============================================================================

    CenterPanel.h
    Created: 18 Nov 2019 7:28:24pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

#include "DeviceSelectorPanel.h"
#include "TonalCenterPanel.h"
#include "InputPanel.h"
#include "OutputPanel.h"
#include "OctavePanel.h"

#include "TranslationPanel.h"

class CenterPanel
:   public PanelBase
{
public:
    CenterPanel(JackelAudioProcessor* inProcessor);
    ~CenterPanel();
    
private:
    
    std::unique_ptr<DeviceSelectorPanel> mDeviceSelectorPanel;
    std::unique_ptr<TonalCenterPanel> mTCPanel;
    std::unique_ptr<InputPanel> mInputPanel;
    std::unique_ptr<OutputPanel> mOutputPanel;
    std::unique_ptr<OctavePanel> mOctavePanel;
    
    std::unique_ptr<TranslationPanel> mTranslationPanel;
    
};
