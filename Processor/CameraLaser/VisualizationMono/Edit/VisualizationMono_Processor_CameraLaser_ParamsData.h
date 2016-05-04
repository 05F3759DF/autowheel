//You need to modify this file.

#ifndef VISUALIZATIONMONO_PROCESSOR_CAMERALASER_PARAMSDATA_H
#define VISUALIZATIONMONO_PROCESSOR_CAMERALASER_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Processor_CameraLaser_ParamsData VisualizationMono_Processor_CameraLaser_ParamsData
	\ingroup VisualizationMono_Processor_CameraLaser
	\brief VisualizationMono_Processor_CameraLaser_ParamsData defines the ParamsData in VisualizationMono_Processor_CameraLaser.
*/

/*! \addtogroup VisualizationMono_Processor_CameraLaser_ParamsData
	@{
*/

/*! \file VisualizationMono_Processor_CameraLaser_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Processor_CameraLaser
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params ProcessorMulti_Processor_CameraLaser_Params and Input Data ProcessorMulti_Processor_CameraLaser_Data
#include<wheelchair/Processor/CameraLaser/ProcessorMulti/Edit/ProcessorMulti_Processor_CameraLaser_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Processor_CameraLaser_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 1, Params_Type = ProcessorMulti_Processor_CameraLaser_Params, Data_Type = ProcessorMulti_Processor_CameraLaser_Data
*/
#define VisualizationMono_Processor_CameraLaser_INPUTPORTSSIZE QList<int>()<<1

//The Params is defined as below
/*! \class VisualizationMono_Processor_CameraLaser_Params 
	\brief The Params of VisualizationMono_Processor_CameraLaser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Processor_CameraLaser_Params 
{
public:
	/*! \fn VisualizationMono_Processor_CameraLaser_Params()
		\brief The constructor of VisualizationMono_Processor_CameraLaser_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Processor_CameraLaser_Params() 
	{
        imageHeight = 480;
        imageWidth = 640;
	}
	/*! \fn ~VisualizationMono_Processor_CameraLaser_Params()
		\brief The destructor of VisualizationMono_Processor_CameraLaser_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Processor_CameraLaser_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    int imageHeight;
    int imageWidth;
};

//There is no Output Data.

/*! \def VisualizationMono_Processor_CameraLaser_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Processor_CameraLaser_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
