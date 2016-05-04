//You need to modify this file.

#ifndef STORAGEMONO_SENSOR_CAMERA_VARS_H
#define STORAGEMONO_SENSOR_CAMERA_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup StorageMono_Sensor_Camera_Vars StorageMono_Sensor_Camera_Vars
	\ingroup StorageMono_Sensor_Camera
	\brief StorageMono_Sensor_Camera_Vars defines the Vars in StorageMono_Sensor_Camera.
*/

/*! \addtogroup StorageMono_Sensor_Camera_Vars
	@{
*/

/*! \file StorageMono_Sensor_Camera_Vars.h
	 Defines the Vars of StorageMono_Sensor_Camera
*/

//*******************Please add other headers below*******************

#include <opencv2/opencv.hpp>
#include "StorageMono_Sensor_Camera_ParamsData.h"

//The Vars is defined as below
/*! \class StorageMono_Sensor_Camera_Vars 
	\brief The Vars of StorageMono_Sensor_Camera.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT StorageMono_Sensor_Camera_Vars 
{
public:
	/*! \fn StorageMono_Sensor_Camera_Vars()
		\brief The constructor of StorageMono_Sensor_Camera_Vars. [required]
		\details ****Please add details below****

	*/
	StorageMono_Sensor_Camera_Vars() 
	{
		
	}
	/*! \fn ~StorageMono_Sensor_Camera_Vars()
		\brief The destructor of StorageMono_Sensor_Camera_Vars. [required]
		\details *****Please add details below*****

	*/
	~StorageMono_Sensor_Camera_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QFile timestampwriter;
    cv::VideoWriter imagewriter;
};

/*! @}*/ 

#endif
