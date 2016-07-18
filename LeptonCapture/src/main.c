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
	int numberOfImages = 10;
	int i;
	char option;
	
	strcpy(image.animalID, "NNNNNNNNNNNNNNN");
	
	//Show the menu options
	option = mainMenu();
	
	//Run an action depending on the selected option
	while (option != '0') {
		if (option == '1') {
			helpers_clearScreen();
			for (i = 1; i <= numberOfImages; i++) {
				image = captureImage(image.animalID);
				printf("\n");
			}
			printf("\n%d images saved\n", numberOfImages);
			helpers_pressAnyKey();
		} else if (option == '2') {
			helpers_clearScreen();
			lepton_perform_ffc();
			helpers_pressAnyKey();
		} else if (option == '3') {
			helpers_clearScreen();
			changeAnimalID(&image);
			helpers_pressAnyKey();
		} else if (option == '4') {
			helpers_clearScreen();
			displayLogs();
			helpers_pressAnyKey();
		} else {
			helpers_clearScreen();
			printf("No function available for this input\n");
			helpers_pressAnyKey();
		}
		option = mainMenu();
	}

    return 0;
}
