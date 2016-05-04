//You need to modify this file.

#ifndef VISUALIZATIONMONO_CALIBRATION_LASER_VARS_H
#define VISUALIZATIONMONO_CALIBRATION_LASER_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Calibration_Laser_Vars VisualizationMono_Calibration_Laser_Vars
	\ingroup VisualizationMono_Calibration_Laser
	\brief VisualizationMono_Calibration_Laser_Vars defines the Vars in VisualizationMono_Calibration_Laser.
*/

/*! \addtogroup VisualizationMono_Calibration_Laser_Vars
	@{
*/

/*! \file VisualizationMono_Calibration_Laser_Vars.h
	 Defines the Vars of VisualizationMono_Calibration_Laser
*/

//*******************Please add other headers below*******************


#include "VisualizationMono_Calibration_Laser_ParamsData.h"

//The Vars is defined as below
/*! \class VisualizationMono_Calibration_Laser_Vars 
	\brief The Vars of VisualizationMono_Calibration_Laser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Calibration_Laser_Vars 
{
public:
	/*! \fn VisualizationMono_Calibration_Laser_Vars()
		\brief The constructor of VisualizationMono_Calibration_Laser_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Calibration_Laser_Vars() 
	{
        beams = new QLabel();
        beams->setAlignment(Qt::AlignCenter);
        frameNum = 0;
	}
	/*! \fn ~VisualizationMono_Calibration_Laser_Vars()
		\brief The destructor of VisualizationMono_Calibration_Laser_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Calibration_Laser_Vars() 
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
    QVector<double> thVector;
    QVector<double> xVector;
    QVector<double> yVector;
    int frameNum;

    double average(QVector<double> v)
    {
        double r = 0;
        for (QVector<double>::iterator i = v.begin(); i != v.end(); i++)
        {
            r += *i;
        }
        return r / v.size();
    }

    void getkb(short data[], int datasize, int l, int r,
               double startangle, double resolution, double ratio,
               double xrangel, double xranger, double yrangel, double yranger,
               double &k, double &b,
               double dth = 0.0, double dw = 0.0, double dh = 0.0)
    {
        double pi=3.1415926535897932384626433832795 / 180.0;
        double linedatax[500], linedatay[500];
        int dotnum = 0;
        for (int i = datasize + l; i < datasize + r; i++)
        {
            double theta = (startangle + resolution * i) * pi + dth;
            double distance = ratio * data[i];
            double x = dw + distance * cos(theta);
            double y = dh + -distance * sin(theta);
            if (xrangel < x && x < xranger && yrangel < y && y < yranger)
            {
                linedatax[dotnum] = x;
                linedatay[dotnum] = y;
                dotnum++;
            }
        }

        double Sx = 0;
        double Sy = 0;
        double Sxy = 0;
        double Sxx = 0;
        double Syy = 0;

        for (int i = 0; i < dotnum; i++)
        {
            Sx += linedatax[i];
            Sy += linedatay[i];
            Sxx += linedatax[i] * linedatax[i];
            Syy += linedatay[i] * linedatay[i];
            Sxy += linedatax[i] * linedatay[i];
        }
        k = (dotnum * Sxy - Sx * Sy) / (dotnum * Sxx - Sx * Sx);
        b = Sy / dotnum - k * Sx / dotnum;
    }
};

/*! @}*/ 

#endif
