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
    setSize(OCTAVE_PANEL_WIDTH, OCTAVE_PANEL_HEIGHT);
    
    mOctaveParameter = (float *)inProcessor->parameters.getRawParameterValue("Octave");
    
    mOctaveGroup = std::make_unique<GroupComponent>("OctaveButtons", "Octave");
    // TODO:match look and feel
    mOctaveGroup->setColour(GroupComponent::textColourId, Colours::black);
    mOctaveGroup->setBounds((OCTAVE_PANEL_WIDTH * 0.5) - (OCTAVE_SELECT_WIDTH * 0.5), 0, OCTAVE_SELECT_WIDTH, OCTAVE_SELECT_HEIGHT);
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
        buttons[i].setBounds((i * OCTAVE_BUTTON_WIDTH) + MEDIUM_BUFFER + (OCTAVE_PANEL_WIDTH * 0.5) - (OCTAVE_SELECT_WIDTH * 0.5) + 10, MEDIUM_BUFFER + SMALL_BUFFER, OCTAVE_BUTTON_WIDTH, OCTAVE_BUTTON_HEIGHT);
        
        // attach parameter
        
        // add to scene
        addAndMakeVisible(buttons[i]);
    }
    
    buttons[(int)*mOctaveParameter+2].setToggleState(true, dontSendNotification);
}
OctavePanel::~OctavePanel()
{
    
}

void OctavePanel::updateToggleState (Button* button, String name)
{
    auto state = button->getToggleState();
    String stateString = state ? "ON" : "OFF";

    //Logger::outputDebugString (name + " Button changed to " + stateString);
};
