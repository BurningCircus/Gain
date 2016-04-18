/* Gain.cpp
   Implementation of prototypes found in Gain.h

   A gain/trim plugin with bypass and polarity reverse.

   Zach Hummel
   9/29/15 */

#include "Gain.h"

//Constructor
Gain::Gain() {
	setGain(1.0f); //Set to unity gain.
	setPolarity(1); //Set to in-phase.
}

//Destructor
Gain::~Gain() {}

//Getters/setters
void Gain::setGain(float gain) {
	if(gain < 0) {
		m_gain = 0;
	} else {
		m_gain = gain;
	}
}

void Gain::setPolarity(float polarity) {
	if(polarity >= 1) {
		m_polarity = 1;
	} else {
		m_polarity = 0;
	}
}

//Use functions
void Gain::ClockProcess(float* leftSample, float* rightSample) {
	//Apply gain scaling
	*leftSample = *leftSample * getGain();
	*rightSample = *rightSample * getGain();

	//Polarity inversion
	if(getPolarity() == 0) {
		*leftSample = *leftSample * -1;
		*rightSample = *rightSample * -1;
	}
}
