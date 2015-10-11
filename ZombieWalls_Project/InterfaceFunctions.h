#ifndef INTERFACEFUNCTIONS_H_
#define INTERFACEFUNCTIONS_H_

#include "Libraries.h"

/*Signs displaying pawns*/
#define PLAYER 'P'
#define ZOMBIE 'Z'
#define EMPTY ' '
#define BOMB '*'

/*Context and peripheral files*/
FILE *MenuContext_FILE;

/*DisplayMenu:	Displays MENU from outlying .txt file
 *Returns:		Decision - int variable which contains decision that player has made */
int DisplayMenu(FILE *MenuContext_FILE);



#endif