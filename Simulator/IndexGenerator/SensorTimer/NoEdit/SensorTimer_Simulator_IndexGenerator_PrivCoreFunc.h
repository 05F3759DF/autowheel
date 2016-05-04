//You need not to modify this file.

/*! \defgroup SensorTimer_Simulator_IndexGenerator SensorTimer_Simulator_IndexGenerator
	\ingroup SensorTimer_Library Simulator_IndexGenerator_NodeClass
	\brief SensorTimer_Simulator_IndexGenerator defines the Simulator_IndexGenerator in SensorTimer.
*/

#ifndef SENSORTIMER_SIMULATOR_INDEXGENERATOR_PRIVCOREFUNC_H
#define SENSORTIMER_SIMULATOR_INDEXGENERATOR_PRIVCOREFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorTimer_Simulator_IndexGenerator_PrivCoreFunc SensorTimer_Simulator_IndexGenerator_PrivCoreFunc
	\ingroup SensorTimer_Simulator_IndexGenerator
	\brief SensorTimer_Simulator_IndexGenerator_PrivCoreFunc defines the PrivCoreFunc in SensorTimer_Simulator_IndexGenerator.
*/

/*! \addtogroup SensorTimer_Simulator_IndexGenerator_PrivCoreFunc
	@{
*/

/*! \file SensorTimer_Simulator_IndexGenerator_PrivCoreFunc.h
	 Defines the PrivCoreFunc of SensorTimer_Simulator_IndexGenerator
*/

//*******************Please add other headers below*******************


#include "../Edit/SensorTimer_Simulator_IndexGenerator_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG SensorTimer_Simulator_IndexGenerator

/*! void SensorTimer_Simulator_IndexGenerator_getPortsSize(QList<int> & inputPortsSize, int & outputPortsNumber)
	\brief [required] Function pointer type for interface function of getting node's port(s)' size.
	\param [out] inputPortsSize The size of each input port's data buffer.
	\param [out] outputPortsNumber The number of output ports.
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber);

/*! void SensorTimer_Simulator_IndexGenerator_initializeParams(boost::shared_ptr<void> & paramsPtr)
	\brief [required] Function pointer type for interface function of initializing node's parameters.
	\param [out] paramsPtr The parameters embelished by boost::shared_pointer<void>.
	\details To initialize parameters:
	- paramsPtr=boost::shared_ptr<void> (new ParametersType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr);

/*! void SensorTimer_Simulator_IndexGenerator_initializeVars(boost::shared_ptr<void> & varsPtr)
	\brief [required] Function pointer type for interface function of initializing node's variables.
	\param [out] varsPtr The variables embelished by boost::shared_pointer<void>.
	\details To initialize variables:
	- varsPtr=boost::shared_ptr<void> (new VariablesType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr);

/*! @}*/ 

#endif