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
    setSize (MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    mMainPanel = std::make_unique<MainPanel>(&processor);
    addAndMakeVisible(*mMainPanel);
    
    mLookAndFeel = std::make_unique<JackelLookAndFeel>();
    setLookAndFeel(&*mLookAndFeel);
    LookAndFeel::setDefaultLookAndFeel(&*mLookAndFeel);
    
    mTranslationPanelButton = std::make_unique<juce::TextButton>(">");
    mTranslationPanelButton->setSize(20, MAIN_PANEL_HEIGHT);
    mTranslationPanelButton->setTopLeftPosition(MAIN_PANEL_WIDTH - 20, 0);
    
    mTranslationPanelButton->onClick = [this] {
        if (translationShown)
        {
            setSize(MAIN_PANEL_WIDTH + TRANSLATION_WIDTH, MAIN_PANEL_HEIGHT);
        }
        else
        {
            setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
        }
        
        translationShown = !translationShown;
    };
    
    addAndMakeVisible(*mTranslationPanelButton);
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
