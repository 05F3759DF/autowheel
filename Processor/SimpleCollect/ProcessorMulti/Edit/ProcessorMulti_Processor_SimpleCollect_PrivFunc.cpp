 //You need to program this file.

#include "../NoEdit/ProcessorMulti_Processor_SimpleCollect_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	ProcessorMulti_Processor_SimpleCollect_Params * params=(ProcessorMulti_Processor_SimpleCollect_Params *)paramsPtr;
	ProcessorMulti_Processor_SimpleCollect_Vars * vars=(ProcessorMulti_Processor_SimpleCollect_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader, params, storagepath);
    GetParamValue(xmlloader, params, laserfilename);
    GetParamValue(xmlloader, params, odomfilename);
    vars->isSimple = 0;
    vars->isOpenFile = 1;
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	ProcessorMulti_Processor_SimpleCollect_Params * params=(ProcessorMulti_Processor_SimpleCollect_Params *)paramsPtr;
	ProcessorMulti_Processor_SimpleCollect_Vars * vars=(ProcessorMulti_Processor_SimpleCollect_Vars *)varsPtr;
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
	ProcessorMulti_Processor_SimpleCollect_Params * params=(ProcessorMulti_Processor_SimpleCollect_Params *)paramsPtr;
	ProcessorMulti_Processor_SimpleCollect_Vars * vars=(ProcessorMulti_Processor_SimpleCollect_Vars *)varsPtr;
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
	ProcessorMulti_Processor_SimpleCollect_Params * params=(ProcessorMulti_Processor_SimpleCollect_Params *)paramsPtr;
	ProcessorMulti_Processor_SimpleCollect_Vars * vars=(ProcessorMulti_Processor_SimpleCollect_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new ProcessorMulti_Processor_SimpleCollect_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

void DECOFUNC(getMultiInputDataSize)(void * paramsPtr, void * varsPtr, QList<int> & inputDataSize)
{
	ProcessorMulti_Processor_SimpleCollect_Params * params=(ProcessorMulti_Processor_SimpleCollect_Params *)paramsPtr;
	ProcessorMulti_Processor_SimpleCollect_Vars * vars=(ProcessorMulti_Processor_SimpleCollect_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 10, Params_Type = SensorInternalEvent_Sensor_Joystick_Params, Data_Type = SensorInternalEvent_Sensor_Joystick_Data
//Input Port #1: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_Laser_Params, Data_Type = SensorTimer_Sensor_Laser_Data
//Input Port #2: Buffer_Size = 10, Params_Type = SourceDrainMono_Sensor_stm32comm_Params, Data_Type = SourceDrainMono_Sensor_stm32comm_Data
//Input Port #3: Buffer_Size = 10, Params_Type = ProcessorMulti_Processor_doordetection_Params, Data_Type = ProcessorMulti_Processor_doordetection_Data
bool DECOFUNC(processMultiInputData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > inputParams, QVector<QVector<void *> > inputData, void * outputData, QList<int> & outputPortIndex)
{
	ProcessorMulti_Processor_SimpleCollect_Params * params=(ProcessorMulti_Processor_SimpleCollect_Params *)paramsPtr;
	ProcessorMulti_Processor_SimpleCollect_Vars * vars=(ProcessorMulti_Processor_SimpleCollect_Vars *)varsPtr;
	QVector<SensorInternalEvent_Sensor_Joystick_Params *> inputparams_0; copyQVector(inputparams_0,inputParams[0]);
	QVector<SensorTimer_Sensor_Laser_Params *> inputparams_1; copyQVector(inputparams_1,inputParams[1]);
	QVector<SourceDrainMono_Sensor_stm32comm_Params *> inputparams_2; copyQVector(inputparams_2,inputParams[2]);
	QVector<ProcessorMulti_Processor_doordetection_Params *> inputparams_3; copyQVector(inputparams_3,inputParams[3]);
	QVector<SensorInternalEvent_Sensor_Joystick_Data *> inputdata_0; copyQVector(inputdata_0,inputData[0]);
	QVector<SensorTimer_Sensor_Laser_Data *> inputdata_1; copyQVector(inputdata_1,inputData[1]);
	QVector<SourceDrainMono_Sensor_stm32comm_Data *> inputdata_2; copyQVector(inputdata_2,inputData[2]);
	QVector<ProcessorMulti_Processor_doordetection_Data *> inputdata_3; copyQVector(inputdata_3,inputData[3]);
	ProcessorMulti_Processor_SimpleCollect_Data * outputdata=(ProcessorMulti_Processor_SimpleCollect_Data *)outputData;
	outputPortIndex=QList<int>();
	if(inputdata_0.size()==0){return 0;}
	if(inputdata_1.size()==0){return 0;}
	if(inputdata_2.size()==0){return 0;}
	if(inputdata_3.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Step 1: process inputdata_index, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/
	
    QTime timestamp = QTime::currentTime();
    if(inputdata_0.front()->startsimple == 1)
    {
        vars->isSimple = 1;
        if(vars->isOpenFile == 1)
        {
            ///open odom file
            QString timestring = timestamp.toString("HHmmsszzz");
            QString filename = params->storagepath + "/" + timestring + ".odom";
            vars->odomfilewriter.open(filename.toStdString().data());
            vars->odomfilewriter<<"door_x: "<<inputdata_3.front()->door_x<<'\t'<<"door_y: "<<inputdata_3.front()->door_y<<std::endl;

            ///open laser file
            filename = params->storagepath + "/" + timestring + ".lms";
            vars->laserfilewriter.open(filename.toStdString().data());
            float angrng=(inputparams_1.front()->last_step-inputparams_1.front()->first_step)*0.25;
            float angres=inputparams_1.front()->skip_step*0.25;
            float unit=inputparams_1.front()->unit;
            vars->laserfilewriter.write((char *)&angrng,sizeof(angrng));
            vars->laserfilewriter.write((char *)&angres,sizeof(angres));
            vars->laserfilewriter.write((char *)&unit,sizeof(unit));

            vars->status= "simple start!";

            vars->isOpenFile = 0;

            outputdata->simplestatus = vars->status;
            return 1;
        }
    }

    if(inputdata_0.front()->endsimple == 1)
    {
        vars->isSimple = 0;
        vars->isOpenFile = 1;
        vars->status= "simple end!";
        //close file
        vars->laserfilewriter.close();
        vars->odomfilewriter.close();

        outputdata->simplestatus = vars->status;
        return 1;
    }

    if(vars->isSimple)
    {
       //record data
        int time = ((inputdata_2.front()->timestamp.hour()*60 + inputdata_2.front()->timestamp.minute())*60
                    + inputdata_2.front()->timestamp.second()) *1000+inputdata_2.front()->timestamp.msec();

        vars->odomfilewriter<<time<<'\t'<<inputdata_2.front()->x<<'\t'<<inputdata_2.front()->y<<'\t'
           <<inputdata_2.front()->theta<<'\t'<<inputdata_2.front()->yaw
          <<'\t'<<inputdata_2.front()->leftodom<<'\t'<<inputdata_2.front()->rightodom<<std::endl;

        time = ((inputdata_1.front()->qtimestamp.hour()*60 + inputdata_1.front()->qtimestamp.minute())*60
                            + inputdata_1.front()->qtimestamp.second()) *1000+inputdata_1.front()->qtimestamp.msec();


        vars->laserfilewriter.write((char *)&time,sizeof(time));

        char lasertype = 'L';
        vars->laserfilewriter.write((char *)&lasertype,sizeof(lasertype));
        vars->laserfilewriter.write((char *)(inputdata_1.front()->ldata),sizeof(short)*(inputdata_1.front()->datasize));

        lasertype = 'R';
        vars->laserfilewriter.write((char *)&lasertype,sizeof(lasertype));
        vars->laserfilewriter.write((char *)(inputdata_1.front()->rdata),sizeof(short)*(inputdata_1.front()->datasize));
    }
    outputdata->simplestatus = vars->status;
    return 1;
}

