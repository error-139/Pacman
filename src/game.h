#pragma once

#include "board.h"
#include "fruit.h"
#include "ghost.h"
#include "pacman.h"
#include "pellet.h"

typedef enum
{
	GameBeginState,
	LevelBeginState,
	GamePlayState,
	WinState,
	DeathState,
	GameoverState
} GameState;

typedef struct 
{
	GameState gameState;
	unsigned int ticksSinceModeChange;
	Pacman pacman;
	Ghost ghosts[4];
	Board board;
	PelletHolder pelletHolder;
	GameFruit gameFruit1, gameFruit2;
	Ghost redGhost;	// TODO: move this somewhere else
	int highscore;
	int currentLevel;
} PacmanGame;

//Updates the game 1 tick, or 1/60th of a second.
void game_tick(PacmanGame *game);

//Renders the game in its current state.
void game_render(PacmanGame *game);

//Returns true if the game is finished and is ready to hand back to the menu system
bool is_game_over(PacmanGame *game);

//call this at start of level 1 to initialize all entities and game objects
void gamestart_init(PacmanGame *game);

//call this at the start of each level to reinitialize all entities to a default state
void level_init(PacmanGame *game);

//Returns the length of the given integer.
int int_length(int num);