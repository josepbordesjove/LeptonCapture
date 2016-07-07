#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
#include "helpers.h"
#include "images.h"
#include "menu.h"

int main(int argc, char *argv[]){
	tImage image;
	char option;
	
	initImage(&image);

	option = mainMenu();
	
	while (option != '0') {
		if (option == '1') {
			helpers_clearScreen();
			image = captureImage();
			helpers_pressAnyKey();
		}else if (option == '2') {
			helpers_clearScreen();
			printf("Selected option 3\n");
			helpers_pressAnyKey();
		}else if (option == '3') {
			helpers_clearScreen();
			printf("Selected option 3\n");
			helpers_pressAnyKey();
		}
		option = mainMenu();
	}

    return 0;
}
