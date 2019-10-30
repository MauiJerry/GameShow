// gameNeoPix : neoPixel/Window module for GameShow System
//////////////////

// NeoPixel Strips
// player rings on RJ1
#define PLAYER1_RING_PIN 7
#define PLAYER2_RING_PIN 2

// top, left, right strips on RJ2
#define TOP_STRIP_PIN 5
#define LEFT_STRIP_PIN 21
#define RIGHT_STRIP_PIN 6 

//#define TOP_STRIP_LEN 64
#define TOP_STRIP_LEN 86
#define TOP_RIGHT_START 0
#define TOP_RIGHT_LEN (TOP_STRIP_LEN/2)
#define TOP_LEFT_START TOP_RIGHT_LEN
#define TOP_LEFT_LEN  43

#define LEFT_STRIP_LEN 60
#define RIGHT_STRIP_LEN LEFT_STRIP_LEN


// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
NeoStrip player1Strip = NeoStrip(RING_LENGTH1, PLAYER1_RING_PIN, NEO_GRB + NEO_KHZ800);
NeoStrip player2Strip = NeoStrip(RING_LENGTH2, PLAYER2_RING_PIN, NEO_RGB + NEO_KHZ800);
NeoWindow player1Ring  = NeoWindow(&player1Strip, 0, RING_LENGTH1);
NeoWindow player2Ring  = NeoWindow(&player2Strip, 0, RING_LENGTH2);//RING_LENGTH);

#define STRIP_TYPE (NEO_GRB+ NEO_KHZ800)
// using rgb+w strip from adafruit which should be RGBW
// however the uberGuide says some may be GRBW
NeoStrip topStrip = NeoStrip(TOP_STRIP_LEN, TOP_STRIP_PIN, STRIP_TYPE );
NeoWindow topFullWindow  = NeoWindow(&topStrip, 0, TOP_STRIP_LEN);
NeoWindow topLeftWindow  = NeoWindow(&topStrip, TOP_LEFT_START, TOP_LEFT_LEN);
NeoWindow topRightWindow = NeoWindow(&topStrip, TOP_RIGHT_START, TOP_RIGHT_LEN);

NeoStrip leftStrip = NeoStrip(LEFT_STRIP_LEN, LEFT_STRIP_PIN, STRIP_TYPE);
NeoWindow leftWindow  = NeoWindow(&leftStrip, 0, LEFT_STRIP_LEN);

NeoStrip rightStrip = NeoStrip(RIGHT_STRIP_LEN, RIGHT_STRIP_PIN, STRIP_TYPE );
NeoWindow rightWindow  = NeoWindow(&rightStrip, 0, RIGHT_STRIP_LEN);

// Oct 2019 - 3 mode pixels become separate LEDs on 3 separate pins
// use modePixQuiet/Game/Dazzle() methods to activate

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
  setupModePixels();
  
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

void setupModePixels()
{
  Serial.println("setupModePixels");

  pinMode(QUIET_PIXEL_PIN, OUTPUT);
  pinMode(GAME_PIXEL_PIN, OUTPUT);
  pinMode(DAZZLE_PIXEL_PIN, OUTPUT);
}


void setAllBrightness(int brightness)
{
    player1Strip.setBrightness(brightness);
    player2Strip.setBrightness(brightness);
    topStrip.setBrightness(brightness);
    leftStrip.setBrightness(brightness);
    rightStrip.setBrightness(brightness);
}

void setAllWindowsNoEfx()
{
  Serial.println("setAllWindowsNoEfx");
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
  Serial.println("Mode Pix On");

    digitalWrite(QUIET_PIXEL_PIN, HIGH);
    digitalWrite(GAME_PIXEL_PIN, HIGH);
    digitalWrite(DAZZLE_PIXEL_PIN, HIGH);

}

void modePixOff()
{
    digitalWrite(QUIET_PIXEL_PIN, LOW);
    digitalWrite(GAME_PIXEL_PIN, LOW);
    digitalWrite(DAZZLE_PIXEL_PIN, LOW);
}

void modePixQuiet()
{
  Serial.println("modePixQuiet");
    digitalWrite(QUIET_PIXEL_PIN, HIGH);
    digitalWrite(GAME_PIXEL_PIN, LOW);
    digitalWrite(DAZZLE_PIXEL_PIN, LOW);
}

void modePixGame()
{
   Serial.println("modePixGame");
   digitalWrite(QUIET_PIXEL_PIN, LOW);
    digitalWrite(GAME_PIXEL_PIN, HIGH);
    digitalWrite(DAZZLE_PIXEL_PIN, LOW);
}

void modePixDazzle()
{
  Serial.println("modePixDazzle");
    digitalWrite(QUIET_PIXEL_PIN, LOW);
    digitalWrite(GAME_PIXEL_PIN, LOW);
    digitalWrite(DAZZLE_PIXEL_PIN, HIGH);
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
  Serial.println("allStripOn");
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
  Serial.println("allStripOff");
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

void  showAllStrip()
{
  topStrip.show();
  leftStrip.show();
  rightStrip.show();
  player1Strip.show();
  player2Strip.show();
}

int dazzleTime = 60;
int dazzelPercent = 70;

int slowDazzleTime = 2000;
int fastDazzleTime = 50;

void  setQuietNeoEfx()
{
  Serial.println("setQuietNeoEfx");
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
  modePixQuiet();
}

void setGameNeoEfx()
{
  Serial.println("setGameNeoEfx");
  
  setAllBrightness(BRIGHTNESS);
  // long strips in slow dazzle
//  int dazzleTime = 2000;
//    setAllBrightness(100);
  topFullWindow.fillBlack();
  leftWindow.fillBlack();
  rightWindow.fillBlack();
  
//  topFullWindow.setSolidColorEfx(RED, 5000);
//  leftWindow.setSolidColorEfx(GREEN, 5000);
//  rightWindow.setSolidColorEfx(BLUE, 5000);
  
  topFullWindow.fillBlack();
  topFullWindow.setFadeEfx(0, BLUE, 100, topFullWindow.fadeTypeCycle, 600);
  topLeftWindow.setNoEfx();
  topRightWindow.setNoEfx();
  
  leftWindow.setFadeEfx(0, BLUE, 100, leftWindow.fadeTypeCycle, 600);
  rightWindow.setFadeEfx(0, BLUE, 100, rightWindow.fadeTypeCycle, 600);
  
  // player buttons slow Dazzle
  player1Ring.setDazzleEfx( slowDazzleTime, 50, 600);
  player2Ring.setDazzleEfx( slowDazzleTime, 50, 600);

  // control buttons Quiet= full color
  modePixGame();
}

void  setLeftNeoEfx()
{
  Serial.println("setLeftNeoEfx");
  setAllBrightness(BRIGHTNESS);

  topFullWindow.fillBlack();
  topFullWindow.setNoEfx();
  
  topLeftWindow.setDazzleEfx( dazzleTime, dazzelPercent, 50);
  
  //topRightWindow.setSolidColorEfx(BLACK, 600);
  topRightWindow.setNoEfx();

  leftWindow.setDazzleEfx( dazzleTime, dazzelPercent, 50);
  rightWindow.fillBlack();
  rightWindow.setNoEfx();

//  topLeftWindow.printData();
//  topRightWindow.printData();
    
  // player buttons solid color
  player1Ring.setDazzleEfx( dazzleTime, dazzelPercent, 75);//setBlinkEfx(RED, 100, 0); 
  player2Ring.setSolidColorEfx(0, 5000);

  // control buttons Quiet= full color
  modePixGame();
}

void  setRightNeoEfx()
{ 
  Serial.println("setRightNeoEfx");
  setAllBrightness(BRIGHTNESS);
  // long strips in slow dazzle
//  int dazzleTime = 2000;
//    setAllBrightness(100);

  topFullWindow.fillBlack();
  topFullWindow.setNoEfx();
  
//  topLeftWindow.fillBlack();
  topLeftWindow.setNoEfx();
  topRightWindow.setDazzleEfx( dazzleTime, dazzelPercent, 50);

  leftWindow.setSolidColorEfx(0, 5000);
  leftWindow.fillBlack();
  
  rightWindow.setDazzleEfx( dazzleTime, dazzelPercent, 50);
//  rightWindow.setReverseWipeEfx(color, 30,600);
//  rightWindow.setBlinkEfx(GREEN, 100, 0);
  
  // player buttons solid color
  player1Ring.setSolidColorEfx(0, 5000); 
  player2Ring.setDazzleEfx( dazzleTime, dazzelPercent, 75);
//  player2Ring.setBlinkEfx(GREEN, 600);

  // control buttons Quiet= full color
  modePixGame();
}

void  setDazzleNeoEfx()
{
  Serial.println("setDazzleNeoEfx");
  setAllBrightness(100);

  topFullWindow.setDazzleEfx( dazzleTime, dazzelPercent, 50);
  topLeftWindow.setNoEfx();
  topRightWindow.setNoEfx();
  
  leftWindow.setDazzleEfx( dazzleTime, dazzelPercent, 50);
  rightWindow.setDazzleEfx( dazzleTime, dazzelPercent, 50);
  
  // player buttons solid color
  player1Ring.setDazzleEfx( dazzleTime, dazzelPercent, 50); // fade between two colors
  player2Ring.setDazzleEfx( dazzleTime, dazzelPercent, 50); // fade between two colors

  // control buttons 
    modePixDazzle();
}

void leftRightSolid()
{
  Serial.println("leftRightSolid");
  topFullWindow.fillBlack();
  topRightWindow.fillColor(RED);
  topLeftWindow.fillColor(GREEN);
}
