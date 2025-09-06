#include <Arduino.h>
#include <stdint.h>


#ifdef __AVR__
#define INPUT_ANALOG_MAX_VOLTAGE 5
#else
#define INPUT_ANALOG_MAX_VOLTAGE 3.3
#endif

class InputAnalog {
	public:
		// Constructor
		InputAnalog(uint8_t Pin) : PIN(Pin) {
			pinMode(PIN, INPUT);
			set_resolution(10);
		}

		// Return raw value
		uint32_t get_value() const { return value; }

		// Return the voltage of the pin (0-3.3V or 0-5V)
		float get_voltage() const {	return (value * INPUT_ANALOG_MAX_VOLTAGE / fullResolution); } 

		// Return the percentage of signal of the pin (0-100%)
		float get_percentage() const {	return ((float)value * 100.0) / (float)fullResolution; }

		// Set how many times the pin 
		void set_sample_rate(float Frequency) { sampleRate = Frequency; }

		// Set the resolution, update bitResolution and resolution, default is 10bit
		void set_resolution(uint32_t Bit) { fullResolution = pow(2,Bit) - 1; };

		// Read value at a rate of sampleRate times per second
		void check()

	private:
		const uint8_t PIN;
		uint32_t value = 0, fullResolution; // fullResolution = 2^bitResolution-1
		float sampleRate = 10.0; // Hz
};