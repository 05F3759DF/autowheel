//Generally you need not to program this file.

#include "SourceDrainMono_Sensor_stm32comm_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=SourceDrainMono_Sensor_stm32comm_INPUTPORTSSIZE;
	outputPortsNumber=SourceDrainMono_Sensor_stm32comm_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new SourceDrainMono_Sensor_stm32comm_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new SourceDrainMono_Sensor_stm32comm_Vars());
	/*======No Need to Program======*/
}

