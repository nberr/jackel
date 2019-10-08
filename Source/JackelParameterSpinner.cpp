/*
  ==============================================================================

    JackelParameterDoubleButton.cpp
    Created: 5 Oct 2019 8:11:37am
    Author:  Nicholas Berriochoa
 
    The spinner class has 3 main components: 2 buttons (up and down) and the
    display label

  ==============================================================================
*/

#include "JackelParameterSpinner.h"

#include "JackelParameters.h"
#include "InterfaceDefines.h"

JackelParameterSpinner::JackelParameterSpinner(AudioProcessorValueTreeState& stateToControl,
                                               const String& parameterID,
                                               const String& parameterLabel)
{
    mTonalCenterParameter = stateToControl.getRawParameterValue("TonalCenter");
    
    index = (int)*stateToControl.getRawParameterValue(parameterID);
    // TODO: set this value with constructor
    numItems = NUM_TONAL_CENTERS;
    
    // TITLE
    mTitle = std::make_unique<Label>();
    mTitle->setText("Tonal Center", dontSendNotification);
    mTitle->setColour(Label::textColourId, Colours::black);
    mTitle->setJustificationType(Justification::centred);
    mTitle->setBounds((TC_BOX_WIDTH / 2) - (TC_LABEL_WIDTH / 2),
                         MEDIUM_BUFFER,
                         TC_LABEL_WIDTH,
                         TC_LABEL_HEIGHT);
    addAndMakeVisible(*mTitle);
     
    
    // TODO: let user set look and feel
    mButtonUp = std::make_unique<ArrowButton>("UpArrow", 0.75, Colours::black);
    mButtonUp->setBounds(TC_DISPLAY_WIDTH + (2 * MEDIUM_BUFFER) + SMALL_BUFFER,
                         TC_LABEL_HEIGHT + (2 * MEDIUM_BUFFER) + SMALL_BUFFER,
                         TC_BUTTON_WIDTH,
                         TC_BUTTON_HEIGHT);
    addAndMakeVisible(*mButtonUp);
    
    mButtonDown = std::make_unique<ArrowButton>("DownArrow", 0.25, Colours::black);
    mButtonDown->setBounds(TC_DISPLAY_WIDTH + (2 * MEDIUM_BUFFER) + SMALL_BUFFER,
                           TC_LABEL_HEIGHT + (3 * MEDIUM_BUFFER) + TC_BUTTON_DISPLAY_HEIGHT + SMALL_BUFFER,
                           TC_BUTTON_WIDTH,
                           TC_BUTTON_HEIGHT);
    addAndMakeVisible(*mButtonDown);
    
    mParamDisplay = std::make_unique<Label>();
    mParamDisplay->setText(TonalCenterLables[((int)*stateToControl.getRawParameterValue("TonalCenter"))], dontSendNotification);
    mParamDisplay->setColour(Label::textColourId, Colours::black);
    mParamDisplay->setJustificationType(Justification::centred);
    mParamDisplay->setBounds(MEDIUM_BUFFER,
                             TC_LABEL_HEIGHT + (2 * MEDIUM_BUFFER),
                             TC_DISPLAY_WIDTH,
                             TC_DISPLAY_HEIGHT);
    addAndMakeVisible(*mParamDisplay);
    
    
    mButtonUp->addListener(this);
    mButtonDown->addListener(this);
    
    // attach the parameter to the buttons
    mAttachmentUp = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(stateToControl,
                                                                                     parameterID,
                                                                                     *mButtonUp);
    mAttachmentDown = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(stateToControl,
                                                                                       parameterID,
                                                                                       *mButtonDown);
    
    
}

JackelParameterSpinner::~JackelParameterSpinner()
{
    
}

void JackelParameterSpinner::buttonClicked (Button* inButton)
{
    if (inButton == &*mButtonUp)
    {
        index = (index + 1 >= numItems) ? 0 : index + 1;
        
        *mTonalCenterParameter = index;
        
        mParamDisplay->setText(TonalCenterLables[index], dontSendNotification);
    }
    else if (inButton == &*mButtonDown)
    {
        index = (index - 1 < 0) ? numItems-1 : index - 1;
            
        *mTonalCenterParameter = index;
        
        mParamDisplay->setText(TonalCenterLables[index], dontSendNotification);
    }
}

void JackelParameterSpinner::paint(Graphics& g)
{
    
}
