//Generally you need not to program this file.

#include "SensorTimer_Gazebo_Odom_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=SensorTimer_Gazebo_Odom_INPUTPORTSSIZE;
	outputPortsNumber=SensorTimer_Gazebo_Odom_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new SourceDrainMono_Sensor_stm32comm_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new SensorTimer_Gazebo_Odom_Vars());
	/*======No Need to Program======*/
}

