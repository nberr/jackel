/*
  ==============================================================================

    SidePanel.cpp
    Created: 9 Mar 2021 9:28:01pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "PopoutPanel.h"

PopoutPanel::PopoutPanel(JackelAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(POPOUT_PANEL_WIDTH, POPOUT_PANEL_HEIGHT);
    
    mTranslationPanel = std::make_unique<TranslationPanel>(inProcessor);
    mTranslationPanel->setTopLeftPosition((POPOUT_PANEL_WIDTH * 0.5) - (TRANSLATION_WIDTH * 0.5), (POPOUT_PANEL_HEIGHT * 0.5) - (TRANSLATION_HEIGHT * 0.5));
    addAndMakeVisible(*mTranslationPanel);
}

PopoutPanel::~PopoutPanel()
{
    
}
