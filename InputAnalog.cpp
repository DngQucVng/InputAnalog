#include "InputAnalog.h"

// Read value at a rate of sampleRate times per second
void InputAnalog::check() {
   static uint32_t now = 0, preCheck = 0;

   now = millis();

   if (now - preCheck >= 1000 / sampleRate) {
		value = analogRead(PIN);
        preCheck = now;
	}
}

// Set the resolution, default is 10bit
void InputAnalog::set_resolution(uint32_t Bit) {
    #ifdef __AVR__
        fullResolution = pow(2, 10) - 1;
    #else
        analogReadResolution(Bit);
        fullResolution = pow(2, Bit) - 1;
    #endif
}