#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
#include "images.h"
#include "menu.h"

void pabort(const char *s);

// Used to clear the output screen
void helpers_clearScreen();

// reads a key input from the user.
char helpers_getOption();

// waits until user presses any key
void helpers_pressAnyKey();

// Parses and gets an string manually introduced by the user until it presses the Enter.
void helpers_scanText(char * property, int maxValue);

// Parses and gets an integer value manually introduced by the user.
void helpers_scanInt(int * retValue);