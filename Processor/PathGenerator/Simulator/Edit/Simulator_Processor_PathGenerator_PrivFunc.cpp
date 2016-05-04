//You need to program this file.

#include "../NoEdit/Simulator_Processor_PathGenerator_PrivFunc.h"
#include "../../ProcessorMulti/Edit/ProcessorMulti_Processor_PathGenerator_ParamsData.h"
//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...
inline double dist2D(double x, double y)
{
    return sqrt(x * x + y * y);
}
inline double getTheta(double x1, double y1, double x2, double y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    if (dx == 0) return PI / 2;
    double theta = atan(dy / dx);
    if (dx < 0)
        theta += PI;
    return theta;
}
bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	Simulator_Processor_PathGenerator_Params * params=(Simulator_Processor_PathGenerator_Params *)paramsPtr;
	Simulator_Processor_PathGenerator_Vars * vars=(Simulator_Processor_PathGenerator_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader, vars, offlineTrajecPath);
    GetParamValue(xmlloader, vars, offlineTrajecFilename);
    GetParamValue(xmlloader,vars,path);
    GetParamValue(xmlloader,vars,filename);
    QByteArray ba = (QString("%1%2").arg(vars->path).arg(vars->filename)).toLatin1();
 //   vars->file.setFileName(QString("%1%2").arg(vars->path).arg(vars->filename));
    vars->file.open((ba.data()),ios::in);
    if(!vars->file.is_open())
    {
        return 0;
    }


    QString str = vars->offlineTrajecPath+vars->offlineTrajecFilename;

    FILE *fp = fopen((str).toStdString().c_str(), "r");
    if(fp == NULL)
        return 0;
    double ox, oy, oth;

    while (fscanf(fp, "%lf %lf %lf", &ox, &oy, &oth) == 3)
    {
        trajec_state tmp;
        tmp.x = ox;
        tmp.y = oy;
        tmp.theta = oth;
        vars->taskPoint.push_back(tmp);
    }
    fclose(fp);

    for (int i = 1; i < vars->taskPoint.size(); i++)
    {
        double dist = dist2D(vars->taskPoint[i - 1].x - vars->taskPoint[i].x,
                vars->taskPoint[i - 1].y - vars->taskPoint[i].y);
        double pd = 0.3;
        double ptheta = getTheta(vars->taskPoint[i - 1].x, vars->taskPoint[i - 1].y,
                vars->taskPoint[i].x, vars->taskPoint[i].y);
        while (pd < dist - 0.6)
        {
            trajec_state tmpPoint;
            tmpPoint.x = vars->taskPoint[i - 1].x + pd / dist * (vars->taskPoint[i].x - vars->taskPoint[i - 1].x);
            tmpPoint.y = vars->taskPoint[i - 1].y + pd / dist * (vars->taskPoint[i].y - vars->taskPoint[i - 1].y);
            tmpPoint.theta = ptheta;
            vars->pointList.push_back(tmpPoint);
            pd += 0.1;
        }
    }

	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	Simulator_Processor_PathGenerator_Params * params=(Simulator_Processor_PathGenerator_Params *)paramsPtr;
	Simulator_Processor_PathGenerator_Vars * vars=(Simulator_Processor_PathGenerator_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->file.close();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	Simulator_Processor_PathGenerator_Params * params=(Simulator_Processor_PathGenerator_Params *)paramsPtr;
	Simulator_Processor_PathGenerator_Vars * vars=(Simulator_Processor_PathGenerator_Vars *)varsPtr;
	internalTrigger=NULL;
	internalTriggerSignal=QString();
	/*======Occasionally Program above======*/
	/*
	Function: get internal trigger [defined in vars] for node.
	You need to program here when you need internal trigger (internalTrigger + internalTriggerSignal) for node.
	E.g.
	internalTrigger=&(vars->trigger);
	internalTriggerSignal=QString(SIGNAL(triggerSignal()));
	*/
}

void DECOFUNC(initializeOutputData)(void * paramsPtr, void * varsPtr, boost::shared_ptr<void> & outputDataPtr)
{
	Simulator_Processor_PathGenerator_Params * params=(Simulator_Processor_PathGenerator_Params *)paramsPtr;
	Simulator_Processor_PathGenerator_Vars * vars=(Simulator_Processor_PathGenerator_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new ProcessorMulti_Processor_PathGenerator_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	Simulator_Processor_PathGenerator_Params * params=(Simulator_Processor_PathGenerator_Params *)paramsPtr;
	Simulator_Processor_PathGenerator_Vars * vars=(Simulator_Processor_PathGenerator_Vars *)varsPtr;
	ProcessorMulti_Processor_PathGenerator_Data * outputdata=(ProcessorMulti_Processor_PathGenerator_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/
    if(vars->file.eof())
    {
        return 0;
    }
    int num_of_traj;
    int num_of_point_per_traj;
    trajec_state temp_traj_point;
    ONETRAJDATA temp_traj;
    outputdata->trajSets.clear();
    vars->file >> outputdata->timestamp >> num_of_traj >> outputdata->startPoint.x >> outputdata->startPoint.y >> outputdata->startPoint.theta;
    for(int i = 0; i < num_of_traj; i++)
    {
        vars->file >> num_of_point_per_traj;
        temp_traj.trajdat.clear();
        for(int j = 0; j < num_of_point_per_traj; j++)
        {
            vars->file >> temp_traj_point.x >> temp_traj_point.y;
            temp_traj.trajdat.push_back(temp_traj_point);
        }
        outputdata->trajSets.push_back(temp_traj);
    }
    vars->file >> num_of_point_per_traj;
    vars->file >> outputdata->index;//这句话是假的
    outputdata->index = num_of_traj;
    temp_traj.trajdat.clear();
    for(int j = 0; j < num_of_point_per_traj; j++)
    {
        vars->file >> temp_traj_point.x >> temp_traj_point.y;
        temp_traj.trajdat.push_back(temp_traj_point);
    }
    outputdata->trajSets.push_back(temp_traj);
    timeStamp = QTime::fromMSecsSinceStartOfDay(outputdata->timestamp);


    outputdata->pointList = vars->pointList;
    return 1;
}

