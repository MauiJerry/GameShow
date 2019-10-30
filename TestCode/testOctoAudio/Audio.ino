// Audio.ino : Audio implementation for Gameshow
// teensy 3.2 -> DAC on pin 14
// https://www.pjrc.com/teensy/td_libs_Audio.html
// cut down to play only one sound

#include <Audio.h>
#include "AudioSampleBrentonring.h"

// global variables
boolean audioInitialized = false;
AudioPlayMemory    playMemSound;
AudioOutputAnalog  dac; // output thru DAC pin 14
AudioConnection audioPatch(playMemSound, 0, dac, 0);

bool AudioBusy()
{
  if (!audioInitialized) return false;
  return false;
}

void AudioInit()
{
  Serial.println("Audio Initializing ... (May take 3~5 seconds)");

  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(10);
  
 // reduce the gain on mixer channels, so more than 1
  // sound can play simultaneously without clipping

//  playOneSound(); // make sound
    
  audioInitialized = true;
  delay(500);
 
  Serial.println("Audio should have played track");
}

void AudioQuietState()
{
  Serial.println("AudioQuietState = none");
}

void AudioPlayState()
{
  Serial.println("AudioPlayState = none");
}

void AudioDazzle()
{
  Serial.println("AudioDazzle");
//  playOneSound();
}

void AudioPlayer1()
{
  Serial.println("AudioPlayer1");
  playOneSound();
}

void AudioPlayer2()
{
  Serial.println("AudioPlayer2");
  playOneSound();
}

void playOneSound()
{
  int count=0;
//  delay(100);
  playMemSound.play(AudioSampleBrentonRing);
  delay(250);
//  while (playMemSound.isPlaying())
//  {
//    count++;
//    delay(50);
//  }
  Serial.printf("Played sound %d counts\n", count);
}
