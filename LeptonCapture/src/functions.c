#include "LEPTON_SDK.h"
#include "LEPTON_SYS.h"
#include "LEPTON_Types.h"

#include "images.h"
#include "helpers.h"
#include "functions.h"

bool _connected;

LEP_CAMERA_PORT_DESC_T _port;
 
 /*
 * Function:    lepton_connect
 * Description: Used to connect the lepton and the raspberry via i2c
 * Arguments:   ---
 * Returns:     ---
 */
int lepton_connect() {
	LEP_OpenPort(1, LEP_CCI_TWI, 400, &_port);
	_connected = true;
	return 0;
}

/*
 * Function:    lepton_perform_ffc
 * Description: This funciont makes the lepton perform the ffc
 * Arguments:   ---
 * Returns:     ---
 */
void lepton_perform_ffc() {
	if(!_connected) {
		lepton_connect();
	}
	LEP_RunSysFFCNormalization(&_port);
	printf("Performing FFC... OK\n");
}

/*
 * Function:    lepton_read_AuxTemperature
 * Description: Used to get the aux temperature from the lepton
 * Arguments:   ---
 * Returns:     A float value that represents the auxTemperature
 */
int lepton_read_AuxTemperature() {
	 LEP_SYS_AUX_TEMPERATURE_CELCIUS_T_PTR auxTemperaturePtr;
		
	 auxTemperaturePtr = NULL;
	 
	if(!_connected) {
		lepton_connect();
	}

	LEP_GetSysAuxTemperatureKelvin(&_port, &auxTemperaturePtr);
	
	return (int)auxTemperaturePtr;
}

/*
 * Function:    lepton_read_FpaTemperature
 * Description: Used to read the fpa temperature from the lepton
 * Arguments:   ---
 * Returns:     A float value that represents the fpa temperature
 */
int lepton_read_FpaTemperature() {
	LEP_SYS_FPA_TEMPERATURE_KELVIN_T_PTR fpaTemperaturePtr;
	
	fpaTemperaturePtr = NULL;
	 
	if(!_connected) {
		lepton_connect();
	}
	LEP_GetSysFpaTemperatureKelvin(&_port, &fpaTemperaturePtr);
	
	return fpaTemperaturePtr;
}