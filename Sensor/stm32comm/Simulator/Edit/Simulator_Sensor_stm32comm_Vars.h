//You need to modify this file.

#ifndef SIMULATOR_SENSOR_STM32COMM_VARS_H
#define SIMULATOR_SENSOR_STM32COMM_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_stm32comm_Vars Simulator_Sensor_stm32comm_Vars
	\ingroup Simulator_Sensor_stm32comm
	\brief Simulator_Sensor_stm32comm_Vars defines the Vars in Simulator_Sensor_stm32comm.
*/

/*! \addtogroup Simulator_Sensor_stm32comm_Vars
	@{
*/

/*! \file Simulator_Sensor_stm32comm_Vars.h
	 Defines the Vars of Simulator_Sensor_stm32comm
*/

//*******************Please add other headers below*******************


#include "Simulator_Sensor_stm32comm_ParamsData.h"
#include <fstream>
//The Vars is defined as below
/*! \class Simulator_Sensor_stm32comm_Vars 
	\brief The Vars of Simulator_Sensor_stm32comm.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_stm32comm_Vars 
{
public:
	/*! \fn Simulator_Sensor_stm32comm_Vars()
		\brief The constructor of Simulator_Sensor_stm32comm_Vars. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_stm32comm_Vars() 
	{
		
	}
	/*! \fn ~Simulator_Sensor_stm32comm_Vars()
		\brief The destructor of Simulator_Sensor_stm32comm_Vars. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_stm32comm_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QVector<SourceDrainMono_Sensor_stm32comm_Data> AllComData;
    int ComDataIndex;

};

/*! @}*/ 

#endif
