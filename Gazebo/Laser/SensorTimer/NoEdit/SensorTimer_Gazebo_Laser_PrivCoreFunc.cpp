//Generally you need not to program this file.

#include "SensorTimer_Gazebo_Laser_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=SensorTimer_Gazebo_Laser_INPUTPORTSSIZE;
	outputPortsNumber=SensorTimer_Gazebo_Laser_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new SensorTimer_Sensor_Laser_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new SensorTimer_Gazebo_Laser_Vars());
	/*======No Need to Program======*/
}

