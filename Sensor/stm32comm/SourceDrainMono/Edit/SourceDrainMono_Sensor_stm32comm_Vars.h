//You need to modify this file.

#ifndef SOURCEDRAINMONO_SENSOR_STM32COMM_VARS_H
#define SOURCEDRAINMONO_SENSOR_STM32COMM_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup SourceDrainMono_Sensor_stm32comm_Vars SourceDrainMono_Sensor_stm32comm_Vars
	\ingroup SourceDrainMono_Sensor_stm32comm
	\brief SourceDrainMono_Sensor_stm32comm_Vars defines the Vars in SourceDrainMono_Sensor_stm32comm.
*/

/*! \addtogroup SourceDrainMono_Sensor_stm32comm_Vars
	@{
*/

/*! \file SourceDrainMono_Sensor_stm32comm_Vars.h
	 Defines the Vars of SourceDrainMono_Sensor_stm32comm
*/

//*******************Please add other headers below*******************


#include "SourceDrainMono_Sensor_stm32comm_ParamsData.h"
#include <QtSerialPort/QtSerialPort>
#include <rosinterface.h>
#include <nav_msgs/Odometry.h>
#include <qmath.h>
#include <fstream>
//The Vars is defined as below
/*! \class SourceDrainMono_Sensor_stm32comm_Vars 
	\brief The Vars of SourceDrainMono_Sensor_stm32comm.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SourceDrainMono_Sensor_stm32comm_Vars 
{
public:
	/*! \fn SourceDrainMono_Sensor_stm32comm_Vars()
		\brief The constructor of SourceDrainMono_Sensor_stm32comm_Vars. [required]
		\details ****Please add details below****

	*/
	SourceDrainMono_Sensor_stm32comm_Vars() 
	{
        roll = pitch = yaw = 0;
        quryinterval = 45;
        isinit = 1;

        serialport = new QSerialPort();
        //odompub = new ROSPub<nav_msgs::Odometry>("/odom", 100, "odom_pub");
        //odom2baselink = new ROSTFPub("base_link", "odom");
        baselink2laser = new ROSTFPub("laser", "base_link");
	}
	/*! \fn ~SourceDrainMono_Sensor_stm32comm_Vars()
		\brief The destructor of SourceDrainMono_Sensor_stm32comm_Vars. [required]
		\details *****Please add details below*****

	*/
	~SourceDrainMono_Sensor_stm32comm_Vars() 
	{
        if(serialport->parent() ==  NULL)
        {
            delete serialport;
        }
//        if(odompub != NULL)
//        {
//           delete odompub;
//            odompub == NULL;
//        }
//        if(odom2baselink != NULL)
//        {
//            delete odom2baselink;
//            odom2baselink = NULL;
//        }
        if(baselink2laser != NULL)
        {
            delete baselink2laser;
            baselink2laser = NULL;
        }
	}
public:
	//*******************Please add variables below*******************
    QSerialPort *serialport;
    //publish odom topic and transform
    //ROSTFPub*odom2baselink; //odom --> base_link
    ROSTFPub*baselink2laser; //base_link --> laser
    //ROSPub<nav_msgs::Odometry> *odompub; //publish odom topic

    tf::TransformBroadcaster odom_broadcaster;

    int quryinterval;
    double roll, pitch, yaw, lastyaw;
    int leftencoder, rightencoder, lastleftencoder,lastrightencoder;
    double leftspeed, rightspeed, leftodom, rightodom;
    double deltaleft, deltaright, deltatheta, deltaIMUtheta, deltaEncodertheta;

    ros::Time current_time, last_time;
    double x,y,theta, vx, vy, vtheta;
    bool isinit;

    std::ofstream speedFile;
    //
};

/*! @}*/ 

#endif
