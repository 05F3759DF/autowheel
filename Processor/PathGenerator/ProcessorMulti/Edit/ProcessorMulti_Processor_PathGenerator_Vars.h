//You need to modify this file.

#ifndef PROCESSORMULTI_PROCESSOR_PATHGENERATOR_VARS_H
#define PROCESSORMULTI_PROCESSOR_PATHGENERATOR_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Processor_PathGenerator_Vars ProcessorMulti_Processor_PathGenerator_Vars
	\ingroup ProcessorMulti_Processor_PathGenerator
	\brief ProcessorMulti_Processor_PathGenerator_Vars defines the Vars in ProcessorMulti_Processor_PathGenerator.
*/

/*! \addtogroup ProcessorMulti_Processor_PathGenerator_Vars
	@{
*/

/*! \file ProcessorMulti_Processor_PathGenerator_Vars.h
	 Defines the Vars of ProcessorMulti_Processor_PathGenerator
*/

//*******************Please add other headers below*******************
#include "ProcessorMulti_Processor_PathGenerator_ParamsData.h"
#include "../barrier_detect.h"

inline double dist2D(double x, double y)
{
    return sqrt(x * x + y * y);
}

//The Vars is defined as below
/*! \class ProcessorMulti_Processor_PathGenerator_Vars 
	\brief The Vars of ProcessorMulti_Processor_PathGenerator.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Processor_PathGenerator_Vars 
{
public:
	/*! \fn ProcessorMulti_Processor_PathGenerator_Vars()
		\brief The constructor of ProcessorMulti_Processor_PathGenerator_Vars. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Processor_PathGenerator_Vars() 
	{
        offlineTrajecPath = "./";
        offlineTrajecFilename = "line.txt";
        rebuild = 1;
        logFilePath = "./";
        logFileName = "generator.log";
        stopPlanning = 1;
        distanceUsed = 1;
        lastPoint.x = lastPoint.y = 0;
        lastPoint.theta = 1.57;
        color = 0;
	}
	/*! \fn ~ProcessorMulti_Processor_PathGenerator_Vars()
		\brief The destructor of ProcessorMulti_Processor_PathGenerator_Vars. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Processor_PathGenerator_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QString offlineTrajecPath;// 离线路点文件
    QString offlineTrajecFilename;

    QString logFilePath;
    QString logFileName;
    FILE *logFile;

    ONETRAJDATA trajs;
    QVector<ONETRAJDATA > last_traj;
    int last_index;
    int rebuild; // 标志位-表示是否重规划
    double distanceUsed;

    QVector<trajec_state> taskPoint; // 路点
    QVector<trajec_state> pointList; // 根据路点生成的路径

    trajec_state lastPoint;
    int lastLabel;

    double averageCost; //为了测试cost临时加入
    bool stopPlanning;


    int color;
     void rotate(double &x, double &y, const double th0)
     {
         double tx = x * cos(th0) + y * sin(th0);
         double ty = -x * sin(th0) + y * cos(th0);
         x = tx;
         y = ty;
     }
     int getIndex(trajec_state startPoint, QVector<trajec_state> traj) // 获得当前轨迹上的目标点，如果当前轨迹已经走到头，则返回-1
     {
         int index = 0;
         trajec_state firstPoint, targetPoint;
         double dist = (traj[0].x - startPoint.x) * (traj[0].x - startPoint.x) + (traj[0].y - startPoint.y) * (traj[0].y - startPoint.y);
         for (int i = 1; i < traj.size(); i++)
         {
             double tmp = (traj[i].x - startPoint.x) * (traj[i].x - startPoint.x) + (traj[i].y - startPoint.y) * (traj[i].y - startPoint.y);
             if (tmp < dist)
             {
                 index = i;
                 dist = tmp;
             }
         }
         firstPoint = traj[0];
         targetPoint = traj[index];
         int index0 = index;
         while (index < traj.size() && dist2D(traj[index].x - startPoint.x, traj[index].y - startPoint.y) < distanceUsed)
             index++;
         index = max(index, index0 + 80);
         if (index > traj.size())
             index = traj.size() - 1;
         return index;
     }
};

/*! @}*/ 

#endif
