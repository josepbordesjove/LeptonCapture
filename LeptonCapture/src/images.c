#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <string.h> 

#include "images.h"
#include "helpers.h"
#include "functions.h"

#define VOSPI_FRAME_SIZE (164)
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

/*
 * Function:    initImage
 * Description: For a input image, this function makes all its value equal to zero
 * Arguments:   (in/out) image: tImage
 * Returns:     ---
 */
void initImage(tImage *image) {
	int i;
	int j;
	
	image = (tImage *)malloc(sizeof(tImage));
	
	for(i=0;i<60;i++) {
        for(j=0;j<80;j++) {
            image->pixel[i][j] = 0;
        }
    }
	
	image->auxTemperature = 0;
	image->fpaTemperature = 0;
	image->min = 0;
	image->max = 0;
}

/*
 * Function:    saveImage
 * Description: Saves the image inisde a .txt FILE
 * Arguments:   (in) image: tImage
 * Returns:     ---
 */
void saveImage(tImage image) {
    int i;
    int j;
    char image_name[32];
    int image_index = 0;

    do {
        sprintf(image_name, IMAGES_FILE, image_index);
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
	fprintf(f,"Max RAW Value:\t\t%.2d \n", image.max);
	fprintf(f,"Min RAW Value:\t\t%.2d \n", image.min);
	fprintf(f,"Animal ID is: \t\t%s \n", image.animalID);
    
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

/*
 * Function:    findMin
 * Description: Finds the minimum value of one image
 * Arguments:   (in) image: tImage
 * Returns:     Unsigned int that represents the minimum value of an image
 */
unsigned int findMin(tImage image) {
	unsigned int minval = 20000;
	int i;
    int j;
	
    for(i=0;i<60;i++) {
        for(j=0;j<80;j++) {
            if (image.pixel[i][j] < minval) {
				minval = image.pixel[i][j];
            }
        }
    }
	return minval;
}

/*
 * Function:    findMax
 * Description: Finds the maximum value of one image
 * Arguments:   (in) image: tImage
 * Returns:     Unsigned int that represents the maximum value of an image
 */
unsigned int findMax(tImage image) {
	unsigned int maxval = 0;
	    int i;
    int j;
	
    for(i=0;i<60;i++) {
        for(j=0;j<80;j++) {
            if (image.pixel[i][j] > maxval) {
				maxval = image.pixel[i][j];
            }
        }
    }
	return maxval;
}

/*
 * Function:    transferImage
 * Description: Reads one line of the image via SPI and stores it into var of type image
 * Arguments:   (in) fd: int, (in/out) image: tImage, (in) SPIconnection: tConnection
 * Returns:     An intger that represents which line of the image has been read
 */
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

/*
 * Function:    captureImage
 * Description: Captures an entire imagr from the camera
 * Arguments:   ---
 * Returns:     A var of type tImage that represents the captured image with some metadata
 */
tImage captureImage(char ID[MAX_ANIMAL_ID]) {
	const char *device = "/dev/spidev0.1";
    int ret = 0;
    int fd;
	tImage image;
	tConnection SPIconnection;
	
	strcpy(image.animalID, ID);
	
	//Initialize the values inside the image
	initImage(&image);
	
	//Setup some parametrs of SP communication
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

	while(transferImage(fd, &image, SPIconnection) != 59){}
    
	image.auxTemperature = (float)lepton_read_AuxTemperature()/100 - 273.15;
	image.fpaTemperature = (float)lepton_read_FpaTemperature()/100 - 273.15;
	image.min = findMin(image);
	image.max = findMax(image);

    close(fd);
	if(image.min > 2000 && image.max < 20000 ){
		saveImage(image);
		saveLog(image);
		
		printf("Aux Temperature: \t%.2f\n", image.auxTemperature);
		printf("Fpa Temperature: \t%.2f\n", image.fpaTemperature);
		printf("Max RAW Value: \t\t%04d\n", image.max);
		printf("Min RAW Value: \t\t%04d\n", image.min);
	} else {
		printf("Please try again, something wrong happened\n");
		initImage(&image);
	}

	return image;
}

/*
 * Function:    saveLog
 * Description: Saves a summary of the captured image, it will help to convert the data into temperatures
 * Arguments:   (in) image: tImage
 * Returns:     ---
 */
void saveLog(tImage image){
    //Create a variable that will contain the local adress to the file
    FILE *outputFile;
	
    //Open the file in write mode
    outputFile = fopen(LOGS_FILE, "a");
    
    //If the variable output is null , it means the file could not has been created or opened, so finish the action 
    if (outputFile == NULL) {
        return;
    }
    
	//Save the data in the specified format
	fprintf(outputFile, "%s;%05d;%05d;%04.0f;%04.0f\n", image.animalID,
														findMax(image),
														findMin(image),
														image.fpaTemperature*100,
														image.auxTemperature*100);
	
    //Close the file
    fclose(outputFile);
}

/*
 * Function:    readLog
 * Description: Reads the log file to be able to display it into the screen
 * Arguments:   ---
 * Returns:     A list of logs of type tLogList
 */
tLogList* readLogs() {
	FILE *inputFile;
	tLogList *currentLog;
	tLogList *retValue;
	int endOfFile;
		
	retValue = NULL;
	endOfFile = 1;
	
	inputFile = fopen(LOGS_FILE, "r");
	if (inputFile == NULL) {
		return NULL;
	}
	
	while (endOfFile != EOF) {
		currentLog = (tLogList *)malloc(sizeof(tLogList));
		currentLog->nextLog = NULL;
		memset(currentLog->animalID, 0, MAX_ANIMAL_ID);
		
		if (retValue == NULL) {
			retValue = currentLog;
		}
		
		endOfFile = fscanf(inputFile, "%[^;];%d;%d;%f;%f\n", 	currentLog->animalID, 
																&currentLog->maxValue,
																&currentLog->minValue,
																&currentLog->fpaTemperature,
																&currentLog->auxTemperature);
		currentLog = currentLog->nextLog;
	}
	
	
	fclose(inputFile);
	
	return retValue;
}

/*
 * Function:    displayLogs
 * Description: Display the logs 
 * Arguments:   ---
 * Returns:     ---
 */
void displayLogs() {
	tLogList *log;
	
	log = readLogs();
	
	if (log != NULL) {
		while(log != NULL) {
			printf("\nThese are the logs of the images captures, press enter to see the next log\n");
			printf("--------------------------------------------------------------------------\n\n");
		
			printf("Animal ID: \t\t%s\n", log->animalID);
			printf("RAW value: \t\t%05d\n", log->maxValue);
			printf("RAW value: \t\t%05d\n", log->minValue);
			printf("FPA temperature: \t%04.2f\n", log->fpaTemperature);
			printf("AUX temperature: \t%04.2f\n", log->auxTemperature);
			
			helpers_pressAnyKey();
			helpers_clearScreen();
			
			log = log->nextLog;
		}
	} else {
		printf("The log file is empty\n\n");
	}
}

/*
 * Function:    imageTreat
 * Description: For a given image this algorithm analyze it and return a representative value of it
 * Arguments:   (in) image: tImage
 * Returns:     An integer that represents a significant value of the image
 */
int imageTreat(tImage image) {
	int RAWresult = 0;
	
	RAWresult = findMax(image);
	
	return RAWresult;
}


/*
 * Function:    changeAnimalID
 * Description: For a given image, it changes the animal ID
 * Arguments:   (in/out) image: tImage
 * Returns:     ---
 */
void changeAnimalID(tImage *image) {
	char introducedID[MAX_ANIMAL_ID];
	
	memset(introducedID, 0, MAX_ANIMAL_ID);
	
	printf("Please, introduce the new animal ID: \n");
	
	getchar();
	helpers_scanText(introducedID, MAX_ANIMAL_ID);
	
	if (strlen(introducedID) == MAX_ANIMAL_ID-1) {
		strcpy(image->animalID, introducedID);
		helpers_clearScreen();
		printf("Animal ID changed succesfully\n\n");
	} else {
		helpers_clearScreen();
		printf("The ID is shorter or longer than it should be.\nPlease be sure that it is 15 characters long\n\n");
	}
	
}