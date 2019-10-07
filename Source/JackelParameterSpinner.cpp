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
    // TODO: grab value from parameter
    index = (int)*stateToControl.getRawParameterValue(parameterID);
    // TODO: set this value with constructor
    numItems = NUM_TONAL_CENTERS;
    
    // TITLE
    /*
    mBoxLabel = std::make_unique<Label>();
    mBoxLabel->setText("Tonal Center", dontSendNotification);
    mBoxLabel->setColour(Label::textColourId, Colours::black);
    mBoxLabel->setJustificationType(Justification::centred);
    mBoxLabel->setBounds((TC_BOX_WIDTH / 2) - (TC_LABEL_WIDTH / 2),
                         MEDIUM_BUFFER,
                         TC_LABEL_WIDTH,
                         TC_LABEL_HEIGHT);
    addAndMakeVisible(*mBoxLabel);
     */
    
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
    
    // TODO: set the param display from parameter
    mParamDisplay = std::make_unique<Label>();
    mParamDisplay->setText("TEST", dontSendNotification);
    mParamDisplay->setColour(Label::textColourId, Colours::black);
    mParamDisplay->setJustificationType(Justification::centred);
    mParamDisplay->setBounds(MEDIUM_BUFFER,
                             TC_LABEL_HEIGHT + (2 * MEDIUM_BUFFER),
                             TC_DISPLAY_WIDTH,
                             TC_DISPLAY_HEIGHT);
    addAndMakeVisible(*mParamDisplay);
    
    

    mButtonUp->onClick = [this] {
        
        // index is bound to (0, numItems)
        index = (index + 1 >= numItems) ? 0 : index + 1;
        
        // update the parameter value
        
        
        // update the label
        mParamDisplay->setText(TonalCenterLables[index], dontSendNotification);
    };
    
    mButtonDown->onClick = [this] {
        index = (index - 1 < 0) ? numItems-1 : index - 1;
        
        // update the parameter value
        
        mParamDisplay->setText(TonalCenterLables[index], dontSendNotification);
    };
    
    
    
    // attach the parameter to the buttons
    mAttachmentUp = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(stateToControl,
                                                                                     parameterID + "Up",
                                                                                     *mButtonUp);
    mAttachmentDown = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(stateToControl,
                                                                                       parameterID + "Down",
                                                                                       *mButtonDown);
    
    
}

JackelParameterSpinner::~JackelParameterSpinner()
{
    
}

int JackelParameterSpinner::getIndex()
{
    return index;
}

void JackelParameterSpinner::paint(Graphics& g)
{
    
}
