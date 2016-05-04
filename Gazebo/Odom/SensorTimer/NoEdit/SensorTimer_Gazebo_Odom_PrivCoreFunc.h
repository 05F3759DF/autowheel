//You need not to modify this file.

/*! \defgroup SensorTimer_Gazebo_Odom SensorTimer_Gazebo_Odom
	\ingroup SensorTimer_Library Gazebo_Odom_NodeClass
	\brief SensorTimer_Gazebo_Odom defines the Gazebo_Odom in SensorTimer.
*/

#ifndef SENSORTIMER_GAZEBO_ODOM_PRIVCOREFUNC_H
#define SENSORTIMER_GAZEBO_ODOM_PRIVCOREFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorTimer_Gazebo_Odom_PrivCoreFunc SensorTimer_Gazebo_Odom_PrivCoreFunc
	\ingroup SensorTimer_Gazebo_Odom
	\brief SensorTimer_Gazebo_Odom_PrivCoreFunc defines the PrivCoreFunc in SensorTimer_Gazebo_Odom.
*/

/*! \addtogroup SensorTimer_Gazebo_Odom_PrivCoreFunc
	@{
*/

/*! \file SensorTimer_Gazebo_Odom_PrivCoreFunc.h
	 Defines the PrivCoreFunc of SensorTimer_Gazebo_Odom
*/

//*******************Please add other headers below*******************


#include "../Edit/SensorTimer_Gazebo_Odom_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG SensorTimer_Gazebo_Odom

/*! void SensorTimer_Gazebo_Odom_getPortsSize(QList<int> & inputPortsSize, int & outputPortsNumber)
	\brief [required] Function pointer type for interface function of getting node's port(s)' size.
	\param [out] inputPortsSize The size of each input port's data buffer.
	\param [out] outputPortsNumber The number of output ports.
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber);

/*! void SensorTimer_Gazebo_Odom_initializeParams(boost::shared_ptr<void> & paramsPtr)
	\brief [required] Function pointer type for interface function of initializing node's parameters.
	\param [out] paramsPtr The parameters embelished by boost::shared_pointer<void>.
	\details To initialize parameters:
	- paramsPtr=boost::shared_ptr<void> (new ParametersType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr);

/*! void SensorTimer_Gazebo_Odom_initializeVars(boost::shared_ptr<void> & varsPtr)
	\brief [required] Function pointer type for interface function of initializing node's variables.
	\param [out] varsPtr The variables embelished by boost::shared_pointer<void>.
	\details To initialize variables:
	- varsPtr=boost::shared_ptr<void> (new VariablesType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr);

/*! @}*/ 

#endif