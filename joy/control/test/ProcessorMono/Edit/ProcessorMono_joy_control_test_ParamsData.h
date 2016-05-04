//You need to modify this file.

#ifndef PROCESSORMONO_JOY_CONTROL_TEST_PARAMSDATA_H
#define PROCESSORMONO_JOY_CONTROL_TEST_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMono_joy_control_test_ParamsData ProcessorMono_joy_control_test_ParamsData
	\ingroup ProcessorMono_joy_control_test
	\brief ProcessorMono_joy_control_test_ParamsData defines the ParamsData in ProcessorMono_joy_control_test.
*/

/*! \addtogroup ProcessorMono_joy_control_test_ParamsData
	@{
*/

/*! \file ProcessorMono_joy_control_test_ParamsData.h
	 Defines the ParamsData of ProcessorMono_joy_control_test
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params SensorInternalEvent_Sensor_Joystick_Params and Input Data SensorInternalEvent_Sensor_Joystick_Data
#include<wheelchair/Sensor/Joystick/SensorInternalEvent/Edit/SensorInternalEvent_Sensor_Joystick_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMono_joy_control_test_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 5, Params_Type = SensorInternalEvent_Sensor_Joystick_Params, Data_Type = SensorInternalEvent_Sensor_Joystick_Data
*/
#define ProcessorMono_joy_control_test_INPUTPORTSSIZE QList<int>()<<5

//The Params is defined as below
/*! \class ProcessorMono_joy_control_test_Params 
	\brief The Params of ProcessorMono_joy_control_test.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMono_joy_control_test_Params 
{
public:
	/*! \fn ProcessorMono_joy_control_test_Params()
		\brief The constructor of ProcessorMono_joy_control_test_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMono_joy_control_test_Params() 
	{
		
	}
	/*! \fn ~ProcessorMono_joy_control_test_Params()
		\brief The destructor of ProcessorMono_joy_control_test_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMono_joy_control_test_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//The Output Data is defined as below
/*! \class ProcessorMono_joy_control_test_Data 
	\brief The Data of ProcessorMono_joy_control_test.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMono_joy_control_test_Data 
{
public:
	/*! \fn ProcessorMono_joy_control_test_Data()
		\brief The constructor of ProcessorMono_joy_control_test_Data. [required]
		\details ****Please add details below****

	*/
	ProcessorMono_joy_control_test_Data() 
	{
		
	}
	/*! \fn ~ProcessorMono_joy_control_test_Data()
		\brief The destructor of ProcessorMono_joy_control_test_Data. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMono_joy_control_test_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    short left_motor;
    short right_motor;
    double left_vel, right_vel;
    bool isManualControl;

};

/*! \def ProcessorMono_joy_control_test_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMono_joy_control_test_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
