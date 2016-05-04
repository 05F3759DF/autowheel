//Generally you need not to program this file.

#include "ProcessorMono_Processor_EvaluateFunction_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=ProcessorMono_Processor_EvaluateFunction_INPUTPORTSSIZE;
	outputPortsNumber=ProcessorMono_Processor_EvaluateFunction_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new ProcessorMono_Processor_EvaluateFunction_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new ProcessorMono_Processor_EvaluateFunction_Vars());
	/*======No Need to Program======*/
}

