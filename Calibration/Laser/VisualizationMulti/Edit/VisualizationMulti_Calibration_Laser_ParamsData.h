//You need to modify this file.

#ifndef VISUALIZATIONMULTI_CALIBRATION_LASER_PARAMSDATA_H
#define VISUALIZATIONMULTI_CALIBRATION_LASER_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMulti_Calibration_Laser_ParamsData VisualizationMulti_Calibration_Laser_ParamsData
	\ingroup VisualizationMulti_Calibration_Laser
	\brief VisualizationMulti_Calibration_Laser_ParamsData defines the ParamsData in VisualizationMulti_Calibration_Laser.
*/

/*! \addtogroup VisualizationMulti_Calibration_Laser_ParamsData
	@{
*/

/*! \file VisualizationMulti_Calibration_Laser_ParamsData.h
	 Defines the ParamsData of VisualizationMulti_Calibration_Laser
*/

//*******************Please add other headers below*******************
#include <cmath>

//1 input data header(s) refered

//Defines Params SensorTimer_Sensor_Laser_Params and Input Data SensorTimer_Sensor_Laser_Data
#include<wheelchair/Sensor/Laser/SensorTimer/Edit/SensorTimer_Sensor_Laser_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMulti_Calibration_Laser_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=2
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_Laser_Params, Data_Type = SensorTimer_Sensor_Laser_Data
	- Input Port #1: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_Laser_Params, Data_Type = SensorTimer_Sensor_Laser_Data
*/
#define VisualizationMulti_Calibration_Laser_INPUTPORTSSIZE QList<int>()<<10<<10

//The Params VisualizationMono_Sensor_Laser_Params is defined in the header below
#include<wheelchair/Sensor/Laser/VisualizationMono/Edit/VisualizationMono_Sensor_Laser_ParamsData.h>

//There is no Output Data.

/*! \def VisualizationMulti_Calibration_Laser_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMulti_Calibration_Laser_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
