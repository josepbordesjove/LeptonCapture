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

#include "functions.h"
#include "helpers.h"
#include "menu.h"

typedef struct {
	float auxTemperature;
	float fpaTemperature;
	unsigned int pixel[60][80]; 
}tImage;

typedef struct {
	uint8_t bits;
	uint32_t speed;
	uint8_t mode;
	uint16_t delay;
}tConnection;

void initImage(tImage *image);
int transferImage(int fd, tImage *image, tConnection SPIconnection);
void captureImage(tImage *image);
void saveImage(tImage image);
unsigned int findMin(tImage image);
unsigned int findMax(tImage image);
