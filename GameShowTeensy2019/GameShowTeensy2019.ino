/*
 * GameShowTeensyAudio - game show using Teensy's DAC audio
// oct 2019 - move 3 mode buttons to individual leds

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
uint32_t BLACK = Adafruit_NeoPixel::Color(0, 0, 0);
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
  delay(500);
  Serial.begin(115200);
  delay(800); // wait half sec to open serial monitor window
  Serial.println("Starting gameShow BtnTriggerEfx1");

  AudioInit();

  setupButtons();
  setupNeoPix();

  if (topStrip.hasWhiteLED())
    Serial.println("Top Strip is rgb+W - has White LED");
  else
    Serial.println("Top Strip is rgb only - NO White LED");
  
  initGameState();
  startupBlinks();
  allOff();

 Serial.println("startup complete, now loop");
 setQuietState();

 //TestTopHalves();
}
void  TestTopHalves()
{
  Serial.println("TestTopHalves");
  leftRightSolid();
  updateAllWindows();
  showAllStrip();
  delay(10000);
}

void loop()
{
  Serial.println("Loop"); //delay(500);
  // Basic NeoEffects loop:
  // update time
  // check inputs & effectsDone - change behavior as needed
  // update each active Window
  // show the strips
  NeoWindow::updateTime();

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
        Serial.println("Player1 press => Right Game State");
        setRightState();
      } else if (player2BtnValue ==0)
      {
        Serial.println("Player2 press => Left Game State");
        setLeftState();
      }      
    }
  }

  updateAllWindows();
  showAllStrip();
}
