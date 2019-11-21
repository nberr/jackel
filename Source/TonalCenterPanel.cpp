/*
  ==============================================================================

    TonalCenterPanel.cpp
    Created: 24 Sep 2019 11:23:57am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "TonalCenterPanel.h"

TonalCenterPanel::TonalCenterPanel(JackelAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(TONAL_CENTER_WIDTH, TONAL_CENTER_HEIGHT);
    mTonalCenterParameter = inProcessor->parameters.getRawParameterValue("TonalCenter");
    //mSpinner = std::make_unique<JackelParameterSpinner>(inProcessor->parameters, "TonalCenter", "Tonal Center");
    //mSpinner->setBounds(0, 0, TC_BOX_WIDTH , TC_BOX_HEIGHT);
    //addAndMakeVisible(*mSpinner);
    
    mTCButtonGroup = std::make_unique<GroupComponent>("TonalButtons", "Tonal Center");
    // TODO:match look and feel
    mTCButtonGroup->setColour(GroupComponent::textColourId, Colours::black);
    mTCButtonGroup->setBounds(0, 0, getWidth(), getHeight());
    addAndMakeVisible(*mTCButtonGroup);
    
    // init buttons
    for (int i = 0; i < NUM_TONAL_CENTERS; i++)
    {
        mTCButtons[i].setButtonText(TonalCenterLables[i]);
        
        mTCButtons[i].setRadioGroupId(1002);
        mTCButtons[i].setClickingTogglesState(true);
        mTCButtons[i].onClick = [this, i]
        {
            updateToggleState(&mTCButtons[i], TonalCenterLables[i]);
            
            // set the param value
            *mTonalCenterParameter = i;
        };
        
        mTCButtons[i].setBounds((i%4 * TC_BUTTON_WIDTH) + 25, (floor(i/4)*(TC_BUTTON_HEIGHT+5)) + 25, TC_BUTTON_WIDTH, TC_BUTTON_HEIGHT);
        // set bounds

        
        addAndMakeVisible(mTCButtons[i]);
    }
}

TonalCenterPanel::~TonalCenterPanel()
{
    
}

void TonalCenterPanel::paint(Graphics& g)
{
    // PanelBase::paint(g);
    //g.setColour(JackelColour_Lighter);
    //g.fillAll();
    
    //g.setColour(JackelColour_Darker);
    //g.drawRoundedRectangle(0, 0, getWidth(), getHeight(), 4, 8);
}

void TonalCenterPanel::updateToggleState (Button* button, String name)
{
    auto state = button->getToggleState();
    String stateString = state ? "ON" : "OFF";

    // Logger::outputDebugString (name + " Button changed to " + stateString);
}
