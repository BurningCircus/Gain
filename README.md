# Gain

A 32-bit stereo VST plugin. See Releases for a pre-built binary.

This is one of the simplest useful plugins that can be designed. The purpose of creating such a simple plugin is twofold. First, it was an exercise in using the JUCE interface for writing the software, and secondly, it solidified my understanding of the mathematics behind gain, which is an extremely common DSP operation that forms a fundamental part of other processes and effects.

The actual processing done by the plugin is as simple as multiplying incoming samples by a scalar gain value. For the sake of utility, a polarity inversion option was included. Implementing this is as simple as multiplying all incoming samples by -1 if polarity inversion is desired. The application of this plugin is actually quite useful, and similar plugins are part of stock packages included with many DAWs. Gain can be inserted anywhere in the digital signal path, allowing adjustment of gain staging between plugins or a gain boost on quiet tracks with minimal processing expenditure. It can also be used to quickly check the phase relationship between two sources using the polarity inversion button.

Gain.h, Gain.cpp: The DSP source code.
PluginProcessor.h, PluginProcessor.cpp: The JUCE wrapper for the DSP source.
PluginEditor.h, PluginEditor.cpp: The JUCE wrapper for GUI components.
