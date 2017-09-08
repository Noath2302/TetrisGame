// ------ Includes -----
#ifndef LINUX
#include <windows.h>
#endif
#include "Game.h"

/*
======================================
Init
======================================
*/
Game::Game(SDL_Renderer *gameRenderer, SDL_Event *gameEvent, Board *pBoard, Pieces *pPieces, gameDraw *pIO, int pScreenHeight, int *pause, bool *lose,int *score):
gameRenderer(gameRenderer), gameEvent(gameEvent), mIO(pIO), game_pause(pause), game_over(lose), score(score)
{
	win_height = pScreenHeight;
	// Get the pointer to the Board and Pieces classes
	mBoard = pBoard;
	mPieces = pPieces;

	// Game initialization
	InitGame();

	// time initiation
	mTime1 = SDL_GetTicks();

}


/*
======================================
Get a random int between to integers

Parameters:
>> pA: First number
>> pB: Second number
======================================
*/
int Game::GetRand(int pA, int pB)
{
	return rand() % (pB - pA + 1) + pA;
}


/*
======================================
Initial parameters of the game
======================================
*/
void Game::InitGame()
{
	// Init random numbers
	srand((unsigned int)time(NULL));

	// First piece
	mPiece = GetRand(0, 6);
	mRotation = GetRand(0, 3);
	mPosX = (BOARD_WIDTH / 2) + mPieces->GetXInitialPosition(mPiece, mRotation);
	mPosY = mPieces->GetYInitialPosition(mPiece, mRotation);

	//  Next piece
	mNextPiece = GetRand(0, 6);
	mNextRotation = GetRand(0, 3);
	mNextPosX = BOARD_WIDTH + 4;
	mNextPosY = 5;
}


/*
======================================
Create a random piece
======================================
*/
void Game::CreateNewPiece()
{
	// The new piece
	mPiece = mNextPiece;
	mRotation = mNextRotation;
	mPosX = (BOARD_WIDTH / 2) + mPieces->GetXInitialPosition(mPiece, mRotation);
	mPosY = mPieces->GetYInitialPosition(mPiece, mRotation);

	// Random next piece
	mNextPiece = GetRand(0, 6);
	mNextRotation = GetRand(0, 3);
}


/*
======================================
Draw piece

Parameters:

>> pX:		Horizontal position in blocks
>> pY:		Vertical position in blocks
>> pPiece:	Piece to draw
>> pRotation:	1 of the 4 possible rotations
======================================
*/
void Game::DrawPiece(int pX, int pY, int pPiece, int pRotation)
{


	// Obtain the position in pixel in the screen of the block we want to draw
	int mPixelsX = mBoard->GetXPosInPixels(pX);
	int mPixelsY = mBoard->GetYPosInPixels(pY);

	// Travel the matrix of blocks of the piece and draw the blocks that are filled
	for (int i = 0; i < PIECE_BLOCKS; i++)
	{
		for (int j = 0; j < PIECE_BLOCKS; j++)
		{
			// Get the type of the block and draw it with the correct color

			if (mPieces->GetBlockType(pPiece, pRotation, j, i) != 0)
				mIO->DrawRectangle(mPixelsX + i * BLOCK_SIZE, mPixelsY + j * BLOCK_SIZE, (mPixelsX + i * BLOCK_SIZE) + BLOCK_SIZE - 1, (mPixelsY + j * BLOCK_SIZE) + BLOCK_SIZE - 1,BLOCK);
		}
	}
}


/*
======================================
Draw board

Draw the two lines that delimit the board
======================================
*/
void Game::DrawBoard()
{

	// Calculate the limits of the board in pixels	
	int mX1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) - 1;
	int mX2 = BOARD_POSITION + (BLOCK_SIZE * (BOARD_WIDTH / 2));
	int mY = win_height - (BLOCK_SIZE * BOARD_HEIGHT);

	// Check that the vertical margin is not to small
	//assert (mY > MIN_VERTICAL_MARGIN);

	// Rectangles that delimits the board
	mIO->DrawRectangle(mX1 - BOARD_LINE_WIDTH, mY, mX1, win_height - 1, COLL);
	mIO->DrawRectangle(mX2, mY, mX2 + BOARD_LINE_WIDTH, win_height - 1, COLL);

	// Check that the horizontal margin is not to small
	//assert (mX1 > MIN_HORIZONTAL_MARGIN);

	// Drawing the blocks that are already stored in the board
	mX1 += 1;
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j < BOARD_HEIGHT; j++)
		{
			// Check if the block is filled, if so, draw it
			if (!mBoard->IsFreeBlock(i, j))
				mIO->DrawRectangle(mX1 + i * BLOCK_SIZE,
				mY + j * BLOCK_SIZE,
				(mX1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
				(mY + j * BLOCK_SIZE) + BLOCK_SIZE - 1,BLOCK);
		}
	}
}


/*
======================================
Draw scene

Draw all the objects of the scene
======================================
*/
void Game::DrawScene()
{
	if (!mBoard->IsGameOver()){
		mIO->bg->draw(0,0,640,480);
		DrawBoard();												// Draw the delimitation lines and blocks stored in the board
		DrawPiece(mPosX, mPosY, mPiece, mRotation);					// Draw the playing piece
		DrawPiece(mNextPosX -2, mNextPosY+3, mNextPiece, mNextRotation);	// Draw the next piece
		// renderings around the game state goes here
		mIO->title->render(450, 120);
		mIO->pointBox->num_render(*score,450,350);
		mIO->score->render(450, 350);
		mIO->next->render(450,200);
		mIO->renderHint();
	}
}

void Game::handle(){
	if (!mBoard->IsGameOver()){
		if (gameEvent->type == SDL_KEYDOWN){
			if (gameEvent->key.keysym.sym == SDLK_ESCAPE){
				*game_pause = (*game_pause + 1) % 2;
			}
			if (!(*game_pause))
			{
				switch (gameEvent->key.keysym.sym)
				{
				case (SDLK_RIGHT) :
				{
					if (mBoard->IsPossibleMovement(mPosX + 1, mPosY, mPiece, mRotation))
						mPosX++;
					break;
				}

				case (SDLK_LEFT) :
				{
					if (mBoard->IsPossibleMovement(mPosX - 1, mPosY, mPiece, mRotation))
						mPosX--;
					break;
				}

				case (SDLK_DOWN) :
				{
					if (mBoard->IsPossibleMovement(mPosX, mPosY + 1, mPiece, mRotation))
						mPosY++;
					break;
				}

				case (SDLK_x) :
				{
					// Check collision from up to down
					while (mBoard->IsPossibleMovement(mPosX, mPosY, mPiece, mRotation)) { mPosY++; }

					mBoard->StorePiece(mPosX, mPosY - 1, mPiece, mRotation);

					mBoard->DeletePossibleLines();

					if (mBoard->IsGameOver())
					{
						mIO->GetKey();
					}

					CreateNewPiece();

					break;
				}

				case (SDLK_z) :
				{
					if (mBoard->IsPossibleMovement(mPosX, mPosY, mPiece, (mRotation + 1) % 4))
						mRotation = (mRotation + 1) % 4;

					break;
				}
				}
			}
		}
	}
	else if (mBoard->IsGameOver()){
		*game_pause = false;
		*game_over = true;
	}
}
void Game::vertical(){
	if (!(*game_pause) && !(*game_over)){
		mTime2 = SDL_GetTicks();

		if (mTime2 - mTime1 > WAIT_TIME)
		{
			if (mBoard->IsPossibleMovement(mPosX, mPosY + 1, mPiece, mRotation))
			{
				mPosY++;
			}
			else
			{
				mBoard->StorePiece(mPosX, mPosY, mPiece, mRotation);

				mBoard->DeletePossibleLines();

				if (mBoard->IsGameOver())
				{
					mIO->GetKey();
					//				exit(0);
				}

				CreateNewPiece();
			}
			mTime1 = SDL_GetTicks();
		}
	}
}

Game::~Game(){


	mBoard = NULL;
	mPiece = NULL;
	mIO = NULL;
}


