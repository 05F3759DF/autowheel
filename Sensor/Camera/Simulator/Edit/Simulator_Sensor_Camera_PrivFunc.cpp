//You need to program this file.

#include "../NoEdit/Simulator_Sensor_Camera_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	Simulator_Sensor_Camera_Params * params=(Simulator_Sensor_Camera_Params *)paramsPtr;
	Simulator_Sensor_Camera_Vars * vars=(Simulator_Sensor_Camera_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
    Proce	GetParamValue(xmlloader,params,path);
    GetParamValue(xmlloader,params,lfilename);dure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader,params,path);
    GetParamValue(xmlloader,params,videofilename);
    GetParamValue(xmlloader,params,timestampfilename);

    QString filename=QString("%1/%2").arg(params->path).arg(params->videofilename);
    vars->videosimu.open(filename.toStdString());
    if(!vars->videosimu.isOpened())
    {
        return 0;
    }
    filename = QString("%1/%2").arg(params->path).arg(params->timestampfilename);
    vars->timestampsimu.setFileName(filename);
    if(!vars->timestampsimu.open(QFile::ReadOnly | QFile::Text))
    {
        vars->videosimu.release();
        return 0;
    }

    vars->textstream.setDevice(&(vars->timestampsimu));
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	Simulator_Sensor_Camera_Params * params=(Simulator_Sensor_Camera_Params *)paramsPtr;
	Simulator_Sensor_Camera_Vars * vars=(Simulator_Sensor_Camera_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->timestampsimu.close();
    vars->videosimu.release();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	Simulator_Sensor_Camera_Params * params=(Simulator_Sensor_Camera_Params *)paramsPtr;
	Simulator_Sensor_Camera_Vars * vars=(Simulator_Sensor_Camera_Vars *)varsPtr;
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
	Simulator_Sensor_Camera_Params * params=(Simulator_Sensor_Camera_Params *)paramsPtr;
	Simulator_Sensor_Camera_Vars * vars=(Simulator_Sensor_Camera_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new SensorInternalEvent_Sensor_Camera_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	Simulator_Sensor_Camera_Params * params=(Simulator_Sensor_Camera_Params *)paramsPtr;
	Simulator_Sensor_Camera_Vars * vars=(Simulator_Sensor_Camera_Vars *)varsPtr;
	SensorInternalEvent_Sensor_Camera_Data * outputdata=(SensorInternalEvent_Sensor_Camera_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/
    cv::Mat temp;
    if(!vars->videosimu.read(temp) ||
            vars->textstream.atEnd())
    {
        timeStamp=QTime();
        return 0;
    }
    cv::cvtColor(temp, outputdata->cvimage, CV_BGR2RGB);
    timeStamp=QTime::fromMSecsSinceStartOfDay(vars->textstream.readLine().toInt());
    outputdata->timestamp = timeStamp;

	return 1;
}

