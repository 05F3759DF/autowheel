//You need to modify this file.

#ifndef VISUALIZATIONMONO_PROCESSOR_FEATUREEXTRACT_VARS_H
#define VISUALIZATIONMONO_PROCESSOR_FEATUREEXTRACT_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Processor_FeatureExtract_Vars VisualizationMono_Processor_FeatureExtract_Vars
	\ingroup VisualizationMono_Processor_FeatureExtract
	\brief VisualizationMono_Processor_FeatureExtract_Vars defines the Vars in VisualizationMono_Processor_FeatureExtract.
*/

/*! \addtogroup VisualizationMono_Processor_FeatureExtract_Vars
	@{
*/

/*! \file VisualizationMono_Processor_FeatureExtract_Vars.h
	 Defines the Vars of VisualizationMono_Processor_FeatureExtract
*/

//*******************Please add other headers below*******************


#include "VisualizationMono_Processor_FeatureExtract_ParamsData.h"

//The Vars is defined as below
/*! \class VisualizationMono_Processor_FeatureExtract_Vars 
	\brief The Vars of VisualizationMono_Processor_FeatureExtract.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Processor_FeatureExtract_Vars 
{
public:
	/*! \fn VisualizationMono_Processor_FeatureExtract_Vars()
		\brief The constructor of VisualizationMono_Processor_FeatureExtract_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Processor_FeatureExtract_Vars() 
	{
        viewer = new QLabel("Image");
	}
	/*! \fn ~VisualizationMono_Processor_FeatureExtract_Vars()
		\brief The destructor of VisualizationMono_Processor_FeatureExtract_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Processor_FeatureExtract_Vars() 
	{
        if(viewer->parent() == NULL)
        {
            delete viewer;
            viewer = NULL;
        }
	}
public:
	//*******************Please add variables below*******************
    QLabel * viewer;
};

/*! @}*/ 

#endif
