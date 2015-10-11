/*  
	Created: 17.08.2015
	Author:  Bartosz Klakla
	File:	 SteeringFunction.c
*/

#include "SteeringFunctions.h"


/*DisplayMenu*/
int DisplayMenu(FILE *MenuContext_FILE)
{
	unsigned int Decision = 0;
	char FileSign = 0;

	MenuContext_FILE = fopen("Context.txt", "r");
	if(MenuContext_FILE == NULL)
	{
		printf("Couldn't open the file with context\nMenu won't be displayed!\n");
		return EXIT_FAILURE;
	}
	else
	{
		while(FileSign != EOF)
			printf("%c", (FileSign = getc(MenuContext_FILE)));
		scanf("%d", &Decision);
		fclose(MenuContext_FILE);
		return Decision;
	}
}


/*Init_Data*/
Datas Init_Data()
{
	Datas NewTemporaryStruct;
	NewTemporaryStruct.NumberOfBombs = 0;
	NewTemporaryStruct.NumberOfZombies = 0;
	NewTemporaryStruct.PreviousPosition_X = START_POS_X;
	NewTemporaryStruct.PreviousPosition_Y = START_POS_Y;
	return NewTemporaryStruct;
}


/*Init_Steering*/
Steering Init_Steering()
{
	Steering NewTemporaryStruct;
	NewTemporaryStruct.DirectionBuffer_PLAYER = (char*)malloc(MAX_CHAR_BUFFER*sizeof(char));
	NewTemporaryStruct.PlayerDirection_X = START_POS_X;
	NewTemporaryStruct.PlayerDirection_Y = START_POS_Y;
	NewTemporaryStruct.ZombieDirection = (int*)malloc(MAX_ZOMBIE_NUMBER*sizeof(int));
	NewTemporaryStruct.ActionButton_PLAYER = (char*)malloc(MAX_CHAR_BUFFER*sizeof(char));

	return NewTemporaryStruct;
}


/*CreateEmptyTable*/
void CreateEmptyTable(Datas *Table)
{
	int CounterX = 0, CounterY = 0;
	for(CounterY = 0; CounterY < TABLESIZE_Y; CounterY++)
		for(CounterX = 0; CounterX < TABLESIZE_X; CounterX++)
			Table->Table[CounterY][CounterX] = EMPTY;
}


/*DisplayTable*/
void DisplayTable(Datas *GameTable)
{
	int CounterX = 0, CounterY = 0;
	for(CounterY = 0; CounterY < TABLESIZE_Y; CounterY++)
	{
		for(CounterX = 0; CounterX < TABLESIZE_X; CounterX++)
			printf("%c", GameTable->Table[CounterY][CounterX]);
		printf("\n");
	}
}


/*ActualizeTable_PLAYER*/
void ActualizeTable_PLAYER(Steering *PlayerDirection_Struct, Datas *GameTable_Struct)
{
	if(PlayerDirection_Struct -> PlayerDirection_Y == GameTable_Struct -> PreviousPosition_Y && 
	   PlayerDirection_Struct -> PlayerDirection_X == GameTable_Struct -> PreviousPosition_X)
	GameTable_Struct -> Table[PlayerDirection_Struct -> PlayerDirection_Y]
							 [PlayerDirection_Struct -> PlayerDirection_X]
							 = PLAYER;
	else
	{
		GameTable_Struct -> Table[PlayerDirection_Struct -> PlayerDirection_Y]
								 [PlayerDirection_Struct -> PlayerDirection_X]
								 = PLAYER;
		GameTable_Struct -> Table[GameTable_Struct -> PreviousPosition_Y]
								 [GameTable_Struct -> PreviousPosition_X]
								 = EMPTY;
	}
}


/*ReadKeyboardBuffer*/
void ReadKeyboardBuffer(Steering *DirBuffer, int RoundCounter)
{
	char Sign = NULL;
	if(kbhit())
	{
		Sign = getch();
		DirBuffer -> ActionButton_PLAYER[RoundCounter] = Sign;
	}
}


/*ConsiderDirection*/
void ConsiderDirection(Steering *DirBuffer, int RoundCounter, Datas *PrevDir)
{
	PrevDir -> PreviousPosition_Y = DirBuffer -> PlayerDirection_Y;
	PrevDir -> PreviousPosition_X = DirBuffer -> PlayerDirection_X;

	switch(DirBuffer -> ActionButton_PLAYER[RoundCounter])
	{
	case 'w': DirBuffer -> PlayerDirection_Y--;
		break;
	case 's': DirBuffer -> PlayerDirection_Y++;
		break;
	case 'd': DirBuffer -> PlayerDirection_X++;
		break;
	case 'a': DirBuffer -> PlayerDirection_X--;
		break;
	default:
		break;
	}
}


/*ClearBuffer*/
void ClearBuffer(Steering DirBuffer)
{
	unsigned int Counter = 0;
	for(Counter = 0; Counter < MAX_CHAR_BUFFER; Counter++)
		DirBuffer.ActionButton_PLAYER[Counter] = EMPTY;
}


/*Randomize_Bombs*/
int Randomize_Bombs(Datas WallsNumber, int RoundCounter)
{
	RoundCounter++;
	srand(time(NULL));
	WallsNumber.NumberOfBombs = rand()%MAX_BOMBS_NUMBER/RoundCounter;
	
	return WallsNumber.NumberOfBombs;
}


/*PlaceBombs*/
void PlaceBombs(Datas *GameTable, int RoundCounter)
{
	unsigned int WallPosition_X = 0, WallPosition_Y = 0, Counter = 0;
	int BombsNumber = Randomize_Bombs(*GameTable, RoundCounter);
	for(Counter = 0; Counter < BombsNumber; Counter++)
	{
		WallPosition_X = rand()%TABLESIZE_X;
		WallPosition_Y = rand()%TABLESIZE_Y;
		GameTable -> Table[WallPosition_Y][WallPosition_X] = BOMB;
	}

	system("PAUSE");
}


/*Randomize_Zombies*/
void Randomize_Zombies(Datas *ZombieStruct)
{
	unsigned int ZombiePosition_X = TABLESIZE_X,
				 ZombieCounter = 0,
				 ZombiePosition_Y = 0,
				 NumberZ = rand()%MAX_BOMBS_NUMBER;
	
	ZombieStruct -> NumberOfZombies = NumberZ;

	for(ZombieCounter = 0; ZombieCounter <= NumberZ; ZombieCounter++)
	{
		ZombiePosition_Y = rand()%TABLESIZE_Y;
		ZombieStruct -> Table[ZombiePosition_Y][ZombiePosition_X] = ZOMBIE;
	}
}
