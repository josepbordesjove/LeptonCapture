#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
#include "helpers.h"
#include "images.h"
#include "menu.h"

const char *device = "/dev/spidev0.1";

int main(int argc, char *argv[]){
    tImage image;
    
    captureImage(&image)
    saveImage(image);

    return 0;
}
