//You need to modify this file.

#ifndef SIMULATOR_PROCESSOR_PATHGENERATOR_VARS_H
#define SIMULATOR_PROCESSOR_PATHGENERATOR_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Processor_PathGenerator_Vars Simulator_Processor_PathGenerator_Vars
	\ingroup Simulator_Processor_PathGenerator
	\brief Simulator_Processor_PathGenerator_Vars defines the Vars in Simulator_Processor_PathGenerator.
*/

/*! \addtogroup Simulator_Processor_PathGenerator_Vars
	@{
*/

/*! \file Simulator_Processor_PathGenerator_Vars.h
	 Defines the Vars of Simulator_Processor_PathGenerator
*/

//*******************Please add other headers below*******************


#include "Simulator_Processor_PathGenerator_ParamsData.h"

//The Vars is defined as below
/*! \class Simulator_Processor_PathGenerator_Vars 
	\brief The Vars of Simulator_Processor_PathGenerator.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Processor_PathGenerator_Vars 
{
public:
	/*! \fn Simulator_Processor_PathGenerator_Vars()
		\brief The constructor of Simulator_Processor_PathGenerator_Vars. [required]
		\details ****Please add details below****

	*/
	Simulator_Processor_PathGenerator_Vars() 
	{
            path=QString("#(DataPath)");
            filename=QString("123");
            offlineTrajecPath = "./";
            offlineTrajecFilename = "line.txt";
	}
	/*! \fn ~Simulator_Processor_PathGenerator_Vars()
		\brief The destructor of Simulator_Processor_PathGenerator_Vars. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Processor_PathGenerator_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    ifstream file;
    QString path;
    QString filename;

    QString offlineTrajecPath;// 离线路点文件
    QString offlineTrajecFilename;

    QVector<trajec_state> taskPoint; // 路点
    QVector<trajec_state> pointList; // 根据路点生成的路径
};

/*! @}*/ 

#endif
