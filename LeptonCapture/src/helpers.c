#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
#include "helpers.h"
#include "images.h"
#include "menu.h"

/*
 * Function:    pabort
 * Description: Used to abort the program execution
 * Arguments:   ---
 * Returns:     ---
 */
void pabort(const char *s) {
    perror(s);
    abort();
}

/*
 * Function:    helpers_clearScreen
 * Description: Used to clear the output screen
 * Arguments:   ---
 * Returns:     ---
 */
void helpers_clearScreen(){
    system("clear");
}

/*
 * Function:    helpers_getOption
 * Description: reads a key input from the user.
 * Arguments:   ---
 * Returns:     The character pressed by the user
 */
char helpers_getOption(){
    char retValue;

    retValue = getchar();
    fflush(stdin);

    return retValue;
}


/*
 * Function:    helpers_pressAnyKey
 * Description: waits until user presses any key
 * Arguments:   ---
 * Returns:     ---
 */
void helpers_pressAnyKey(){
    printf("\nPress any key to continue.\n");

    getchar();
    fflush(stdin);

}

/*
 * Function:    helpers_scanText
 * Description: Parses and gets an string manually introduced by the user until it presses the Enter.
 * Arguments:   property: Upon return, the pointer to the captured string
 * 			    maxValue: The maximum string length to parse.
 * Returns:     ---
 */
void helpers_scanText(char * property, int maxValue) {
    int i;
    char c;
    
    i = 0;
    c = getchar();
    while ((i < maxValue - 1) && (c != '\n')) {
        // Concatenate the characters until 'Enter' or string maximum length
        property[i] = c;
        i++;
        c = getchar();
    }
    
    fflush(stdin);
}

/*
 * Function:    helpers_scanInt
 * Description: Parses and gets an integer value manually introduced by the user.
 * Arguments:   retValue: Upon return, the captured integer value
 * Returns:     ---
 */
void helpers_scanInt(int * retValue) {
    scanf("%d", retValue);
    fflush(stdin);
}