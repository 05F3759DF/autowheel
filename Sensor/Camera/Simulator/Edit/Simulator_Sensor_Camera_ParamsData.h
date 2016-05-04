//You need to modify this file.

#ifndef SIMULATOR_SENSOR_CAMERA_PARAMSDATA_H
#define SIMULATOR_SENSOR_CAMERA_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_Camera_ParamsData Simulator_Sensor_Camera_ParamsData
	\ingroup Simulator_Sensor_Camera
	\brief Simulator_Sensor_Camera_ParamsData defines the ParamsData in Simulator_Sensor_Camera.
*/

/*! \addtogroup Simulator_Sensor_Camera_ParamsData
	@{
*/

/*! \file Simulator_Sensor_Camera_ParamsData.h
	 Defines the ParamsData of Simulator_Sensor_Camera
*/

//*******************Please add other headers below*******************


//There is no input data headers.

/*! \def Simulator_Sensor_Camera_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define Simulator_Sensor_Camera_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class Simulator_Sensor_Camera_Params 
	\brief The Params of Simulator_Sensor_Camera.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_Camera_Params 
{
public:
	/*! \fn Simulator_Sensor_Camera_Params()
		\brief The constructor of Simulator_Sensor_Camera_Params. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_Camera_Params() 
	{
        path=QString("#(DataPath)");
        videofilename=QString("l.avi");
        timestampfilename = QString("aa.log");
	}
	/*! \fn ~Simulator_Sensor_Camera_Params()
		\brief The destructor of Simulator_Sensor_Camera_Params. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_Camera_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QString path;
    QString videofilename;
    QString timestampfilename;
};

//The Output Data SensorInternalEvent_Sensor_Camera_Data is defined in the header below
#include<wheelchair/Sensor/Camera/SensorInternalEvent/Edit/SensorInternalEvent_Sensor_Camera_ParamsData.h>

/*! \def Simulator_Sensor_Camera_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define Simulator_Sensor_Camera_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
