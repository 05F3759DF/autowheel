//You need to modify this file.

#ifndef SENSORINTERNALEVENT_SENSOR_LASER_VARS_H
#define SENSORINTERNALEVENT_SENSOR_LASER_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_Sensor_Laser_Vars SensorInternalEvent_Sensor_Laser_Vars
	\ingroup SensorInternalEvent_Sensor_Laser
	\brief SensorInternalEvent_Sensor_Laser_Vars defines the Vars in SensorInternalEvent_Sensor_Laser.
*/

/*! \addtogroup SensorInternalEvent_Sensor_Laser_Vars
	@{
*/

/*! \file SensorInternalEvent_Sensor_Laser_Vars.h
	 Defines the Vars of SensorInternalEvent_Sensor_Laser
*/

//*******************Please add other headers below*******************

#include <rosinterface.h>
#include <sensor_msgs/LaserScan.h>
#include "SensorInternalEvent_Sensor_Laser_ParamsData.h"

//The Vars is defined as below
/*! \class SensorInternalEvent_Sensor_Laser_Vars 
	\brief The Vars of SensorInternalEvent_Sensor_Laser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Sensor_Laser_Vars 
{
public:
	/*! \fn SensorInternalEvent_Sensor_Laser_Vars()
		\brief The constructor of SensorInternalEvent_Sensor_Laser_Vars. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Sensor_Laser_Vars() 
	{
        llaser_on = rlaser_on = 1;

        queuesize = 100;

        quryinterval = 50;

        lLaserTopic = "LLaser/scan";
        lLaserSub = new ROSSub<sensor_msgs::LaserScan>(lLaserTopic, queuesize, quryinterval);

        rLaserTopic = "RLaser/scan";
        rLaserSub = new ROSSub<sensor_msgs::LaserScan>(rLaserTopic, queuesize, quryinterval);

        laserPubTopic = "/MyLaserPub";
        laserPub = new ROSPub<sensor_msgs::LaserScan>(laserPubTopic, 100, "LaserPub");
	}
	/*! \fn ~SensorInternalEvent_Sensor_Laser_Vars()
		\brief The destructor of SensorInternalEvent_Sensor_Laser_Vars. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Sensor_Laser_Vars() 
	{
        if(lLaserSub != NULL)
        {
            delete lLaserSub;
            lLaserSub = NULL;
        }
        if(rLaserSub != NULL)
        {
            delete rLaserSub;
            rLaserSub = NULL;
        }
	}
public:
	//*******************Please add variables below*******************
    bool llaser_on, rlaser_on;
    QString lLaserTopic, rLaserTopic, laserPubTopic;
    u_int32_t queuesize;
    int quryinterval;
    ROSSub<sensor_msgs::LaserScan>* lLaserSub;
    ROSSub<sensor_msgs::LaserScan>* rLaserSub;
    ROSPub<sensor_msgs::LaserScan>* laserPub;

    sensor_msgs::LaserScan currentLaserPtr;
};

/*! @}*/ 

#endif
