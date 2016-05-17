//You need to modify this file.

#ifndef VISUALIZATIONMONO_PROCESSOR_PATHGENERATOR_VARS_H
#define VISUALIZATIONMONO_PROCESSOR_PATHGENERATOR_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Processor_PathGenerator_Vars VisualizationMono_Processor_PathGenerator_Vars
	\ingroup VisualizationMono_Processor_PathGenerator
	\brief VisualizationMono_Processor_PathGenerator_Vars defines the Vars in VisualizationMono_Processor_PathGenerator.
*/

/*! \addtogroup VisualizationMono_Processor_PathGenerator_Vars
	@{
*/

/*! \file VisualizationMono_Processor_PathGenerator_Vars.h
	 Defines the Vars of VisualizationMono_Processor_PathGenerator
*/

//*******************Please add other headers below*******************
#include "glviewer.h"

#include "VisualizationMono_Processor_PathGenerator_ParamsData.h"

//The Vars is defined as below
/*! \class VisualizationMono_Processor_PathGenerator_Vars 
	\brief The Vars of VisualizationMono_Processor_PathGenerator.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Processor_PathGenerator_Vars 
{
public:
	/*! \fn VisualizationMono_Processor_PathGenerator_Vars()
		\brief The constructor of VisualizationMono_Processor_PathGenerator_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Processor_PathGenerator_Vars() 
	{

        indexLabel = new QLabel();
        glviewer = new GLViewer();
        shownum = 1;
        glviewer->setBackground(QColor(222,222,222));

        offlineTrajecPath = "./";
        offlineTrajecFilename = "line.txt";

        offsetx = offsety = 800;
        for (int i = 0; i < 1600; i++) {
            for (int j = 0; j < 1600; j++) {
                map[i][j] = 0;
            }
        }
	}
	/*! \fn ~VisualizationMono_Processor_PathGenerator_Vars()
		\brief The destructor of VisualizationMono_Processor_PathGenerator_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Processor_PathGenerator_Vars() 
	{
        glviewer->clearDisplayList();
        if(glviewer->parent() ==NULL)
            delete glviewer;
	}
public:
	//*******************Please add variables below*******************
    GLViewer *glviewer;
    GLuint shownum;
    GLuint displaylistbase;
    //trajec_state lastposition;

    QString offlineTrajecPath;
    QString offlineTrajecFilename;
    QVector<trajec_state> offlinetrajec;

    QVector<cv::Point2d> onlinetrajec;
    cv::Point2f currentposition, lastPos;

    QLabel *indexLabel;
    int map[1600][1600];
    int offsetx, offsety;
};

/*! @}*/ 

#endif
