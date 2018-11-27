/*
 * testTeensyAudio - game show using Teensy's DAC audio
 * test the new octo-audio effects
 * cycle tween Quiet/Left/Right effect every 5 sec
//
//  three mode push buttons (quiet, game, dazzle)
//  Two buttons for participants
//  2 NeoPixel 16LED ring (2 neo Strips - not chained
//  3 Neopixel strip Top, Left, Right
//     left top, left side
//     right top, right side
//     top needs All, Player1, Player2 sides
 */

#include "gameNeoPix.h"
#include "gameButtons.h"
#include "gameState.h"
#include "Audio.h"

#define FULLON 254

////////////////////////////////////

//////////////////////////
uint32_t lastTime;

void setup() {
  Serial.begin(115200);
  delay(500); // wait half sec to open serial monitor window
  Serial.println("Starting gameShow Octo Audio");

  AudioInit();

  setupButtons();
  setupNeoPix();
 
  initGameState();
  startupBlinks();
  allOff();

 Serial.println("startup complete, now loop");
 setQuietState();
 
 lastTime = millis(); 
}

uint32_t delayTime = 5000;
int state = 0;
 
void loop()
{
  // Basic NeoEffects loop:
  // update time
  // check inputs & effectsDone - change behavior as needed
  // update each active Window
  // show the strips
  OctoWindow::updateTime();

 uint32_t currTime = millis(); 

  if ( currTime - lastTime > delayTime) 
  {
    lastTime = currTime;
    if (state == 0 )
    {
      state = 1;
      setLeftState();
    } else if (state == 1)
    {
      state = 2;
      setRightState();
    } else
    {
      state = 0;
      setQuietState();
    } 
    
  }
  
  updateAllWindows();
  showStrip();
}
