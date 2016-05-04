//You need to modify this file.

#ifndef PROCESSORMULTI_PROCESSOR_SIMPLECOLLECT_VARS_H
#define PROCESSORMULTI_PROCESSOR_SIMPLECOLLECT_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Processor_SimpleCollect_Vars ProcessorMulti_Processor_SimpleCollect_Vars
	\ingroup ProcessorMulti_Processor_SimpleCollect
	\brief ProcessorMulti_Processor_SimpleCollect_Vars defines the Vars in ProcessorMulti_Processor_SimpleCollect.
*/

/*! \addtogroup ProcessorMulti_Processor_SimpleCollect_Vars
	@{
*/

/*! \file ProcessorMulti_Processor_SimpleCollect_Vars.h
	 Defines the Vars of ProcessorMulti_Processor_SimpleCollect
*/

//*******************Please add other headers below*******************

#include <fstream>
#include <QMediaPlayer>
#include "ProcessorMulti_Processor_SimpleCollect_ParamsData.h"

//The Vars is defined as below
/*! \class ProcessorMulti_Processor_SimpleCollect_Vars 
	\brief The Vars of ProcessorMulti_Processor_SimpleCollect.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Processor_SimpleCollect_Vars 
{
public:
	/*! \fn ProcessorMulti_Processor_SimpleCollect_Vars()
		\brief The constructor of ProcessorMulti_Processor_SimpleCollect_Vars. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Processor_SimpleCollect_Vars() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Processor_SimpleCollect_Vars()
		\brief The destructor of ProcessorMulti_Processor_SimpleCollect_Vars. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Processor_SimpleCollect_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    std::ofstream laserfilewriter;
    std::ofstream odomfilewriter;
    bool isSimple, isOpenFile;
    QString status;
};

/*! @}*/ 

#endif
