//You need to modify this file.

#ifndef SENSORTIMER_GAZEBO_LASER_PARAMSDATA_H
#define SENSORTIMER_GAZEBO_LASER_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorTimer_Gazebo_Laser_ParamsData SensorTimer_Gazebo_Laser_ParamsData
	\ingroup SensorTimer_Gazebo_Laser
	\brief SensorTimer_Gazebo_Laser_ParamsData defines the ParamsData in SensorTimer_Gazebo_Laser.
*/

/*! \addtogroup SensorTimer_Gazebo_Laser_ParamsData
	@{
*/

/*! \file SensorTimer_Gazebo_Laser_ParamsData.h
	 Defines the ParamsData of SensorTimer_Gazebo_Laser
*/

//*******************Please add other headers below*******************


//There is no input data headers.

/*! \def SensorTimer_Gazebo_Laser_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define SensorTimer_Gazebo_Laser_INPUTPORTSSIZE QList<int>()

//The Params SensorTimer_Sensor_Laser_Params is defined in the header below
#include<wheelchair/Sensor/Laser/SensorTimer/Edit/SensorTimer_Sensor_Laser_ParamsData.h>

//The Output Data SensorTimer_Sensor_Laser_Data is defined in the header below
#include<wheelchair/Sensor/Laser/SensorTimer/Edit/SensorTimer_Sensor_Laser_ParamsData.h>

/*! \def SensorTimer_Gazebo_Laser_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define SensorTimer_Gazebo_Laser_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif