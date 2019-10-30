#include "gameNeoPix.h"
#include "gameState.h"

GameState gameState = InitState;

void initGameState()
{
  gameState = InitState;
  Serial.println("Init GameState");
}

void setQuietState()
{
  Serial.println("Quiet GameState");
  gameState = QuietState;
  // Top, Left, Right strips in very slow dazzle
  AudioQuietState();
  
  setAllBrightness(10);
  // long strips in slow dazzle

  setQuietNeoEfx();
}

void setPlayState()
{
  Serial.println("Play GameState");
  
  gameState = PlayState;
  // Top, Left, Right strips in very slow dazzle
  AudioPlayState();

  setGameNeoEfx();
  Serial.println("end Play GameState");  
}

void setLeftState()
{
  Serial.println("set Left GameState ");
  gameState = LeftState;
  // Top, Left, Right strips in very slow dazzle
  AudioPlayer1();

  setLeftNeoEfx();
}

void setRightState()
{
  Serial.println("set Right GameState");
  gameState = RightState;
  // Top, Left, Right strips in very slow dazzle
  AudioPlayer2();

  setRightNeoEfx();
}

void setDazzleState()
{
  Serial.println("Dazzle GameState");
    gameState = DazzleState;
  // Top, Left, Right strips in very slow dazzle

  AudioDazzle();
  setDazzleNeoEfx();
}

void checkWindowsDone()
{
  
}
