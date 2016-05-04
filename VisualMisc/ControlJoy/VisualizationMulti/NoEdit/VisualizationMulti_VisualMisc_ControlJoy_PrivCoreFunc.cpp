//Generally you need not to program this file.

#include "VisualizationMulti_VisualMisc_ControlJoy_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=VisualizationMulti_VisualMisc_ControlJoy_INPUTPORTSSIZE;
	outputPortsNumber=VisualizationMulti_VisualMisc_ControlJoy_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new VisualizationMulti_VisualMisc_ControlJoy_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new VisualizationMulti_VisualMisc_ControlJoy_Vars());
	/*======No Need to Program======*/
}

