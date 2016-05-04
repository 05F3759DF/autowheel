//You need to program this file.

#include "../NoEdit/Simulator_Localization_Slam_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	Simulator_Localization_Slam_Params * params=(Simulator_Localization_Slam_Params *)paramsPtr;
	Simulator_Localization_Slam_Vars * vars=(Simulator_Localization_Slam_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader, vars, filepath);
    GetParamValue(xmlloader, vars, filename);

    vars->slamFile.open((vars->filepath+vars->filename).toStdString().c_str());

	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	Simulator_Localization_Slam_Params * params=(Simulator_Localization_Slam_Params *)paramsPtr;
	Simulator_Localization_Slam_Vars * vars=(Simulator_Localization_Slam_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->slamFile.close();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	Simulator_Localization_Slam_Params * params=(Simulator_Localization_Slam_Params *)paramsPtr;
	Simulator_Localization_Slam_Vars * vars=(Simulator_Localization_Slam_Vars *)varsPtr;
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
	Simulator_Localization_Slam_Params * params=(Simulator_Localization_Slam_Params *)paramsPtr;
	Simulator_Localization_Slam_Vars * vars=(Simulator_Localization_Slam_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new SensorTimer_Localization_Slam_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	Simulator_Localization_Slam_Params * params=(Simulator_Localization_Slam_Params *)paramsPtr;
	Simulator_Localization_Slam_Vars * vars=(Simulator_Localization_Slam_Vars *)varsPtr;
	SensorTimer_Localization_Slam_Data * outputdata=(SensorTimer_Localization_Slam_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/

    if(vars->slamFile.eof())
        return 0;

    vars->slamFile>> outputdata->timestamp >> outputdata->x >> outputdata->y >> outputdata->theta;

    outputdata->qtimestamp=QTime::fromMSecsSinceStartOfDay(outputdata->timestamp);

    timeStamp = outputdata->qtimestamp;

	return 1;
}

