/*
 *   test rig for GameShowFantatics
 * Test buttons + Led, 
 * push button and led should change color
 * proves buttons and leds working
 * not doing much with top/left/right strips
 * and nothing with windows yet
// Flashes all led 2x, blink in sequence 2x, Blink all again 1x
// then enter btn test loop:
//     if button is pressed, report it and turn on its led while button is down.
//   btn down or toggle?
//  
 */

#include "gameNeoPix.h"
#include "gameButtons.h"

#define INTENSITY 255      //for NeoPixels
uint32_t
  BLUE = Adafruit_NeoPixel::Color(0, 0, INTENSITY),
  WHITE = Adafruit_NeoPixel::Color(INTENSITY, INTENSITY, INTENSITY),
  RED = Adafruit_NeoPixel::Color(INTENSITY, 0, 0),
  GREEN = Adafruit_NeoPixel::Color(0, INTENSITY, 0),
  YELLOW = Adafruit_NeoPixel::Color(INTENSITY, INTENSITY, 0),
  BROWN = Adafruit_NeoPixel::Color(165, 42, 0),
  ORANGE = Adafruit_NeoPixel::Color(INTENSITY, 128, 0);

////////////////////////////////////
void setup() {
  Serial.begin(115200);
  delay(500); // wait half sec to open serial monitor window
  Serial.println("Starting gameShow led test one in sequence");

  setupButtons();
  
  setupNeoPix();

  startupBlinks();
  allOff();

  for (int i=0; i< 5; i++)
    blinkModePixels();
 Serial.println("startup complete, now loop");
}

void loop()
{
  // Basic NeoEffects loop:
  // update time
  // check inputs & effectsDone - change behavior as needed
  // update each active Window
  // show the strips

  if (updateButtons() >0) // something pressed
  {
    logButtons();
  } 
  
  // individual test
  testModeColor= 255;
    if (mode1BtnValue)
    {
       modePixels.setPixelColor(QUIET_PIXEL, modePixels.Color(0,0,0));
    } else {
     Serial.println("Mode1 Pressed");
      modePixels.setPixelColor(QUIET_PIXEL, modePixels.Color(testModeColor,0,0));
    } 
      
    if (mode2BtnValue)
    {
       modePixels.setPixelColor(GAME_PIXEL, modePixels.Color(0,0,0));
    } else {
     Serial.println("Mode2 Pressed");
      modePixels.setPixelColor(GAME_PIXEL, modePixels.Color(0,testModeColor,0));
    }
      
    if (mode3BtnValue)
    {
       modePixels.setPixelColor(DAZZLE_PIXEL, modePixels.Color(0,0,0));
    } else {
     Serial.println("Mode3 Pressed");
//     modePixels.setPixelColor(DAZZLE_PIXEL, modePixels.Color(0,0,testModeColor));      
  modePixels.setPixelColor(DAZZLE_PIXEL, modePixels.Color(0,0,255));
    }
  modePixels.show();

   if (player1BtnValue)
    {
        player1Strip.clearStrip();
    } else {
     Serial.println("Player1 Pressed");
        player1Strip.fillStrip(RED);
    }
   if (player2BtnValue)
    {
        player2Strip.clearStrip();
    } else {
     Serial.println("Player2 Pressed");
        player2Strip.fillStrip(GREEN);
    }

  NeoWindow::updateTime();
  
  // change any effects?
  // if (window.effectDone()) changeIt

  // do one frame of all neoWindows
  //updateAllWindows();
  // updateWindow with no function => console mesg
 

  showAllStrip();
}
