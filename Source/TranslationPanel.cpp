/*
  ==============================================================================

    TranslationPanel.cpp
    Created: 24 Sep 2019 11:24:09am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "TranslationPanel.h"
#include "JackelParameters.h"
#include "MidiFunctions.h"

TranslationPanel::TranslationPanel(JackelAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(TRANSLATION_WIDTH, TRANSLATION_HEIGHT);
    
    mTonalCenterParameter = (float *)inProcessor->parameters.getRawParameterValue("TonalCenter");
    
    mTranslationGroup = std::make_unique<GroupComponent>("Translation", "Translation");
    // TODO:match look and feel
    mTranslationGroup->setColour(GroupComponent::textColourId, Colours::black);
    mTranslationGroup->setBounds(0, 0, getWidth(), getHeight());
    addAndMakeVisible(*mTranslationGroup);
    
}

TranslationPanel::~TranslationPanel()
{
    
}

void TranslationPanel::paint(Graphics& g)
{
    //PanelBase::paint(g);
    // g.drawText(std::to_string(*mTonalCenterParameter), 0, 0, 60, 60, Justification::centred);
    
    for (int i = 0; i < NUM_TONAL_CENTERS/2; i++)
    {
        // draw original note starting with the tonal center
        g.drawText(TonalCenterLables[(i+(int)*mTonalCenterParameter) % 12],
                   (i * 40)+ 30,
                   20,
                   TRANSLATION_LABEL_WIDTH,
                   TRANSLATION_LABEL_HEIGHT,
                   Justification::centred);
        
        
        int negative_note = getNegative(60 + i + (int)*mTonalCenterParameter,
                                        *mTonalCenterParameter, 3)%12;
        
        // draw translated note
        g.drawText(TonalCenterLables[negative_note],
                   (i * 40)+ 30,
                   110,
                   TRANSLATION_LABEL_WIDTH,
                   TRANSLATION_LABEL_HEIGHT,
                   Justification::centred);
    }
    
    
}

void TranslationPanel::updateTranslation()
{
    repaint();
}

