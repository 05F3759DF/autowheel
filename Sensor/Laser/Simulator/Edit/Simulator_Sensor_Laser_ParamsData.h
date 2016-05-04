//You need to modify this file.

#ifndef SIMULATOR_SENSOR_LASER_PARAMSDATA_H
#define SIMULATOR_SENSOR_LASER_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_Laser_ParamsData Simulator_Sensor_Laser_ParamsData
	\ingroup Simulator_Sensor_Laser
	\brief Simulator_Sensor_Laser_ParamsData defines the ParamsData in Simulator_Sensor_Laser.
*/

/*! \addtogroup Simulator_Sensor_Laser_ParamsData
	@{
*/

/*! \file Simulator_Sensor_Laser_ParamsData.h
	 Defines the ParamsData of Simulator_Sensor_Laser
*/

//*******************Please add other headers below*******************


//There is no input data headers.

/*! \def Simulator_Sensor_Laser_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define Simulator_Sensor_Laser_INPUTPORTSSIZE QList<int>()

//The Params SensorTimer_Sensor_Laser_Params is defined in the header below
#include<wheelchair/Sensor/Laser/SensorInternalEvent/Edit/SensorInternalEvent_Sensor_Laser_ParamsData.h>

//The Output Data SensorTimer_Sensor_Laser_Data is defined in the header below
#include<wheelchair/Sensor/Laser/SensorInternalEvent/Edit/SensorInternalEvent_Sensor_Laser_ParamsData.h>
/*! \def Simulator_Sensor_Laser_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define Simulator_Sensor_Laser_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
