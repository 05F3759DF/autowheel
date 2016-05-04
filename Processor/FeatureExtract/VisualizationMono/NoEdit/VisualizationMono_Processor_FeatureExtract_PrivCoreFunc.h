//You need not to modify this file.

/*! \defgroup VisualizationMono_Processor_FeatureExtract VisualizationMono_Processor_FeatureExtract
	\ingroup VisualizationMono_Library Processor_FeatureExtract_NodeClass
	\brief VisualizationMono_Processor_FeatureExtract defines the Processor_FeatureExtract in VisualizationMono.
*/

#ifndef VISUALIZATIONMONO_PROCESSOR_FEATUREEXTRACT_PRIVCOREFUNC_H
#define VISUALIZATIONMONO_PROCESSOR_FEATUREEXTRACT_PRIVCOREFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Processor_FeatureExtract_PrivCoreFunc VisualizationMono_Processor_FeatureExtract_PrivCoreFunc
	\ingroup VisualizationMono_Processor_FeatureExtract
	\brief VisualizationMono_Processor_FeatureExtract_PrivCoreFunc defines the PrivCoreFunc in VisualizationMono_Processor_FeatureExtract.
*/

/*! \addtogroup VisualizationMono_Processor_FeatureExtract_PrivCoreFunc
	@{
*/

/*! \file VisualizationMono_Processor_FeatureExtract_PrivCoreFunc.h
	 Defines the PrivCoreFunc of VisualizationMono_Processor_FeatureExtract
*/

//*******************Please add other headers below*******************


#include "../Edit/VisualizationMono_Processor_FeatureExtract_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG VisualizationMono_Processor_FeatureExtract

/*! void VisualizationMono_Processor_FeatureExtract_getPortsSize(QList<int> & inputPortsSize, int & outputPortsNumber)
	\brief [required] Function pointer type for interface function of getting node's port(s)' size.
	\param [out] inputPortsSize The size of each input port's data buffer.
	\param [out] outputPortsNumber The number of output ports.
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber);

/*! void VisualizationMono_Processor_FeatureExtract_initializeParams(boost::shared_ptr<void> & paramsPtr)
	\brief [required] Function pointer type for interface function of initializing node's parameters.
	\param [out] paramsPtr The parameters embelished by boost::shared_pointer<void>.
	\details To initialize parameters:
	- paramsPtr=boost::shared_ptr<void> (new ParametersType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr);

/*! void VisualizationMono_Processor_FeatureExtract_initializeVars(boost::shared_ptr<void> & varsPtr)
	\brief [required] Function pointer type for interface function of initializing node's variables.
	\param [out] varsPtr The variables embelished by boost::shared_pointer<void>.
	\details To initialize variables:
	- varsPtr=boost::shared_ptr<void> (new VariablesType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr);

/*! @}*/ 

#endif