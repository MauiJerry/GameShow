////////////////////
// Button Stuff
// bounce2 is new version that depricates the allinone initialization
#include <Bounce2.h>

// time to allow switches to settle for debouncing
#define DEBOUNCETIME 5

// Two sets of buttons - 3 selectors and 2 players
// Two Player buttons
#define Player1BtnPin 22
#define Player2BtnPin 23
// for mode selections 3 pushbuttons on Octo pad
#define Mode1Pin 17
#define Mode2Pin 18
#define Mode3Pin 19

#define BUTTON Mode1Pin
// Instantiate a Bounce object with a 5 millisecond debounce time
Bounce player1Btn = Bounce( Player1BtnPin,5 ); 
Bounce player2Btn = Bounce( Player2BtnPin,5 ); 
Bounce mode1Btn = Bounce( Mode1Pin,5 ); 
Bounce mode2Btn = Bounce( Mode2Pin,5 ); 
Bounce mode3Btn = Bounce( Mode3Pin,5 ); 

// Button Status; updated during updateButtons
int player1BtnValue = 0;
int player2BtnValue = 0;
int mode1BtnValue = 0;
int mode2BtnValue = 0;
int mode3BtnValue = 0;
 
void setupButtons() 
{
  pinMode(Player1BtnPin,INPUT_PULLUP);
  pinMode(Player2BtnPin,INPUT_PULLUP);
  pinMode(Mode1Pin,INPUT_PULLUP);
  pinMode(Mode2Pin,INPUT_PULLUP);
  pinMode(Mode3Pin,INPUT_PULLUP);
  Serial.println("Buttons Setup Complete");
}

// updateButtons() Updates Inputs returns 0 if no change in buttons, 1+ otherwise
int updateButtons() 
{
  int change = 0;
  change = player1Btn.update ( );
  change += player2Btn.update ( );
  change += mode1Btn.update ( );
  change += mode2Btn.update ( );
  change += mode3Btn.update ( );
  // Get the update value
  player1BtnValue = player1Btn.read();
  player2BtnValue = player2Btn.read();
  mode1BtnValue = mode1Btn.read();
  mode2BtnValue = mode2Btn.read();
  mode3BtnValue = mode3Btn.read();
  
  if (change> 0) Serial.printf("a button pressed %d\n", change);

 return change; // 0 none pressed, 1+ something changed
}

void logButtons() 
{
  Serial.print("Buttons: P1 P2 M1 M2 M3 "); 
  Serial.print(player1BtnValue); Serial.print(" ");
  Serial.print(player2BtnValue); Serial.print(" ");
  Serial.print(mode1BtnValue); Serial.print(" ");
  Serial.print(mode2BtnValue); Serial.print(" ");
  Serial.println(mode3BtnValue);
}
