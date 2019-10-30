// revision of PJRC Audio SamplePlayer that just cycles thru all
// does not use Buttons, only uses DAC

#include <Audio.h>
#include <SerialFlash.h>

// WAV files converted to code by wav2sketch
#include "AudioSampleOne.h"
//#include "AudioSampleSnare.h"
//#include "AudioSampleBell.h"
//#include "AudioSampleBuzzer.h"

#define SOUND AudioSampleOne
//#define SOUND AudioSampleBuzzer
//#define SOUND AudioSampleBell

// Create the Audio components.  These should be created in the
// order data flows, inputs/sources -> processing -> outputs
// one memory sound, one analog output, and one audio connection
AudioPlayMemory    playMemSound;
AudioOutputAnalog  dac;  
AudioConnection c10(playMemSound, 0, dac, 0);

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("Teensy One Sound Player");

  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(10);

}

void loop() 
{
  playOneSound();
  delay (1000);
}

void playOneSound()
{
  Serial.println("PlayOneSound");
  int count=0;
//  delay(100);
  playMemSound.play(SOUND);
  delay(50);
  while (playMemSound.isPlaying())
  {
    count++;
    delay(200);
  }
  Serial.printf("Played sound %d counts\n", count);
}
