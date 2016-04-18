/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_4DE42E2F24264EE2__
#define __JUCE_HEADER_4DE42E2F24264EE2__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include <math.h>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class GainAudioProcessorEditor  : public AudioProcessorEditor,
                                  public Timer,
                                  public SliderListener,
                                  public ButtonListener
{
public:
    //==============================================================================
    GainAudioProcessorEditor (GainAudioProcessor& ownerFilter);
    ~GainAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();
    GainAudioProcessor* getProcessor() const {
        return static_cast <GainAudioProcessor*>(getAudioProcessor());
    }
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> GainSld;
    ScopedPointer<Label> TopLbl;
    ScopedPointer<ToggleButton> BypassBtn;
    ScopedPointer<ToggleButton> PolarityBtn;
    ScopedPointer<Label> DbLbl;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GainAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_4DE42E2F24264EE2__
