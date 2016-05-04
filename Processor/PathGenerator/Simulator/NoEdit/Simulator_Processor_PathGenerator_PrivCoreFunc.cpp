//Generally you need not to program this file.

#include "Simulator_Processor_PathGenerator_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=Simulator_Processor_PathGenerator_INPUTPORTSSIZE;
	outputPortsNumber=Simulator_Processor_PathGenerator_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new Simulator_Processor_PathGenerator_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new Simulator_Processor_PathGenerator_Vars());
	/*======No Need to Program======*/
}

