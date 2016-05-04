//You need to modify this file.

#ifndef VISUALIZATIONMULTI_CALIBRATION_LASER_VARS_H
#define VISUALIZATIONMULTI_CALIBRATION_LASER_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMulti_Calibration_Laser_Vars VisualizationMulti_Calibration_Laser_Vars
	\ingroup VisualizationMulti_Calibration_Laser
	\brief VisualizationMulti_Calibration_Laser_Vars defines the Vars in VisualizationMulti_Calibration_Laser.
*/

/*! \addtogroup VisualizationMulti_Calibration_Laser_Vars
	@{
*/

/*! \file VisualizationMulti_Calibration_Laser_Vars.h
	 Defines the Vars of VisualizationMulti_Calibration_Laser
*/

//*******************Please add other headers below*******************


#include "VisualizationMulti_Calibration_Laser_ParamsData.h"

//The Vars is defined as below
/*! \class VisualizationMulti_Calibration_Laser_Vars 
	\brief The Vars of VisualizationMulti_Calibration_Laser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMulti_Calibration_Laser_Vars 
{
public:
	/*! \fn VisualizationMulti_Calibration_Laser_Vars()
		\brief The constructor of VisualizationMulti_Calibration_Laser_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMulti_Calibration_Laser_Vars() 
	{
        beams = new QLabel();
        beams->setAlignment(Qt::AlignCenter);
	}
	/*! \fn ~VisualizationMulti_Calibration_Laser_Vars()
		\brief The destructor of VisualizationMulti_Calibration_Laser_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMulti_Calibration_Laser_Vars() 
	{
        if(beams->parent() == NULL)
        {
            delete beams;
        }
	}
public:
	//*******************Please add variables below*******************
    QLabel * beams;
    QPainter painter;
    double startangle;
    double endtangle;
    double resolution;
    void lineSquare(double x[], double y[], int dotnum, double &k, double &b)
        {
            double Sx = 0;
            double Sy = 0;
            double Sxy = 0;
            double Sxx = 0;
            double Syy = 0;

            for (int i = 0; i < dotnum; i++)
            {
                Sx += x[i];
                Sy += y[i];
                Sxx += x[i] * x[i];
                Syy += y[i] * y[i];
                Sxy += x[i] * y[i];
            }
            b = (dotnum * Sxy - Sx * Sy) / (dotnum * Sxx - Sx * Sx);
            k = Sy / dotnum - b * Sx / dotnum;
        }

};

/*! @}*/ 

#endif
