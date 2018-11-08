// gameNeoPix : neoPixel/Window module for GameShow System
//////////////////

// NeoPixel Strips
// player rings and single LED on RJ1 (with their single leds)
// 2ring and 3 mode LEDs on RJ1 (with 3 mode leds)
#define PLAYER1_RING_PIN 7
#define PLAYER2_RING_PIN 2
#define MODE_PIX_PIN 8

// top, left, right strips on RJ2
#define TOP_STRIP_PIN 21
#define LEFT_STRIP_PIN 5
#define RIGHT_STRIP_PIN 6

#define TOP_STRIP_LEN 86
#define TOP_LEFT_START 0
#define TOP_LEFT_LEN  40
#define TOP_RIGHT_START TOP_LEFT_LEN
#define TOP_RIGHT_LEN 40

#define LEFT_STRIP_LEN 60
#define RIGHT_STRIP_LEN LEFT_STRIP_LEN


// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
NeoStrip player1Strip = NeoStrip(RING_LENGTH, PLAYER1_RING_PIN, NEO_GRB + NEO_KHZ800);
NeoStrip player2Strip = NeoStrip(RING_LENGTH, PLAYER2_RING_PIN, NEO_RGB + NEO_KHZ800);
NeoWindow player1Ring  = NeoWindow(&player1Strip, 0, RING_LENGTH);
NeoWindow player2Ring  = NeoWindow(&player2Strip, 0, 12);//RING_LENGTH);

#define STRIP_TYPE NEO_GRBW
// using rgb+w strip from adafruit which should be RGBW
// however the uberGuide says some may be GRBW
NeoStrip topStrip = NeoStrip(TOP_STRIP_LEN, TOP_STRIP_PIN, STRIP_TYPE + NEO_KHZ800);
NeoWindow topFullWindow  = NeoWindow(&topStrip, 0, TOP_STRIP_LEN);
NeoWindow topLeftWindow  = NeoWindow(&topStrip, 0, TOP_LEFT_LEN);
NeoWindow topRightWindow = NeoWindow(&topStrip, TOP_RIGHT_START, TOP_RIGHT_LEN);

NeoStrip leftStrip = NeoStrip(LEFT_STRIP_LEN, LEFT_STRIP_PIN, STRIP_TYPE + NEO_KHZ800);
NeoWindow leftWindow  = NeoWindow(&leftStrip, 0, LEFT_STRIP_LEN);

NeoStrip rightStrip = NeoStrip(RIGHT_STRIP_LEN, RIGHT_STRIP_PIN, STRIP_TYPE + NEO_KHZ800);
NeoWindow rightWindow  = NeoWindow(&rightStrip, 0, RIGHT_STRIP_LEN);

// Mode Flora NeoPixels are just simple neopixels as we just do on/off in testModeColor
Adafruit_NeoPixel modePixels = Adafruit_NeoPixel(3, MODE_PIX_PIN, NEO_GRB + NEO_KHZ800);

void setupNeoPix() 
{
  // start the strip.  do this first for all strips
  Serial.println("Setup Neo Pixels");
  NeoWindow::updateTime();
  player1Strip.begin();
  player2Strip.begin();
  topStrip.begin();
  leftStrip.begin();
  rightStrip.begin();
  modePixels.begin();
  
  Serial.printf("player1Strip id: %d\n", player1Strip.getId());
  Serial.printf("player2Strip id: %d\n", player2Strip.getId());
  Serial.printf("topStrip id: %d\n", topStrip.getId());
  Serial.printf("leftStrip id: %d\n", leftStrip.getId());
  Serial.printf("rightStrip id: %d\n", rightStrip.getId());
//  Serial.printf("modePixels id: %d\n", modePixels.getId());

  if (BRIGHTNESS != 0)
  {
    setAllBrightness(BRIGHTNESS);
  }

  // start effects?
  setAllWindowsNoEfx();

}

void setAllBrightness(int brightness)
{
    player1Strip.setBrightness(brightness);
    player2Strip.setBrightness(brightness);
    topStrip.setBrightness(brightness);
    leftStrip.setBrightness(brightness);
    rightStrip.setBrightness(brightness);
    //modePixels.setBrightness(brightness);
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
  //modePixels.setPixelColor(DEAD_PIXEL,  modePixels.Color(100,100,100));
  modePixels.setPixelColor(QUIET_PIXEL,  modePixels.Color(255,0,0));
  modePixels.setPixelColor(GAME_PIXEL,   modePixels.Color(0,255,0));
  modePixels.setPixelColor(DAZZLE_PIXEL, modePixels.Color(0,0,255));
  modePixels.show();
}

void modePixOff()
{
//  Serial.println("Mode Pix Off");
  //modePixels.setPixelColor(DEAD_PIXEL,  0);
  modePixels.setPixelColor(QUIET_PIXEL,  0);
  modePixels.setPixelColor(GAME_PIXEL,   0);
  modePixels.setPixelColor(DAZZLE_PIXEL, 0);
  modePixels.show();
}

void showStrips()
{
//  int delayTweenShow = 0;
//  Serial.println("allStripOn Show topStrip");
  topStrip.show();
//  delay(delayTweenShow);
//  Serial.println("allStripOn Show leftStrip");
  leftStrip.show();
//  delay(delayTweenShow);
//  Serial.println("allStripOn Show rightStrip");
  rightStrip.show();
//  delay(delayTweenShow);
  
//  Serial.println("allStripOn Show player1Strip");
  player1Strip.show();
//  delay(delayTweenShow);
//  Serial.println("allStripOn Show player2Strip");
  player2Strip.show();
//  delay(delayTweenShow);
}

void allStripOn()
{
  int maxOn = 100;
  topStrip.fillStrip( topStrip.Color   (0, 0, 0, maxOn));
  leftStrip.fillStrip(leftStrip.Color  (maxOn, maxOn,0));//randomColor());
  rightStrip.fillStrip(rightStrip.Color(0, maxOn, maxOn));//randomColor());
  player1Strip.fillStrip(rightStrip.Color(maxOn, maxOn, maxOn));
  player2Strip.fillStrip(rightStrip.Color(maxOn, maxOn, maxOn));
  showStrips();
}

void allStripOff()
{
  topStrip.clearStrip();
  leftStrip.clearStrip();
  rightStrip.clearStrip();
  player1Strip.clearStrip();
  player2Strip.clearStrip();
  showStrips();
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
  
  for (int i =0; i< 3; i++)
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

void rampModePixels() 
{
 Serial.println("rampModePixels - r, g, b");
 modePixels.setPixelColor(QUIET_PIXEL, modePixels.Color(testModeColor,0,0));
 modePixels.setPixelColor(GAME_PIXEL, modePixels.Color(0,testModeColor,0));
 modePixels.setPixelColor(DAZZLE_PIXEL, modePixels.Color(0,0,testModeColor));
 modePixels.show();
 delay(1000);
 if (testModeDirection) {
  testModeColor++;
  if (testModeColor >255) {
    Serial.println("Change to go Down");
    testModeDirection = 0; 
  }
 } else {
  testModeColor --;
  if (testModeColor < 0) {
    Serial.println("Change to go UP");
    testModeDirection = 1;
  }
 }
 Serial.println("rampModePixels - done");
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

void  showAllStrip()
{
  topStrip.show();
  leftStrip.show();
  rightStrip.show();
  player1Strip.show();
  player2Strip.show();
  modePixels.show();
}
