#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "SPI.h"

int startConnection(int *fd, tConnection *SPIconnection) {
    const char *device = "/dev/spidev0.1";
    int ret = 0;
    
    fd = open(device, O_RDWR);
    if (fd < 0){
        pabort("can't open device");
    }

    ret = ioctl(fd, SPI_IOC_WR_MODE, &SPIconnection.mode);
    if (ret == -1){
        pabort("can't set spi mode");
    }

    ret = ioctl(fd, SPI_IOC_RD_MODE, &SPIconnection.mode);
    if (ret == -1){
        pabort("can't get spi mode");
    }

    ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &SPIconnection.bits);
    if (ret == -1){
        pabort("can't set bits per word");
    }

    ret = ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &SPIconnection.bits);
   if (ret == -1){
        pabort("can't get bits per word");
    }

    ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &SPIconnection.speed);
    if (ret == -1){
        pabort("can't set max speed hz");
    }

    ret = ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &SPIconnection.speed);
    if (ret == -1){
        pabort("can't get max speed hz");
    }
    
    return ret;
}