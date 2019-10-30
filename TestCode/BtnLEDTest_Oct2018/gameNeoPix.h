// gameNeoPix.h : defines/externs for GameShow System

#include <Adafruit_NeoPixel.h>
#include <NeoEffects.h>
#include <NeoStrip.h>
#include <NeoWindow.h>

// mode buttons lit by chained Flora NeoPixels on RJ1
// mode pixel numbers
#define QUIET_PIXEL 2
#define GAME_PIXEL 1
#define DAZZLE_PIXEL 0

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

// Mode Flora NeoPixels are just simple neopixels as we just do on/off in color
extern Adafruit_NeoPixel modePixels;

extern void startupBlinks();
extern void allOn(); 
extern void allOff(); 
extern void modePixOff();
extern void modePixOn();
extern void setupNeoPix(); 

extern void  showAllStrip();
extern void blinkModePixels();
extern void rampModePixels();

extern int testModeColor;
