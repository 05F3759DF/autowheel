//You need to modify this file.

#ifndef SIMULATOR_PROCESSOR_PATHGENERATOR_PARAMSDATA_H
#define SIMULATOR_PROCESSOR_PATHGENERATOR_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Processor_PathGenerator_ParamsData Simulator_Processor_PathGenerator_ParamsData
	\ingroup Simulator_Processor_PathGenerator
	\brief Simulator_Processor_PathGenerator_ParamsData defines the ParamsData in Simulator_Processor_PathGenerator.
*/

/*! \addtogroup Simulator_Processor_PathGenerator_ParamsData
	@{
*/

/*! \file Simulator_Processor_PathGenerator_ParamsData.h
	 Defines the ParamsData of Simulator_Processor_PathGenerator
*/

//*******************Please add other headers below*******************


//There is no input data headers.

/*! \def Simulator_Processor_PathGenerator_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define Simulator_Processor_PathGenerator_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class Simulator_Processor_PathGenerator_Params 
	\brief The Params of Simulator_Processor_PathGenerator.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Processor_PathGenerator_Params 
{
public:
	/*! \fn Simulator_Processor_PathGenerator_Params()
		\brief The constructor of Simulator_Processor_PathGenerator_Params. [required]
		\details ****Please add details below****

	*/
	Simulator_Processor_PathGenerator_Params() 
	{
		
	}
	/*! \fn ~Simulator_Processor_PathGenerator_Params()
		\brief The destructor of Simulator_Processor_PathGenerator_Params. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Processor_PathGenerator_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//The Output Data ProcessorMulti_Processor_PathGenerator_Data is defined in the header below
#include<wheelchair/Processor/PathGenerator/ProcessorMulti/Edit/ProcessorMulti_Processor_PathGenerator_ParamsData.h>

/*! \def Simulator_Processor_PathGenerator_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define Simulator_Processor_PathGenerator_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif