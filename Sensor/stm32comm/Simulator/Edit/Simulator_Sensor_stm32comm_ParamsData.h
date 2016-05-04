//You need to modify this file.

#ifndef SIMULATOR_SENSOR_STM32COMM_PARAMSDATA_H
#define SIMULATOR_SENSOR_STM32COMM_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_stm32comm_ParamsData Simulator_Sensor_stm32comm_ParamsData
	\ingroup Simulator_Sensor_stm32comm
	\brief Simulator_Sensor_stm32comm_ParamsData defines the ParamsData in Simulator_Sensor_stm32comm.
*/

/*! \addtogroup Simulator_Sensor_stm32comm_ParamsData
	@{
*/

/*! \file Simulator_Sensor_stm32comm_ParamsData.h
	 Defines the ParamsData of Simulator_Sensor_stm32comm
*/

//*******************Please add other headers below*******************


//There is no input data headers.

/*! \def Simulator_Sensor_stm32comm_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define Simulator_Sensor_stm32comm_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class Simulator_Sensor_stm32comm_Params 
	\brief The Params of Simulator_Sensor_stm32comm.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_stm32comm_Params 
{
public:
	/*! \fn Simulator_Sensor_stm32comm_Params()
		\brief The constructor of Simulator_Sensor_stm32comm_Params. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_stm32comm_Params() 
	{
		
	}
	/*! \fn ~Simulator_Sensor_stm32comm_Params()
		\brief The destructor of Simulator_Sensor_stm32comm_Params. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_stm32comm_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QString path;
    QString filename;
};

//The Output Data SourceDrainMono_Sensor_stm32comm_Data is defined in the header below
#include<wheelchair/Sensor/stm32comm/SourceDrainMono/Edit/SourceDrainMono_Sensor_stm32comm_ParamsData.h>

/*! \def Simulator_Sensor_stm32comm_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define Simulator_Sensor_stm32comm_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
