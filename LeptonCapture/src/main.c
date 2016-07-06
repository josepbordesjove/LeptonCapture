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

#include "LEPTON_SDK.h"
#include "LEPTON_SYS.h"
#include "LEPTON_Types.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

static void pabort(const char *s) {
    perror(s);
    abort();
}

bool _connected;

LEP_CAMERA_PORT_DESC_T _port;

static const char *device = "/dev/spidev0.1";
static uint8_t mode;
static uint8_t bits = 8;
static uint32_t speed = 16000000;
static uint16_t delay;

#define VOSPI_FRAME_SIZE (164)
uint8_t lepton_frame_packet[VOSPI_FRAME_SIZE];
static unsigned int lepton_image[80][80];

static void saveFile(float auxTemperature, float fpaTemperature) {
    int i;
    int j;
    unsigned int maxval = 0;
    unsigned int minval = UINT_MAX;
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

    printf("Calculating min/max values for proper scaling...\n");
    for(i=0;i<60;i++) {
        for(j=0;j<80;j++) {
            if (lepton_image[i][j] > maxval) {
                maxval = lepton_image[i][j];
            }
            if (lepton_image[i][j] < minval) {
                minval = lepton_image[i][j];
            }
        }
    }
    printf("maxval = %u\n",maxval);
    printf("minval = %u\n",minval);
	
	fprintf(f,"Aux Temperature:\t%.2f \n", auxTemperature);
	fprintf(f,"Fpa Temperature:\t%.2f \n", fpaTemperature);
    
    for(i=0;i<60;i++) {
        for(j=0;j<80;j++) {
            fprintf(f,"%d ", lepton_image[i][j]);
            fprintf(f,"\t");
        }
        fprintf(f,"\n");
    }
    fprintf(f,"\n\n");

    fclose(f);
}

int transfer(int fd){
    int ret;
    int i;
    int frame_number;
    uint8_t tx[VOSPI_FRAME_SIZE] = {0, };
    struct spi_ioc_transfer tr = {
        .tx_buf = (unsigned long)tx,
        .rx_buf = (unsigned long)lepton_frame_packet,
        .len = VOSPI_FRAME_SIZE,
        .delay_usecs = delay,
        .speed_hz = speed,
        .bits_per_word = bits,
    };

    ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
    if (ret < 1)
        pabort("can't send spi message");

    if(((lepton_frame_packet[0]&0xf) != 0x0f)) {
        frame_number = lepton_frame_packet[1];

        if(frame_number < 60 ) {
            for(i=0;i<80;i++){
                lepton_image[frame_number][i] = (lepton_frame_packet[2*i+4] << 8 | lepton_frame_packet[2*i+5]);
            }
        }
    }
    return frame_number;
}

int lepton_connect() {
	LEP_OpenPort(1, LEP_CCI_TWI, 400, &_port);
	_connected = true;
	return 0;
}

void lepton_perform_ffc() {
	if(!_connected) {
		lepton_connect();
	}
	printf("Performing FFC\n");
	LEP_RunSysFFCNormalization(&_port);
}

float lepton_read_AuxTemperature() {
	 LEP_SYS_AUX_TEMPERATURE_CELCIUS_T_PTR auxTemperaturePtr;
	 
	 float AUXTemperature = 0;
	 
	 auxTemperaturePtr = NULL;
	 
	if(!_connected) {
		lepton_connect();
	}

	LEP_GetSysAuxTemperatureKelvin(&_port, &auxTemperaturePtr);
	AUXTemperature = (int)auxTemperaturePtr/100 - 273.15;
	
	printf("AUX Temperature: %.2f\n", AUXTemperature);
	
	return AUXTemperature;
}

float lepton_read_FpaTemperature() {
	LEP_SYS_FPA_TEMPERATURE_KELVIN_T_PTR fpaTemperaturePtr ;
	float FPATemperature = 0;
	
	fpaTemperaturePtr = NULL;
	 
	if(!_connected) {
		lepton_connect();
	}
	LEP_GetSysFpaTemperatureKelvin(&_port, &fpaTemperaturePtr);
	
	FPATemperature = (int)fpaTemperaturePtr/100 - 273.15;
	
	printf("FPA Temperature: %.2f\n", FPATemperature);
	
	return FPATemperature;
}

int main(int argc, char *argv[]){
    int ret = 0;
    int fd;
	float auxTemperature = 0;
	float fpaTemperature = 0;

    fd = open(device, O_RDWR);
    if (fd < 0){
        pabort("can't open device");
    }

    ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
    if (ret == -1){
        pabort("can't set spi mode");
    }

    ret = ioctl(fd, SPI_IOC_RD_MODE, &mode);
    if (ret == -1){
        pabort("can't get spi mode");
    }

    ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
    if (ret == -1){
        pabort("can't set bits per word");
    }

    ret = ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits);
   if (ret == -1){
        pabort("can't get bits per word");
    }

    ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
    if (ret == -1){
        pabort("can't set max speed hz");
    }

    ret = ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
    if (ret == -1){
        pabort("can't get max speed hz");
    }

    printf("spi mode: %d\n", mode);
    printf("bits per word: %d\n", bits);
    printf("max speed: %d Hz (%d KHz)\n", speed, speed/1000);
	auxTemperature = lepton_read_AuxTemperature();
	fpaTemperature = lepton_read_FpaTemperature();

    while(transfer(fd)!=59){}

    close(fd);

    saveFile(auxTemperature,fpaTemperature);

    return ret;
}
