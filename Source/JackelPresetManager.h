/*
  ==============================================================================

    PresetManager.h
    Created: 9 Mar 2021 9:15:13pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#define PRESET_FILE_EXTENSION ".tf"

class JackelPresetManager
{
public:
    JackelPresetManager(juce::AudioProcessor* inProcssor);
    ~JackelPresetManager();
    
    void getXmlForPreset(juce::XmlElement* inElement);
    void loadPresetForXml(juce::XmlElement* inElement);
       
    int getNumberOfPresets();
    juce::String getPresetName(int inPresetIndex);
    void createNewPreset();
    void savePreset();
    void saveAsPreset(juce::String inPresetName);
    void loadPreset(int inPresetIndex);
    bool getIsCurrentPresetSaved();
    juce::String getCurrentPresetName();
private:
    void storeLocalPreset();
        
    bool mCurrentPresetIsSaved;
        
    juce::File mCurrentlyLoadedPreset;
    juce::Array<juce::File> mLocalPresets;
        
    juce::String mCurrentPresetName;
    juce::String mPresetDirectory;
        
    juce::AudioProcessor* mProcessor;
        
    juce::XmlElement* mCurrentPresetXml;
};
