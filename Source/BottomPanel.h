/*
  ==============================================================================

    BottomPanel.h
    Created: 17 Sep 2019 10:53:37am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

#include "OctavePanel.h"

class BottomPanel
:   public PanelBase
{
public:
    BottomPanel(JackelAudioProcessor* inProcessor, MidiKeyboardComponent* inKeyboardComponent);
    ~BottomPanel();
    
    void paint(Graphics& g) override;
    
private:
    //std::unique_ptr<TonalCenterPanel> mTCPanel;
    //std::unique_ptr<TranslationPanel> mTranslationPanel;
    std::unique_ptr<OctavePanel> mOctavePanel;
    
    MidiKeyboardComponent* mKeyboardComponent;
};
