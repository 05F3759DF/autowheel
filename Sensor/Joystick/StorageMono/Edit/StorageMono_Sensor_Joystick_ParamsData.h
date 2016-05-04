//You need to modify this file.

#ifndef STORAGEMONO_SENSOR_JOYSTICK_PARAMSDATA_H
#define STORAGEMONO_SENSOR_JOYSTICK_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup StorageMono_Sensor_Joystick_ParamsData StorageMono_Sensor_Joystick_ParamsData
	\ingroup StorageMono_Sensor_Joystick
	\brief StorageMono_Sensor_Joystick_ParamsData defines the ParamsData in StorageMono_Sensor_Joystick.
*/

/*! \addtogroup StorageMono_Sensor_Joystick_ParamsData
	@{
*/

/*! \file StorageMono_Sensor_Joystick_ParamsData.h
	 Defines the ParamsData of StorageMono_Sensor_Joystick
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params SensorInternalEvent_Sensor_Joystick_Params and Input Data SensorInternalEvent_Sensor_Joystick_Data
#include<wheelchair/Sensor/Joystick/SensorInternalEvent/Edit/SensorInternalEvent_Sensor_Joystick_ParamsData.h>

//0 new input data type(s) created

/*! \def StorageMono_Sensor_Joystick_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = SensorInternalEvent_Sensor_Joystick_Params, Data_Type = SensorInternalEvent_Sensor_Joystick_Data
*/
#define StorageMono_Sensor_Joystick_INPUTPORTSSIZE QList<int>()<<0

//The Params is defined as below
/*! \class StorageMono_Sensor_Joystick_Params 
	\brief The Params of StorageMono_Sensor_Joystick.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT StorageMono_Sensor_Joystick_Params 
{
public:
	/*! \fn StorageMono_Sensor_Joystick_Params()
		\brief The constructor of StorageMono_Sensor_Joystick_Params. [required]
		\details ****Please add details below****

	*/
	StorageMono_Sensor_Joystick_Params() 
	{
		
	}
	/*! \fn ~StorageMono_Sensor_Joystick_Params()
		\brief The destructor of StorageMono_Sensor_Joystick_Params. [required]
		\details *****Please add details below*****

	*/
	~StorageMono_Sensor_Joystick_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//There is no Output Data.

/*! \def StorageMono_Sensor_Joystick_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define StorageMono_Sensor_Joystick_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
