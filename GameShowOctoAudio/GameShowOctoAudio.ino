/*
 * GameShowTeensyAudio - game show using Teensy's DAC audio
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
}

void loop()
{
  // Basic NeoEffects loop:
  // update time
  // check inputs & effectsDone - change behavior as needed
  // update each active Window
  // show the strips
  OctoWindow::updateTime();

  if (updateButtons() > 0) // something pressed
  {
    logButtons();

     if (!mode1BtnValue)
    {
      Serial.println("Mode1 Quiet Pressed");
      setQuietState();
    } else if (!mode2BtnValue)
    {
      Serial.println("Mode2 PLAY Pressed");
      setPlayState();
    } else if (!mode3BtnValue)
    {
      Serial.println("Mode3 DAZZLE Pressed");
      setDazzleState();
    } else if (gameState==PlayState)
    { 
      if (player1BtnValue==0)
      {
        setLeftState();
      } else if (player2BtnValue ==0)
      {
        setRightState();
      }      
    }
  }

  updateAllWindows();
  showStrip();
}
