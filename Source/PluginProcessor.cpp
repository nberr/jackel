/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
JackelAudioProcessor::JackelAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ),
#endif
parameters(*this, &undoManager, "PARAMETERS", createParameterLayout()),
inputMidiKeyboard(inputKeyboardState, juce::MidiKeyboardComponent::horizontalKeyboard),
outputMidiKeyboard(outputKeyboardState, juce::MidiKeyboardComponent::horizontalKeyboard)
{
    
}

JackelAudioProcessor::~JackelAudioProcessor()
{
    
}

//==============================================================================
const juce::String JackelAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool JackelAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool JackelAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool JackelAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double JackelAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int JackelAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int JackelAudioProcessor::getCurrentProgram()
{
    return 0;
}

void JackelAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String JackelAudioProcessor::getProgramName (int index)
{
    return {};
}

void JackelAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void JackelAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void JackelAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool JackelAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void JackelAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    MidiProcessorParameters midi_proc_params = {
        parameters.getParameterAsValue("TonalCenterID").getValue(),
        parameters.getParameterAsValue("OctaveID").getValue(),
    };
    
    midiProcessor.setParameters(midi_proc_params);
    midiProcessor.processBlock(midiMessages, buffer.getNumSamples());
}

//==============================================================================
bool JackelAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* JackelAudioProcessor::createEditor()
{
    return new JackelAudioProcessorEditor (*this);
}

//==============================================================================
void JackelAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void JackelAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
juce::AudioProcessorValueTreeState::ParameterLayout JackelAudioProcessor::createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    
    layout.add(std::make_unique<juce::AudioParameterInt>("TonalCenterID", "Tonal Center", 0, 12, 1, ""));
    layout.add(std::make_unique<juce::AudioParameterInt>("OctaveID", "Octave", 0, 10, 3, ""));
    
    return layout;
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new JackelAudioProcessor();
}
