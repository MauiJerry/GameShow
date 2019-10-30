// gameNeoPix.h : defines/externs for GameShow System

#include <Adafruit_NeoPixel.h>
#include <NeoEffects.h>
#include <NeoStrip.h>
#include <NeoWindow.h>

// mode buttons are now separate regular leds on own pins
#define QUIET_PIXEL_PIN 8
#define GAME_PIXEL_PIN 14
#define DAZZLE_PIXEL_PIN 20

#define RING_LENGTH1 16
#define RING_LENGTH2 12
#define BRIGHTNESS 100

// Three Strips, two Rings, 3 Modes
extern NeoStrip topStrip;
extern NeoWindow topFullWindow;
extern NeoWindow topLeftWindow;
extern NeoWindow topRightWindow;

extern NeoStrip leftStrip;
extern NeoWindow leftWindow;

extern NeoStrip rightStrip;
extern NeoWindow rightWindow;

extern NeoStrip player1Strip;
extern NeoStrip player2Strip;
extern NeoWindow player1Ring;
extern NeoWindow player2Ring;


extern void startupBlinks();
extern void allOn(); 
extern void allOff(); 
extern void modePixOff();
extern void modePixOn();
extern void setupNeoPix();

extern void modePixQuiet();
extern void modePixGame();
extern void modePixDazzle();

extern void  setQuietNeoEfx();
extern void  setGameNeoEfx();
extern void  setLeftNeoEfx();
extern void  setRightNeoEfx();
extern void  setDazzleNeoEfx();
extern void leftRightSolid();

extern void showAllStrip();
extern void blinkModePixels();
extern void rampModePixels();

extern int testModeColor;
