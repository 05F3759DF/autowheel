//You need to modify this file.

#ifndef VISUALIZATIONMONO_PROCESSOR_SIMPLECOLLECT_PARAMSDATA_H
#define VISUALIZATIONMONO_PROCESSOR_SIMPLECOLLECT_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Processor_SimpleCollect_ParamsData VisualizationMono_Processor_SimpleCollect_ParamsData
	\ingroup VisualizationMono_Processor_SimpleCollect
	\brief VisualizationMono_Processor_SimpleCollect_ParamsData defines the ParamsData in VisualizationMono_Processor_SimpleCollect.
*/

/*! \addtogroup VisualizationMono_Processor_SimpleCollect_ParamsData
	@{
*/

/*! \file VisualizationMono_Processor_SimpleCollect_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Processor_SimpleCollect
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params ProcessorMulti_Processor_SimpleCollect_Params and Input Data ProcessorMulti_Processor_SimpleCollect_Data
#include<wheelchair/Processor/SimpleCollect/ProcessorMulti/Edit/ProcessorMulti_Processor_SimpleCollect_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Processor_SimpleCollect_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 1, Params_Type = ProcessorMulti_Processor_SimpleCollect_Params, Data_Type = ProcessorMulti_Processor_SimpleCollect_Data
*/
#define VisualizationMono_Processor_SimpleCollect_INPUTPORTSSIZE QList<int>()<<1

//The Params is defined as below
/*! \class VisualizationMono_Processor_SimpleCollect_Params 
	\brief The Params of VisualizationMono_Processor_SimpleCollect.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Processor_SimpleCollect_Params 
{
public:
	/*! \fn VisualizationMono_Processor_SimpleCollect_Params()
		\brief The constructor of VisualizationMono_Processor_SimpleCollect_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Processor_SimpleCollect_Params() 
	{
		
	}
	/*! \fn ~VisualizationMono_Processor_SimpleCollect_Params()
		\brief The destructor of VisualizationMono_Processor_SimpleCollect_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Processor_SimpleCollect_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//There is no Output Data.

/*! \def VisualizationMono_Processor_SimpleCollect_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Processor_SimpleCollect_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif