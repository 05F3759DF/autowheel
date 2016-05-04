//You need to modify this file.

#ifndef PROCESSORMULTI_PROCESSOR_CAMERALASER_PARAMSDATA_H
#define PROCESSORMULTI_PROCESSOR_CAMERALASER_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Processor_CameraLaser_ParamsData ProcessorMulti_Processor_CameraLaser_ParamsData
	\ingroup ProcessorMulti_Processor_CameraLaser
	\brief ProcessorMulti_Processor_CameraLaser_ParamsData defines the ParamsData in ProcessorMulti_Processor_CameraLaser.
*/

/*! \addtogroup ProcessorMulti_Processor_CameraLaser_ParamsData
	@{
*/

/*! \file ProcessorMulti_Processor_CameraLaser_ParamsData.h
	 Defines the ParamsData of ProcessorMulti_Processor_CameraLaser
*/

//*******************Please add other headers below*******************


//2 input data header(s) refered

//Defines Params SensorInternalEvent_Sensor_Camera_Params and Input Data SensorInternalEvent_Sensor_Camera_Data
#include<wheelchair/Sensor/Camera/SensorInternalEvent/Edit/SensorInternalEvent_Sensor_Camera_ParamsData.h>
//Defines Params SensorTimer_Sensor_Laser_Params and Input Data SensorTimer_Sensor_Laser_Data
#include<wheelchair/Sensor/Laser/SensorTimer/Edit/SensorTimer_Sensor_Laser_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMulti_Processor_CameraLaser_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=2
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = SensorInternalEvent_Sensor_Camera_Params, Data_Type = SensorInternalEvent_Sensor_Camera_Data
	- Input Port #1: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_Laser_Params, Data_Type = SensorTimer_Sensor_Laser_Data
*/
#define ProcessorMulti_Processor_CameraLaser_INPUTPORTSSIZE QList<int>()<<10<<10

//The Params is defined as below
/*! \class ProcessorMulti_Processor_CameraLaser_Params 
	\brief The Params of ProcessorMulti_Processor_CameraLaser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Processor_CameraLaser_Params 
{
public:
	/*! \fn ProcessorMulti_Processor_CameraLaser_Params()
		\brief The constructor of ProcessorMulti_Processor_CameraLaser_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Processor_CameraLaser_Params() 
	{
        pixelsize = 0.1;
        calibfilepath = "./data";
        calibfilename = ".camera";
		
	}
	/*! \fn ~ProcessorMulti_Processor_CameraLaser_Params()
		\brief The destructor of ProcessorMulti_Processor_CameraLaser_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Processor_CameraLaser_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QString calibfilename;
    QString calibfilepath;

    double pixelsize;

};

//The Output Data is defined as below
/*! \class ProcessorMulti_Processor_CameraLaser_Data 
	\brief The Data of ProcessorMulti_Processor_CameraLaser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Processor_CameraLaser_Data 
{
public:
	/*! \fn ProcessorMulti_Processor_CameraLaser_Data()
		\brief The constructor of ProcessorMulti_Processor_CameraLaser_Data. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Processor_CameraLaser_Data() 
	{

	}
	/*! \fn ~ProcessorMulti_Processor_CameraLaser_Data()
		\brief The destructor of ProcessorMulti_Processor_CameraLaser_Data. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Processor_CameraLaser_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    cv::Mat cameralaserMat;
};

/*! \def ProcessorMulti_Processor_CameraLaser_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMulti_Processor_CameraLaser_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
