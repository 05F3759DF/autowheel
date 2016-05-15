//You need to program this file.

#include "../NoEdit/ProcessorMulti_Processor_PathGenerator_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...
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
    ProcessorMulti_Processor_PathGenerator_Params * params=(ProcessorMulti_Processor_PathGenerator_Params *)paramsPtr;
    ProcessorMulti_Processor_PathGenerator_Vars * vars=(ProcessorMulti_Processor_PathGenerator_Vars *)varsPtr;
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
    GetParamValue(xmlloader, vars, logFilePath);
    GetParamValue(xmlloader, vars, logFileName);

    GetParamValue(xmlloader, params, planDist);
    GetParamValue(xmlloader, params, trajNum);
    GetParamValue(xmlloader, params, nextDis);
    GetParamValue(xmlloader, vars, distanceUsed);
    GetParamValue(xmlloader, params, saveLog);
    GetParamValue(xmlloader, vars, stopPlanning);

    QString tmpfilename = QString("%1/%2").arg(vars->logFilePath).arg(vars->logFileName);
    const char* filename = tmpfilename.toStdString().c_str();
    if (params->saveLog)
    {
        vars->logFile = fopen(filename, "w");
    }
    QString str = vars->offlineTrajecPath + vars->offlineTrajecFilename;

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
//        double dist = dist2D(vars->taskPoint[i - 1].x - vars->taskPoint[i].x,
//                vars->taskPoint[i - 1].y - vars->taskPoint[i].y);
//        double pd = 0.3;
//        double ptheta = getTheta(vars->taskPoint[i - 1].x, vars->taskPoint[i - 1].y,
//                vars->taskPoint[i].x, vars->taskPoint[i].y);
//        while (pd < dist - 0.01)
//        {
//            trajec_state tmpPoint;
//            tmpPoint.x = vars->taskPoint[i - 1].x + pd / dist * (vars->taskPoint[i].x - vars->taskPoint[i - 1].x);
//            tmpPoint.y = vars->taskPoint[i - 1].y + pd / dist * (vars->taskPoint[i].y - vars->taskPoint[i - 1].y);
//            tmpPoint.theta = ptheta;
//            vars->pointList.push_back(tmpPoint);
//            pd += 0.1;
//        }
        vars->pointList.push_back(vars->taskPoint[i]);
    }

    return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
    ProcessorMulti_Processor_PathGenerator_Params * params=(ProcessorMulti_Processor_PathGenerator_Params *)paramsPtr;
    ProcessorMulti_Processor_PathGenerator_Vars * vars=(ProcessorMulti_Processor_PathGenerator_Vars *)varsPtr;
    /*======Please Program below======*/
    /*
    Function: close node.
    Procedure:
    1: handle/close variables (vars).
    2: If everything is OK, return 1 for successful closing and vice versa.
    */
    if(params->saveLog)
        fclose(vars->logFile);
    return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
    ProcessorMulti_Processor_PathGenerator_Params * params=(ProcessorMulti_Processor_PathGenerator_Params *)paramsPtr;
    ProcessorMulti_Processor_PathGenerator_Vars * vars=(ProcessorMulti_Processor_PathGenerator_Vars *)varsPtr;
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
    ProcessorMulti_Processor_PathGenerator_Params * params=(ProcessorMulti_Processor_PathGenerator_Params *)paramsPtr;
    ProcessorMulti_Processor_PathGenerator_Vars * vars=(ProcessorMulti_Processor_PathGenerator_Vars *)varsPtr;
    outputDataPtr=boost::shared_ptr<void>(new ProcessorMulti_Processor_PathGenerator_Data());
    /*======Occasionally Program below/above======*/
    /*
    Function: initial output data.
    You need to program here when you need to manually initialize output data.
    */

}

void DECOFUNC(getMultiInputDataSize)(void * paramsPtr, void * varsPtr, QList<int> & inputDataSize)
{
    ProcessorMulti_Processor_PathGenerator_Params * params=(ProcessorMulti_Processor_PathGenerator_Params *)paramsPtr;
    ProcessorMulti_Processor_PathGenerator_Vars * vars=(ProcessorMulti_Processor_PathGenerator_Vars *)varsPtr;
    inputDataSize=QList<int>();
    /*======Please Program above======*/
    /*
    Function: get input data size to be grabbed from buffer.
    Rules:
    inputDataSize=0: grab and remove all data from buffer.
    inputDataSize>0: grab inputDataSize latest data from buffer.
    inputDataSize<0: grab and remove inputDataSize ancient data from buffer.
    E.g.
    inputDataSize=QList<int>()<<0<<1<<-1...;
    */
}

//Input Port #0: Buffer_Size = 10, Params_Type = SourceDrainMono_Sensor_stm32comm_Params, Data_Type = SourceDrainMono_Sensor_stm32comm_Data
//Input Port #1: Buffer_Size = 10, Params_Type = ProcessorMono_Processor_EvaluateFunction_Params, Data_Type = ProcessorMono_Processor_EvaluateFunction_Data
//Input Port #2: Buffer_Size = 10, Params_Type = SensorTimer_Localization_Slam_Params, Data_Type = SensorTimer_Localization_Slam_Data
bool DECOFUNC(processMultiInputData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > inputParams, QVector<QVector<void *> > inputData, void * outputData, QList<int> & outputPortIndex)
{
    ProcessorMulti_Processor_PathGenerator_Params * params=(ProcessorMulti_Processor_PathGenerator_Params *)paramsPtr;
    ProcessorMulti_Processor_PathGenerator_Vars * vars=(ProcessorMulti_Processor_PathGenerator_Vars *)varsPtr;
    QVector<SourceDrainMono_Sensor_stm32comm_Params *> inputparams_0; copyQVector(inputparams_0,inputParams[0]);
    QVector<ProcessorMono_Processor_EvaluateFunction_Params *> inputparams_1; copyQVector(inputparams_1,inputParams[1]);
    QVector<SensorTimer_Localization_Slam_Params *> inputparams_2; copyQVector(inputparams_2,inputParams[2]);
    QVector<SourceDrainMono_Sensor_stm32comm_Data *> inputdata_0; copyQVector(inputdata_0,inputData[0]);
    QVector<ProcessorMono_Processor_EvaluateFunction_Data *> inputdata_1; copyQVector(inputdata_1,inputData[1]);
    QVector<SensorTimer_Localization_Slam_Data *> inputdata_2; copyQVector(inputdata_2,inputData[2]);
    ProcessorMulti_Processor_PathGenerator_Data * outputdata=(ProcessorMulti_Processor_PathGenerator_Data *)outputData;
    outputPortIndex=QList<int>();
    if(inputdata_0.size()==0){return 0;}
    if(inputdata_1.size()==0){return 0;}
    // if(inputdata_2.size()==0){return 0;}
    /*======Please Program below======*/
    /*
    Step 1: process inputdata_index, then store it into outputdata.
    Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
    E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
    */
    ProcessorMono_Processor_EvaluateFunction_Data *evaluate = inputdata_1.front();
    PG_kelly pg;
    trajec_state startState = {0, 0, PI / 2, 0};
    trajec_state endState = {0, 3, PI / 2 , 0};
    double x, y, theta;
    outputdata->front_barrier.clear();
    if(vars->stopPlanning)
    {
        x = y = 0;
        return 1;
    }
    else
    {
        x = outputdata->startPoint.x = inputdata_0.front()->x;
        y = outputdata->startPoint.y = inputdata_0.front()->y;
        theta = outputdata->startPoint.theta = inputdata_0.front()->theta;

        outputdata->angle = theta;
        outputdata->pointList = vars->pointList;

        outputdata->index = evaluate->index;

        // 找到轨迹中离当前点最近的点
        int label = -1;
        double dis = 10000000;
        for (int i = 0; i < vars->pointList.size(); i++)
        {
            trajec_state ts = vars->pointList[i];
            double tmp = (ts.x - x) * (ts.x - x) + (ts.y - y) * (ts.y - y);
            if (tmp < dis)
            {
                dis = tmp;
                label = i;
            }
        }

        //向前找nextDis长度的点，作为规划的中心目标点
        double ex, ey, etheta;
        while (label < vars->pointList.size())
        {
            ex = endState.x = vars->pointList[label].x;
            ey = endState.y = vars->pointList[label].y;
            etheta = vars->pointList.at(label).theta ;
            double dist = (ex - x) * (ex - x) + (ey - y) * (ey - y);
            if (dist > params->nextDis) break;
            label++;
        }
        qDebug() << 'label - ' << label;
        //如果走完了全部轨迹，停止规划
        if (label > vars->pointList.size() - 5)
        {
            outputdata->stop = true;
            return 1;
        }

        //预瞄点转化到局部坐标系下
        ex -= x;
        ey -= y;
        vars->rotate(ex, ey, theta - PI / 2);
        endState.theta += etheta - theta;

        for (int i = -params->trajNum; i <= params->trajNum; i++)
        {
            ONETRAJDATA tmp;
            trajec_state traj;
            tmp.trajdat.clear();
            tmp.valid = true;
            tmp.cost = 0;

            endState.x = ex + 0.05 * i * sin(endState.theta) + params->planDist * cos(endState.theta);
            endState.y = ey - 0.05 * i * cos(endState.theta) + params->planDist * sin(endState.theta);

            pg.Path_Generating(startState, endState);
            int num = pg.state_data.size();

            //这里忘了= =
            double tx = ex  + 0.05 * i * sin(endState.theta);// target point
            double ty = ey  - 0.05 * i * cos(endState.theta);
            vars->rotate(tx, ty, PI / 2 - theta);
            traj.x = x + tx;
            traj.y = y + ty;
            outputdata->nextPoint.push_back(traj);

            //将所有轨迹转化为全局坐标系
            for (int k = 0; k < num; k++)
            {
                tx = pg.state_data[k].x;
                ty = pg.state_data[k].y;
                vars->rotate(tx, ty, PI / 2 - theta);
                traj.x = x + tx;
                traj.y = y + ty;
                traj.theta = pg.state_data[k].theta;
                tmp.trajdat.push_back(traj);
            }
            outputdata->trajSets.push_back(tmp);
        }
        if (outputdata->trajSets.size() == 0 || outputdata->trajSets[outputdata->index].trajdat.size() == 0) {
            return 1;
        }
        //获得预瞄点
        int preIndex = vars->getIndex(outputdata->startPoint, outputdata->trajSets[outputdata->index].trajdat);
        outputdata->targetPoint = outputdata->trajSets[outputdata->index].trajdat[preIndex];
        vars->last_traj = outputdata->trajSets;
        vars->last_index = outputdata->index;
        double curcost = outputdata->trajSets[outputdata->index].cost;
        double angleThresh = M_PI / 24.0 * double(outputdata->trajSets[outputdata->index].trajdat.size());
        if(curcost > angleThresh) //outputdata->trajSets[outputdata->index].cost*1.2) //大于均值设置为慢速
        {
            outputdata->speedState = outputdata->LOW;
        }
        else
        {
            outputdata->speedState = outputdata->MID;
        }
    }

    //如果到左右墙的距离小于3m
//    if((evaluate->d2leftwall+evaluate->d2rightwall) < 2)
//        outputdata->speedState = outputdata->LOW;
    return 1;
}

