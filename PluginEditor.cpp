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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GainAudioProcessorEditor::GainAudioProcessorEditor (GainAudioProcessor& ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    addAndMakeVisible (GainSld = new Slider ("Gain Slider"));
    GainSld->setRange (-75, 20, 0.1);
    GainSld->setSliderStyle (Slider::LinearVertical);
    GainSld->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    GainSld->addListener (this);

    addAndMakeVisible (TopLbl = new Label ("Top Label",
                                           TRANS("Gain\n")));
    TopLbl->setFont (Font ("Arial", 32.00f, Font::plain));
    TopLbl->setJustificationType (Justification::centred);
    TopLbl->setEditable (false, false, false);
    TopLbl->setColour (TextEditor::textColourId, Colours::black);
    TopLbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (BypassBtn = new ToggleButton ("Bypass Button"));
    BypassBtn->setButtonText (TRANS("Bypass"));
    BypassBtn->addListener (this);

    addAndMakeVisible (PolarityBtn = new ToggleButton ("Polarity Button"));
    PolarityBtn->setButtonText (CharPointer_UTF8 ("\xc3\x98"));
    PolarityBtn->addListener (this);

    addAndMakeVisible (DbLbl = new Label ("Db Label",
                                          TRANS("db")));
    DbLbl->setFont (Font (15.00f, Font::plain));
    DbLbl->setJustificationType (Justification::centredLeft);
    DbLbl->setEditable (false, false, false);
    DbLbl->setColour (TextEditor::textColourId, Colours::black);
    DbLbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (224, 400);


    //[Constructor] You can add your own custom stuff here..
    startTimer(30);

    //Set double-click return values
    GainSld->SetDoubleClickReturnValue(true, 0);

    //Force a parameter reset upon re-opening.
    ownerFilter.RequestUIUpdate();
    timerCallback();
    //[/Constructor]
}

GainAudioProcessorEditor::~GainAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    GainSld = nullptr;
    TopLbl = nullptr;
    BypassBtn = nullptr;
    PolarityBtn = nullptr;
    DbLbl = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GainAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffa1a1a1));

    g.setColour (Colour (0xff7ca52a));
    g.fillRect (0, 0, 224, 400);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GainAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    GainSld->setBounds (40, 72, 63, 320);
    TopLbl->setBounds (32, 24, 150, 24);
    BypassBtn->setBounds (112, 320, 72, 24);
    PolarityBtn->setBounds (112, 288, 150, 24);
    DbLbl->setBounds (104, 72, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GainAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    GainAudioProcessor* ourProcessor = getProcessor();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == GainSld)
    {
        //[UserSliderCode_GainSld] -- add your slider handling code here..

        //Update the gain value. We use a logarithmic scale here to get everything from
        //dB to "computer-language" gain levels (linear power scaling) for ease of use.
        ourProcessor->setParameter(GainAudioProcessor::gain, (float) pow(10, .05*GainSld->getValue()));
        //[/UserSliderCode_GainSld]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void GainAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    GainAudioProcessor* ourProcessor = getProcessor();
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == BypassBtn)
    {
        //[UserButtonCode_BypassBtn] -- add your button handler code here..
        ourProcessor->setParameter(GainAudioProcessor::masterBypass, (float) BypassBtn->getToggleState());
        //[/UserButtonCode_BypassBtn]
    }
    else if (buttonThatWasClicked == PolarityBtn)
    {
        //[UserButtonCode_PolarityBtn] -- add your button handler code here..

        //Polarity settings are inverted from the getToggleState return value.
        //For some reason getToggleState returns a bool.
        if(PolarityBtn->getToggleState()) {
            ourProcessor->setParameter(GainAudioProcessor::polarity, 0.0f);
        } else {
            ourProcessor->setParameter(GainAudioProcessor::polarity, 1.0f);
        }
        //[/UserButtonCode_PolarityBtn]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void GainAudioProcessorEditor::timerCallback() {
    GainAudioProcessor* ourProcessor = getProcessor();

    //Now we can exchange data between the UI and the plugin ("ourProcessor")
    //Do necessary UI updating by pulling info from ourProcessor

    if(ourProcessor->NeedsUIUpdate()) {
        //Update BypassBtn's state.
        BypassBtn->setToggleState(1.0f == ourProcessor->getParameter(GainAudioProcessor::masterBypass), dontSendNotification);

        //Update PolarityBtn's state. Note that polarity is toggled opposite bypass.
        PolarityBtn->setToggleState(0.0f == ourProcessor->getParameter(GainAudioProcessor::polarity), dontSendNotification);

        //Update GainSld's state. We use a logarithmic scale here to get everything from
        //"computer-language" gain levels (linear power scaling) to dB for ease of use.
        GainSld->setValue(20*log10((float) ourProcessor->getParameter(GainAudioProcessor::gain)), dontSendNotification);

        //We're done and can clear the UI Update Flag.
        ourProcessor->ClearUIUpdateFlag();
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GainAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="GainAudioProcessor&amp; ownerFilter" variableInitialisers="AudioProcessorEditor(ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="224" initialHeight="400">
  <BACKGROUND backgroundColour="ffa1a1a1">
    <RECT pos="0 0 224 400" fill="solid: ff7ca52a" hasStroke="0"/>
  </BACKGROUND>
  <SLIDER name="Gain Slider" id="6b714ac1ffe191db" memberName="GainSld"
          virtualName="" explicitFocusOrder="0" pos="40 72 63 320" min="-75"
          max="20" int="0.10000000000000001" style="LinearVertical" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Top Label" id="970c5a902465fd8e" memberName="TopLbl" virtualName=""
         explicitFocusOrder="0" pos="32 24 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Gain&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Arial" fontsize="32" bold="0"
         italic="0" justification="36"/>
  <TOGGLEBUTTON name="Bypass Button" id="301c25cc022ed569" memberName="BypassBtn"
                virtualName="" explicitFocusOrder="0" pos="112 320 72 24" buttonText="Bypass"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="Polarity Button" id="bd29e5356f141520" memberName="PolarityBtn"
                virtualName="" explicitFocusOrder="0" pos="112 288 150 24" buttonText="&#216;"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="Db Label" id="f20464be8d8a0618" memberName="DbLbl" virtualName=""
         explicitFocusOrder="0" pos="104 72 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="db" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
