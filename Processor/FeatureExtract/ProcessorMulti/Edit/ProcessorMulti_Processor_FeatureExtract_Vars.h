//You need to modify this file.

#ifndef PROCESSORMULTI_PROCESSOR_FEATUREEXTRACT_VARS_H
#define PROCESSORMULTI_PROCESSOR_FEATUREEXTRACT_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Processor_FeatureExtract_Vars ProcessorMulti_Processor_FeatureExtract_Vars
	\ingroup ProcessorMulti_Processor_FeatureExtract
	\brief ProcessorMulti_Processor_FeatureExtract_Vars defines the Vars in ProcessorMulti_Processor_FeatureExtract.
*/

/*! \addtogroup ProcessorMulti_Processor_FeatureExtract_Vars
	@{
*/

/*! \file ProcessorMulti_Processor_FeatureExtract_Vars.h
	 Defines the Vars of ProcessorMulti_Processor_FeatureExtract
*/

//*******************Please add other headers below*******************
#include <fstream>
#include "Processor/FeatureExtract/ProcessorMulti/processormulti_processor_featureextract_ex.h"

#include "ProcessorMulti_Processor_FeatureExtract_ParamsData.h"

//The Vars is defined as below
/*! \class ProcessorMulti_Processor_FeatureExtract_Vars 
	\brief The Vars of ProcessorMulti_Processor_FeatureExtract.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Processor_FeatureExtract_Vars 
{
public:
	/*! \fn ProcessorMulti_Processor_FeatureExtract_Vars()
		\brief The constructor of ProcessorMulti_Processor_FeatureExtract_Vars. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Processor_FeatureExtract_Vars() 
	{
        Pi = 3.14159265358979;
        unit = 100;
//        for(int i = 0; i < 10; i++)
//            door_point.push_back(_point(0,0));
        mapImageName = "map.png";
        keyPointFilename = "map.txt";
        filePath = "./";
        stream1 = fopen("$(CurTime)_featureExtract.txt","wb");
        if(stream1 == NULL)
        {
            printf("save_result_of_featureExtract failed to create the file.\n");
        }
	}
	/*! \fn ~ProcessorMulti_Processor_FeatureExtract_Vars()
		\brief The destructor of ProcessorMulti_Processor_FeatureExtract_Vars. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Processor_FeatureExtract_Vars() 
	{
            fclose(stream1);
	}
public:
	//*******************Please add variables below*******************
    int unit;
    double Pi;
    FILE*stream1;
    QVector<cv::Point2d> door_point;

    //20150519 mei
    cv::Point2i originPoint;
    Line leftWall, rightWall;

    cv::Mat mapImage;

    QString mapImageName;
    QString keyPointFilename;
    QString filePath;

    cv::Mat img_hough_l;
    cv::Mat img_hough_r;
    cv::Mat img;
};

/*! @}*/ 

#endif
