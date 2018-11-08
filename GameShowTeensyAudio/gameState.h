/* 
 *  gameState: tools to support GameShow states
 *  
 */

#ifndef GAMESTATE_DEFINES
#define GAMESTATE_DEFINES

typedef enum GameState {InitState, QuietState, PlayState, LeftState, RightState, DazzleState} GameState;
extern GameState gameState;

extern void initGameState();
extern void setQuietState();
extern void setPlayState();
extern void setLeftState();
extern void setRightState();
extern void setDazzleState();

extern void checkWindowsDone();
#endif //  GAMESTATE_DEFINES
