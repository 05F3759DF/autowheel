//You need to program this file.

#include "../NoEdit/SensorTimer_Gazebo_Odom_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	SourceDrainMono_Sensor_stm32comm_Params * params=(SourceDrainMono_Sensor_stm32comm_Params *)paramsPtr;
	SensorTimer_Gazebo_Odom_Vars * vars=(SensorTimer_Gazebo_Odom_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    vars->isinit = 0;
    vars->offset_x = vars->offset_y = vars->offset_yaw = 0;
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	SourceDrainMono_Sensor_stm32comm_Params * params=(SourceDrainMono_Sensor_stm32comm_Params *)paramsPtr;
	SensorTimer_Gazebo_Odom_Vars * vars=(SensorTimer_Gazebo_Odom_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
	
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	SourceDrainMono_Sensor_stm32comm_Params * params=(SourceDrainMono_Sensor_stm32comm_Params *)paramsPtr;
	SensorTimer_Gazebo_Odom_Vars * vars=(SensorTimer_Gazebo_Odom_Vars *)varsPtr;
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
	SourceDrainMono_Sensor_stm32comm_Params * params=(SourceDrainMono_Sensor_stm32comm_Params *)paramsPtr;
	SensorTimer_Gazebo_Odom_Vars * vars=(SensorTimer_Gazebo_Odom_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new SourceDrainMono_Sensor_stm32comm_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	SourceDrainMono_Sensor_stm32comm_Params * params=(SourceDrainMono_Sensor_stm32comm_Params *)paramsPtr;
	SensorTimer_Gazebo_Odom_Vars * vars=(SensorTimer_Gazebo_Odom_Vars *)varsPtr;
	SourceDrainMono_Sensor_stm32comm_Data * outputdata=(SourceDrainMono_Sensor_stm32comm_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/
    OdomStruct currentOdom;
    vars->odomSub->getOdomMessage(currentOdom);
    if(!vars->isinit)
    {
        vars->isinit = 1;
        vars->offset_x = currentOdom.x;
        vars->offset_y = currentOdom.y;
        vars->offset_yaw = currentOdom.yaw;
    }
    outputdata->x = -(currentOdom.x-vars->offset_x);
    outputdata->y = -(currentOdom.y-vars->offset_y);
    outputdata->yaw = outputdata->theta = (currentOdom.yaw - vars->offset_yaw) + PI / 2; //0524xlw
    outputdata->leftodom = outputdata->rightodom = outputdata->leftspeed = outputdata->rightspeed=0;

    outputdata->timestamp = QTime::currentTime();
	return 1;
}

