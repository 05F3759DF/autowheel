//You need to modify this file.

#ifndef VISUALIZATIONMULTI_VISUALMISC_COMBINEDVISUAL_PARAMSDATA_H
#define VISUALIZATIONMULTI_VISUALMISC_COMBINEDVISUAL_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMulti_VisualMisc_CombinedVisual_ParamsData VisualizationMulti_VisualMisc_CombinedVisual_ParamsData
	\ingroup VisualizationMulti_VisualMisc_CombinedVisual
	\brief VisualizationMulti_VisualMisc_CombinedVisual_ParamsData defines the ParamsData in VisualizationMulti_VisualMisc_CombinedVisual.
*/

/*! \addtogroup VisualizationMulti_VisualMisc_CombinedVisual_ParamsData
	@{
*/

/*! \file VisualizationMulti_VisualMisc_CombinedVisual_ParamsData.h
	 Defines the ParamsData of VisualizationMulti_VisualMisc_CombinedVisual
*/

//*******************Please add other headers below*******************


//3 input data header(s) refered

//Defines Params ProcessorMulti_Processor_FeatureExtract_Params and Input Data ProcessorMulti_Processor_FeatureExtract_Data
#include<wheelchair/Processor/FeatureExtract/ProcessorMulti/Edit/ProcessorMulti_Processor_FeatureExtract_ParamsData.h>
//Defines Params ProcessorMulti_Processor_PathGenerator_Params and Input Data ProcessorMulti_Processor_PathGenerator_Data
#include<wheelchair/Processor/PathGenerator/ProcessorMulti/Edit/ProcessorMulti_Processor_PathGenerator_ParamsData.h>
//Defines Params SourceDrainMono_Sensor_stm32comm_Params and Input Data SourceDrainMono_Sensor_stm32comm_Data
#include<wheelchair/Sensor/stm32comm/SourceDrainMono/Edit/SourceDrainMono_Sensor_stm32comm_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMulti_VisualMisc_CombinedVisual_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=3
	\details
	- Input Port #0: Buffer_Size = 5, Params_Type = ProcessorMulti_Processor_FeatureExtract_Params, Data_Type = ProcessorMulti_Processor_FeatureExtract_Data
	- Input Port #1: Buffer_Size = 5, Params_Type = ProcessorMulti_Processor_PathGenerator_Params, Data_Type = ProcessorMulti_Processor_PathGenerator_Data
	- Input Port #2: Buffer_Size = 5, Params_Type = SourceDrainMono_Sensor_stm32comm_Params, Data_Type = SourceDrainMono_Sensor_stm32comm_Data
*/
#define VisualizationMulti_VisualMisc_CombinedVisual_INPUTPORTSSIZE QList<int>()<<5<<5<<5

//The Params is defined as below
/*! \class VisualizationMulti_VisualMisc_CombinedVisual_Params 
	\brief The Params of VisualizationMulti_VisualMisc_CombinedVisual.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMulti_VisualMisc_CombinedVisual_Params 
{
public:
	/*! \fn VisualizationMulti_VisualMisc_CombinedVisual_Params()
		\brief The constructor of VisualizationMulti_VisualMisc_CombinedVisual_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMulti_VisualMisc_CombinedVisual_Params() 
	{
        filepath = "/home/wheel/config/sim/";
        sketchFileName = "sketchMap.txt";
        offlineFileName = "line.txt";
	}
	/*! \fn ~VisualizationMulti_VisualMisc_CombinedVisual_Params()
		\brief The destructor of VisualizationMulti_VisualMisc_CombinedVisual_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMulti_VisualMisc_CombinedVisual_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QString filepath;
    QString sketchFileName;
    QString offlineFileName;

};

//There is no Output Data.

/*! \def VisualizationMulti_VisualMisc_CombinedVisual_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMulti_VisualMisc_CombinedVisual_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
