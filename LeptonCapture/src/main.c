#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
#include "helpers.h"
#include "images.h"
#include "SPI.h"

int main(int argc, char *argv[]){
    int ret = 0;
    int fd;
	tImage image;
	tConnection SPIconnection;
	
	SPIconnection.bits = 8;
	SPIconnection.speed = 16000000;

    ret = startConnection(&fd, &SPIconnection);

    printf("spi mode: %d\n", SPIconnection.mode);
    printf("bits per word: %d\n", SPIconnection.bits);
    printf("max speed: %d Hz (%d KHz)\n", SPIconnection.speed, SPIconnection.speed/1000);

	while(transferImage(fd, &image, SPIconnection) != 59){}
    
	image.auxTemperature = lepton_read_AuxTemperature();
	image.fpaTemperature = lepton_read_FpaTemperature();

    close(fd);
	
	saveImage(image);

    return ret;
}
