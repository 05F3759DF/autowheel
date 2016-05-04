//You need to modify this file.

#ifndef PROCESSORMONO_PROCESSOR_EVALUATEFUNCTION_PARAMSDATA_H
#define PROCESSORMONO_PROCESSOR_EVALUATEFUNCTION_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMono_Processor_EvaluateFunction_ParamsData ProcessorMono_Processor_EvaluateFunction_ParamsData
    \ingroup ProcessorMono_Processor_EvaluateFunction
    \brief ProcessorMono_Processor_EvaluateFunction_ParamsData defines the ParamsData in ProcessorMono_Processor_EvaluateFunction.
*/

/*! \addtogroup ProcessorMono_Processor_EvaluateFunction_ParamsData
    @{
*/

/*! \file ProcessorMono_Processor_EvaluateFunction_ParamsData.h
     Defines the ParamsData of ProcessorMono_Processor_EvaluateFunction
*/

//*******************Please add other headers below*******************

#include <cstdio>

//1 input data header(s) refered

//Defines Params ProcessorMulti_Processor_FeatureExtract_Params and Input Data ProcessorMulti_Processor_FeatureExtract_Data
#include<wheelchair/Processor/FeatureExtract/ProcessorMulti/Edit/ProcessorMulti_Processor_FeatureExtract_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMono_Processor_EvaluateFunction_INPUTPORTSSIZE
    \brief Defines input port(s) info: number=1
    \details
    - Input Port #0: Buffer_Size = 0, Params_Type = ProcessorMulti_Processor_FeatureExtract_Params, Data_Type = ProcessorMulti_Processor_FeatureExtract_Data
*/
#define ProcessorMono_Processor_EvaluateFunction_INPUTPORTSSIZE QList<int>()<<0

//The Params is defined as below
/*! \class ProcessorMono_Processor_EvaluateFunction_Params
    \brief The Params of ProcessorMono_Processor_EvaluateFunction.
    \details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMono_Processor_EvaluateFunction_Params
{
public:
    /*! \fn ProcessorMono_Processor_EvaluateFunction_Params()
        \brief The constructor of ProcessorMono_Processor_EvaluateFunction_Params. [required]
        \details ****Please add details below****

    */
    ProcessorMono_Processor_EvaluateFunction_Params()
    {

    }
    /*! \fn ~ProcessorMono_Processor_EvaluateFunction_Params()
        \brief The destructor of ProcessorMono_Processor_EvaluateFunction_Params. [required]
        \details *****Please add details below*****

    */
    ~ProcessorMono_Processor_EvaluateFunction_Params()
    {

    }
public:
    //*******************Please add variables below*******************

};

//The Output Data is defined as below
/*! \class ProcessorMono_Processor_EvaluateFunction_Data
    \brief The Data of ProcessorMono_Processor_EvaluateFunction.
    \details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMono_Processor_EvaluateFunction_Data
{
public:
    /*! \fn ProcessorMono_Processor_EvaluateFunction_Data()
        \brief The constructor of ProcessorMono_Processor_EvaluateFunction_Data. [required]
        \details ****Please add details below****

    */
    ProcessorMono_Processor_EvaluateFunction_Data()
    {

    }
    /*! \fn ~ProcessorMono_Processor_EvaluateFunction_Data()
        \brief The destructor of ProcessorMono_Processor_EvaluateFunction_Data. [required]
        \details *****Please add details below*****

    */
    ~ProcessorMono_Processor_EvaluateFunction_Data()
    {

    }
public:
    //*******************Please add variables below*******************
    int index;
    int timestamp;

    ///0617 Mei, 以下变量是为了把FeatureExtract模块的数据传到PathGenerator
    double urg_data_point[2][600][2];
    int is_door_open[SIZE_OF_FEATURE/2];
    double URGData_size;
    QVector<cv::Point2d> door_point;
    double d2leftwall;
    double d2rightwall;
};

/*! \def ProcessorMono_Processor_EvaluateFunction_OUTPUTPORTSNUMBER
    \brief Defines output port(s) info: number = 1.
*/
#define ProcessorMono_Processor_EvaluateFunction_OUTPUTPORTSNUMBER 1

/*! @}*/

#endif
