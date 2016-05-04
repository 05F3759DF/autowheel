//You need to modify this file.

#ifndef SIMULATOR_SENSOR_LASER_VARS_H
#define SIMULATOR_SENSOR_LASER_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_Laser_Vars Simulator_Sensor_Laser_Vars
	\ingroup Simulator_Sensor_Laser
	\brief Simulator_Sensor_Laser_Vars defines the Vars in Simulator_Sensor_Laser.
*/

/*! \addtogroup Simulator_Sensor_Laser_Vars
	@{
*/

/*! \file Simulator_Sensor_Laser_Vars.h
	 Defines the Vars of Simulator_Sensor_Laser
*/

//*******************Please add other headers below*******************


#include "Simulator_Sensor_Laser_ParamsData.h"

//The Vars is defined as below
/*! \class Simulator_Sensor_Laser_Vars 
	\brief The Vars of Simulator_Sensor_Laser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_Laser_Vars 
{
public:
	/*! \fn Simulator_Sensor_Laser_Vars()
		\brief The constructor of Simulator_Sensor_Laser_Vars. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_Laser_Vars() 
	{
        path=QString("#(DataPath)");
        filename=QString("urg.lms");
	}
	/*! \fn ~Simulator_Sensor_Laser_Vars()
		\brief The destructor of Simulator_Sensor_Laser_Vars. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_Laser_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QFile file;
    QString path;
    QString filename;
};

/*! @}*/ 

#endif
