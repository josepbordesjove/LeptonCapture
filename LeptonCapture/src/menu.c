#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "functions.h"
#include "helpers.h"
#include "images.h"

/* 
 * Function:    vwrMenu_mainMenu
 * Description: Displays the Race Viewer main menu with the available operations
 * Arguments:   ---
 * Returns:     The option the user selected.
 */
char mainMenu() {
	char option;
	
	helpers_clearScreen();
	
	printf("\nThis is a FLiR Lepton Application to capture and analize images\n");
	printf("---------------------------------------------------------------\n\n");
	printf("Lepton SDK: August 28, 2014\n");
	
	printf("Select an option:\n\n");
	printf("1. Capture image \n");
	printf("2. Options\n");
	printf("\n");
	printf("0. Exit\n\n");
	
	option = helpers_getOption();
	
	return option;
}