//You need to modify this file.

#ifndef PROCESSORMULTI_PROCESSOR_PATHGENERATOR_PARAMSDATA_H
#define PROCESSORMULTI_PROCESSOR_PATHGENERATOR_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Processor_PathGenerator_ParamsData ProcessorMulti_Processor_PathGenerator_ParamsData
	\ingroup ProcessorMulti_Processor_PathGenerator
	\brief ProcessorMulti_Processor_PathGenerator_ParamsData defines the ParamsData in ProcessorMulti_Processor_PathGenerator.
*/

/*! \addtogroup ProcessorMulti_Processor_PathGenerator_ParamsData
	@{
*/

/*! \file ProcessorMulti_Processor_PathGenerator_ParamsData.h
	 Defines the ParamsData of ProcessorMulti_Processor_PathGenerator
*/

//*******************Please add other headers below*******************

#include "kelly_PG.h"

//3 input data header(s) refered

//Defines Params SensorInternalEvent_Localization_Slam_Params and Input Data SensorTimer_Localization_Slam_Data
#include<wheelchair/Localization/Slam/SensorTimer/Edit/SensorTimer_Localization_Slam_ParamsData.h>
//Defines Params ProcessorMono_Processor_EvaluateFunction_Params and Input Data ProcessorMono_Processor_EvaluateFunction_Data
#include<wheelchair/Processor/EvaluateFunction/ProcessorMono/Edit/ProcessorMono_Processor_EvaluateFunction_ParamsData.h>
//Defines Params SourceDrainMono_Sensor_stm32comm_Params and Input Data SourceDrainMono_Sensor_stm32comm_Data
#include<wheelchair/Sensor/stm32comm/SourceDrainMono/Edit/SourceDrainMono_Sensor_stm32comm_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMulti_Processor_PathGenerator_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=3
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = SourceDrainMono_Sensor_stm32comm_Params, Data_Type = SourceDrainMono_Sensor_stm32comm_Data
	- Input Port #1: Buffer_Size = 10, Params_Type = ProcessorMono_Processor_EvaluateFunction_Params, Data_Type = ProcessorMono_Processor_EvaluateFunction_Data
    - Input Port #2: Buffer_Size = 10, Params_Type = SensorInternalEvent_Localization_Slam_Params, Data_Type = SensorTimer_Localization_Slam_Data
*/
#define ProcessorMulti_Processor_PathGenerator_INPUTPORTSSIZE QList<int>()<<10<<10<<10

//The Params is defined as below
/*! \class ProcessorMulti_Processor_PathGenerator_Params 
	\brief The Params of ProcessorMulti_Processor_PathGenerator.
	\details **Please add details below**

*/

struct ONETRAJDATA{
    QVector<trajec_state> trajdat;
    bool valid;
    double cost;
    int step;
public:
    void operator =(const ONETRAJDATA& traj)
    {
        trajdat = traj.trajdat;
        valid = traj.valid;
        cost = traj.cost;
    }
};

class ROBOTSDK_OUTPUT ProcessorMulti_Processor_PathGenerator_Params 
{
public:
	/*! \fn ProcessorMulti_Processor_PathGenerator_Params()
		\brief The constructor of ProcessorMulti_Processor_PathGenerator_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Processor_PathGenerator_Params() 
	{
        planDist = 3.0;
        trajNum = 18;
        nextDis = 5.0;
        saveLog = 1;
	}
	/*! \fn ~ProcessorMulti_Processor_PathGenerator_Params()
		\brief The destructor of ProcessorMulti_Processor_PathGenerator_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Processor_PathGenerator_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    double planDist;
    int trajNum;
    double nextDis;
    int saveLog;
};

//The Output Data is defined as below
/*! \class ProcessorMulti_Processor_PathGenerator_Data 
	\brief The Data of ProcessorMulti_Processor_PathGenerator.
	\details **Please add details below**

*/

class ROBOTSDK_OUTPUT ProcessorMulti_Processor_PathGenerator_Data 
{
public:
	/*! \fn ProcessorMulti_Processor_PathGenerator_Data()
		\brief The constructor of ProcessorMulti_Processor_PathGenerator_Data. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Processor_PathGenerator_Data() 
	{
        for (int i = 0; i < trajSets.size(); i++)
            trajSets[i].trajdat.clear();
        trajSets.clear();
        startPoint.x = 0;
        startPoint.y = 0;
        startPoint.theta = M_PI / 2;
        index = 18;
        stop = false;
        newColor = 0;
	}
	/*! \fn ~ProcessorMulti_Processor_PathGenerator_Data()
		\brief The destructor of ProcessorMulti_Processor_PathGenerator_Data. [required]
		\details *****Please add details below*****

	*/
    ~ProcessorMulti_Processor_PathGenerator_Data()
	{
        for (int i = 0; i < trajSets.size(); i++)
            trajSets[i].trajdat.clear();
        trajSets.clear();
	}
public:
	//*******************Please add variables below*******************
    QVector<ONETRAJDATA > trajSets;
    QVector<cv::Point2f> front_barrier;
    trajec_state startPoint;
    QVector<trajec_state> nextPoint;
    trajec_state targetPoint;
    bool stop;
    int index;
    int timestamp;
    enum {STOP, LOW, MID, HIGH}speedState;
    QVector<trajec_state> pointList;

    //画碰撞检测椭圆范围用
    cv::Point2d front_center;
    cv::Point2d back_center;
    double size;
    double angle;

    int newColor;

    double URGData_size;
    double urg_data_point[2][600][2];
    bool urg_valid[2][600];

};

/*! \def ProcessorMulti_Processor_PathGenerator_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMulti_Processor_PathGenerator_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
