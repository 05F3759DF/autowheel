//You need to program this file.

#include "../NoEdit/ProcessorMono_joy_control_test_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	ProcessorMono_joy_control_test_Params * params=(ProcessorMono_joy_control_test_Params *)paramsPtr;
	ProcessorMono_joy_control_test_Vars * vars=(ProcessorMono_joy_control_test_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
	
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	ProcessorMono_joy_control_test_Params * params=(ProcessorMono_joy_control_test_Params *)paramsPtr;
	ProcessorMono_joy_control_test_Vars * vars=(ProcessorMono_joy_control_test_Vars *)varsPtr;
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
	ProcessorMono_joy_control_test_Params * params=(ProcessorMono_joy_control_test_Params *)paramsPtr;
	ProcessorMono_joy_control_test_Vars * vars=(ProcessorMono_joy_control_test_Vars *)varsPtr;
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
	ProcessorMono_joy_control_test_Params * params=(ProcessorMono_joy_control_test_Params *)paramsPtr;
	ProcessorMono_joy_control_test_Vars * vars=(ProcessorMono_joy_control_test_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new ProcessorMono_joy_control_test_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

void DECOFUNC(getMonoInputDataSize)(void * paramsPtr, void * varsPtr, int & inputDataSize)
{
	ProcessorMono_joy_control_test_Params * params=(ProcessorMono_joy_control_test_Params *)paramsPtr;
	ProcessorMono_joy_control_test_Vars * vars=(ProcessorMono_joy_control_test_Vars *)varsPtr;
	inputDataSize=0;
	/*======Please Program above======*/
	/*
	Function: get input data size to be grabbed from buffer.
	Rules:
	inputDataSize=0: grab and remove all data from buffer.
	inputDataSize>0: grab inputDataSize latest data from buffer.
	inputDataSize<0: grab and remove inputDataSize ancient data from buffer.
	*/
}

//Input Port #0: Buffer_Size = 5, Params_Type = SensorInternalEvent_Sensor_Joystick_Params, Data_Type = SensorInternalEvent_Sensor_Joystick_Data
bool DECOFUNC(processMonoInputData)(void * paramsPtr, void * varsPtr, QVector<void *> inputParams, QVector<void *> inputData, void * outputData, QList<int> & outputPortIndex)
{
	ProcessorMono_joy_control_test_Params * params=(ProcessorMono_joy_control_test_Params *)paramsPtr;
	ProcessorMono_joy_control_test_Vars * vars=(ProcessorMono_joy_control_test_Vars *)varsPtr;
	QVector<SensorInternalEvent_Sensor_Joystick_Params *> inputparams; copyQVector(inputparams,inputParams);
	QVector<SensorInternalEvent_Sensor_Joystick_Data *> inputdata; copyQVector(inputdata,inputData);
	ProcessorMono_joy_control_test_Data * outputdata=(ProcessorMono_joy_control_test_Data *)outputData;
	outputPortIndex=QList<int>();
	if(inputdata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Step 1: process inputdata, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/
    SensorInternalEvent_Sensor_Joystick_Data* joystickdata = inputdata.front();

    short left_motor;
    short right_motor;

    vars->left_vel = joystickdata->linear_vel + vars->WheelBase*joystickdata->angular_vel/2;
    vars->right_vel = joystickdata->linear_vel - vars->WheelBase*joystickdata->angular_vel/2;

    left_motor = vars->left_vel * 1376.9 + 214.5;
    right_motor = vars->right_vel * 1376.9 + 214.5;

    outputdata->left_motor = left_motor;
    outputdata->right_motor = right_motor;
    outputdata->isManualControl = 1;
	return 1;
}

