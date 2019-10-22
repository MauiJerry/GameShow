#include <Bounce2.h>

extern Bounce player1Btn; 
extern Bounce player2Btn; 
extern Bounce mode1Btn; 
extern Bounce mode2Btn; 
extern Bounce mode3Btn; 

// Button Status; updated during updateButtons
extern int player1BtnValue;
extern int player2BtnValue;
extern int mode1BtnValue;
extern int mode2BtnValue;
extern int mode3BtnValue;

int updateButtons();
void logButtons();
void setupButtons();
