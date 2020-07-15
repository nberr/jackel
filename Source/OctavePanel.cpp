/*
  ==============================================================================

    OctavePanel.cpp
    Created: 8 Nov 2019 11:15:20am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "OctavePanel.h"

OctavePanel::OctavePanel(JackelAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(OCTAVE_WIDTH, OCTAVE_HEIGHT + 3);
    
    mOctaveParameter = (float *)inProcessor->parameters.getRawParameterValue("Octave");
    
    mOctaveGroup = std::make_unique<GroupComponent>("OctaveButtons", "Octave");
    // TODO:match look and feel
    mOctaveGroup->setColour(GroupComponent::textColourId, Colours::black);
    mOctaveGroup->setBounds(0, 0, getWidth(), getHeight());
    addAndMakeVisible(*mOctaveGroup);
    
    // initialize buttons
    for (int i = 0; i < 11; i++)
    {
        // set the text
        buttons[i].setButtonText(std::to_string(i-2));
        
        buttons[i].setRadioGroupId(1001);
        buttons[i].setClickingTogglesState(true);
        buttons[i].onClick = [this, i]
        {
            updateToggleState(&buttons[i], std::to_string(i-2));
            
            // update the parameter
            *mOctaveParameter = i - 2;
        };
        
        // set size
        buttons[i].setBounds((i * OCTAVE_BUTTON_WIDTH) + MEDIUM_BUFFER, MEDIUM_BUFFER + SMALL_BUFFER, OCTAVE_BUTTON_WIDTH, OCTAVE_BUTTON_HEIGHT);
        
        // attach parameter
        
        // add to scene
        addAndMakeVisible(buttons[i]);
    }
    
    buttons[(int)*mOctaveParameter+2].setToggleState(true, dontSendNotification);
}
OctavePanel::~OctavePanel()
{
    
}

void OctavePanel::paint(Graphics& g)
{
    // PanelBase::paint(g);
    //g.setColour(JackelColour_Lighter);
    //g.fillAll();
    
    //g.setColour(JackelColour_Darker);
    //g.drawRoundedRectangle(0, 0, getWidth(), getHeight(), 4, 2);
    
}

void OctavePanel::updateToggleState (Button* button, String name)
{
    auto state = button->getToggleState();
    String stateString = state ? "ON" : "OFF";

    //Logger::outputDebugString (name + " Button changed to " + stateString);
};
