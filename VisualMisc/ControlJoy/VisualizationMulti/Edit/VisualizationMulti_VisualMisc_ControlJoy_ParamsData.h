//You need to modify this file.

#ifndef VISUALIZATIONMULTI_VISUALMISC_CONTROLJOY_PARAMSDATA_H
#define VISUALIZATIONMULTI_VISUALMISC_CONTROLJOY_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMulti_VisualMisc_ControlJoy_ParamsData VisualizationMulti_VisualMisc_ControlJoy_ParamsData
	\ingroup VisualizationMulti_VisualMisc_ControlJoy
	\brief VisualizationMulti_VisualMisc_ControlJoy_ParamsData defines the ParamsData in VisualizationMulti_VisualMisc_ControlJoy.
*/

/*! \addtogroup VisualizationMulti_VisualMisc_ControlJoy_ParamsData
	@{
*/

/*! \file VisualizationMulti_VisualMisc_ControlJoy_ParamsData.h
	 Defines the ParamsData of VisualizationMulti_VisualMisc_ControlJoy
*/

//*******************Please add other headers below*******************


//2 input data header(s) refered

//Defines Params ProcessorMulti_Processor_Control_Params and Input Data ProcessorMulti_Processor_Control_Data
#include<wheelchair/Processor/Control/ProcessorMulti/Edit/ProcessorMulti_Processor_Control_ParamsData.h>
//Defines Params SensorInternalEvent_Sensor_Joystick_Params and Input Data SensorInternalEvent_Sensor_Joystick_Data
#include<wheelchair/Sensor/Joystick/SensorInternalEvent/Edit/SensorInternalEvent_Sensor_Joystick_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMulti_VisualMisc_ControlJoy_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=2
	\details
	- Input Port #0: Buffer_Size = 1, Params_Type = ProcessorMulti_Processor_Control_Params, Data_Type = ProcessorMulti_Processor_Control_Data
	- Input Port #1: Buffer_Size = 1, Params_Type = SensorInternalEvent_Sensor_Joystick_Params, Data_Type = SensorInternalEvent_Sensor_Joystick_Data
*/
#define VisualizationMulti_VisualMisc_ControlJoy_INPUTPORTSSIZE QList<int>()<<1<<1

//The Params is defined as below
/*! \class VisualizationMulti_VisualMisc_ControlJoy_Params 
	\brief The Params of VisualizationMulti_VisualMisc_ControlJoy.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMulti_VisualMisc_ControlJoy_Params 
{
public:
	/*! \fn VisualizationMulti_VisualMisc_ControlJoy_Params()
		\brief The constructor of VisualizationMulti_VisualMisc_ControlJoy_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMulti_VisualMisc_ControlJoy_Params() 
	{
		
	}
	/*! \fn ~VisualizationMulti_VisualMisc_ControlJoy_Params()
		\brief The destructor of VisualizationMulti_VisualMisc_ControlJoy_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMulti_VisualMisc_ControlJoy_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//There is no Output Data.

/*! \def VisualizationMulti_VisualMisc_ControlJoy_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMulti_VisualMisc_ControlJoy_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif