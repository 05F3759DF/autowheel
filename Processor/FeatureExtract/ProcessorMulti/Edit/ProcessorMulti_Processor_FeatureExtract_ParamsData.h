//You need to modify this file.

#ifndef PROCESSORMULTI_PROCESSOR_FEATUREEXTRACT_PARAMSDATA_H
#define PROCESSORMULTI_PROCESSOR_FEATUREEXTRACT_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Processor_FeatureExtract_ParamsData ProcessorMulti_Processor_FeatureExtract_ParamsData
	\ingroup ProcessorMulti_Processor_FeatureExtract
	\brief ProcessorMulti_Processor_FeatureExtract_ParamsData defines the ParamsData in ProcessorMulti_Processor_FeatureExtract.
*/

/*! \addtogroup ProcessorMulti_Processor_FeatureExtract_ParamsData
	@{
*/

/*! \file ProcessorMulti_Processor_FeatureExtract_ParamsData.h
	 Defines the ParamsData of ProcessorMulti_Processor_FeatureExtract
*/

//*******************Please add other headers below*******************
#include "../processormulti_processor_featureextract_ex.h"

//3 input data header(s) refered

//Defines Params SensorInternalEvent_Localization_Slam_Params and Input Data SensorTimer_Localization_Slam_Data
#include<wheelchair/Localization/Slam/SensorTimer/Edit/SensorTimer_Localization_Slam_ParamsData.h>
//Defines Params SensorInternalEvent_Sensor_Laser_Params and Input Data SensorInternalEvent_Sensor_Laser_Data
#include<wheelchair/Sensor/Laser/SensorInternalEvent/Edit/SensorInternalEvent_Sensor_Laser_ParamsData.h>
//Defines Params SourceDrainMono_Sensor_stm32comm_Params and Input Data SourceDrainMono_Sensor_stm32comm_Data
#include<wheelchair/Sensor/stm32comm/SourceDrainMono/Edit/SourceDrainMono_Sensor_stm32comm_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMulti_Processor_FeatureExtract_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=3
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = SensorInternalEvent_Sensor_Laser_Params, Data_Type = SensorInternalEvent_Sensor_Laser_Data
	- Input Port #1: Buffer_Size = 10, Params_Type = SourceDrainMono_Sensor_stm32comm_Params, Data_Type = SourceDrainMono_Sensor_stm32comm_Data
    - Input Port #2: Buffer_Size = 10, Params_Type = SensorInternalEvent_Localization_Slam_Params, Data_Type = SensorTimer_Localization_Slam_Data
*/
#define ProcessorMulti_Processor_FeatureExtract_INPUTPORTSSIZE QList<int>()<<10<<10<<10

//The Params is defined as below
/*! \class ProcessorMulti_Processor_FeatureExtract_Params 
	\brief The Params of ProcessorMulti_Processor_FeatureExtract.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Processor_FeatureExtract_Params 
{
public:
	/*! \fn ProcessorMulti_Processor_FeatureExtract_Params()
		\brief The constructor of ProcessorMulti_Processor_FeatureExtract_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Processor_FeatureExtract_Params() 
	{
        map_size = 500;
        pixel_per_meter = 20;
	}
	/*! \fn ~ProcessorMulti_Processor_FeatureExtract_Params()
		\brief The destructor of ProcessorMulti_Processor_FeatureExtract_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Processor_FeatureExtract_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    int map_size;
     int pixel_per_meter;
     //Mei
     double pixelsize, ox, oy;
     const double a_big_number = 999999999.0;
};

//The Output Data is defined as below
/*! \class ProcessorMulti_Processor_FeatureExtract_Data 
	\brief The Data of ProcessorMulti_Processor_FeatureExtract.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Processor_FeatureExtract_Data 
{
public:
	/*! \fn ProcessorMulti_Processor_FeatureExtract_Data()
		\brief The constructor of ProcessorMulti_Processor_FeatureExtract_Data. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Processor_FeatureExtract_Data() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Processor_FeatureExtract_Data()
		\brief The destructor of ProcessorMulti_Processor_FeatureExtract_Data. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Processor_FeatureExtract_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    double urg_data_point[2][600][2];
    _feature feature;
    int is_door_open[SIZE_OF_FEATURE/2];
    cv::Mat mapImage;
    double URGData_size;
    QVector<_lms_gap>lms_gap;
    QVector<cv::Point2d> door_point;
    Line leftWall, rightWall;
    QVector<cv::Point> barrier;
    double d2leftwall;
    double d2rightwall;
    QVector<cv::Point2d> wall_detect_point;
};

/*! \def ProcessorMulti_Processor_FeatureExtract_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMulti_Processor_FeatureExtract_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
