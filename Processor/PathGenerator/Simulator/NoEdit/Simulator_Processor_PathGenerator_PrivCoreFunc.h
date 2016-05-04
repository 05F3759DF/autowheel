//You need not to modify this file.

/*! \defgroup Simulator_Processor_PathGenerator Simulator_Processor_PathGenerator
	\ingroup Simulator_Library Processor_PathGenerator_NodeClass
	\brief Simulator_Processor_PathGenerator defines the Processor_PathGenerator in Simulator.
*/

#ifndef SIMULATOR_PROCESSOR_PATHGENERATOR_PRIVCOREFUNC_H
#define SIMULATOR_PROCESSOR_PATHGENERATOR_PRIVCOREFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Processor_PathGenerator_PrivCoreFunc Simulator_Processor_PathGenerator_PrivCoreFunc
	\ingroup Simulator_Processor_PathGenerator
	\brief Simulator_Processor_PathGenerator_PrivCoreFunc defines the PrivCoreFunc in Simulator_Processor_PathGenerator.
*/

/*! \addtogroup Simulator_Processor_PathGenerator_PrivCoreFunc
	@{
*/

/*! \file Simulator_Processor_PathGenerator_PrivCoreFunc.h
	 Defines the PrivCoreFunc of Simulator_Processor_PathGenerator
*/

//*******************Please add other headers below*******************


#include "../Edit/Simulator_Processor_PathGenerator_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG Simulator_Processor_PathGenerator

/*! void Simulator_Processor_PathGenerator_getPortsSize(QList<int> & inputPortsSize, int & outputPortsNumber)
	\brief [required] Function pointer type for interface function of getting node's port(s)' size.
	\param [out] inputPortsSize The size of each input port's data buffer.
	\param [out] outputPortsNumber The number of output ports.
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber);

/*! void Simulator_Processor_PathGenerator_initializeParams(boost::shared_ptr<void> & paramsPtr)
	\brief [required] Function pointer type for interface function of initializing node's parameters.
	\param [out] paramsPtr The parameters embelished by boost::shared_pointer<void>.
	\details To initialize parameters:
	- paramsPtr=boost::shared_ptr<void> (new ParametersType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr);

/*! void Simulator_Processor_PathGenerator_initializeVars(boost::shared_ptr<void> & varsPtr)
	\brief [required] Function pointer type for interface function of initializing node's variables.
	\param [out] varsPtr The variables embelished by boost::shared_pointer<void>.
	\details To initialize variables:
	- varsPtr=boost::shared_ptr<void> (new VariablesType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr);

/*! @}*/ 

#endif