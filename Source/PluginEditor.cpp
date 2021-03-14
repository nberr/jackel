/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
JackelAudioProcessorEditor::JackelAudioProcessorEditor (JackelAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (MAIN_PANEL_WIDTH , MAIN_PANEL_HEIGHT);
    
    mMainPanel = std::make_unique<MainPanel>(&processor);
    addAndMakeVisible(*mMainPanel);
    
    
    mPopoutButton = std::make_unique<juce::TextButton>(">");
    mPopoutButton->setSize(POPOUT_BUTTON_WIDTH, CENTER_PANEL_HEIGHT);
    mPopoutButton->setTopLeftPosition(MAIN_PANEL_WIDTH - POPOUT_BUTTON_WIDTH, TOP_PANEL_HEIGHT);
    
    mPopoutButton->onClick = [this] {
        if (mPopoutShow)
        {
            setSize(MAIN_PANEL_WIDTH + POPOUT_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
            mPopoutButton->setButtonText("<");
        }
        else
        {
            setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
            mPopoutButton->setButtonText(">");
        }
        mPopoutShow = !mPopoutShow;
    };
    
    addAndMakeVisible(*mPopoutButton);
    
    mPopoutPanel = std::make_unique<PopoutPanel>(&processor);
    mPopoutPanel->setTopLeftPosition(MAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    addAndMakeVisible(*mPopoutPanel);
    
    mLookAndFeel = std::make_unique<JackelLookAndFeel>();
    setLookAndFeel(&*mLookAndFeel);
    LookAndFeel::setDefaultLookAndFeel(&*mLookAndFeel);
}

JackelAudioProcessorEditor::~JackelAudioProcessorEditor()
{
    setLookAndFeel(nullptr);
    LookAndFeel::setDefaultLookAndFeel(nullptr);
}

//==============================================================================
void JackelAudioProcessorEditor::paint (Graphics& g)
{
    
}

void JackelAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
