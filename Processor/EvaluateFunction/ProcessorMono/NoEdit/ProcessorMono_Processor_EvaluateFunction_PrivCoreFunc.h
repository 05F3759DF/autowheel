//You need not to modify this file.

/*! \defgroup ProcessorMono_Processor_EvaluateFunction ProcessorMono_Processor_EvaluateFunction
	\ingroup ProcessorMono_Library Processor_EvaluateFunction_NodeClass
	\brief ProcessorMono_Processor_EvaluateFunction defines the Processor_EvaluateFunction in ProcessorMono.
*/

#ifndef PROCESSORMONO_PROCESSOR_EVALUATEFUNCTION_PRIVCOREFUNC_H
#define PROCESSORMONO_PROCESSOR_EVALUATEFUNCTION_PRIVCOREFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMono_Processor_EvaluateFunction_PrivCoreFunc ProcessorMono_Processor_EvaluateFunction_PrivCoreFunc
	\ingroup ProcessorMono_Processor_EvaluateFunction
	\brief ProcessorMono_Processor_EvaluateFunction_PrivCoreFunc defines the PrivCoreFunc in ProcessorMono_Processor_EvaluateFunction.
*/

/*! \addtogroup ProcessorMono_Processor_EvaluateFunction_PrivCoreFunc
	@{
*/

/*! \file ProcessorMono_Processor_EvaluateFunction_PrivCoreFunc.h
	 Defines the PrivCoreFunc of ProcessorMono_Processor_EvaluateFunction
*/

//*******************Please add other headers below*******************


#include "../Edit/ProcessorMono_Processor_EvaluateFunction_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG ProcessorMono_Processor_EvaluateFunction

/*! void ProcessorMono_Processor_EvaluateFunction_getPortsSize(QList<int> & inputPortsSize, int & outputPortsNumber)
	\brief [required] Function pointer type for interface function of getting node's port(s)' size.
	\param [out] inputPortsSize The size of each input port's data buffer.
	\param [out] outputPortsNumber The number of output ports.
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber);

/*! void ProcessorMono_Processor_EvaluateFunction_initializeParams(boost::shared_ptr<void> & paramsPtr)
	\brief [required] Function pointer type for interface function of initializing node's parameters.
	\param [out] paramsPtr The parameters embelished by boost::shared_pointer<void>.
	\details To initialize parameters:
	- paramsPtr=boost::shared_ptr<void> (new ParametersType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr);

/*! void ProcessorMono_Processor_EvaluateFunction_initializeVars(boost::shared_ptr<void> & varsPtr)
	\brief [required] Function pointer type for interface function of initializing node's variables.
	\param [out] varsPtr The variables embelished by boost::shared_pointer<void>.
	\details To initialize variables:
	- varsPtr=boost::shared_ptr<void> (new VariablesType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr);

/*! @}*/ 

#endif