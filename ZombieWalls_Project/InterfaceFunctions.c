#include "InterfaceFunctions.h"


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

