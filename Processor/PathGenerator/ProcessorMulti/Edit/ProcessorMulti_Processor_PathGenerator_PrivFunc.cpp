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
    if(inputdata_2.size()==0){return 0;}
    /*======Please Program below======*/
    /*
    Step 1: process inputdata_index, then store it into outputdata.
    Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
    E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
    */
    ProcessorMono_Processor_EvaluateFunction_Data *evaluate = inputdata_1.front();
    SensorTimer_Localization_Slam_Data *slam  = inputdata_2.front();
    PG_kelly pg;
    trajec_state startState = {0, 0, PI / 2, 0};
    trajec_state endState = {0, 3, PI / 2 , 0};
    double x, y, theta;
    outputdata->front_barrier.clear();
    if(vars->stopPlanning)
    {
        x = y = 0;
    }
    else
    {
#if 0
        ///使用惯导编码器定位
        x = outputdata->startPoint.x = inputdata_0.front()->x;
        y = outputdata->startPoint.y = inputdata_0.front()->y;
        theta = outputdata->startPoint.theta = inputdata_0.front()->theta;
#else
        ///使用SLAM定位
        x = outputdata->startPoint.x = slam->x;
        y = outputdata->startPoint.y = slam->y;
        theta = outputdata->startPoint.theta = slam->theta;
#endif
    }
    //碰撞检测的参数
    int URGDataSize = evaluate->URGData_size;
    double IMUorientation = slam->theta;
    double IMUx = slam->x;
    double IMUy = slam->y;
    double IMUx_lmsl = IMUx + nav_shift_f*cos(IMUorientation) - nav_shift_s*sin(IMUorientation);//*******ÕýžººÅ¿ÉÄÜÒªµ÷
    double IMUy_lmsl = IMUy + nav_shift_f*sin(IMUorientation) + nav_shift_s*cos(IMUorientation);
    double IMUx_lmsr = IMUx + nav_shift_f*cos(IMUorientation) + nav_shift_s*sin(IMUorientation);//*******ÕýžººÅ¿ÉÄÜÒªµ÷
    double IMUy_lmsr = IMUy + nav_shift_f*sin(IMUorientation) - nav_shift_s*cos(IMUorientation);

    double front_center_x = (IMUx_lmsl+IMUx_lmsr)/2;
    double front_center_y = (IMUy_lmsl+IMUy_lmsr)/2;
    double back_center_x = IMUx;//椭圆焦点们
    double back_center_y = IMUy;
    front_center_x = 4*front_center_x -3*back_center_x;//椭圆前焦点
    front_center_y = 4*front_center_y - 3*back_center_y;//椭圆焦点
    outputdata->size = 3;//两倍长轴
    outputdata->front_center.x = front_center_x;//
    outputdata->front_center.y = front_center_y;
    outputdata->back_center.x = back_center_x;
    outputdata->back_center.y = back_center_y;
    outputdata->angle = IMUorientation;

    outputdata->pointList = vars->pointList;

    //测试避障
    int trajNum ;
    ///使用SLAM定位trajs.trajdat
    outputdata->index = inputdata_1.front()->index;

    ///away from the door area
    if (y > 20.0) outputdata->index = params->trajNum;
    outputdata->timestamp = slam->timestamp;
    if (params->saveLog)
    {
        fprintf(vars->logFile, "%d\t%d\t%lf\t%lf\t%lf\n", inputdata_0.front()->timestamp,
                outputdata->index, x, y, theta);
    }

    //检测障碍，判断当前是否有好的轨迹
//    if (vars->rebuild != 1)
//    {
//        outputdata->front_barrier = colli_detect(evaluate,slam,front_center_x,front_center_y,back_center_x,back_center_y,outputdata->size);//正面 内近处激光点坐标
//        path_exclude(outputdata->front_barrier,  vars->last_traj);
//        if (!vars->last_traj[outputdata->index].valid || outputdata->front_barrier.size() > 10)
//        {
//            vars->rebuild = 1;
//        }
//    }
    while (true)
    {
        if (vars->rebuild == 1)
        {
            //for test
            x = outputdata->startPoint.x = vars->lastPoint.x;
            y = outputdata->startPoint.y = vars->lastPoint.y;
            theta = outputdata->startPoint.theta = vars->lastPoint.theta;
            vars->lastLabel = 0;

            for (int i = 0; i < outputdata->trajSets.size(); i++)
                outputdata->trajSets[i].trajdat.clear();
            outputdata->trajSets.clear();
            vars->color++;
            //找到轨迹上里当前位置最近的点
            int label = -1;
            double dis = 100000;
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
            label += 15;
            label = min(label, vars->pointList.size() - 1);
            double ex, ey, etheta;
            while (label < vars->pointList.size())
            {
                ex = endState.x = vars->pointList.at(label).x;
                ey = endState.y = vars->pointList.at(label).y;
                etheta = vars->pointList.at(label).theta ;
                double dist = (ex-x)*(ex-x)+(ey-y)*(ey-y);
                if (dist > params->nextDis) break;
                label++;
            }

            if (label < vars->pointList.size() - 25)
            {
                if (fabs(vars->pointList[label].theta - vars->pointList[label + 20].theta) > PI / 6)
                    label += 24;
            }
            //如果走完了全部轨迹，停止规划
            if (label > vars->pointList.size() - 5)
            {
                outputdata->stop = true;
                vars->rebuild = 1;
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

            ///0624为了测试避障加入
            ///碰撞检测
            outputdata->front_barrier = colli_detect(evaluate,slam,front_center_x,front_center_y,
                                                     back_center_x,back_center_y,outputdata->size);//正面 内近处激光点坐标
            path_exclude(outputdata->front_barrier,  outputdata->trajSets);
            ///以下代码测试避障用
            //outputdata->index = getNearestTraj(outputdata->trajSets, outputdata->index);

            ///计算cost,轨迹相邻两点斜率和
            vars->averageCost = calcTrajSumCost(outputdata->trajSets, trajNum);
            vars->averageCost = vars->averageCost/double(trajNum);

            //获得预瞄点
            int preIndex = vars->getIndex(outputdata->startPoint, outputdata->trajSets[outputdata->index].trajdat);
            outputdata->targetPoint = outputdata->trajSets[outputdata->index].trajdat[preIndex];
            vars->last_traj = outputdata->trajSets;
            vars->last_index = outputdata->index;
            vars->rebuild = 0;
            outputdata->newColor = vars->color;
            break;
        }
        else
        {
            outputdata->trajSets = vars->last_traj;

            //for test
            x = outputdata->startPoint.x = vars->lastPoint.x;
            y = outputdata->startPoint.y = vars->lastPoint.y;
            theta = outputdata->startPoint.theta = vars->lastPoint.theta;
            vars->lastLabel++;

            int preIndex = vars->getIndex(outputdata->startPoint, outputdata->trajSets[vars->last_index].trajdat);
            if (preIndex != -1)
            {
                outputdata->index = vars->last_index;
                outputdata->targetPoint = outputdata->trajSets[outputdata->index].trajdat[preIndex];
                outputdata->nextPoint.clear();


                if (vars->lastLabel < outputdata->trajSets[outputdata->index].trajdat.size() - 11)
                {
                    vars->lastPoint = outputdata->trajSets[outputdata->index].trajdat[vars->lastLabel];
                    break;
                }
                else
                    vars->rebuild = 1;

            }
            else
            {
                vars->rebuild = 1;
            }
        }

    }

    //for test
   outputdata->newColor = vars->color;
    //检测障碍，判断规划完成后是否有好的轨迹
    outputdata->front_barrier = colli_detect(evaluate,slam,front_center_x,front_center_y,back_center_x,back_center_y,outputdata->size);//正面 内近处激光点坐标
    path_exclude(outputdata->front_barrier,  outputdata->trajSets);
    if (!outputdata->trajSets[outputdata->index].valid)
    {
        outputdata->stop = true;
        return 1;
    }

    //速度模式设置
    double curcost = outputdata->trajSets[outputdata->index].cost;
    double angleThresh = M_PI/24.0*double(outputdata->trajSets[outputdata->index].trajdat.size());
    if(curcost > angleThresh) //outputdata->trajSets[outputdata->index].cost*1.2) //大于均值设置为慢速
    {
        outputdata->speedState = outputdata->LOW;
    }
    else
    {
        outputdata->speedState = outputdata->MID;
    }



    //如果到左右墙的距离小于3m
//    if((evaluate->d2leftwall+evaluate->d2rightwall) < 2)
//        outputdata->speedState = outputdata->LOW;
    return 1;
}

