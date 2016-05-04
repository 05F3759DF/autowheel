//Generally you need not to program this file.

#include "SensorTimer_Localization_Slam_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=SensorTimer_Localization_Slam_INPUTPORTSSIZE;
	outputPortsNumber=SensorTimer_Localization_Slam_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new SensorTimer_Localization_Slam_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new SensorTimer_Localization_Slam_Vars());
	/*======No Need to Program======*/
}

