#ifndef LIBRARIES_H_
#define LIBRARIES_H_

#define _CRT_SECURE_NO_WARNINGS

/*Definition of Izabelka*/
#ifndef IZABELKA
#define IZABELKA_NAME 'I'
#define IZABELKA 'IS SWEET!'
#endif

/*Size of game table*/
#define TABLESIZE_X 30
#define TABLESIZE_Y 15

/*Player starting position*/
#define START_POS_X 20
#define START_POS_Y 14

/*Maximum number of zombies*/
#define MAX_ZOMBIE_NUMBER 20
#define MAX_BOMBS_NUMBER 15

/*Maximum number of characters player can input to keyboard buffer*/
#define MAX_CHAR_BUFFER 10

/*Time in milliseconds for block to wait to read another sign*/
#define MAX_TIME_MS 50

/*Included libraries*/
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

#endif