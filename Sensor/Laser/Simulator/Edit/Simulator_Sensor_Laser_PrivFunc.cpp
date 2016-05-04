//You need to program this file.

#include "../NoEdit/Simulator_Sensor_Laser_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
    SensorInternalEvent_Sensor_Laser_Params * params=(SensorInternalEvent_Sensor_Laser_Params *)paramsPtr;
	Simulator_Sensor_Laser_Vars * vars=(Simulator_Sensor_Laser_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader,vars,path);
    GetParamValue(xmlloader,vars,filename);
    GetParamValue(xmlloader,params,first_step);
    GetParamValue(xmlloader,params,last_step);
    GetParamValue(xmlloader,params,skip_step);
    GetParamValue(xmlloader,params,nearfilter);
    GetParamValue(xmlloader,params,farfilter);

    vars->file.setFileName(QString("%1%2").arg(vars->path).arg(vars->filename));
    if(!vars->file.open(QIODevice::ReadOnly))
    {
        return 0;
    }
    vars->file.read(sizeof(float)*3);//文件头
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
    SensorInternalEvent_Sensor_Laser_Params * params=(SensorInternalEvent_Sensor_Laser_Params *)paramsPtr;
	Simulator_Sensor_Laser_Vars * vars=(Simulator_Sensor_Laser_Vars *)varsPtr;
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
    SensorInternalEvent_Sensor_Laser_Params * params=(SensorInternalEvent_Sensor_Laser_Params *)paramsPtr;
	Simulator_Sensor_Laser_Vars * vars=(Simulator_Sensor_Laser_Vars *)varsPtr;
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
    SensorInternalEvent_Sensor_Laser_Params * params=(SensorInternalEvent_Sensor_Laser_Params *)paramsPtr;
	Simulator_Sensor_Laser_Vars * vars=(Simulator_Sensor_Laser_Vars *)varsPtr;

    int beamnumber=(params->last_step-params->first_step)/params->skip_step+1;
    outputDataPtr=boost::shared_ptr<void>(new SensorInternalEvent_Sensor_Laser_Data(beamnumber));
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
    SensorInternalEvent_Sensor_Laser_Params * params=(SensorInternalEvent_Sensor_Laser_Params *)paramsPtr;
	Simulator_Sensor_Laser_Vars * vars=(Simulator_Sensor_Laser_Vars *)varsPtr;
    SensorInternalEvent_Sensor_Laser_Data * outputdata=(SensorInternalEvent_Sensor_Laser_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/
    if(vars->file.atEnd())
    {
        return 0;
    }
    int timestamp;
    vars->file.read((char *)&(timestamp),sizeof(timestamp));
    outputdata->timestamp = timestamp;
    outputdata->qtimestamp=QTime::fromMSecsSinceStartOfDay(outputdata->timestamp);

    int i,n=outputdata->datasize;
    char lasertype;
    vars->file.read((char *)&lasertype,sizeof(char));
    if(lasertype == 'L')
    {
        vars->file.read((char *)outputdata->ldata,sizeof(short)*(outputdata->datasize));
        for(i=0;i<n;i++)
        {
            if(outputdata->ldata[i]<params->nearfilter||outputdata->ldata[i]>params->farfilter)
            {
                outputdata->ldata[i]=0;
            }
        }
    }
    else
        return 0;


    vars->file.read((char *)&lasertype,sizeof(char));
    if(lasertype == 'R')
    {
        vars->file.read((char *)outputdata->rdata,sizeof(short)*(outputdata->datasize));
        for(i=0;i<n;i++)
        {
            if(outputdata->rdata[i]<params->nearfilter||outputdata->rdata[i]>params->farfilter)
            {
                outputdata->rdata[i]=0;
            }
        }
    }
    else
        return 0;

    timeStamp=outputdata->qtimestamp;
	return 1;
}

