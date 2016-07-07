#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include <fcntl.h>
#include <errno.h>

#include "helpers.h"

typedef struct {
	float auxTemperature;
	float fpaTemperature;
	unsigned int min;
	unsigned int max;
	unsigned int pixel[60][80]; 
}tImage;

typedef struct {
	uint8_t bits;
	uint32_t speed;
	uint8_t mode;
	uint16_t delay;
}tConnection;

//Initialize a var of type tImage, putting all their values at 0
void initImage(tImage *image);

//Transfers one frame from the Lepton and stores it into an image
int transferImage(int fd, tImage *image, tConnection SPIconnection);

//This function is used to capture the images
tImage captureImage();

//This function is used to save the images into a .txt file
void saveImage(tImage image);

//Find the minimum RAW value into an image
unsigned int findMin(tImage image);

//Finds the maximum RAW value into an image
unsigned int findMax(tImage image);

//Save the log of the captured image
void saveLog(tImage image);
