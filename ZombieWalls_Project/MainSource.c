#include "SteeringFunctions.h"
#include "InterfaceFunctions.h"

int main(void)
{
	/*Initializating the structures*/
	Datas GameData = Init_Data();
	Steering GameSteering = Init_Steering();

	int RoundCounter = 0;

	
	/*Main body of the game*/
	printf("\n%d\n", DisplayMenu(MenuContext_FILE));
	CreateEmptyTable(&GameData);
	PlaceBombs(&GameData, RoundCounter);
	Randomize_Zombies(&GameData);
	
	while(1)
	{
		Sleep(MAX_TIME_MS);
		ReadKeyboardBuffer(&GameSteering, RoundCounter);
		ActualizeTable_PLAYER(&GameSteering, &GameData);
		ConsiderDirection(&GameSteering, RoundCounter, &GameData);
		system("cls");
		DisplayTable(&GameData);
		RoundCounter++;
		
		if(RoundCounter == 9)
		{
			ClearBuffer(GameSteering);
			RoundCounter = 0;
		}
	}
	

	/*Cleaning the memory taken by allocation*/
	free(GameSteering.DirectionBuffer_PLAYER);
	free(GameSteering.ZombieDirection);
	
	/*End of program*/
	system("PAUSE");
	return EXIT_SUCCESS;
}
