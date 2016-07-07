#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>

#include "functions.h"
#include "helpers.h"
#include "images.h"
#include "menu.h"

#define VOSPI_FRAME_SIZE (164)
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

const char *device = "/dev/spidev0.1";

void initImage(tImage *image) {
	int i;
	int j;
	
	for(i=0;i<60;i++) {
        for(j=0;j<80;j++) {
            image->pixel[i][j] = 0;
        }
    }
	
	image->auxTemperature = 0;
	image->fpaTemperature = 0;
}

void saveImage(tImage image) {
    int i;
    int j;
    char image_name[32];
    int image_index = 0;

    do {
        sprintf(image_name, "../Images/IMG_%.4d.txt", image_index);
        image_index += 1;
        if (image_index > 9999) {
            image_index = 0;
            break;
        }

    } while (access(image_name, F_OK) == 0);

    FILE *f = fopen(image_name, "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
	
	fprintf(f,"Aux Temperature:\t%.2f \n", image.auxTemperature);
	fprintf(f,"Fpa Temperature:\t%.2f \n", image.fpaTemperature);
    
    for(i=0;i<60;i++) {
        for(j=0;j<80;j++) {
            fprintf(f,"%d ", image.pixel[i][j]);
            fprintf(f,"\t");
        }
        fprintf(f,"\n");
    }
    fprintf(f,"\n\n");

    fclose(f);
}

unsigned int findMin(tImage image) {
	unsigned int minval = 20000;
	int i;
    int j;
	
	printf("Calculate the min\n");
    for(i=0;i<60;i++) {
        for(j=0;j<80;j++) {
            if (image.pixel[i][j] < minval) {
				minval = image.pixel[i][j];
            }
        }
    }
    printf("minval = %u\n",minval);
	
	return minval;
}

unsigned int findMax(tImage image) {
	unsigned int maxval = 0;
	    int i;
    int j;
	
	printf("Calculate the max\n");
    for(i=0;i<60;i++) {
        for(j=0;j<80;j++) {
            if (image.pixel[i][j] > maxval) {
				maxval = image.pixel[i][j];
            }
        }
    }
    printf("maxval = %u\n",maxval);
	
	return maxval;
}

int transferImage(int fd, tImage *image, tConnection SPIconnection) {
    int ret;
    int i;
    int frame_number;
    uint8_t tx[VOSPI_FRAME_SIZE] = {0, };
	uint8_t lepton_frame_packet[VOSPI_FRAME_SIZE];
	
    struct spi_ioc_transfer tr = {
        .tx_buf = (unsigned long)tx,
        .rx_buf = (unsigned long)lepton_frame_packet,
        .len = VOSPI_FRAME_SIZE,
        .delay_usecs = SPIconnection.delay,
        .speed_hz = SPIconnection.speed,
        .bits_per_word = SPIconnection.bits,
    };

    ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
    if (ret < 1)
        pabort("can't send spi message");

    if(((lepton_frame_packet[0]&0xf) != 0x0f)) {
        frame_number = lepton_frame_packet[1];

        if(frame_number < 60 ) {
            for(i=0;i<80;i++){
                image->pixel[frame_number][i] = (lepton_frame_packet[2*i+4] << 8 | lepton_frame_packet[2*i+5]);
            }
        }
    }
    return frame_number;
}

void captureImage(tImage *image) {
    int ret = 0;
    int fd;
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
    

}