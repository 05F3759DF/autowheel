//Generally you need not to program this file.

#include "VisualizationMulti_Calibration_Laser_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=VisualizationMulti_Calibration_Laser_INPUTPORTSSIZE;
	outputPortsNumber=VisualizationMulti_Calibration_Laser_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new VisualizationMono_Sensor_Laser_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new VisualizationMulti_Calibration_Laser_Vars());
	/*======No Need to Program======*/
}

