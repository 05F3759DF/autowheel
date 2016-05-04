//You need to modify this file.

#ifndef SENSORTIMER_GAZEBO_LASER_VARS_H
#define SENSORTIMER_GAZEBO_LASER_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorTimer_Gazebo_Laser_Vars SensorTimer_Gazebo_Laser_Vars
	\ingroup SensorTimer_Gazebo_Laser
	\brief SensorTimer_Gazebo_Laser_Vars defines the Vars in SensorTimer_Gazebo_Laser.
*/

/*! \addtogroup SensorTimer_Gazebo_Laser_Vars
	@{
*/

/*! \file SensorTimer_Gazebo_Laser_Vars.h
	 Defines the Vars of SensorTimer_Gazebo_Laser
*/

//*******************Please add other headers below*******************

#include "lasersub.h"
#include "SensorTimer_Gazebo_Laser_ParamsData.h"

//The Vars is defined as below
/*! \class SensorTimer_Gazebo_Laser_Vars 
	\brief The Vars of SensorTimer_Gazebo_Laser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorTimer_Gazebo_Laser_Vars 
{
public:
	/*! \fn SensorTimer_Gazebo_Laser_Vars()
		\brief The constructor of SensorTimer_Gazebo_Laser_Vars. [required]
		\details ****Please add details below****

	*/
	SensorTimer_Gazebo_Laser_Vars() 
	{
        leftLaserSub = new LaserSub("~/wheelchairrobot/leftlaser_link/laser/scan");
        rightLaserSub = new LaserSub("~/wheelchairrobot/rightlaser_link/laser/scan");
	}
	/*! \fn ~SensorTimer_Gazebo_Laser_Vars()
		\brief The destructor of SensorTimer_Gazebo_Laser_Vars. [required]
		\details *****Please add details below*****

	*/
	~SensorTimer_Gazebo_Laser_Vars() 
	{
        if(leftLaserSub != NULL)
            delete leftLaserSub;

        if(rightLaserSub != NULL)
            delete rightLaserSub;
	}
public:
	//*******************Please add variables below*******************
    LaserSub* leftLaserSub;
    LaserSub* rightLaserSub;
};

/*! @}*/ 

#endif
