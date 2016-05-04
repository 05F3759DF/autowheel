//You need to modify this file.

#ifndef PROCESSORMULTI_PROCESSOR_CAMERALASER_VARS_H
#define PROCESSORMULTI_PROCESSOR_CAMERALASER_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Processor_CameraLaser_Vars ProcessorMulti_Processor_CameraLaser_Vars
	\ingroup ProcessorMulti_Processor_CameraLaser
	\brief ProcessorMulti_Processor_CameraLaser_Vars defines the Vars in ProcessorMulti_Processor_CameraLaser.
*/

/*! \addtogroup ProcessorMulti_Processor_CameraLaser_Vars
	@{
*/

/*! \file ProcessorMulti_Processor_CameraLaser_Vars.h
	 Defines the Vars of ProcessorMulti_Processor_CameraLaser
*/

//*******************Please add other headers below*******************


#include "ProcessorMulti_Processor_CameraLaser_ParamsData.h"

//The Vars is defined as below
/*! \class ProcessorMulti_Processor_CameraLaser_Vars 
	\brief The Vars of ProcessorMulti_Processor_CameraLaser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Processor_CameraLaser_Vars 
{
public:
	/*! \fn ProcessorMulti_Processor_CameraLaser_Vars()
		\brief The constructor of ProcessorMulti_Processor_CameraLaser_Vars. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Processor_CameraLaser_Vars() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Processor_CameraLaser_Vars()
		\brief The destructor of ProcessorMulti_Processor_CameraLaser_Vars. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Processor_CameraLaser_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    cv::Mat cameralaserMat;
};

/*! @}*/ 

#endif
