/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

#include "JackelParameters.h"

//==============================================================================
JackelAudioProcessor::JackelAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
#endif
    parameters(*this, nullptr, "PARAMETERS", createParameterLayout())
{
    mMidiProcessor = std::make_unique<MidiProcessor>();
}

JackelAudioProcessor::~JackelAudioProcessor()
{
}

//==============================================================================
const String JackelAudioProcessor::getName() const
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

const String JackelAudioProcessor::getProgramName (int index)
{
    return {};
}

void JackelAudioProcessor::changeProgramName (int index, const String& newName)
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
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
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

void JackelAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    std::unique_ptr<MidiBuffer> processedMidi = std::make_unique<MidiBuffer>();
    int time;
    MidiMessage m;
 
    for (MidiBuffer::Iterator i (midiMessages); i.getNextEvent (m, time);)
    {
        mMidiProcessor->process(m, time, &*processedMidi, (int)*parameters.getRawParameterValue("TonalCenter"));
    }
    
    midiMessages.swapWith(*processedMidi);
}

//==============================================================================
bool JackelAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* JackelAudioProcessor::createEditor()
{
    return new JackelAudioProcessorEditor (*this);
}

//==============================================================================
void JackelAudioProcessor::getStateInformation (MemoryBlock& destData)
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

AudioProcessorValueTreeState::ParameterLayout JackelAudioProcessor::createParameterLayout()
{
    std::vector<std::unique_ptr<AudioParameterInt>> params;
    
    
    // init the tonal center parameter
    // TODO: add in mode parameter later
    params.push_back (std::make_unique<AudioParameterInt>(JPID[0],
                                                          JPID[0],
                                                          0,
                                                          NUM_TONAL_CENTERS,
                                                          JPDefaultValue[0],
                                                          JPLabel[0]));
    
    // add this loop back when you have more params to initialize
    /*
    for (int i = 0; i < JP_TotalNumParams; i++)
    {
        params.push_back (std::make_unique<AudioParameterInt>(JPID[i],
                                                              JPID[i],
                                                              0,
                                                              12,
                                                              JPDefaultValue[i],
                                                              JPLabel[i]));
    }
    */
    
    return { params.begin(), params.end() };
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new JackelAudioProcessor();
}
