//You need to modify this file.

#ifndef SENSORTIMER_LOCALIZATION_SLAM_VARS_H
#define SENSORTIMER_LOCALIZATION_SLAM_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorTimer_Localization_Slam_Vars SensorTimer_Localization_Slam_Vars
	\ingroup SensorTimer_Localization_Slam
	\brief SensorTimer_Localization_Slam_Vars defines the Vars in SensorTimer_Localization_Slam.
*/

/*! \addtogroup SensorTimer_Localization_Slam_Vars
	@{
*/

/*! \file SensorTimer_Localization_Slam_Vars.h
	 Defines the Vars of SensorTimer_Localization_Slam
*/

//*******************Please add other headers below*******************
#include "rosinterface.h"
#include <geometry_msgs/PoseWithCovarianceStamped.h>

#include "SensorTimer_Localization_Slam_ParamsData.h"
#include <fstream>
using namespace std;
//The Vars is defined as below
/*! \class SensorTimer_Localization_Slam_Vars 
	\brief The Vars of SensorTimer_Localization_Slam.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorTimer_Localization_Slam_Vars 
{
public:
	/*! \fn SensorTimer_Localization_Slam_Vars()
		\brief The constructor of SensorTimer_Localization_Slam_Vars. [required]
		\details ****Please add details below****

	*/
	SensorTimer_Localization_Slam_Vars() 
	{
        //slamSub = new ROSSub<geometry_msgs::PoseWithCovarianceStampedConstPtr>("/amcl_pose", 100, 100, "SLAMSub");
	}
	/*! \fn ~SensorTimer_Localization_Slam_Vars()
		\brief The destructor of SensorTimer_Localization_Slam_Vars. [required]
		\details *****Please add details below*****

	*/
	~SensorTimer_Localization_Slam_Vars() 
	{
//        if(slamSub != NULL)
//        {
//            delete slamSub;
//            slamSub = NULL;
//        }
	}
public:
	//*******************Please add variables below*******************
    //ROSSub<geometry_msgs::PoseWithCovarianceStampedConstPtr>* slamSub;
    tf::TransformListener listener;
    double x, y, z, yaw;
    double variance[36];

    QString storagepath;
    ofstream slamFile;
};

/*! @}*/ 

#endif
