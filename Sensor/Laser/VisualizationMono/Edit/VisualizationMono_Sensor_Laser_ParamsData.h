//You need to modify this file.

#ifndef VISUALIZATIONMONO_SENSOR_LASER_PARAMSDATA_H
#define VISUALIZATIONMONO_SENSOR_LASER_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Sensor_Laser_ParamsData VisualizationMono_Sensor_Laser_ParamsData
	\ingroup VisualizationMono_Sensor_Laser
	\brief VisualizationMono_Sensor_Laser_ParamsData defines the ParamsData in VisualizationMono_Sensor_Laser.
*/

/*! \addtogroup VisualizationMono_Sensor_Laser_ParamsData
	@{
*/

/*! \file VisualizationMono_Sensor_Laser_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Sensor_Laser
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params SensorInternalEvent_Sensor_Laser_Params and Input Data SensorInternalEvent_Sensor_Laser_Data
#include<wheelchair/Sensor/Laser/SensorInternalEvent/Edit/SensorInternalEvent_Sensor_Laser_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Sensor_Laser_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 1, Params_Type = SensorInternalEvent_Sensor_Laser_Params, Data_Type = SensorInternalEvent_Sensor_Laser_Data
*/
#define VisualizationMono_Sensor_Laser_INPUTPORTSSIZE QList<int>()<<1

//The Params is defined as below
/*! \class VisualizationMono_Sensor_Laser_Params 
	\brief The Params of VisualizationMono_Sensor_Laser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Sensor_Laser_Params 
{
public:
	/*! \fn VisualizationMono_Sensor_Laser_Params()
		\brief The constructor of VisualizationMono_Sensor_Laser_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Sensor_Laser_Params() 
	{
        range=2500;
        interval=500;
        imageradius=400;
        frontonly=1;
        laserbeam=1;
        range = 2500;
        calib_height = 60;
        calib_width = 55;
	}
	/*! \fn ~VisualizationMono_Sensor_Laser_Params()
		\brief The destructor of VisualizationMono_Sensor_Laser_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Sensor_Laser_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    short range;
    short interval;
    int imageradius;
    bool frontonly;
    bool laserbeam;
    double calib_width; //单位cm
    double calib_height;
};

//There is no Output Data.

/*! \def VisualizationMono_Sensor_Laser_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Sensor_Laser_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
