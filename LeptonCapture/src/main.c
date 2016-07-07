#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
#include "helpers.h"
#include "images.h"

const char *device = "/dev/spidev0.1";

int main(int argc, char *argv[]){
    int ret = 0;
    int fd;
	tImage image;
	tConnection SPIconnection;
	
	SPIconnection.bits = 8;
	SPIconnection.speed = 16000000;
    
    fd = open(device, O_RDWR);
    if (fd < 0){
        pabort("can't open device");
    }

    ret = ioctl(fd, SPI_IOC_WR_MODE, &SPIconnection.mode);
    ret = ioctl(fd, SPI_IOC_RD_MODE, &SPIconnection.mode);
    ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &SPIconnection.bits);
    ret = ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &SPIconnection.bits);
    ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &SPIconnection.speed);
    ret = ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &SPIconnection.speed);
    if (ret == -1){
        pabort("Something was wrong during the SPI Connection");
    }

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
