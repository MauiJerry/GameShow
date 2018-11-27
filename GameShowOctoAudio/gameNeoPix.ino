/* gameNeoPix : neoPixel/Window module for GameShow System
// revised to use OctoEffects & PJRC Octo library vs Adafruit
// Note that Octo uses one large memory array for draw and optionally another (or reuses)
// memory for display (double buffering if desired)
// memory is based on max strip size for all 8 possible strips
// memsize = STRIPSIZE *6 ... not sure why 6, ask PJRC
//
// there is only one OctoStrip with 8 ws8211 strips on its 8 defined ports
// Windows need to be offset by their row/port
// which is a bit different from the way done under NeoPixels

//////////////////

// Octo Strip has 8 rows corresponding to the 8 pins used
// the OctoStrip::getAbsolutePixel(row,col) gives the absolute index of pixel in strip
// which is what is needed to set its color
//
  pin 2   = row 0 = Player1Ring (16)
  pin 14  = row 1 = NC
  pin 7   = row 2 = Player2 Ring (12) 
  pin 8   = row 3 = ModeBtnPixels (3) 
  pin 6   = row 4 = Left Strip
  pin 20  = row 5 = NC 
  pin 21  = row 6 = Right Strip
  pin 5   = row 7 = Top Strip
*/

#define PLAYER1_RING_ROW 0
#define PLAYER2_RING_ROW 2
#define MODE_PIX_ROW 3
#define LEFT_STRIP_ROW 4
#define RIGHT_STRIP_ROW 6
#define TOP_STRIP_ROW 7

// window lengths
#define PLAYER1_RING_LEN 16
#define PLAYER2_RING_LEN 12

// Top Strip has 3 windows, full, left, right
#define TOP_STRIP_LEN 84
#define TOP_LEFT_START 0
#define TOP_LEFT_LEN  42
#define TOP_RIGHT_START TOP_LEFT_LEN
#define TOP_RIGHT_LEN 42

// two side strips
#define LEFT_STRIP_LEN 57
#define RIGHT_STRIP_LEN LEFT_STRIP_LEN

#define MAX_STRIP_LEN TOP_STRIP_LEN

// Octo Library requires display/draw memory for each of the pixel strips.
//OctoStrip strip1 = OctoStrip(ledsPerStrip, displayMemory, drawingMemory, stripType);
const int memSize = MAX_STRIP_LEN *6;
DMAMEM int displayMemory[memSize];
int drawingMemory[memSize];
const int stripType = WS2811_GRB | WS2811_800kHz;

OctoStrip octo = OctoStrip(MAX_STRIP_LEN, displayMemory, drawingMemory, stripType);

OctoWindow player1Ring = OctoWindow(octo.getAbsolutePixel(PLAYER1_RING_ROW,0), PLAYER1_RING_LEN);
OctoWindow player2Ring = OctoWindow(octo.getAbsolutePixel(PLAYER2_RING_ROW,0), PLAYER2_RING_LEN);

OctoWindow topFullWindow = OctoWindow(octo.getAbsolutePixel(TOP_STRIP_ROW,0), TOP_STRIP_LEN);
OctoWindow topLeftWindow = OctoWindow(octo.getAbsolutePixel(TOP_STRIP_ROW,TOP_LEFT_START), TOP_LEFT_LEN); 
OctoWindow topRightWindow = OctoWindow(octo.getAbsolutePixel(TOP_STRIP_ROW,TOP_RIGHT_START), TOP_RIGHT_LEN); 

OctoWindow leftWindow  = OctoWindow(octo.getAbsolutePixel(LEFT_STRIP_ROW,0), LEFT_STRIP_LEN);
OctoWindow rightWindow = OctoWindow(octo.getAbsolutePixel(RIGHT_STRIP_ROW,0), RIGHT_STRIP_LEN);
  
// 3 Mode Buttons have single Flora NeoPixel chained into 3 pixel row
OctoWindow modePixels = OctoWindow(octo.getAbsolutePixel(MODE_PIX_ROW,0),3);

void setupNeoPix() 
{
  // start the strip.  do this first for all strips
  Serial.println("Setup Neo Pixels");
  OctoWindow::updateTime();
  octo.begin();
  
  if (BRIGHTNESS != 0)
  {
    octo.setBrightness(BRIGHTNESS);
  }

  // start effects?
  setAllWindowsNoEfx();
}

void setAllWindowsNoEfx()
{
  player1Ring.setNoEfx();
  player2Ring.setNoEfx();
  rightWindow.setNoEfx();
  leftWindow.setNoEfx();
  topLeftWindow.setNoEfx();
  topRightWindow.setNoEfx();
  topFullWindow.setNoEfx();
}

void modePixOn()
{
//  Serial.println("Mode Pix On");
  //modePixels.setPixelColor(DEAD_PIXEL,  octo.Color(100,100,100));
  modePixels.setPixelColor(QUIET_PIXEL,  octo.Color(255,0,0));
  modePixels.setPixelColor(GAME_PIXEL,   octo.Color(0,255,0));
  modePixels.setPixelColor(DAZZLE_PIXEL, octo.Color(0,0,255));
}

void modePixOff()
{
//  Serial.println("Mode Pix Off");
  //modePixels.setPixelColor(DEAD_PIXEL,  0);
  modePixels.setPixelColor(QUIET_PIXEL,  0);
  modePixels.setPixelColor(GAME_PIXEL,   0);
  modePixels.setPixelColor(DAZZLE_PIXEL, 0);
}

void showStrip()
{
  octo.show();
}

void allStripOn()
{
  int maxOn = 100;
  topFullWindow.fillColor( WHITE);
  leftWindow.fillColor(octo.Color  (maxOn, maxOn,0));//randomColor());
  rightWindow.fillColor(octo.Color(0, maxOn, maxOn));//randomColor());
  player1Ring.fillColor(octo.Color(maxOn, maxOn, maxOn));
  player2Ring.fillColor(octo.Color(maxOn, maxOn, maxOn));
  showStrip();
}

void allStripOff()
{

  topFullWindow.fillBlack();
  leftWindow.fillBlack();
  rightWindow.fillBlack();
  player1Ring.fillBlack();
  player2Ring.fillBlack();
 showStrip();
}

void allOn() 
{
//  Serial.println("Turn all LED OFF");
  allStripOn();
  modePixOn();
}

void allOff() 
{
//  Serial.println("Turn all LED OFF");
  allStripOff();
  modePixOff();
}

void  startupBlinks()
{
  Serial.println("Startup Mode Blinks Begin");
  
  for (int i =0; i< 2; i++)
  {
    Serial.println("AllOn");
    allOn();
    delay(500);
    Serial.println("AllOff");
    allOff();
    delay(500);
  }
  Serial.println("Startup Mode Blinks Done");
}

int testModeColor = 0;
int testModeDirection = 1;

void blinkModePixels()
{
  modePixOn();
  delay(500);
  modePixOff();
  delay(500);
}

void updateAllWindows()
{
  player1Ring.updateWindow();
  player2Ring.updateWindow();
  rightWindow.updateWindow();
  leftWindow.updateWindow();
  topLeftWindow.updateWindow();
  topRightWindow.updateWindow();
  topFullWindow.updateWindow();
}
