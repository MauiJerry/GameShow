// Audio.ino : Audio implementation for Gameshow
// audio player from Teensy 3.2 on Serial2 to DFPlayer
// Uses Serial2 on Teensy pins 9r 10t

#include <DFRobotDFPlayerMini.h>

// global variables
const int audioBusyPin = 12; // DFPlayer Busy signal
boolean audioInitialized = false;
DFRobotDFPlayerMini myDFPlayer;

bool AudioBusy()
{
  if (!audioInitialized) return false;
  Serial.print("Test AudioBusy: "); Serial.println(digitalRead(audioBusyPin));
  if (digitalRead(audioBusyPin) == 0) return true;
  return false;
}

void AudioInit()
{
  Serial.println("Audio Initializing DFPlayer ... (May take 3~5 seconds)");

  pinMode(audioBusyPin, INPUT);
  Serial2.begin(9600, SERIAL_8N1);

  if (!myDFPlayer.begin(Serial2, false, false))
//  if (!myDFPlayer.begin(Serial2, true, true)) // stream, isAck, doReset
  {
    Serial.println("ERROR Unable to initialize Audio:");
    Serial.println("1.Please recheck the connection!");
    Serial.println("2.Please insert the SD card!");
    // flash Leds?
    return;
  }
  // let it boot
  delay(500);
  myDFPlayer.setTimeOut(500); //Set serial communictaion time out 500ms
  myDFPlayer.volume(10);  //Set volume value (0~30).
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  myDFPlayer.disableLoop();

  audioInitialized = true;
  delay(500);
  Serial.println("DFPlayer Mini started, should start playing.");

  Serial.println("Audio Play init sound 1,1");
  myDFPlayer.playFolder(1,1);  // Play 01/001.mp3 - HAL
  delay(5000);// give it time to start

  // we are using the AudioBusy pin16 connected to teensy digital pin 12
  uint32_t startAudioTime = millis();
  while (AudioBusy())
  {
    Serial.println("wait for initial audio to finish");
    delay(500);
    uint32_t currTime = millis();
    uint32_t deltaT = currTime - startAudioTime;
    if (deltaT > (1000 *10))
    {
      Serial.println("ERROR - audio not responding, ignore pin");
      audioInitialized = false;
      break;
    }
  }
  Serial.println("Audio should have played track");
}

void AudioQuietState()
{
  Serial.println("AudioQuietState");
//myDFPlayer.disableLoop();
myDFPlayer.stop();
    myDFPlayer.playFolder(1,2);  
  AudioPrintDetail();
}

void AudioPlayState()
{
  Serial.println("AudioPlayState");
//myDFPlayer.disableLoop(); Serial.println("Disabled Loop");
myDFPlayer.stop(); Serial.println("Stop");
  myDFPlayer.playFolder(2,3);  Serial.println(" folder 2, 3");
  AudioPrintDetail();
}

void AudioDazzle()
{
  Serial.println("AudioDazzle");
myDFPlayer.stop();
//myDFPlayer.disableLoop();
  myDFPlayer.playFolder(3,1);
}

void AudioPlayer1()
{
  Serial.println("AudioPlayer1");
//myDFPlayer.disableLoop();
myDFPlayer.stop();
    myDFPlayer.playFolder(2,1);
  AudioPrintDetail();
}

void AudioPlayer2()
{
  Serial.println("AudioPlayer2");
//myDFPlayer.disableLoop();
myDFPlayer.stop();
    myDFPlayer.playFolder(2,2);
  AudioPrintDetail();
}

void AudioPlayList()
{
  Serial.println("AudioPlayList");
myDFPlayer.stop();
//myDFPlayer.disableLoop();
myDFPlayer.loopFolder(4);
}

void AudioPrintDetail()
{
  uint8_t type;
  int value;
  if (true) return; // seems to screw up any play, so disable with this
  
  if (!myDFPlayer.available())
  {
    Serial.println("AudioDetail - none available");
    return;
  }
  type = myDFPlayer.readType();
  value = myDFPlayer.read();
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}
