//You need to modify this file.

#ifndef VISUALIZATIONMONO_PROCESSOR_CAMERALASER_VARS_H
#define VISUALIZATIONMONO_PROCESSOR_CAMERALASER_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Processor_CameraLaser_Vars VisualizationMono_Processor_CameraLaser_Vars
	\ingroup VisualizationMono_Processor_CameraLaser
	\brief VisualizationMono_Processor_CameraLaser_Vars defines the Vars in VisualizationMono_Processor_CameraLaser.
*/

/*! \addtogroup VisualizationMono_Processor_CameraLaser_Vars
	@{
*/

/*! \file VisualizationMono_Processor_CameraLaser_Vars.h
	 Defines the Vars of VisualizationMono_Processor_CameraLaser
*/

//*******************Please add other headers below*******************


#include "VisualizationMono_Processor_CameraLaser_ParamsData.h"

//The Vars is defined as below
/*! \class VisualizationMono_Processor_CameraLaser_Vars 
	\brief The Vars of VisualizationMono_Processor_CameraLaser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Processor_CameraLaser_Vars 
{
public:
	/*! \fn VisualizationMono_Processor_CameraLaser_Vars()
		\brief The constructor of VisualizationMono_Processor_CameraLaser_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Processor_CameraLaser_Vars() 
	{
        imagelabel = new QLabel();
        imagelabel->setAlignment(Qt::AlignCenter);
	}
	/*! \fn ~VisualizationMono_Processor_CameraLaser_Vars()
		\brief The destructor of VisualizationMono_Processor_CameraLaser_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Processor_CameraLaser_Vars() 
	{
        if(imagelabel->parent() == NULL)
            delete imagelabel;
	}
public:
	//*******************Please add variables below*******************
    QLabel *imagelabel;
};

/*! @}*/ 

#endif
