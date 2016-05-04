//You need to modify this file.

#ifndef SIMULATOR_LOCALIZATION_SLAM_PARAMSDATA_H
#define SIMULATOR_LOCALIZATION_SLAM_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Localization_Slam_ParamsData Simulator_Localization_Slam_ParamsData
	\ingroup Simulator_Localization_Slam
	\brief Simulator_Localization_Slam_ParamsData defines the ParamsData in Simulator_Localization_Slam.
*/

/*! \addtogroup Simulator_Localization_Slam_ParamsData
	@{
*/

/*! \file Simulator_Localization_Slam_ParamsData.h
	 Defines the ParamsData of Simulator_Localization_Slam
*/

//*******************Please add other headers below*******************


//There is no input data headers.

/*! \def Simulator_Localization_Slam_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define Simulator_Localization_Slam_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class Simulator_Localization_Slam_Params 
	\brief The Params of Simulator_Localization_Slam.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Localization_Slam_Params 
{
public:
	/*! \fn Simulator_Localization_Slam_Params()
		\brief The constructor of Simulator_Localization_Slam_Params. [required]
		\details ****Please add details below****

	*/
	Simulator_Localization_Slam_Params() 
	{
		
	}
	/*! \fn ~Simulator_Localization_Slam_Params()
		\brief The destructor of Simulator_Localization_Slam_Params. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Localization_Slam_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//The Output Data SensorTimer_Localization_Slam_Data is defined in the header below
#include<wheelchair/Localization/Slam/SensorTimer/Edit/SensorTimer_Localization_Slam_ParamsData.h>

/*! \def Simulator_Localization_Slam_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define Simulator_Localization_Slam_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif