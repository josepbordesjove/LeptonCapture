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

#define MAX_ANIMAL_ID 15
#define IMAGES_FILE "../Images/IMG_%.6d.txt"
#define LOGS_FILE "../Logs/imageLog.txt"

typedef struct {
	float auxTemperature;
	float fpaTemperature;
	unsigned int min;
	unsigned int max;
	char animalID[MAX_ANIMAL_ID];
	unsigned int pixel[60][80]; 
}tImage;

typedef struct {
	unsigned short x;
	unsigned short y;
}tCoordinate;

typedef struct {
	uint8_t bits;
	uint32_t speed;
	uint8_t mode;
	uint16_t delay;
}tConnection;

typedef struct sLog {
	unsigned int maxValue;
	unsigned int minValue;
	float auxTemperature;
	float fpaTemperature;
	char animalID[MAX_ANIMAL_ID];
	struct sLog *nextLog;
}tLogList;

//Initialize a var of type tImage, putting all their values at 0
void initImage(tImage *image);

//Transfers one frame from the Lepton and stores it into an image
int transferImage(int fd, tImage *image, tConnection SPIconnection);

//This function is used to capture the images
tImage captureImage(char ID[MAX_ANIMAL_ID]);

//This function is used to save the images into a .txt file
void saveImage(tImage image);

//Find the minimum RAW value into an image
unsigned int findMin(tImage image);

//Finds the maximum RAW value into an image
unsigned int findMax(tImage image);

//Save the log of the captured image
void saveLog(tImage image);

//Reads the logs from the file and outputs it as a file
tLogList* readLogs();

//Display the logs into the screen
void displayLogs();

//Gets an image and outputs a representative value that could be converted into temperature
 int imageTreat(tImage image);
 
 //Changes the animalID
 void changeAnimalID(tImage *image);