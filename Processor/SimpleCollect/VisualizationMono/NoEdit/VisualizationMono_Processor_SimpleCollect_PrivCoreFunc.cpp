//Generally you need not to program this file.

#include "VisualizationMono_Processor_SimpleCollect_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=VisualizationMono_Processor_SimpleCollect_INPUTPORTSSIZE;
	outputPortsNumber=VisualizationMono_Processor_SimpleCollect_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new VisualizationMono_Processor_SimpleCollect_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new VisualizationMono_Processor_SimpleCollect_Vars());
	/*======No Need to Program======*/
}

