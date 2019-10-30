// gameNeoPix.h : defines/externs for GameShow System

#include <OctoEffects.h>

#define RED    0xFF0000
#define GREEN  0x00FF00
#define BLUE   0x0000FF
#define YELLOW 0xFFFF00
#define PINK   0xFF1088
#define ORANGE 0xE05800
#define WHITE  0xFFFFFF

// mode buttons lit by chained Flora NeoPixels on RJ1
// mode pixel numbers
#define QUIET_PIXEL 2
#define GAME_PIXEL 1
#define DAZZLE_PIXEL 0

#define RING_LENGTH1 16
#define RING_LENGTH2 12
#define BRIGHTNESS 100

// Three Strips, two Rings, 3 Modes
extern OctoStrip octo;
extern OctoWindow topFullWindow;
extern OctoWindow topLeftWindow;
extern OctoWindow topRightWindow;
extern OctoWindow leftWindow;
extern OctoWindow rightWindow;
extern OctoWindow player1Ring;
extern OctoWindow player2Ring;

extern OctoWindow modePixels;

extern void startupBlinks();
extern void allOn(); 
extern void allOff(); 
extern void modePixOff();
extern void modePixOn();
extern void setupNeoPix(); 

extern void showStrip();
extern void blinkModePixels();

extern void updateAllWindows();

extern int testModeColor;
