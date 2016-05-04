//You need to modify this file.

#ifndef SENSORTIMER_GAZEBO_ODOM_PARAMSDATA_H
#define SENSORTIMER_GAZEBO_ODOM_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorTimer_Gazebo_Odom_ParamsData SensorTimer_Gazebo_Odom_ParamsData
	\ingroup SensorTimer_Gazebo_Odom
	\brief SensorTimer_Gazebo_Odom_ParamsData defines the ParamsData in SensorTimer_Gazebo_Odom.
*/

/*! \addtogroup SensorTimer_Gazebo_Odom_ParamsData
	@{
*/

/*! \file SensorTimer_Gazebo_Odom_ParamsData.h
	 Defines the ParamsData of SensorTimer_Gazebo_Odom
*/

//*******************Please add other headers below*******************


//There is no input data headers.

/*! \def SensorTimer_Gazebo_Odom_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define SensorTimer_Gazebo_Odom_INPUTPORTSSIZE QList<int>()

//The Params SourceDrainMono_Sensor_stm32comm_Params is defined in the header below
#include<wheelchair/Sensor/stm32comm/SourceDrainMono/Edit/SourceDrainMono_Sensor_stm32comm_ParamsData.h>

//The Output Data SourceDrainMono_Sensor_stm32comm_Data is defined in the header below
#include<wheelchair/Sensor/stm32comm/SourceDrainMono/Edit/SourceDrainMono_Sensor_stm32comm_ParamsData.h>

/*! \def SensorTimer_Gazebo_Odom_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define SensorTimer_Gazebo_Odom_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif