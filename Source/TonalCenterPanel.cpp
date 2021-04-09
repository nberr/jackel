/*
  ==============================================================================

    TonalCenterPanel.cpp
    Created: 24 Sep 2019 11:23:57am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "TonalCenterPanel.h"

TonalCenterPanel::TonalCenterPanel(JackelAudioProcessor* inProcessor, TranslationPanel* inTranslationPanel)
:   PanelBase(inProcessor)
{
    setSize(TONAL_CENTER_WIDTH, TONAL_CENTER_HEIGHT);
    mTonalCenterParameter = (float *)inProcessor->parameters.getRawParameterValue("TonalCenter");
    //mSpinner = std::make_unique<JackelParameterSpinner>(inProcessor->parameters, "TonalCenter", "Tonal Center");
    //mSpinner->setBounds(0, 0, TC_BOX_WIDTH , TC_BOX_HEIGHT);
    //addAndMakeVisible(*mSpinner);
    
    mTranslationPanel = inTranslationPanel;
    
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
            
            // update the translation panel
            mTranslationPanel->updateTranslation();
            
        };
        
        mTCButtons[i].setBounds((i%4 * TC_BUTTON_WIDTH) + 25, (floor(i/4)*(TC_BUTTON_HEIGHT+5)) + 25, TC_BUTTON_WIDTH, TC_BUTTON_HEIGHT);
        // set bounds

        
        //addAndMakeVisible(mTCButtons[i]);
    }
    
    mTCButtons[(int)*mTonalCenterParameter].setToggleState(true, dontSendNotification);
    
    
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
    
    int width = 185, height = width;
    g.setColour(juce::Colours::black);
    //g.drawEllipse((TONAL_CENTER_WIDTH / 2) - (width / 2), (TONAL_CENTER_HEIGHT / 2) - (height / 2), width, height, 1);
    
    double angle = 0;
    double inc = 30;
    double radius = (width-10) / 2.;
    double label_width = 40, label_height = 10;
    double center_x = (TONAL_CENTER_WIDTH / 2) - (label_width / 2), center_y = (TONAL_CENTER_HEIGHT / 2) - (label_height / 2);
    for (int i = 0; i < NUM_TONAL_CENTERS; i++) {
        double x = cos(angle * M_PI / 180.) * radius;
        double y = sin(angle * M_PI / 180.) * radius;
        
        g.drawText(TonalCenterLables[i], center_x + x, center_y + y, label_width, label_height, Justification::centred);
        
        angle += inc;
        
    }
}

void TonalCenterPanel::updateToggleState (Button* button, String name)
{
    auto state = button->getToggleState();
    String stateString = state ? "ON" : "OFF";

    // Logger::outputDebugString (name + " Button changed to " + stateString);
}
