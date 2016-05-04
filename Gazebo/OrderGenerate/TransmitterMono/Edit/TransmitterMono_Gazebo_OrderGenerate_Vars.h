//You need to modify this file.

#ifndef TRANSMITTERMONO_GAZEBO_ORDERGENERATE_VARS_H
#define TRANSMITTERMONO_GAZEBO_ORDERGENERATE_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup TransmitterMono_Gazebo_OrderGenerate_Vars TransmitterMono_Gazebo_OrderGenerate_Vars
	\ingroup TransmitterMono_Gazebo_OrderGenerate
	\brief TransmitterMono_Gazebo_OrderGenerate_Vars defines the Vars in TransmitterMono_Gazebo_OrderGenerate.
*/

/*! \addtogroup TransmitterMono_Gazebo_OrderGenerate_Vars
	@{
*/

/*! \file TransmitterMono_Gazebo_OrderGenerate_Vars.h
	 Defines the Vars of TransmitterMono_Gazebo_OrderGenerate
*/

//*******************Please add other headers below*******************

#include "controlpub.h"
#include "TransmitterMono_Gazebo_OrderGenerate_ParamsData.h"

//The Vars is defined as below
/*! \class TransmitterMono_Gazebo_OrderGenerate_Vars 
	\brief The Vars of TransmitterMono_Gazebo_OrderGenerate.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT TransmitterMono_Gazebo_OrderGenerate_Vars 
{
public:
	/*! \fn TransmitterMono_Gazebo_OrderGenerate_Vars()
		\brief The constructor of TransmitterMono_Gazebo_OrderGenerate_Vars. [required]
		\details ****Please add details below****

	*/
	TransmitterMono_Gazebo_OrderGenerate_Vars() 
	{
        controlPub = new ControlPub("~/wheelchairrobot/joint_cmd");
        vel_ratio = 1.5;
	}
	/*! \fn ~TransmitterMono_Gazebo_OrderGenerate_Vars()
		\brief The destructor of TransmitterMono_Gazebo_OrderGenerate_Vars. [required]
		\details *****Please add details below*****

	*/
	~TransmitterMono_Gazebo_OrderGenerate_Vars() 
	{
        if(controlPub != NULL)
             delete controlPub;
	}
public:
	//*******************Please add variables below*******************
    ControlPub* controlPub;
    double vel_ratio;
};

/*! @}*/ 

#endif
