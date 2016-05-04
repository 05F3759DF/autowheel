//You need to modify this file.

#ifndef PROCESSORMULTI_PROCESSOR_SIMPLECOLLECT_PARAMSDATA_H
#define PROCESSORMULTI_PROCESSOR_SIMPLECOLLECT_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Processor_SimpleCollect_ParamsData ProcessorMulti_Processor_SimpleCollect_ParamsData
	\ingroup ProcessorMulti_Processor_SimpleCollect
	\brief ProcessorMulti_Processor_SimpleCollect_ParamsData defines the ParamsData in ProcessorMulti_Processor_SimpleCollect.
*/

/*! \addtogroup ProcessorMulti_Processor_SimpleCollect_ParamsData
	@{
*/

/*! \file ProcessorMulti_Processor_SimpleCollect_ParamsData.h
	 Defines the ParamsData of ProcessorMulti_Processor_SimpleCollect
*/

//*******************Please add other headers below*******************


//4 input data header(s) refered

//Defines Params ProcessorMulti_Processor_doordetection_Params and Input Data ProcessorMulti_Processor_doordetection_Data
#include<wheelchair/Processor/doordetection/ProcessorMulti/Edit/ProcessorMulti_Processor_doordetection_ParamsData.h>
//Defines Params SensorInternalEvent_Sensor_Joystick_Params and Input Data SensorInternalEvent_Sensor_Joystick_Data
#include<wheelchair/Sensor/Joystick/SensorInternalEvent/Edit/SensorInternalEvent_Sensor_Joystick_ParamsData.h>
//Defines Params SensorTimer_Sensor_Laser_Params and Input Data SensorTimer_Sensor_Laser_Data
#include<wheelchair/Sensor/Laser/SensorTimer/Edit/SensorTimer_Sensor_Laser_ParamsData.h>
//Defines Params SourceDrainMono_Sensor_stm32comm_Params and Input Data SourceDrainMono_Sensor_stm32comm_Data
#include<wheelchair/Sensor/stm32comm/SourceDrainMono/Edit/SourceDrainMono_Sensor_stm32comm_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMulti_Processor_SimpleCollect_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=4
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = SensorInternalEvent_Sensor_Joystick_Params, Data_Type = SensorInternalEvent_Sensor_Joystick_Data
	- Input Port #1: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_Laser_Params, Data_Type = SensorTimer_Sensor_Laser_Data
	- Input Port #2: Buffer_Size = 10, Params_Type = SourceDrainMono_Sensor_stm32comm_Params, Data_Type = SourceDrainMono_Sensor_stm32comm_Data
	- Input Port #3: Buffer_Size = 10, Params_Type = ProcessorMulti_Processor_doordetection_Params, Data_Type = ProcessorMulti_Processor_doordetection_Data
*/
#define ProcessorMulti_Processor_SimpleCollect_INPUTPORTSSIZE QList<int>()<<10<<10<<10<<10

//The Params is defined as below
/*! \class ProcessorMulti_Processor_SimpleCollect_Params 
	\brief The Params of ProcessorMulti_Processor_SimpleCollect.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Processor_SimpleCollect_Params 
{
public:
	/*! \fn ProcessorMulti_Processor_SimpleCollect_Params()
		\brief The constructor of ProcessorMulti_Processor_SimpleCollect_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Processor_SimpleCollect_Params() 
	{
        laserfilename=QString("$(CurTime).lms");
        odomfilename = QString("$(CurTime).lms");
        storagepath = QString("#(DataPath)");
	}
	/*! \fn ~ProcessorMulti_Processor_SimpleCollect_Params()
		\brief The destructor of ProcessorMulti_Processor_SimpleCollect_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Processor_SimpleCollect_Params() 
	{

	}
public:
	//*******************Please add variables below*******************
    QString storagepath;
    QString laserfilename;
    //QString rlaserfilename;
    QString odomfilename;
};

//The Output Data is defined as below
/*! \class ProcessorMulti_Processor_SimpleCollect_Data 
	\brief The Data of ProcessorMulti_Processor_SimpleCollect.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Processor_SimpleCollect_Data 
{
public:
	/*! \fn ProcessorMulti_Processor_SimpleCollect_Data()
		\brief The constructor of ProcessorMulti_Processor_SimpleCollect_Data. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Processor_SimpleCollect_Data() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Processor_SimpleCollect_Data()
		\brief The destructor of ProcessorMulti_Processor_SimpleCollect_Data. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Processor_SimpleCollect_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
QString simplestatus;
};

/*! \def ProcessorMulti_Processor_SimpleCollect_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMulti_Processor_SimpleCollect_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
