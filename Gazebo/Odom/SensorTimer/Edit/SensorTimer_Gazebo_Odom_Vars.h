//You need to modify this file.

#ifndef SENSORTIMER_GAZEBO_ODOM_VARS_H
#define SENSORTIMER_GAZEBO_ODOM_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorTimer_Gazebo_Odom_Vars SensorTimer_Gazebo_Odom_Vars
	\ingroup SensorTimer_Gazebo_Odom
	\brief SensorTimer_Gazebo_Odom_Vars defines the Vars in SensorTimer_Gazebo_Odom.
*/

/*! \addtogroup SensorTimer_Gazebo_Odom_Vars
	@{
*/

/*! \file SensorTimer_Gazebo_Odom_Vars.h
	 Defines the Vars of SensorTimer_Gazebo_Odom
*/

//*******************Please add other headers below*******************
#include "odomsub.h"

#include "SensorTimer_Gazebo_Odom_ParamsData.h"

//The Vars is defined as below
/*! \class SensorTimer_Gazebo_Odom_Vars 
	\brief The Vars of SensorTimer_Gazebo_Odom.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorTimer_Gazebo_Odom_Vars 
{
public:
	/*! \fn SensorTimer_Gazebo_Odom_Vars()
		\brief The constructor of SensorTimer_Gazebo_Odom_Vars. [required]
		\details ****Please add details below****

	*/
	SensorTimer_Gazebo_Odom_Vars() 
	{
        odomSub = new OdomSub("~/pose/info");
	}
	/*! \fn ~SensorTimer_Gazebo_Odom_Vars()
		\brief The destructor of SensorTimer_Gazebo_Odom_Vars. [required]
		\details *****Please add details below*****

	*/
	~SensorTimer_Gazebo_Odom_Vars() 
	{
        if(odomSub != NULL)
            delete odomSub;
	}
public:
	//*******************Please add variables below*******************
    double roll, pitch, yaw, lastyaw;
    double leftspeed, rightspeed, leftodom, rightodom;
    double x, y, theta, deltaleft, deltaright, deltatheta, deltaIMUtheta, deltaEncodertheta;
    QTime qlasttimestamp;
    bool isinit;
    double offset_x, offset_y, offset_yaw;
    ////
    OdomSub* odomSub;
};

/*! @}*/ 

#endif
