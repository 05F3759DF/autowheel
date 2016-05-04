//You need to modify this file.

#ifndef PROCESSORMONO_PROCESSOR_EVALUATEFUNCTION_VARS_H
#define PROCESSORMONO_PROCESSOR_EVALUATEFUNCTION_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMono_Processor_EvaluateFunction_Vars ProcessorMono_Processor_EvaluateFunction_Vars
    \ingroup ProcessorMono_Processor_EvaluateFunction
    \brief ProcessorMono_Processor_EvaluateFunction_Vars defines the Vars in ProcessorMono_Processor_EvaluateFunction.
*/

/*! \addtogroup ProcessorMono_Processor_EvaluateFunction_Vars
    @{
*/

/*! \file ProcessorMono_Processor_EvaluateFunction_Vars.h
     Defines the Vars of ProcessorMono_Processor_EvaluateFunction
*/

//*******************Please add other headers below*******************

#include "learning.h"
#include "ProcessorMono_Processor_EvaluateFunction_ParamsData.h"
#include <fstream>
using namespace std;

//The Vars is defined as below
/*! \class ProcessorMono_Processor_EvaluateFunction_Vars
    \brief The Vars of ProcessorMono_Processor_EvaluateFunction.
    \details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMono_Processor_EvaluateFunction_Vars
{
public:
    /*! \fn ProcessorMono_Processor_EvaluateFunction_Vars()
        \brief The constructor of ProcessorMono_Processor_EvaluateFunction_Vars. [required]
        \details ****Please add details below****

    */
    ProcessorMono_Processor_EvaluateFunction_Vars()
    {
        param.k = 0.1 ;
        param.dataNum = 483 ;
        param.featureNum = 50 ;
        param.startNum = 2 ;
        param.barrierNum = 18 ;
        param.leftBNum = 1 ;
        param.rightBNum = 1 ;
        param.wallNum = 30 ;
        param.leftDNum = 1 ;
        param.rightDNum = 1 ;
        param.bigNum = 100000000.0 ;
        param.newFeatureNum = 0 ;
        param.filePath = "./" ;
        param.fileName = "data.dat" ;
    }
    /*! \fn ~ProcessorMono_Processor_EvaluateFunction_Vars()
        \brief The destructor of ProcessorMono_Processor_EvaluateFunction_Vars. [required]
        \details *****Please add details below*****

    */
    ~ProcessorMono_Processor_EvaluateFunction_Vars()
    {

    }
public:
    //*******************Please add variables below*******************
    ValueFeature VF ;
    params param ;
};

/*! @}*/

#endif
