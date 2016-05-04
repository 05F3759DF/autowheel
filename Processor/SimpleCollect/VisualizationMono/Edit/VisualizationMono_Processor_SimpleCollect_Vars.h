//You need to modify this file.

#ifndef VISUALIZATIONMONO_PROCESSOR_SIMPLECOLLECT_VARS_H
#define VISUALIZATIONMONO_PROCESSOR_SIMPLECOLLECT_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Processor_SimpleCollect_Vars VisualizationMono_Processor_SimpleCollect_Vars
	\ingroup VisualizationMono_Processor_SimpleCollect
	\brief VisualizationMono_Processor_SimpleCollect_Vars defines the Vars in VisualizationMono_Processor_SimpleCollect.
*/

/*! \addtogroup VisualizationMono_Processor_SimpleCollect_Vars
	@{
*/

/*! \file VisualizationMono_Processor_SimpleCollect_Vars.h
	 Defines the Vars of VisualizationMono_Processor_SimpleCollect
*/

//*******************Please add other headers below*******************


#include "VisualizationMono_Processor_SimpleCollect_ParamsData.h"

//The Vars is defined as below
/*! \class VisualizationMono_Processor_SimpleCollect_Vars 
	\brief The Vars of VisualizationMono_Processor_SimpleCollect.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Processor_SimpleCollect_Vars 
{
public:
	/*! \fn VisualizationMono_Processor_SimpleCollect_Vars()
		\brief The constructor of VisualizationMono_Processor_SimpleCollect_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Processor_SimpleCollect_Vars() 
	{
        label = new QLabel();
	}
	/*! \fn ~VisualizationMono_Processor_SimpleCollect_Vars()
		\brief The destructor of VisualizationMono_Processor_SimpleCollect_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Processor_SimpleCollect_Vars() 
	{
        if(label->parent() ==NULL)
        {
            delete label;
        }
	}
public:
	//*******************Please add variables below*******************
    QLabel* label;
    QString status;
};

/*! @}*/ 

#endif
