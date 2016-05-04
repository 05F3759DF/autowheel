//You need to modify this file.

#ifndef SENSORTIMER_SIMULATOR_INDEXGENERATOR_PARAMSDATA_H
#define SENSORTIMER_SIMULATOR_INDEXGENERATOR_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorTimer_Simulator_IndexGenerator_ParamsData SensorTimer_Simulator_IndexGenerator_ParamsData
	\ingroup SensorTimer_Simulator_IndexGenerator
	\brief SensorTimer_Simulator_IndexGenerator_ParamsData defines the ParamsData in SensorTimer_Simulator_IndexGenerator.
*/

/*! \addtogroup SensorTimer_Simulator_IndexGenerator_ParamsData
	@{
*/

/*! \file SensorTimer_Simulator_IndexGenerator_ParamsData.h
	 Defines the ParamsData of SensorTimer_Simulator_IndexGenerator
*/

//*******************Please add other headers below*******************


//There is no input data headers.

/*! \def SensorTimer_Simulator_IndexGenerator_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define SensorTimer_Simulator_IndexGenerator_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class SensorTimer_Simulator_IndexGenerator_Params 
	\brief The Params of SensorTimer_Simulator_IndexGenerator.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorTimer_Simulator_IndexGenerator_Params 
{
public:
	/*! \fn SensorTimer_Simulator_IndexGenerator_Params()
		\brief The constructor of SensorTimer_Simulator_IndexGenerator_Params. [required]
		\details ****Please add details below****

	*/
	SensorTimer_Simulator_IndexGenerator_Params() 
	{
        filePath = "./";
        fileName = "labels.txt";
	}
	/*! \fn ~SensorTimer_Simulator_IndexGenerator_Params()
		\brief The destructor of SensorTimer_Simulator_IndexGenerator_Params. [required]
		\details *****Please add details below*****

	*/
	~SensorTimer_Simulator_IndexGenerator_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QString filePath;
    QString fileName;
};

//The Output Data is defined as below
/*! \class SensorTimer_Simulator_IndexGenerator_Data 
	\brief The Data of SensorTimer_Simulator_IndexGenerator.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorTimer_Simulator_IndexGenerator_Data 
{
public:
	/*! \fn SensorTimer_Simulator_IndexGenerator_Data()
		\brief The constructor of SensorTimer_Simulator_IndexGenerator_Data. [required]
		\details ****Please add details below****

	*/
	SensorTimer_Simulator_IndexGenerator_Data() 
	{
        index = 10;
	}
	/*! \fn ~SensorTimer_Simulator_IndexGenerator_Data()
		\brief The destructor of SensorTimer_Simulator_IndexGenerator_Data. [required]
		\details *****Please add details below*****

	*/
	~SensorTimer_Simulator_IndexGenerator_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    int index;
};

/*! \def SensorTimer_Simulator_IndexGenerator_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define SensorTimer_Simulator_IndexGenerator_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
