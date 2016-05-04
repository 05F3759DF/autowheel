//You need to modify this file.

#ifndef SIMULATOR_LOCALIZATION_SLAM_VARS_H
#define SIMULATOR_LOCALIZATION_SLAM_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Localization_Slam_Vars Simulator_Localization_Slam_Vars
	\ingroup Simulator_Localization_Slam
	\brief Simulator_Localization_Slam_Vars defines the Vars in Simulator_Localization_Slam.
*/

/*! \addtogroup Simulator_Localization_Slam_Vars
	@{
*/

/*! \file Simulator_Localization_Slam_Vars.h
	 Defines the Vars of Simulator_Localization_Slam
*/

//*******************Please add other headers below*******************
#include <fstream>


#include "Simulator_Localization_Slam_ParamsData.h"
using namespace std;
//The Vars is defined as below
/*! \class Simulator_Localization_Slam_Vars 
	\brief The Vars of Simulator_Localization_Slam.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Localization_Slam_Vars 
{
public:
	/*! \fn Simulator_Localization_Slam_Vars()
		\brief The constructor of Simulator_Localization_Slam_Vars. [required]
		\details ****Please add details below****

	*/
	Simulator_Localization_Slam_Vars() 
	{
		
	}
	/*! \fn ~Simulator_Localization_Slam_Vars()
		\brief The destructor of Simulator_Localization_Slam_Vars. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Localization_Slam_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
//    double x, y, z, yaw;
//    double variance[36];
    QString filepath, filename;

    ifstream slamFile;
};

/*! @}*/ 

#endif
