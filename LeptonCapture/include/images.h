#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include <limits.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <errno.h>

#include "helpers.h" 

typedef struct {
	float auxTemperature;
	float fpaTemperature;
	unsigned int pixel[60][80]; 
}tImage;

void initImage(tImage *image);
int transferImage(int fd, tImage *image, tConnection SPIconnection);
void saveImage(tImage image);
unsigned int findMin(tImage image);
unsigned int findMax(tImage image);
