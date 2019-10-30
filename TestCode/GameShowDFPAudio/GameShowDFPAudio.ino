/*
 *   test rig for GameShowFantatics
 * BtnTrigerEfx1
 * Intended to show each button starting efx
 * however this is just a shell at present
 * early version is behind WindowTest1 and needs update
 * 
// Test buttons + Leds, 
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
      

//for NeoPixels
uint32_t BLUE = Adafruit_NeoPixel::Color(0, 0, FULLON);
uint32_t WHITE = Adafruit_NeoPixel::Color(FULLON, FULLON, FULLON, FULLON);
uint32_t RED = Adafruit_NeoPixel::Color(FULLON, 0, 0);
uint32_t   GREEN = Adafruit_NeoPixel::Color(0, FULLON, 0);
uint32_t   YELLOW = Adafruit_NeoPixel::Color(FULLON, FULLON, 0);
uint32_t   BROWN = Adafruit_NeoPixel::Color(165, 42, 0);
uint32_t   ORANGE = Adafruit_NeoPixel::Color(FULLON, 128, 0);

////////////////////////////////////

//////////////////////////

void setup() {
  Serial.begin(115200);
  delay(500); // wait half sec to open serial monitor window
  Serial.println("Starting gameShow BtnTriggerEfx1");

  setupButtons();
  setupNeoPix();

  if (topStrip.hasWhiteLED())
    Serial.println("Top Strip is rgb+W - has White LED");
  else
    Serial.println("Top Strip is rgb only - NO White LED");
  
  initGameState();
  startupBlinks();
  allOff();

  AudioInit();

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
  NeoWindow::updateTime();

  if (updateButtons() > 0) // something pressed
  {
    logButtons();

    if (!mode1BtnValue && !mode2BtnValue && !mode3BtnValue)
    {
      Serial.println("All 3 Control buttons pressed!");
      AudioPlayList();
      delay(500);
    } else
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
  showAllStrip();
}
