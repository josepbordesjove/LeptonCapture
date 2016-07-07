#include "LEPTON_SDK.h"
#include "LEPTON_SYS.h"
#include "LEPTON_Types.h"
#include "functions.h"

bool _connected;

LEP_CAMERA_PORT_DESC_T _port;
 
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