//You need to modify this file.

#ifndef VISUALIZATIONMULTI_VISUALMISC_COMBINEDVISUAL_VARS_H
#define VISUALIZATIONMULTI_VISUALMISC_COMBINEDVISUAL_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMulti_VisualMisc_CombinedVisual_Vars VisualizationMulti_VisualMisc_CombinedVisual_Vars
	\ingroup VisualizationMulti_VisualMisc_CombinedVisual
	\brief VisualizationMulti_VisualMisc_CombinedVisual_Vars defines the Vars in VisualizationMulti_VisualMisc_CombinedVisual.
*/

/*! \addtogroup VisualizationMulti_VisualMisc_CombinedVisual_Vars
	@{
*/

/*! \file VisualizationMulti_VisualMisc_CombinedVisual_Vars.h
	 Defines the Vars of VisualizationMulti_VisualMisc_CombinedVisual
*/

//*******************Please add other headers below*******************
#include "glviewer.h"

#include "VisualizationMulti_VisualMisc_CombinedVisual_ParamsData.h"
#include "VisualMisc/CombinedVisual/VisualizationMulti/sensorwidgets.h"
//The Vars is defined as below
/*! \class VisualizationMulti_VisualMisc_CombinedVisual_Vars 
	\brief The Vars of VisualizationMulti_VisualMisc_CombinedVisual.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMulti_VisualMisc_CombinedVisual_Vars 
{
public:
	/*! \fn VisualizationMulti_VisualMisc_CombinedVisual_Vars()
		\brief The constructor of VisualizationMulti_VisualMisc_CombinedVisual_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMulti_VisualMisc_CombinedVisual_Vars() 
	{
        glviewer = new GLViewer();
        sensor = new SensorWidgets();
        textWidget = new QLabel();
        isSimulator = 0;
        lastPos.x = lastPos.y = lastPos.theta = 0;

	}
	/*! \fn ~VisualizationMulti_VisualMisc_CombinedVisual_Vars()
		\brief The destructor of VisualizationMulti_VisualMisc_CombinedVisual_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMulti_VisualMisc_CombinedVisual_Vars() 
    {
        glviewer->clearDisplayList();
        if(glviewer->parent() == NULL)
            delete glviewer;
        if(textWidget->parent() == NULL)
            delete textWidget;
	}
    void drawCar(const trajec_state& pos)
    {
        double wheelbase = 0.48, borderWidth=0.7, borderHeight=0.8;
        double carLength = 0.6;

        cv::Point2d leftup(-borderWidth/2, borderHeight);
        cv::Point2d leftbottom(-borderWidth/2, 0);
        cv::Point2d rightbottom(borderWidth/2, 0);
        cv::Point2d rightup(borderWidth/2, borderHeight);

        double tt = (borderHeight-carLength)/2.0;

        cv::Point2d leftwheel(wheelbase/2.0, tt);
        cv::Point2d rightwheel(-wheelbase/2.0,tt);

        cv::Point2d carFrontPt(0, carLength);


        glNewList(m_list[CarListID], GL_COMPILE);
        glColor3f(1,0,0);
        glLineWidth(2);

        glTranslatef(offset_x+pos.y,offset_y-pos.x ,offset_z);
        double theta = -90+(pos.theta-M_PI/2.0)*180.0/M_PI;
        glRotatef(theta, 0,0,1);

        glBegin(GL_LINES);//draw rectangle
            glVertex3f(leftup.x, leftup.y, 0); glVertex3f(leftbottom.x, leftbottom.y, 0);
            glVertex3f(rightbottom.x, rightbottom.y, 0); glVertex3f(rightup.x, rightup.y, 0);
            glVertex3f(leftup.x, leftup.y, 0);glVertex3f(rightup.x, rightup.y, 0);
            glVertex3f(leftbottom.x, leftbottom.y, 0); glVertex3f(rightbottom.x, rightbottom.y, 0);
        glEnd();

        glColor3f(0,0,1);
        glPointSize(3);
        glBegin(GL_POINTS);
            glVertex3f(leftwheel.x, leftwheel.y, 0);
            glVertex3f(rightwheel.x, rightwheel.y, 0);
            glVertex3f(carFrontPt.x, carFrontPt.y, 0);
        glEnd();
        glEndList();
    }
public:
	//*******************Please add variables below*******************
    GLViewer* glviewer;
    SensorWidgets *sensor; //可视化速度和朝向
    QLabel* textWidget;

    enum {MapListID=0, CarListID, OfflineTrajID, OnlineTrajID, TextID, ListCount};
    GLuint m_list[ListCount];

    QVector<cv::Point2d> sketchMap;
    double offset_x, offset_y, offset_z;


    QVector<trajec_state> offlinetrajec;
    QVector<cv::Point2d> onlinetrajec;
    cv::Point2d currentposition,lastposition;

    QVector<int> colorList;

    trajec_state lastPos;

    bool isSimulator;
};

/*! @}*/ 

#endif
