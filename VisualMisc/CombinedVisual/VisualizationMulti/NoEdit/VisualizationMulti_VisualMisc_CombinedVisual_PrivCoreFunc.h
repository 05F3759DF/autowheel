//You need not to modify this file.

/*! \defgroup VisualizationMulti_VisualMisc_CombinedVisual VisualizationMulti_VisualMisc_CombinedVisual
	\ingroup VisualizationMulti_Library VisualMisc_CombinedVisual_NodeClass
	\brief VisualizationMulti_VisualMisc_CombinedVisual defines the VisualMisc_CombinedVisual in VisualizationMulti.
*/

#ifndef VISUALIZATIONMULTI_VISUALMISC_COMBINEDVISUAL_PRIVCOREFUNC_H
#define VISUALIZATIONMULTI_VISUALMISC_COMBINEDVISUAL_PRIVCOREFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMulti_VisualMisc_CombinedVisual_PrivCoreFunc VisualizationMulti_VisualMisc_CombinedVisual_PrivCoreFunc
	\ingroup VisualizationMulti_VisualMisc_CombinedVisual
	\brief VisualizationMulti_VisualMisc_CombinedVisual_PrivCoreFunc defines the PrivCoreFunc in VisualizationMulti_VisualMisc_CombinedVisual.
*/

/*! \addtogroup VisualizationMulti_VisualMisc_CombinedVisual_PrivCoreFunc
	@{
*/

/*! \file VisualizationMulti_VisualMisc_CombinedVisual_PrivCoreFunc.h
	 Defines the PrivCoreFunc of VisualizationMulti_VisualMisc_CombinedVisual
*/

//*******************Please add other headers below*******************


#include "../Edit/VisualizationMulti_VisualMisc_CombinedVisual_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG VisualizationMulti_VisualMisc_CombinedVisual

/*! void VisualizationMulti_VisualMisc_CombinedVisual_getPortsSize(QList<int> & inputPortsSize, int & outputPortsNumber)
	\brief [required] Function pointer type for interface function of getting node's port(s)' size.
	\param [out] inputPortsSize The size of each input port's data buffer.
	\param [out] outputPortsNumber The number of output ports.
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber);

/*! void VisualizationMulti_VisualMisc_CombinedVisual_initializeParams(boost::shared_ptr<void> & paramsPtr)
	\brief [required] Function pointer type for interface function of initializing node's parameters.
	\param [out] paramsPtr The parameters embelished by boost::shared_pointer<void>.
	\details To initialize parameters:
	- paramsPtr=boost::shared_ptr<void> (new ParametersType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr);

/*! void VisualizationMulti_VisualMisc_CombinedVisual_initializeVars(boost::shared_ptr<void> & varsPtr)
	\brief [required] Function pointer type for interface function of initializing node's variables.
	\param [out] varsPtr The variables embelished by boost::shared_pointer<void>.
	\details To initialize variables:
	- varsPtr=boost::shared_ptr<void> (new VariablesType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr);

/*! @}*/ 

#endif