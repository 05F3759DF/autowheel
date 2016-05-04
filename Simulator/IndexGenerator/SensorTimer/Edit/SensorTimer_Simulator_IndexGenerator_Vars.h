//You need to modify this file.

#ifndef SENSORTIMER_SIMULATOR_INDEXGENERATOR_VARS_H
#define SENSORTIMER_SIMULATOR_INDEXGENERATOR_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorTimer_Simulator_IndexGenerator_Vars SensorTimer_Simulator_IndexGenerator_Vars
	\ingroup SensorTimer_Simulator_IndexGenerator
	\brief SensorTimer_Simulator_IndexGenerator_Vars defines the Vars in SensorTimer_Simulator_IndexGenerator.
*/

/*! \addtogroup SensorTimer_Simulator_IndexGenerator_Vars
	@{
*/

/*! \file SensorTimer_Simulator_IndexGenerator_Vars.h
	 Defines the Vars of SensorTimer_Simulator_IndexGenerator
*/

//*******************Please add other headers below*******************


#include "SensorTimer_Simulator_IndexGenerator_ParamsData.h"

//The Vars is defined as below
/*! \class SensorTimer_Simulator_IndexGenerator_Vars 
	\brief The Vars of SensorTimer_Simulator_IndexGenerator.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorTimer_Simulator_IndexGenerator_Vars 
{
public:
	/*! \fn SensorTimer_Simulator_IndexGenerator_Vars()
		\brief The constructor of SensorTimer_Simulator_IndexGenerator_Vars. [required]
		\details ****Please add details below****

	*/
	SensorTimer_Simulator_IndexGenerator_Vars() 
	{
		
	}
	/*! \fn ~SensorTimer_Simulator_IndexGenerator_Vars()
		\brief The destructor of SensorTimer_Simulator_IndexGenerator_Vars. [required]
		\details *****Please add details below*****

	*/
	~SensorTimer_Simulator_IndexGenerator_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    FILE *labels;
};

/*! @}*/ 

#endif
