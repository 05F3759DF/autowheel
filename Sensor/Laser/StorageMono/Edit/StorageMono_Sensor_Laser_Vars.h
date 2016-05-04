//You need to modify this file.

#ifndef STORAGEMONO_SENSOR_LASER_VARS_H
#define STORAGEMONO_SENSOR_LASER_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup StorageMono_Sensor_Laser_Vars StorageMono_Sensor_Laser_Vars
	\ingroup StorageMono_Sensor_Laser
	\brief StorageMono_Sensor_Laser_Vars defines the Vars in StorageMono_Sensor_Laser.
*/

/*! \addtogroup StorageMono_Sensor_Laser_Vars
	@{
*/

/*! \file StorageMono_Sensor_Laser_Vars.h
	 Defines the Vars of StorageMono_Sensor_Laser
*/

//*******************Please add other headers below*******************


#include "StorageMono_Sensor_Laser_ParamsData.h"

//The Vars is defined as below
/*! \class StorageMono_Sensor_Laser_Vars 
	\brief The Vars of StorageMono_Sensor_Laser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT StorageMono_Sensor_Laser_Vars 
{
public:
	/*! \fn StorageMono_Sensor_Laser_Vars()
		\brief The constructor of StorageMono_Sensor_Laser_Vars. [required]
		\details ****Please add details below****

	*/
	StorageMono_Sensor_Laser_Vars() 
	{
		
	}
	/*! \fn ~StorageMono_Sensor_Laser_Vars()
		\brief The destructor of StorageMono_Sensor_Laser_Vars. [required]
		\details *****Please add details below*****

	*/
	~StorageMono_Sensor_Laser_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QFile file;
    bool writehead;
};

/*! @}*/ 

#endif
