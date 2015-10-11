/*  
	Created: 14.08.2015
	Author:  Bartosz Klakla
	File:	 SteeringFunction.h
*/

#ifndef STEERINGFUNCTIONS_H_
#define STEERINGFUNCTIONS_H_

#include "Libraries.h"

/*Signs displaying pawns*/
#define PLAYER 'P'
#define ZOMBIE 'Z'
#define EMPTY ' '
#define BOMB '*'

/*Context and peripheral files*/
FILE *MenuContext_FILE;

/*Structures defining and containing needed data*/
typedef struct GameTable_Data
{
	char Table[TABLESIZE_Y][TABLESIZE_X];
	unsigned int NumberOfBombs, NumberOfZombies;
	unsigned int PreviousPosition_X, PreviousPosition_Y;
} Datas;

typedef struct SteeringStructure
{
	char *DirectionBuffer_PLAYER;
	unsigned int PlayerDirection_X, PlayerDirection_Y;
	char *ActionButton_PLAYER;
	int *ZombieDirection;
} Steering;

/*Functions which initialize structures*/
Datas Init_Data(void);
Steering Init_Steering(void);

void CreateEmptyTable(Datas *Table);


/*Other functions*/

/*ActualizeTable_PLAYER:	Actualizing the game table for player position
 *Parameters:				Two structs gathering data = {character buffer, game table}*/
void ActualizeTable_PLAYER(Steering *PlayerDirection_Struct, Datas *GameTable_Struct);

/*ConsiderDirection:	Function checking which direction has been chosen
 *Parameter:			BufferSign - Gathers all signs defined by buffer and struct (?)
 *Returns:				Direction - integer variable (will be added to position)*/
void ConsiderDirection(Steering *PlayerDirection_Struct, int RoundCounter, Datas *PrevDir);

/*Randomize_Zombies:	Create random number of Zombies on a table
 *Parameter:			Structure containing number of Zombies*/
void Randomize_Zombies(Datas *ZombieNumber);

/*Randomize_Bombss:		Create random number of bombs on a table
 *Parameter:			Structure containing number of bombs*/
int Randomize_Bombs(Datas BombsNumber, int RoundCounter);

/*PlaceWalls:		Place the random generated bombs (dots) in random places
 *Parameter:		GameTable as structure GameTable_Data*/
void PlaceBombs(Datas *GameTable, int RoundCounter);

/*CountDistance_ZombiePlayer:	Counts the distance between Zombie and Player
 *Parameter:					Struct with game table
 *Returns:						Distance between (NO UNSIGNED!! Minus needed!!)*/
int CountDistance_ZombiePlayer(Datas GameTable);

/*MovePawns:	Changing positions of both Zombies and Player
 *Parameter:	Struct containing game table
				Distance between Player and every Zombie (gathered in table: "SomeTable")*/
void MovePawns(Datas GameTable, int ZP_Distance);

/*ReadKeyboardBuffer:	Reads the buffer from keyboard and place it in structure
 *Parameter:			Structure with characters table for Player direction*/
void ReadKeyboardBuffer(Steering *DirBuffer, int RoundCounter);

/*ClearBuffer:		Clears the buffer by filling it with white characters
 *Parameter:		Structures containing the buffer*/
void ClearBuffer(Steering DirBuffer);


/*Functions that display or handle the screen*/

/*DisplayTable:		Function which display the actual state of game table
 *Parameter:		Structure containing the game table*/
void DisplayTable(Datas *GameTable);

/*DisplayMenu:	Displays MENU from outlying .txt file
 *Returns:		Decision - int variable which contains decision that player has made */
int DisplayMenu(FILE *MenuContext_FILE);

#endif