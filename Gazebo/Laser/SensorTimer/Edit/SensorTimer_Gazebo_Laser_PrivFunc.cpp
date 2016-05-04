//You need to program this file.

#include "../NoEdit/SensorTimer_Gazebo_Laser_PrivFunc.h"
#include "lasersub.h"
//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	SensorTimer_Sensor_Laser_Params * params=(SensorTimer_Sensor_Laser_Params *)paramsPtr;
	SensorTimer_Gazebo_Laser_Vars * vars=(SensorTimer_Gazebo_Laser_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader,params,first_step);
    GetParamValue(xmlloader,params,last_step);
    GetParamValue(xmlloader,params,skip_step);
    GetParamValue(xmlloader,params,nearfilter);
    GetParamValue(xmlloader,params,farfilter);
    GetParamValue(xmlloader,params,unit);
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	SensorTimer_Sensor_Laser_Params * params=(SensorTimer_Sensor_Laser_Params *)paramsPtr;
	SensorTimer_Gazebo_Laser_Vars * vars=(SensorTimer_Gazebo_Laser_Vars *)varsPtr;
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
	SensorTimer_Sensor_Laser_Params * params=(SensorTimer_Sensor_Laser_Params *)paramsPtr;
	SensorTimer_Gazebo_Laser_Vars * vars=(SensorTimer_Gazebo_Laser_Vars *)varsPtr;
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
	SensorTimer_Sensor_Laser_Params * params=(SensorTimer_Sensor_Laser_Params *)paramsPtr;
	SensorTimer_Gazebo_Laser_Vars * vars=(SensorTimer_Gazebo_Laser_Vars *)varsPtr;

    int beamnumber=(params->last_step-params->first_step)/params->skip_step+1;

    outputDataPtr=boost::shared_ptr<void>(new SensorTimer_Sensor_Laser_Data(beamnumber));

	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	SensorTimer_Sensor_Laser_Params * params=(SensorTimer_Sensor_Laser_Params *)paramsPtr;
	SensorTimer_Gazebo_Laser_Vars * vars=(SensorTimer_Gazebo_Laser_Vars *)varsPtr;
	SensorTimer_Sensor_Laser_Data * outputdata=(SensorTimer_Sensor_Laser_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/
    outputdata->qtimestamp=QTime::currentTime();
    double* urgdata=new double[outputdata->datasize];

    int datasize;
    u_int32_t timestamp;
    // leftlaser data
    vars->leftLaserSub->getLaserMessage(timestamp, urgdata, datasize);
    for(int i=0; i<datasize; i++)
    {
        outputdata->ldata[i] = (short)(urgdata[i]*100);
    }

    //rightlaser data
    QVector<short> test;
    double* tmp;
    vars->rightLaserSub->getLaserMessage(timestamp, urgdata, datasize);
    for(int i=0; i<datasize; i++)
    {
        outputdata->rdata[i] = (short)(urgdata[i]*100);
        test.push_back(outputdata->rdata[i]);
    }

    outputdata->timestamp = (long)timestamp;
    outputdata->datasize = datasize;
	return 1;
}

