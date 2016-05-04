//You need to modify this file.

#ifndef VISUALIZATIONMULTI_VISUALMISC_CONTROLJOY_VARS_H
#define VISUALIZATIONMULTI_VISUALMISC_CONTROLJOY_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMulti_VisualMisc_ControlJoy_Vars VisualizationMulti_VisualMisc_ControlJoy_Vars
	\ingroup VisualizationMulti_VisualMisc_ControlJoy
	\brief VisualizationMulti_VisualMisc_ControlJoy_Vars defines the Vars in VisualizationMulti_VisualMisc_ControlJoy.
*/

/*! \addtogroup VisualizationMulti_VisualMisc_ControlJoy_Vars
	@{
*/

/*! \file VisualizationMulti_VisualMisc_ControlJoy_Vars.h
	 Defines the Vars of VisualizationMulti_VisualMisc_ControlJoy
*/

//*******************Please add other headers below*******************


#include "VisualizationMulti_VisualMisc_ControlJoy_ParamsData.h"

//The Vars is defined as below
/*! \class VisualizationMulti_VisualMisc_ControlJoy_Vars 
	\brief The Vars of VisualizationMulti_VisualMisc_ControlJoy.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMulti_VisualMisc_ControlJoy_Vars 
{
public:
	/*! \fn VisualizationMulti_VisualMisc_ControlJoy_Vars()
		\brief The constructor of VisualizationMulti_VisualMisc_ControlJoy_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMulti_VisualMisc_ControlJoy_Vars() 
	{
        label = new QLabel();
        label->setAlignment(Qt::AlignCenter);
        width = 320;
        height = 240;
        fontSize = 15;
        leftArrowPath = "left.png";
        rightArrowPath = "right.png";
        forwardArrowPath = "forward.png";
        backArrowPath = "back.png";
	}
	/*! \fn ~VisualizationMulti_VisualMisc_ControlJoy_Vars()
		\brief The destructor of VisualizationMulti_VisualMisc_ControlJoy_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMulti_VisualMisc_ControlJoy_Vars() 
	{
        if(label->parent() == NULL)
        {
            delete label;
        }
	}
public:
	//*******************Please add variables below*******************
    QLabel * label;
    int width, height,fontSize;
    QString leftArrowPath, rightArrowPath, forwardArrowPath, backArrowPath;
    QImage leftArrowImg, rightArrowImg, forwardArrowImg, backArrowImg;
};

/*! @}*/ 

#endif
