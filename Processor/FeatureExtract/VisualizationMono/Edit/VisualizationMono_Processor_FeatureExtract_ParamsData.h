//You need to modify this file.

#ifndef VISUALIZATIONMONO_PROCESSOR_FEATUREEXTRACT_PARAMSDATA_H
#define VISUALIZATIONMONO_PROCESSOR_FEATUREEXTRACT_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Processor_FeatureExtract_ParamsData VisualizationMono_Processor_FeatureExtract_ParamsData
	\ingroup VisualizationMono_Processor_FeatureExtract
	\brief VisualizationMono_Processor_FeatureExtract_ParamsData defines the ParamsData in VisualizationMono_Processor_FeatureExtract.
*/

/*! \addtogroup VisualizationMono_Processor_FeatureExtract_ParamsData
	@{
*/

/*! \file VisualizationMono_Processor_FeatureExtract_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Processor_FeatureExtract
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params ProcessorMulti_Processor_FeatureExtract_Params and Input Data ProcessorMulti_Processor_FeatureExtract_Data
#include<wheelchair/Processor/FeatureExtract/ProcessorMulti/Edit/ProcessorMulti_Processor_FeatureExtract_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Processor_FeatureExtract_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 5, Params_Type = ProcessorMulti_Processor_FeatureExtract_Params, Data_Type = ProcessorMulti_Processor_FeatureExtract_Data
*/
#define VisualizationMono_Processor_FeatureExtract_INPUTPORTSSIZE QList<int>()<<5

//The Params is defined as below
/*! \class VisualizationMono_Processor_FeatureExtract_Params 
	\brief The Params of VisualizationMono_Processor_FeatureExtract.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Processor_FeatureExtract_Params 
{
public:
	/*! \fn VisualizationMono_Processor_FeatureExtract_Params()
		\brief The constructor of VisualizationMono_Processor_FeatureExtract_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Processor_FeatureExtract_Params() 
	{
		
	}
	/*! \fn ~VisualizationMono_Processor_FeatureExtract_Params()
		\brief The destructor of VisualizationMono_Processor_FeatureExtract_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Processor_FeatureExtract_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//There is no Output Data.

/*! \def VisualizationMono_Processor_FeatureExtract_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Processor_FeatureExtract_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif