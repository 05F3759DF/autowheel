//You need to modify this file.

#ifndef VISUALIZATIONMONO_SENSOR_LASER_VARS_H
#define VISUALIZATIONMONO_SENSOR_LASER_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Sensor_Laser_Vars VisualizationMono_Sensor_Laser_Vars
	\ingroup VisualizationMono_Sensor_Laser
	\brief VisualizationMono_Sensor_Laser_Vars defines the Vars in VisualizationMono_Sensor_Laser.
*/

/*! \addtogroup VisualizationMono_Sensor_Laser_Vars
	@{
*/

/*! \file VisualizationMono_Sensor_Laser_Vars.h
	 Defines the Vars of VisualizationMono_Sensor_Laser
*/

//*******************Please add other headers below*******************


#include "VisualizationMono_Sensor_Laser_ParamsData.h"

//The Vars is defined as below
/*! \class VisualizationMono_Sensor_Laser_Vars 
	\brief The Vars of VisualizationMono_Sensor_Laser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Sensor_Laser_Vars 
{
public:
	/*! \fn VisualizationMono_Sensor_Laser_Vars()
		\brief The constructor of VisualizationMono_Sensor_Laser_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Sensor_Laser_Vars() 
	{
        beams = new QLabel();
        beams->setAlignment(Qt::AlignCenter);
	}
	/*! \fn ~VisualizationMono_Sensor_Laser_Vars()
		\brief The destructor of VisualizationMono_Sensor_Laser_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Sensor_Laser_Vars() 
	{
        if(beams->parent() == NULL)
        {
            delete beams;
        }
	}
public:
	//*******************Please add variables below*******************
    QLabel * beams;
    QPainter painter;
    double startangle;
    double endtangle;
    double resolution;
};

/*! @}*/ 

#endif
