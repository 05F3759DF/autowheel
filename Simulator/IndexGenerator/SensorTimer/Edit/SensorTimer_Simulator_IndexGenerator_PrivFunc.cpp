//You need to program this file.

#include "../NoEdit/SensorTimer_Simulator_IndexGenerator_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	SensorTimer_Simulator_IndexGenerator_Params * params=(SensorTimer_Simulator_IndexGenerator_Params *)paramsPtr;
	SensorTimer_Simulator_IndexGenerator_Vars * vars=(SensorTimer_Simulator_IndexGenerator_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader, params, filePath);
    GetParamValue(xmlloader, params, fileName);
    vars->labels = fopen((params->filePath + params->fileName).toStdString().c_str(), "r");

	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	SensorTimer_Simulator_IndexGenerator_Params * params=(SensorTimer_Simulator_IndexGenerator_Params *)paramsPtr;
	SensorTimer_Simulator_IndexGenerator_Vars * vars=(SensorTimer_Simulator_IndexGenerator_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    fclose(vars->labels);
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	SensorTimer_Simulator_IndexGenerator_Params * params=(SensorTimer_Simulator_IndexGenerator_Params *)paramsPtr;
	SensorTimer_Simulator_IndexGenerator_Vars * vars=(SensorTimer_Simulator_IndexGenerator_Vars *)varsPtr;
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
	SensorTimer_Simulator_IndexGenerator_Params * params=(SensorTimer_Simulator_IndexGenerator_Params *)paramsPtr;
	SensorTimer_Simulator_IndexGenerator_Vars * vars=(SensorTimer_Simulator_IndexGenerator_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new SensorTimer_Simulator_IndexGenerator_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	SensorTimer_Simulator_IndexGenerator_Params * params=(SensorTimer_Simulator_IndexGenerator_Params *)paramsPtr;
	SensorTimer_Simulator_IndexGenerator_Vars * vars=(SensorTimer_Simulator_IndexGenerator_Vars *)varsPtr;
	SensorTimer_Simulator_IndexGenerator_Data * outputdata=(SensorTimer_Simulator_IndexGenerator_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/

    if (fscanf(vars->labels, "%d", &outputdata->index) < 1)
        return 0;
	return 1;
}

