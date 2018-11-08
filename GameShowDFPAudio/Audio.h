// Audio.h :: audio interface for GameShow System
// teensy 3.2 -> DFPlayerMini
// https://www.dfrobot.com/wiki/index.php/DFPlayer_Mini_SKU:DFR0299#Connection_Diagram
//

extern void AudioInit();
extern void AudioQuietState();
extern void AudioPlayState();
extern void AudioDazzle();

extern void AudioPlayer1();
extern void AudioPlayer2();
extern bool AudioBusy();
