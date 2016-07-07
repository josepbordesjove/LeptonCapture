#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"
#include "helpers.h"
#include "images.h"
#include "menu.h"

/* 
 * Function:    vwrMenu_mainMenu
 * Description: Displays the Race Viewer main menu with the available operations
 * Arguments:   ---
 * Returns:     The option the user selected.
 */
char vwrMenu_mainMenu()
{
	int version;
	char option;
	
	helpers_clearScreen();
	
	version = ops_getVersion();
	
	printf("\nWelcome to the UOC Race Viewer application!\n");
	printf("\n------------------------------------\n\n");
	printf("Library version: %d\n\n", version);
	
	printf("Please, select a menu option:\n\n");
	printf("1. List all races \n");
	printf("2. View subscribed races\n");
	printf("\n");
	printf("0. Exit\n\n");
	
	option = helpers_getOption();
	
	return option;
}