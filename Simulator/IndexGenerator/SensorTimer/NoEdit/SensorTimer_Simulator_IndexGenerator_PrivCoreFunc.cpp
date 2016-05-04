//Generally you need not to program this file.

#include "SensorTimer_Simulator_IndexGenerator_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=SensorTimer_Simulator_IndexGenerator_INPUTPORTSSIZE;
	outputPortsNumber=SensorTimer_Simulator_IndexGenerator_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new SensorTimer_Simulator_IndexGenerator_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new SensorTimer_Simulator_IndexGenerator_Vars());
	/*======No Need to Program======*/
}

