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
float lepton_read_AuxTemperature() {
	 LEP_SYS_AUX_TEMPERATURE_CELCIUS_T_PTR auxTemperaturePtr;
	 
	 float AUXTemperature = 0;
	 
	 auxTemperaturePtr = NULL;
	 
	if(!_connected) {
		lepton_connect();
	}

	LEP_GetSysAuxTemperatureKelvin(&_port, &auxTemperaturePtr);
	AUXTemperature = (int)auxTemperaturePtr/100 - 273.15;
	
	printf("AUX Temperature: %.2f\t\n", AUXTemperature);
	
	return AUXTemperature;
}

/*
 * Function:    lepton_read_FpaTemperature
 * Description: Used to read the fpa temperature from the lepton
 * Arguments:   ---
 * Returns:     A float value that represents the fpa temperature
 */
float lepton_read_FpaTemperature() {
	LEP_SYS_FPA_TEMPERATURE_KELVIN_T_PTR fpaTemperaturePtr ;
	float FPATemperature = 0;
	
	fpaTemperaturePtr = NULL;
	 
	if(!_connected) {
		lepton_connect();
	}
	LEP_GetSysFpaTemperatureKelvin(&_port, &fpaTemperaturePtr);
	
	FPATemperature = (int)fpaTemperaturePtr/100 - 273.15;
	
	printf("FPA Temperature: %.2f\t\n", FPATemperature);
	
	return FPATemperature;
}