/*
  ==============================================================================

    TopPanel.cpp
    Created: 17 Sep 2019 10:53:31am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "TopPanel.h"

TopPanel::TopPanel(JackelAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    mMidiController = std::make_unique<MidiController>();
    addAndMakeVisible(mMidiController->getMidiKeyboardComponent());
    
    mMidiCOntrollerLabel.setText("Midi Input", dontSendNotification);
    mMidiCOntrollerLabel.setFont (Font (20.0f, Font::bold));
    mMidiCOntrollerLabel.setColour(Label::textColourId, Colours::black);
    mMidiCOntrollerLabel.setBounds(185, 80, TONAL_CENTER_LABEL_WIDTH, TONAL_CENTER_LABEL_HEIGHT);
    addAndMakeVisible(mMidiCOntrollerLabel);
    
    mMidiControllerComboBox = std::make_unique<MidiControllerComboBox>();
    mMidiControllerComboBox->setBounds(285, 80, MIDI_COMBO_BOX_WIDTH, MIDI_COMBO_BOX_HEIGHT);
    addAndMakeVisible(*mMidiControllerComboBox);
    
    mTonalCenterLabel.setText("Tonal Center", dontSendNotification);
    mTonalCenterLabel.setFont (Font (20.0f, Font::bold));
    mTonalCenterLabel.setColour(Label::textColourId, Colours::black);
    mTonalCenterLabel.setBounds(30, 80, TONAL_CENTER_LABEL_WIDTH, TONAL_CENTER_LABEL_HEIGHT);
    addAndMakeVisible(mTonalCenterLabel);
    
    mTonalCenterComboBox.setBounds(130, 80, TONAL_CENTER_CB_WIDTH, TONAL_CENTER_CB_HEIGHT);
    addAndMakeVisible(mTonalCenterComboBox);
}

TopPanel::~TopPanel()
{
    
}

void TopPanel::paint(Graphics& g)
{
    PanelBase::paint(g);
    
    g.drawRect(20, 80, 135, TONAL_CENTER_LABEL_HEIGHT);
    g.drawRect(180, 80, TONAL_CENTER_LABEL_WIDTH + MIDI_COMBO_BOX_WIDTH, TONAL_CENTER_LABEL_HEIGHT);
}
