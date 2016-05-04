//You need not to modify this file.

/*! \defgroup ProcessorMulti_Processor_CameraLaser ProcessorMulti_Processor_CameraLaser
	\ingroup ProcessorMulti_Library Processor_CameraLaser_NodeClass
	\brief ProcessorMulti_Processor_CameraLaser defines the Processor_CameraLaser in ProcessorMulti.
*/

#ifndef PROCESSORMULTI_PROCESSOR_CAMERALASER_PRIVCOREFUNC_H
#define PROCESSORMULTI_PROCESSOR_CAMERALASER_PRIVCOREFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Processor_CameraLaser_PrivCoreFunc ProcessorMulti_Processor_CameraLaser_PrivCoreFunc
	\ingroup ProcessorMulti_Processor_CameraLaser
	\brief ProcessorMulti_Processor_CameraLaser_PrivCoreFunc defines the PrivCoreFunc in ProcessorMulti_Processor_CameraLaser.
*/

/*! \addtogroup ProcessorMulti_Processor_CameraLaser_PrivCoreFunc
	@{
*/

/*! \file ProcessorMulti_Processor_CameraLaser_PrivCoreFunc.h
	 Defines the PrivCoreFunc of ProcessorMulti_Processor_CameraLaser
*/

//*******************Please add other headers below*******************


#include "../Edit/ProcessorMulti_Processor_CameraLaser_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG ProcessorMulti_Processor_CameraLaser

/*! void ProcessorMulti_Processor_CameraLaser_getPortsSize(QList<int> & inputPortsSize, int & outputPortsNumber)
	\brief [required] Function pointer type for interface function of getting node's port(s)' size.
	\param [out] inputPortsSize The size of each input port's data buffer.
	\param [out] outputPortsNumber The number of output ports.
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber);

/*! void ProcessorMulti_Processor_CameraLaser_initializeParams(boost::shared_ptr<void> & paramsPtr)
	\brief [required] Function pointer type for interface function of initializing node's parameters.
	\param [out] paramsPtr The parameters embelished by boost::shared_pointer<void>.
	\details To initialize parameters:
	- paramsPtr=boost::shared_ptr<void> (new ParametersType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr);

/*! void ProcessorMulti_Processor_CameraLaser_initializeVars(boost::shared_ptr<void> & varsPtr)
	\brief [required] Function pointer type for interface function of initializing node's variables.
	\param [out] varsPtr The variables embelished by boost::shared_pointer<void>.
	\details To initialize variables:
	- varsPtr=boost::shared_ptr<void> (new VariablesType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr);

/*! @}*/ 

#endif