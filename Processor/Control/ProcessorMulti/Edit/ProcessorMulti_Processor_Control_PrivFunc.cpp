//You need to program this file.

#include "../NoEdit/ProcessorMulti_Processor_Control_PrivFunc.h"
#include "Processor/Control/control.h"
//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...
inline double dist(double x1, double y1, double x2, double y2) {
    return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1-y2);}
bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	ProcessorMulti_Processor_Control_Params * params=(ProcessorMulti_Processor_Control_Params *)paramsPtr;
	ProcessorMulti_Processor_Control_Vars * vars=(ProcessorMulti_Processor_Control_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/

    GetParamValue(xmlloader, params, lowSpeed);
    GetParamValue(xmlloader, params, midSpeed);
    GetParamValue(xmlloader, params, highSpeed);
    GetParamValue(xmlloader, params, stopPWM);

    GetParamValue(xmlloader, vars, WheelBase);
    GetParamValue(xmlloader, vars, WheelRadius);

    GetParamValue(xmlloader, vars, KpAngle);

    GetParamValue(xmlloader, vars, isSaveTraj);

    GetParamValue(xmlloader, vars, storagepath);

    GetParamValue(xmlloader, vars, speedAcc);

    vars->lowSpeedThresh = vars->highSpeedThresh = params->lowSpeed;
    vars->assignedSpeed = 0;

    QDateTime now = QDateTime::currentDateTime();
    QString subFolder = now.toString("MMdd_hhmm");
    QString filename = "path_"+subFolder + ".txt";
    QDir target(vars->storagepath+"/"+subFolder);
    if (!target.exists())
    {
        target.mkpath("./");
    }

    QString tmpfilename = QString("%1/%2/%3").arg(vars->storagepath).arg(subFolder).arg(filename);


    vars->pathFile.open(tmpfilename.toStdString().c_str());


	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	ProcessorMulti_Processor_Control_Params * params=(ProcessorMulti_Processor_Control_Params *)paramsPtr;
	ProcessorMulti_Processor_Control_Vars * vars=(ProcessorMulti_Processor_Control_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->pathFile.close();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	ProcessorMulti_Processor_Control_Params * params=(ProcessorMulti_Processor_Control_Params *)paramsPtr;
	ProcessorMulti_Processor_Control_Vars * vars=(ProcessorMulti_Processor_Control_Vars *)varsPtr;
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
	ProcessorMulti_Processor_Control_Params * params=(ProcessorMulti_Processor_Control_Params *)paramsPtr;
	ProcessorMulti_Processor_Control_Vars * vars=(ProcessorMulti_Processor_Control_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new ProcessorMulti_Processor_Control_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

void DECOFUNC(getMultiInputDataSize)(void * paramsPtr, void * varsPtr, QList<int> & inputDataSize)
{
	ProcessorMulti_Processor_Control_Params * params=(ProcessorMulti_Processor_Control_Params *)paramsPtr;
	ProcessorMulti_Processor_Control_Vars * vars=(ProcessorMulti_Processor_Control_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 10, Params_Type = ProcessorMulti_Processor_PathGenerator_Params, Data_Type = ProcessorMulti_Processor_PathGenerator_Data
//Input Port #1: Buffer_Size = 10, Params_Type = SensorInternalEvent_Sensor_Joystick_Params, Data_Type = SensorInternalEvent_Sensor_Joystick_Data
bool DECOFUNC(processMultiInputData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > inputParams, QVector<QVector<void *> > inputData, void * outputData, QList<int> & outputPortIndex)
{
	ProcessorMulti_Processor_Control_Params * params=(ProcessorMulti_Processor_Control_Params *)paramsPtr;
	ProcessorMulti_Processor_Control_Vars * vars=(ProcessorMulti_Processor_Control_Vars *)varsPtr;
	QVector<ProcessorMulti_Processor_PathGenerator_Params *> inputparams_0; copyQVector(inputparams_0,inputParams[0]);
	QVector<SensorInternalEvent_Sensor_Joystick_Params *> inputparams_1; copyQVector(inputparams_1,inputParams[1]);
	QVector<ProcessorMulti_Processor_PathGenerator_Data *> inputdata_0; copyQVector(inputdata_0,inputData[0]);
	QVector<SensorInternalEvent_Sensor_Joystick_Data *> inputdata_1; copyQVector(inputdata_1,inputData[1]);
	ProcessorMulti_Processor_Control_Data * outputdata=(ProcessorMulti_Processor_Control_Data *)outputData;
	outputPortIndex=QList<int>();
	if(inputdata_0.size()==0){return 0;}
    if(inputdata_1.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Step 1: process inputdata_index, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/
    SensorInternalEvent_Sensor_Joystick_Data* joystickdata = inputdata_1.front();
    ProcessorMulti_Processor_PathGenerator_Data* pathdata = inputdata_0.front();


    bool flag = 1;

    if(dist(pathdata->startPoint.x, pathdata->startPoint.y,
            pathdata->targetPoint.x, pathdata->targetPoint.y) > 10.0)
        flag = 0;

    if((pathdata->stop == 1)|| (flag==0))
    {
        vars->left_vel = joystickdata->linear_vel + vars->WheelBase*joystickdata->angular_vel/2;
        vars->right_vel = joystickdata->linear_vel - vars->WheelBase*joystickdata->angular_vel/2;
        outputdata->left_motor = vars->left_vel * 1376.9 + 214.5;
        outputdata->right_motor = vars->right_vel * 1376.9 + 214.5;
        outputdata->isManualControl = 1;
        outputdata->left_vel = vars->left_vel;
        outputdata->right_vel = vars->right_vel;
        return 1;
    }

    short left_motor;
    short right_motor;


    double hx = cos(pathdata->startPoint.theta);
    double hy = sin(pathdata->startPoint.theta);

    double tx = pathdata->targetPoint.x,ty=pathdata->targetPoint.y;

    if(pathdata->startPoint.y<24)
        vars->KpAngle = 2;
    else if(pathdata->startPoint.y>24 && pathdata->startPoint.y<47)
        vars->KpAngle = 2.8;
    else
        vars->KpAngle = 2.1;

    if(joystickdata->manual_control == 1)
    {
        vars->left_vel = joystickdata->linear_vel + vars->WheelBase*joystickdata->angular_vel/2;
        vars->right_vel = joystickdata->linear_vel - vars->WheelBase*joystickdata->angular_vel/2;
        left_motor = vars->left_vel * 1376.9 + 214.5;
        right_motor = vars->right_vel * 1376.9 + 214.5;
        outputdata->left_vel = vars->left_vel;
        outputdata->right_vel = vars->right_vel;
    }
    else
    {
        vars->lastSpeed = vars->assignedSpeed; //保存上次速度结果
        switch (pathdata->speedState)
        {
        case ProcessorMulti_Processor_PathGenerator_Data::MID:
            vars->assignedSpeed = params->midSpeed;
            break;
        case ProcessorMulti_Processor_PathGenerator_Data::LOW:
            vars->assignedSpeed = params->lowSpeed;
            break;
        case ProcessorMulti_Processor_PathGenerator_Data::HIGH:
            vars->assignedSpeed = params->highSpeed;
            break;
        default:
            break;
        }
        //以固定的加速度来调节速度
        if(vars->lastSpeed != vars->assignedSpeed)
        {
            if(vars->lastSpeed < vars->assignedSpeed)
            {
                if(vars->speedAcc < 0) //加速过程，加速度大于0
                    vars->speedAcc = -vars->speedAcc;
                vars->lowSpeedThresh = vars->lastSpeed;
                vars->highSpeedThresh = vars->assignedSpeed;
            }
            else
            {
                if(vars->speedAcc > 0) //减速过程，加速度小于0
                    vars->speedAcc = -vars->speedAcc;
                vars->lowSpeedThresh = vars->assignedSpeed;
                vars->highSpeedThresh = vars->lastSpeed;
            }
            vars->targetSpeed = vars->lastSpeed;
        }
        //以固定的加速度来调节速度
        vars->targetSpeed = vars->targetSpeed + vars->speedAcc;

        vars->targetSpeed = vars->targetSpeed > vars->highSpeedThresh ?
                    vars->highSpeedThresh:vars->targetSpeed;

        vars->targetSpeed = vars->targetSpeed < vars->lowSpeedThresh ?
                    vars->lowSpeedThresh:vars->targetSpeed;



        generateControlCmd(vars, pathdata->startPoint.x, pathdata->startPoint.y, hx, hy, tx, ty);

        if(pathdata->speedState == ProcessorMulti_Processor_PathGenerator_Data::STOP)
        {
            left_motor = right_motor = (short)params->stopPWM;
            outputdata->left_vel = outputdata->right_vel = 0;
        }
        else
        {
            left_motor = vars->left_vel * 1376.9 + 214.5;
            right_motor = vars->right_vel * 1376.9 + 214.5;

            outputdata->left_vel = vars->left_vel;
            outputdata->right_vel = vars->right_vel;
        }
    }

    outputdata->left_motor = left_motor;
    outputdata->right_motor = right_motor;
    outputdata->isManualControl = joystickdata->manual_control;

    //存轨迹集和选中的轨迹,用于模拟
    if(vars->isSaveTraj)
    {
        vars->pathFile<<pathdata->timestamp<<' '<< (pathdata->trajSets.size()+2)/3<<' '
                     << pathdata->startPoint.x << ' ' << pathdata->startPoint.y << ' '<<pathdata->startPoint.theta;
        vars->pathFile<<endl;
        for(int i = 0; i < pathdata->trajSets.size(); i+=3)
        {
            vars->pathFile<<pathdata->trajSets[i].trajdat.size() <<' ';
            for(int j = 0; j < pathdata->trajSets[i].trajdat.size(); j++)\
            {
            vars->pathFile<<pathdata->trajSets[i].trajdat[j].x<<' '<<pathdata->trajSets[i].trajdat[j].y <<' ';
            }
            vars->pathFile<<endl;
        }
        int temp_index = pathdata->index;
        vars->pathFile<<pathdata->trajSets[temp_index].trajdat.size() <<' '<<pathdata->index<<' ';
        for(int j = 0; j < pathdata->trajSets[temp_index].trajdat.size(); j++)
        {
        vars->pathFile<<pathdata->trajSets[temp_index].trajdat[j].x<<' '<<pathdata->trajSets[temp_index].trajdat[j].y <<' ';
        }
        vars->pathFile<<endl;
    }
    //保存轨迹数据
	return 1;
}

