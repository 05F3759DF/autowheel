//You need to modify this file.

#ifndef STORAGEMONO_SENSOR_STM32COMM_VARS_H
#define STORAGEMONO_SENSOR_STM32COMM_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup StorageMono_Sensor_stm32comm_Vars StorageMono_Sensor_stm32comm_Vars
	\ingroup StorageMono_Sensor_stm32comm
	\brief StorageMono_Sensor_stm32comm_Vars defines the Vars in StorageMono_Sensor_stm32comm.
*/

/*! \addtogroup StorageMono_Sensor_stm32comm_Vars
	@{
*/

/*! \file StorageMono_Sensor_stm32comm_Vars.h
	 Defines the Vars of StorageMono_Sensor_stm32comm
*/

//*******************Please add other headers below*******************
#include <iostream>
#include <fstream>

#include "StorageMono_Sensor_stm32comm_ParamsData.h"

//The Vars is defined as below
/*! \class StorageMono_Sensor_stm32comm_Vars 
	\brief The Vars of StorageMono_Sensor_stm32comm.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT StorageMono_Sensor_stm32comm_Vars 
{
public:
	/*! \fn StorageMono_Sensor_stm32comm_Vars()
		\brief The constructor of StorageMono_Sensor_stm32comm_Vars. [required]
		\details ****Please add details below****

	*/
	StorageMono_Sensor_stm32comm_Vars() 
	{
		
	}
	/*! \fn ~StorageMono_Sensor_stm32comm_Vars()
		\brief The destructor of StorageMono_Sensor_stm32comm_Vars. [required]
		\details *****Please add details below*****

	*/
	~StorageMono_Sensor_stm32comm_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
 std::ofstream storagefile;
};

/*! @}*/ 

#endif
