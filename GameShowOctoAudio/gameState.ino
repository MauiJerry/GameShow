#include "gameNeoPix.h"
#include "gameState.h"

GameState gameState = InitState;
int dazzleTime = 60;
int dazzelPercent = 70;

void initGameState()
{
  gameState = InitState;
  Serial.println("Init GameState");
}

int slowDazzleTime = 2000;
int fastDazzleTime = 50;

void setQuietState()
{
  Serial.println("Quiet GameState");
  gameState = QuietState;
  // Top, Left, Right strips in very slow dazzle
  AudioQuietState();
  
  octo.setBrightness(10);
  // long strips in slow dazzle

  topFullWindow.setDazzleEfx( slowDazzleTime, 50, 600);
  topLeftWindow.setNoEfx();
  topRightWindow.setNoEfx();

  leftWindow.setDazzleEfx( slowDazzleTime, 50, 600);
  rightWindow.setDazzleEfx( slowDazzleTime, 50, 600);
  
  // player buttons slow fade
//  player1Ring.setFadeEfx(0, RED, 100, player1Ring.fadeTypeCycle, 600); // fade between two colors
//  player2Ring.setFadeEfx(0, GREEN, 100, player2Ring.fadeTypeCycle, 600); // fade between two colors
  player1Ring.setDazzleEfx( slowDazzleTime, 50, 600);
  player2Ring.setDazzleEfx( slowDazzleTime, 50, 600);

  // control buttons Quiet= full color
  modePixels.setPixelColor(QUIET_PIXEL,  octo.Color(255,0,0));
  modePixels.setPixelColor(GAME_PIXEL,   octo.Color(0,0,0));
  modePixels.setPixelColor(DAZZLE_PIXEL, octo.Color(0,0,0));
}

void setPlayState()
{
  Serial.println("Play GameState");
  
  gameState = PlayState;
  // Top, Left, Right strips in very slow dazzle
  AudioPlayState();

  octo.setBrightness(BRIGHTNESS);
  // long strips in slow dazzle
//  int dazzleTime = 2000;
//    octo.setBrightness(100);
  topFullWindow.setFadeEfx(0, BLUE, 100, topFullWindow.fadeTypeCycle, 600);
  topLeftWindow.setNoEfx();
  topRightWindow.setNoEfx();
  leftWindow.setFadeEfx(0, BLUE, 100, topFullWindow.fadeTypeCycle, 600);
  rightWindow.setFadeEfx(0, BLUE, 100, topFullWindow.fadeTypeCycle, 600);
  
  // player buttons solid color
//  player1Ring.setMultiSparkleEfx(RED, 50, 50, player1Ring.getNumPixels()/2, 0); // fade between two colors
//  player2Ring.setMultiSparkleEfx(BLUE, 50, 50, player2Ring.getNumPixels()/2, 0); // fade between two colors
//  player1Ring.setSolidColorEfx(0, 600); // fade between two colors
//  player2Ring.setSolidColorEfx(0, 600); // fade between two colors
  player1Ring.setDazzleEfx( slowDazzleTime, 50, 600);
  player2Ring.setDazzleEfx( slowDazzleTime, 50, 600);

  // control buttons Quiet= full color
  modePixels.setPixelColor(QUIET_PIXEL,  octo.Color(0,0,0));
  modePixels.setPixelColor(GAME_PIXEL,   octo.Color(0,255,0));
  modePixels.setPixelColor(DAZZLE_PIXEL, octo.Color(0,0,0));
}

void setLeftState()
{
  Serial.println("Left GameState");
  gameState = LeftState;
  // Top, Left, Right strips in very slow dazzle
AudioPlayer1();

  octo.setBrightness(BRIGHTNESS);
  // long strips in slow dazzle
//  int dazzleTime = 2000;
//    octo.setBrightness(100);
  topFullWindow.setNoEfx();
  topFullWindow.fillBlack();
//  topLeftWindow.setWipeEfx(RED, 30,600);
  topLeftWindow.setDazzleEfx( dazzleTime, dazzelPercent, 50);
  topRightWindow.setNoEfx();
  topRightWindow.fillBlack();
//  leftWindow.setBlinkEfx(RED, 100, 0);
  leftWindow.setDazzleEfx( dazzleTime, dazzelPercent, 50);
  rightWindow.setNoEfx();
  rightWindow.fillBlack();
  
  // player buttons solid color
  player1Ring.setDazzleEfx( dazzleTime, dazzelPercent, 75);//setBlinkEfx(RED, 100, 0); 
  player2Ring.setSolidColorEfx(0, 5000);

  // control buttons Quiet= full color
  modePixels.setPixelColor(QUIET_PIXEL,  octo.Color(0,0,0));
  modePixels.setPixelColor(GAME_PIXEL,   octo.Color(0,255,0));
  modePixels.setPixelColor(DAZZLE_PIXEL, octo.Color(0,0,0));

}

void setRightState()
{
  Serial.println("Left GameState");
  gameState = LeftState;
  // Top, Left, Right strips in very slow dazzle
AudioPlayer2();

  octo.setBrightness(BRIGHTNESS);
  // long strips in slow dazzle
//  int dazzleTime = 2000;
//    octo.setBrightness(100);
  topFullWindow.setNoEfx();
  topFullWindow.fillBlack();
  topLeftWindow.setNoEfx();
  topLeftWindow.fillBlack();
  topRightWindow.setDazzleEfx( dazzleTime, dazzelPercent, 50);
  leftWindow.setNoEfx();
  leftWindow.fillBlack();
  rightWindow.setDazzleEfx( dazzleTime, dazzelPercent, 50);
//  rightWindow.setReverseWipeEfx(color, 30,600);
//  rightWindow.setBlinkEfx(GREEN, 100, 0);
  
  // player buttons solid color
  player1Ring.setSolidColorEfx(0, 5000); 
  player2Ring.setDazzleEfx( dazzleTime, dazzelPercent, 75);
//  player2Ring.setBlinkEfx(GREEN, 600);

  // control buttons Quiet= full color
  modePixels.setPixelColor(QUIET_PIXEL,  octo.Color(0,0,0));
  modePixels.setPixelColor(GAME_PIXEL,   octo.Color(0,255,0));
  modePixels.setPixelColor(DAZZLE_PIXEL, octo.Color(0,0,0));
}

void setDazzleState()
{
  Serial.println("Dazzle GameState");
    gameState = DazzleState;
  // Top, Left, Right strips in very slow dazzle

  AudioDazzle();

  octo.setBrightness(100);

  topFullWindow.setDazzleEfx( dazzleTime, dazzelPercent, 50);
  topLeftWindow.setNoEfx();
  topRightWindow.setNoEfx();
  leftWindow.setDazzleEfx( dazzleTime, dazzelPercent, 50);
  rightWindow.setDazzleEfx( dazzleTime, dazzelPercent, 50);
  
  // player buttons solid color
  player1Ring.setDazzleEfx( dazzleTime, dazzelPercent, 50); // fade between two colors
  player2Ring.setDazzleEfx( dazzleTime, dazzelPercent, 50); // fade between two colors

  // control buttons 
  modePixels.setPixelColor(QUIET_PIXEL,  octo.Color(0,0,0));
  modePixels.setPixelColor(GAME_PIXEL,   octo.Color(0,0,0));
  modePixels.setPixelColor(DAZZLE_PIXEL, octo.Color(0,0,255));
}

void checkWindowsDone()
{
  
}
