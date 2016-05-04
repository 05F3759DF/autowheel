//Generally you need not to program this file.

#include "TransmitterMono_Gazebo_OrderGenerate_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=TransmitterMono_Gazebo_OrderGenerate_INPUTPORTSSIZE;
	outputPortsNumber=TransmitterMono_Gazebo_OrderGenerate_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new TransmitterMono_Gazebo_OrderGenerate_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new TransmitterMono_Gazebo_OrderGenerate_Vars());
	/*======No Need to Program======*/
}

