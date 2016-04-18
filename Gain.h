/* Gain.h
   A gain/trim plugin with bypass and polarity reverse

   Developed by Zach Hummel using JUCE
   9/29/15 */

class Gain {
public:
	//Constructor/destructor
	Gain();
	~Gain();

	//Getters/setters
	void setGain(float gain);
	float getGain() {
		return m_gain;
	}

	void setPolarity(float polarity);
	float getPolarity() {
		return m_polarity;
	}

	//Use functions
	void ClockProcess(float* leftSample, float* rightSample); //The actual DSP

private:
	float m_gain; //0 <= gain <= 100 (-infinity to +20dB gain)
	float m_polarity; //Where >= 1 -> no change, <= 0 -> reverse polarity
};