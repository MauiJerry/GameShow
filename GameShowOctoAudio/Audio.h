// Audio.h :: audio interface for GameShow System
// teensy 3.2 -> DAC on pin 14
// https://www.pjrc.com/teensy/td_libs_Audio.html

extern void AudioInit();
extern void AudioQuietState();
extern void AudioPlayState();
extern void AudioDazzle();

extern void AudioPlayer1();
extern void AudioPlayer2();
extern bool AudioBusy();
