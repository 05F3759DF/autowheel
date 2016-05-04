//You need to modify this file.

#ifndef PROCESSORMONO_JOY_CONTROL_TEST_VARS_H
#define PROCESSORMONO_JOY_CONTROL_TEST_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMono_joy_control_test_Vars ProcessorMono_joy_control_test_Vars
	\ingroup ProcessorMono_joy_control_test
	\brief ProcessorMono_joy_control_test_Vars defines the Vars in ProcessorMono_joy_control_test.
*/

/*! \addtogroup ProcessorMono_joy_control_test_Vars
	@{
*/

/*! \file ProcessorMono_joy_control_test_Vars.h
	 Defines the Vars of ProcessorMono_joy_control_test
*/

//*******************Please add other headers below*******************


#include "ProcessorMono_joy_control_test_ParamsData.h"

//The Vars is defined as below
/*! \class ProcessorMono_joy_control_test_Vars 
	\brief The Vars of ProcessorMono_joy_control_test.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMono_joy_control_test_Vars 
{
public:
	/*! \fn ProcessorMono_joy_control_test_Vars()
		\brief The constructor of ProcessorMono_joy_control_test_Vars. [required]
		\details ****Please add details below****

	*/
	ProcessorMono_joy_control_test_Vars() 
	{
        WheelRadius = 0.1735;
        max_linearVel = 0.5;
        targetPt_index = 20;
        left_vel = right_vel = 0;
        WheelBase = 0.576;
	}
	/*! \fn ~ProcessorMono_joy_control_test_Vars()
		\brief The destructor of ProcessorMono_joy_control_test_Vars. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMono_joy_control_test_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    double WheelBase, WheelRadius;
    double max_linearVel;
    int targetPt_index;
    double left_vel, right_vel;
};

/*! @}*/ 

#endif
