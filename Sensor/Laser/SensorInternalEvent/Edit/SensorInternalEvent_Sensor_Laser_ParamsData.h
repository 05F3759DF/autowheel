//You need to modify this file.

#ifndef SENSORINTERNALEVENT_SENSOR_LASER_PARAMSDATA_H
#define SENSORINTERNALEVENT_SENSOR_LASER_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_Sensor_Laser_ParamsData SensorInternalEvent_Sensor_Laser_ParamsData
	\ingroup SensorInternalEvent_Sensor_Laser
	\brief SensorInternalEvent_Sensor_Laser_ParamsData defines the ParamsData in SensorInternalEvent_Sensor_Laser.
*/

/*! \addtogroup SensorInternalEvent_Sensor_Laser_ParamsData
	@{
*/

/*! \file SensorInternalEvent_Sensor_Laser_ParamsData.h
	 Defines the ParamsData of SensorInternalEvent_Sensor_Laser
*/

//*******************Please add other headers below*******************

#include <sensor_msgs/LaserScan.h>
//There is no input data headers.

/*! \def SensorInternalEvent_Sensor_Laser_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define SensorInternalEvent_Sensor_Laser_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class SensorInternalEvent_Sensor_Laser_Params 
	\brief The Params of SensorInternalEvent_Sensor_Laser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Sensor_Laser_Params 
{
public:
	/*! \fn SensorInternalEvent_Sensor_Laser_Params()
		\brief The constructor of SensorInternalEvent_Sensor_Laser_Params. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Sensor_Laser_Params() 
	{
        first_step=-360;
        last_step=360;
        skip_step=2;
        nearfilter=0;
        farfilter=5000;
        unit = 100.0;
	}
	/*! \fn ~SensorInternalEvent_Sensor_Laser_Params()
		\brief The destructor of SensorInternalEvent_Sensor_Laser_Params. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Sensor_Laser_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    int first_step;
    int last_step;
    int skip_step;
    short nearfilter;
    short farfilter;
    double unit;
};

//The Output Data is defined as below
/*! \class SensorInternalEvent_Sensor_Laser_Data 
	\brief The Data of SensorInternalEvent_Sensor_Laser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Sensor_Laser_Data 
{
public:
	/*! \fn SensorInternalEvent_Sensor_Laser_Data()
		\brief The constructor of SensorInternalEvent_Sensor_Laser_Data. [required]
		\details ****Please add details below****

	*/
    SensorInternalEvent_Sensor_Laser_Data(int dataSize)
	{
        datasize=dataSize;
        if(datasize>0)
        {
            ldata=new short[dataSize];
            rdata=new short[dataSize];
        }
        else
        {
            ldata=NULL;
            rdata=NULL;
        }
	}
	/*! \fn ~SensorInternalEvent_Sensor_Laser_Data()
		\brief The destructor of SensorInternalEvent_Sensor_Laser_Data. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Sensor_Laser_Data() 
	{
        if(ldata!=NULL)
        {
            delete []ldata;
            ldata=NULL;
        }
        if(rdata!=NULL)
        {
            delete []rdata;
            rdata=NULL;
        }
	}
public:
	//*******************Please add variables below*******************
    long timestamp;
    QTime qtimestamp;
    int datasize;
    short * ldata;
    short * rdata;
};

/*! \def SensorInternalEvent_Sensor_Laser_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define SensorInternalEvent_Sensor_Laser_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
