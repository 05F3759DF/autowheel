//You need to modify this file.

#ifndef TRANSMITTERMONO_GAZEBO_ORDERGENERATE_PARAMSDATA_H
#define TRANSMITTERMONO_GAZEBO_ORDERGENERATE_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup TransmitterMono_Gazebo_OrderGenerate_ParamsData TransmitterMono_Gazebo_OrderGenerate_ParamsData
	\ingroup TransmitterMono_Gazebo_OrderGenerate
	\brief TransmitterMono_Gazebo_OrderGenerate_ParamsData defines the ParamsData in TransmitterMono_Gazebo_OrderGenerate.
*/

/*! \addtogroup TransmitterMono_Gazebo_OrderGenerate_ParamsData
	@{
*/

/*! \file TransmitterMono_Gazebo_OrderGenerate_ParamsData.h
	 Defines the ParamsData of TransmitterMono_Gazebo_OrderGenerate
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params ProcessorMulti_Processor_Control_Params and Input Data ProcessorMulti_Processor_Control_Data
#include<wheelchair/Processor/Control/ProcessorMulti/Edit/ProcessorMulti_Processor_Control_ParamsData.h>

//0 new input data type(s) created

/*! \def TransmitterMono_Gazebo_OrderGenerate_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = ProcessorMulti_Processor_Control_Params, Data_Type = ProcessorMulti_Processor_Control_Data
*/
#define TransmitterMono_Gazebo_OrderGenerate_INPUTPORTSSIZE QList<int>()<<10

//The Params is defined as below
/*! \class TransmitterMono_Gazebo_OrderGenerate_Params 
	\brief The Params of TransmitterMono_Gazebo_OrderGenerate.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT TransmitterMono_Gazebo_OrderGenerate_Params 
{
public:
	/*! \fn TransmitterMono_Gazebo_OrderGenerate_Params()
		\brief The constructor of TransmitterMono_Gazebo_OrderGenerate_Params. [required]
		\details ****Please add details below****

	*/
	TransmitterMono_Gazebo_OrderGenerate_Params() 
	{
		
	}
	/*! \fn ~TransmitterMono_Gazebo_OrderGenerate_Params()
		\brief The destructor of TransmitterMono_Gazebo_OrderGenerate_Params. [required]
		\details *****Please add details below*****

	*/
	~TransmitterMono_Gazebo_OrderGenerate_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//There is no Output Data.

/*! \def TransmitterMono_Gazebo_OrderGenerate_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define TransmitterMono_Gazebo_OrderGenerate_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif