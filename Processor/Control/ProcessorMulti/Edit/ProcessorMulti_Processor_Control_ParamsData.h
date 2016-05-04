//You need to modify this file.

#ifndef PROCESSORMULTI_PROCESSOR_CONTROL_PARAMSDATA_H
#define PROCESSORMULTI_PROCESSOR_CONTROL_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Processor_Control_ParamsData ProcessorMulti_Processor_Control_ParamsData
	\ingroup ProcessorMulti_Processor_Control
	\brief ProcessorMulti_Processor_Control_ParamsData defines the ParamsData in ProcessorMulti_Processor_Control.
*/

/*! \addtogroup ProcessorMulti_Processor_Control_ParamsData
	@{
*/

/*! \file ProcessorMulti_Processor_Control_ParamsData.h
	 Defines the ParamsData of ProcessorMulti_Processor_Control
*/

//*******************Please add other headers below*******************


//2 input data header(s) refered

//Defines Params ProcessorMulti_Processor_PathGenerator_Params and Input Data ProcessorMulti_Processor_PathGenerator_Data
#include<wheelchair/Processor/PathGenerator/ProcessorMulti/Edit/ProcessorMulti_Processor_PathGenerator_ParamsData.h>
//Defines Params SensorInternalEvent_Sensor_Joystick_Params and Input Data SensorInternalEvent_Sensor_Joystick_Data
#include<wheelchair/Sensor/Joystick/SensorInternalEvent/Edit/SensorInternalEvent_Sensor_Joystick_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMulti_Processor_Control_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=2
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = ProcessorMulti_Processor_PathGenerator_Params, Data_Type = ProcessorMulti_Processor_PathGenerator_Data
	- Input Port #1: Buffer_Size = 10, Params_Type = SensorInternalEvent_Sensor_Joystick_Params, Data_Type = SensorInternalEvent_Sensor_Joystick_Data
*/
#define ProcessorMulti_Processor_Control_INPUTPORTSSIZE QList<int>()<<10<<10

//The Params is defined as below
/*! \class ProcessorMulti_Processor_Control_Params 
	\brief The Params of ProcessorMulti_Processor_Control.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Processor_Control_Params 
{
public:
	/*! \fn ProcessorMulti_Processor_Control_Params()
		\brief The constructor of ProcessorMulti_Processor_Control_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Processor_Control_Params() 
	{
        lowSpeed = 0.4;
        midSpeed = 0.7;
        highSpeed = 1.0;
        stopPWM = 0;
	}
	/*! \fn ~ProcessorMulti_Processor_Control_Params()
		\brief The destructor of ProcessorMulti_Processor_Control_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Processor_Control_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
 double stopPWM,lowSpeed, midSpeed, highSpeed;
};

//The Output Data is defined as below
/*! \class ProcessorMulti_Processor_Control_Data 
	\brief The Data of ProcessorMulti_Processor_Control.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Processor_Control_Data 
{
public:
	/*! \fn ProcessorMulti_Processor_Control_Data()
		\brief The constructor of ProcessorMulti_Processor_Control_Data. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Processor_Control_Data() 
	{
        isStop = 0;
	}
	/*! \fn ~ProcessorMulti_Processor_Control_Data()
		\brief The destructor of ProcessorMulti_Processor_Control_Data. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Processor_Control_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    short left_motor;
    short right_motor;
    double left_vel, right_vel;
    bool isManualControl;
    char isStop;

};

/*! \def ProcessorMulti_Processor_Control_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMulti_Processor_Control_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
