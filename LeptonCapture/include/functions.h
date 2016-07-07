#include "LEPTON_SDK.h"
#include "LEPTON_SYS.h"
#include "LEPTON_Types.h"

//Connect the lepton with the Raspberry for the i2c communication
int lepton_connect();

//Performs the FFC
void lepton_perform_ffc();

//Reads the Aux Temperature from the Lepton
float lepton_read_AuxTemperature();

//Reads the FPA temperature from the Lepton
float lepton_read_FpaTemperature();