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
			set_resolution(bitResolution);
		}

		// Return raw value
		uint32_t get_value() const {  }

		// Return the voltage of the pin (0-3.3V or 0-5V)
		float get_voltage() const {  }

		// Return the percentage of signal of the pin (0-100%)
		float get_percentage() const {  }

		// Set how many times the pin 
		void set_sample_rate(float Frequency) {  }

		// Set the resolution, update bitResolution and resolution
		void set_resolution(uint32_t Bit);

		// Read value at a rate of sampleRate times per second
		void check();

	private:
		const uint8_t PIN;

		uint32_t value = 0, bitResolution = 10, fullResolution; // fullResolution = 2^bitResolution
		float sampleRate = 10.0; // Hz
};