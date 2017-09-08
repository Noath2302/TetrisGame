
#ifndef _GAME_
#define _GAME_

// ------ Includes -----

#include "Board.h"
#include "Pieces.h"
#include <time.h>
#include "SDL.h"
#include "gameStates.h"
#include "gameDraw.h"

// ------ Defines -----

#define WAIT_TIME 700			// Number of milliseconds that the piece remains before going 1 block down */ 


class Game
{
public:

	Game(SDL_Renderer *gameRenderer, SDL_Event *gameEvent, Board *pBoard, Pieces *pPieces, gameDraw *pIO, int pScreenHeight, int *gamePause, bool *Tetris_lose, int *score);
	~Game();

	// ===== render function ===== 
	void DrawScene();

	// ===== update function =====
	void vertical();

	// ===== handle function =====
	void handle();
	// ===== new piece (applying random from cstdlib) =====
	void CreateNewPiece();
	

	int mPosX, mPosY;				// Position of the piece that is falling down
	int mPiece, mRotation;			// Kind and rotation the piece that is falling down

	// ===== pointer for managing game =====
	SDL_Renderer *gameRenderer;
	SDL_Event *gameEvent;

	/* ===== game renderings =====
	2 states:
	- game_over state:
	get nextGameStates pointer ->> Menu
	- pause state
	get nextGameStates pointer ->> Menu
	execute when bool gamePause -> true		--------> get gamePause pointer ~> gamePause -> false
	==============================*/
	int *game_pause;
	bool *game_over;

	int *score;
private:

	// ===== variable for pos to draw =====
	int win_height;				// Screen height in pixels
	int mNextPosX, mNextPosY;		// Position of the next piece
	int mNextPiece, mNextRotation;	// Kind and rotation of the next piece
	

	// ===== obj for running board =====
	Board *mBoard;
	Pieces *mPieces;
	gameDraw *mIO;
	unsigned long mTime1;
	unsigned long mTime2;

	//----- game operation -----

	int GetRand(int pA, int pB);
	void InitGame();
	void DrawPiece(int pX, int pY, int pPiece, int pRotation);
	void DrawBoard();
	
	
};

#endif // _GAME_//'



