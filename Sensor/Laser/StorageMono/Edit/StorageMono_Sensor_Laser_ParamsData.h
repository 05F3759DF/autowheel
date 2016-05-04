//You need to modify this file.

#ifndef STORAGEMONO_SENSOR_LASER_PARAMSDATA_H
#define STORAGEMONO_SENSOR_LASER_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup StorageMono_Sensor_Laser_ParamsData StorageMono_Sensor_Laser_ParamsData
	\ingroup StorageMono_Sensor_Laser
	\brief StorageMono_Sensor_Laser_ParamsData defines the ParamsData in StorageMono_Sensor_Laser.
*/

/*! \addtogroup StorageMono_Sensor_Laser_ParamsData
	@{
*/

/*! \file StorageMono_Sensor_Laser_ParamsData.h
	 Defines the ParamsData of StorageMono_Sensor_Laser
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params SensorInternalEvent_Sensor_Laser_Params and Input Data SensorInternalEvent_Sensor_Laser_Data
#include<wheelchair/Sensor/Laser/SensorInternalEvent/Edit/SensorInternalEvent_Sensor_Laser_ParamsData.h>

//0 new input data type(s) created

/*! \def StorageMono_Sensor_Laser_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = SensorInternalEvent_Sensor_Laser_Params, Data_Type = SensorInternalEvent_Sensor_Laser_Data
*/
#define StorageMono_Sensor_Laser_INPUTPORTSSIZE QList<int>()<<0

//The Params is defined as below
/*! \class StorageMono_Sensor_Laser_Params 
	\brief The Params of StorageMono_Sensor_Laser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT StorageMono_Sensor_Laser_Params 
{
public:
	/*! \fn StorageMono_Sensor_Laser_Params()
		\brief The constructor of StorageMono_Sensor_Laser_Params. [required]
		\details ****Please add details below****

	*/
	StorageMono_Sensor_Laser_Params() 
	{
        filename=QString("$(CurTime).lms");
        storagepath = QString("#(DataPath)");

	}
	/*! \fn ~StorageMono_Sensor_Laser_Params()
		\brief The destructor of StorageMono_Sensor_Laser_Params. [required]
		\details *****Please add details below*****

	*/
	~StorageMono_Sensor_Laser_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QString filename;
    QString storagepath;
};

//There is no Output Data.

/*! \def StorageMono_Sensor_Laser_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define StorageMono_Sensor_Laser_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
