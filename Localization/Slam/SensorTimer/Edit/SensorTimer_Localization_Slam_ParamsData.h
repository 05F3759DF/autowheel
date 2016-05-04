//You need to modify this file.

#ifndef SENSORTIMER_LOCALIZATION_SLAM_PARAMSDATA_H
#define SENSORTIMER_LOCALIZATION_SLAM_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorTimer_Localization_Slam_ParamsData SensorTimer_Localization_Slam_ParamsData
	\ingroup SensorTimer_Localization_Slam
	\brief SensorTimer_Localization_Slam_ParamsData defines the ParamsData in SensorTimer_Localization_Slam.
*/

/*! \addtogroup SensorTimer_Localization_Slam_ParamsData
	@{
*/

/*! \file SensorTimer_Localization_Slam_ParamsData.h
	 Defines the ParamsData of SensorTimer_Localization_Slam
*/

//*******************Please add other headers below*******************
#include <qmath.h>

//There is no input data headers.

/*! \def SensorTimer_Localization_Slam_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define SensorTimer_Localization_Slam_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class SensorTimer_Localization_Slam_Params 
	\brief The Params of SensorTimer_Localization_Slam.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorTimer_Localization_Slam_Params 
{
public:
	/*! \fn SensorTimer_Localization_Slam_Params()
		\brief The constructor of SensorTimer_Localization_Slam_Params. [required]
		\details ****Please add details below****

	*/
	SensorTimer_Localization_Slam_Params() 
	{
		
	}
	/*! \fn ~SensorTimer_Localization_Slam_Params()
		\brief The destructor of SensorTimer_Localization_Slam_Params. [required]
		\details *****Please add details below*****

	*/
	~SensorTimer_Localization_Slam_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//The Output Data is defined as below
/*! \class SensorTimer_Localization_Slam_Data 
	\brief The Data of SensorTimer_Localization_Slam.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorTimer_Localization_Slam_Data 
{
public:
	/*! \fn SensorTimer_Localization_Slam_Data()
		\brief The constructor of SensorTimer_Localization_Slam_Data. [required]
		\details ****Please add details below****

	*/
	SensorTimer_Localization_Slam_Data() 
	{
        x = y = z = 0.0;
        theta = M_PI/2.0;
	}
	/*! \fn ~SensorTimer_Localization_Slam_Data()
		\brief The destructor of SensorTimer_Localization_Slam_Data. [required]
		\details *****Please add details below*****

	*/
	~SensorTimer_Localization_Slam_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    double x, y, z, theta;
    double variance[36];
    int timestamp;
    QTime qtimestamp;
};

/*! \def SensorTimer_Localization_Slam_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define SensorTimer_Localization_Slam_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
