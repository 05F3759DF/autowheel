//You need to program this file.

#include "../NoEdit/ProcessorMono_Processor_EvaluateFunction_PrivFunc.h"
#include <fstream>
#include <string>
#include <strstream>
using namespace std;
//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
    XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
    ProcessorMono_Processor_EvaluateFunction_Params * params=(ProcessorMono_Processor_EvaluateFunction_Params *)paramsPtr;
    ProcessorMono_Processor_EvaluateFunction_Vars * vars=(ProcessorMono_Processor_EvaluateFunction_Vars *)varsPtr;
    /*======Please Program below======*/
    /*
    Function: open node.
    Procedure:
    1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
    2: initialize variables (vars).
    3: If everything is OK, return 1 for successful opening and vice versa.
    */

    GetParamValue(xmlloader, vars, param.k);
    GetParamValue(xmlloader, vars, param.dataNum);
    GetParamValue(xmlloader, vars, param.featureNum);
    GetParamValue(xmlloader, vars, param.startNum);
    GetParamValue(xmlloader, vars, param.barrierNum);
    GetParamValue(xmlloader, vars, param.leftBNum) ;
    GetParamValue(xmlloader, vars, param.rightBNum) ;
    GetParamValue(xmlloader, vars, param.wallNum);
    GetParamValue(xmlloader, vars, param.leftDNum) ;
    GetParamValue(xmlloader, vars, param.rightDNum) ;
    GetParamValue(xmlloader, vars, param.bigNum);
    GetParamValue(xmlloader, vars, param.filePath);
    GetParamValue(xmlloader, vars, param.fileName);

    if ( !vars->VF.SetParameter(vars->param) )
        return false ;
    if ( !vars->VF.ReadRawData() )
        return false ;
    if ( !vars->VF.ProcessRawData() )
        return false ;

    return true ;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
    ProcessorMono_Processor_EvaluateFunction_Params * params=(ProcessorMono_Processor_EvaluateFunction_Params *)paramsPtr;
    ProcessorMono_Processor_EvaluateFunction_Vars * vars=(ProcessorMono_Processor_EvaluateFunction_Vars *)varsPtr;
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
    ProcessorMono_Processor_EvaluateFunction_Params * params=(ProcessorMono_Processor_EvaluateFunction_Params *)paramsPtr;
    ProcessorMono_Processor_EvaluateFunction_Vars * vars=(ProcessorMono_Processor_EvaluateFunction_Vars *)varsPtr;
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
    ProcessorMono_Processor_EvaluateFunction_Params * params=(ProcessorMono_Processor_EvaluateFunction_Params *)paramsPtr;
    ProcessorMono_Processor_EvaluateFunction_Vars * vars=(ProcessorMono_Processor_EvaluateFunction_Vars *)varsPtr;
    outputDataPtr=boost::shared_ptr<void>(new ProcessorMono_Processor_EvaluateFunction_Data());
    /*======Occasionally Program below/above======*/
    /*
    Function: initial output data.
    You need to program here when you need to manually initialize output data.
    */

}

void DECOFUNC(getMonoInputDataSize)(void * paramsPtr, void * varsPtr, int & inputDataSize)
{
    ProcessorMono_Processor_EvaluateFunction_Params * params=(ProcessorMono_Processor_EvaluateFunction_Params *)paramsPtr;
    ProcessorMono_Processor_EvaluateFunction_Vars * vars=(ProcessorMono_Processor_EvaluateFunction_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 0, Params_Type = ProcessorMulti_Processor_FeatureExtract_Params, Data_Type = ProcessorMulti_Processor_FeatureExtract_Data
bool DECOFUNC(processMonoInputData)(void * paramsPtr, void * varsPtr, QVector<void *> inputParams, QVector<void *> inputData, void * outputData, QList<int> & outputPortIndex)
{
    ProcessorMono_Processor_EvaluateFunction_Params * params=(ProcessorMono_Processor_EvaluateFunction_Params *)paramsPtr;
    ProcessorMono_Processor_EvaluateFunction_Vars * vars=(ProcessorMono_Processor_EvaluateFunction_Vars *)varsPtr;
    QVector<ProcessorMulti_Processor_FeatureExtract_Params *> inputparams; copyQVector(inputparams,inputParams);
    QVector<ProcessorMulti_Processor_FeatureExtract_Data *> inputdata; copyQVector(inputdata,inputData);
    ProcessorMono_Processor_EvaluateFunction_Data * outputdata=(ProcessorMono_Processor_EvaluateFunction_Data *)outputData;
    outputPortIndex=QList<int>();
    if(inputdata.size()==0){return 0;}
    /*======Please Program below======*/
    /*
    Step 1: process inputdata, then store it into outputdata.
    Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
    E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
    */

    double res = 0 ;
    res = vars->VF.valueFeature(inputdata.front()->feature) ;
    if ( res <= 0 ) res = 0.1 ;
    if ( res >= 1 ) res = 0.9 ;
    outputdata->index = floor((res)*36.0) ;
    outputdata->timestamp = inputdata.front()->feature.timestamp ;
    //outputdata->index = 18;
    //for Test
    outputdata->index += 4;

    // Debug
    int TS = inputdata.front()->feature.timestamp ;
    //if ( (TS%1000) < 100 )
        //vars->VF.OutputTestData(TS) ;

    ///以下变量是为了把FeatureExtract模块的数据传到PathGenerator
    //传输激光和门的状态
    ProcessorMulti_Processor_FeatureExtract_Data* feature = inputdata.front();
    outputdata->URGData_size = feature->URGData_size;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<feature->URGData_size; j++)
        {
            outputdata->urg_data_point[i][j][0] = feature->urg_data_point[i][j][0];
            outputdata->urg_data_point[i][j][1] = feature->urg_data_point[i][j][1];
        }
    }
    for(int i=0; i< SIZE_OF_FEATURE/2; i++)
    {
        outputdata->is_door_open[i] = feature->is_door_open[i];
    }
    outputdata->door_point = feature->door_point;

    outputdata->d2leftwall = feature->d2leftwall;
    outputdata->d2rightwall = feature->d2rightwall;

    return 1;
}

