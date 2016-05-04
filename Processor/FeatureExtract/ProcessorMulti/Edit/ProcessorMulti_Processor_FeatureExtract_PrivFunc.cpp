//You need to program this file.

#include "../NoEdit/ProcessorMulti_Processor_FeatureExtract_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	ProcessorMulti_Processor_FeatureExtract_Params * params=(ProcessorMulti_Processor_FeatureExtract_Params *)paramsPtr;
	ProcessorMulti_Processor_FeatureExtract_Vars * vars=(ProcessorMulti_Processor_FeatureExtract_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader, vars, mapImageName);
    GetParamValue(xmlloader, vars, keyPointFilename);  
    GetParamValue(xmlloader, vars, filePath);

    vars->mapImage = cv::imread((vars->filePath+vars->mapImageName).toStdString());
    std::ifstream pointFile;
    pointFile.open((vars->filePath+vars->keyPointFilename).toStdString().c_str());

    string str;
    pointFile>>str>>params->ox;
    pointFile>>str>>params->oy;
    pointFile>>str>>params->pixelsize;
    ///计算坐标远点
    vars->originPoint.x = qRound(params->ox/params->pixelsize);
    vars->originPoint.y = vars->mapImage.rows-1-qRound(params->oy/params->pixelsize);
    ///忽略起点和终点-3行
    std::getline(pointFile, str);
    std::getline(pointFile, str);
    std::getline(pointFile, str);
    std::getline(pointFile, str);
//    cv::Point2d startPoint, endPoint;
//    pointFile>>str>>startPoint.x>>startPoint.y;
//    pointFile>>str>>endPoint.x>>endPoint.y;
//    cv::Point2i tmpStart = world2image(startPoint, vars->originPoint, params->pixelsize);
//    cv::circle(vars->mapImage, tmpStart, 3, cv::Scalar(0,0,255), 3);
//    tmpStart = world2image(endPoint, vars->originPoint, params->pixelsize);
//    cv::circle(vars->mapImage, tmpStart, 3, cv::Scalar(0,0,255), 3);
    ///读门的坐标
    int doornums=0;
    pointFile>>str>>doornums;
    if(str == "DOORS")
    {
        for(int i=0; i<doornums; i++)
        {
            cv::Point2d temp;
            pointFile>>str>>temp.x>>temp.y;
            vars->door_point.push_back(temp);
        }
    }
    else
        return 0;
    ///画门的位置
//    for(int i=0; i<vars->door_point.size(); i++)
//    {
//        cv::Point2i tPoint = world2image(vars->door_point[i], vars->originPoint,
//                                         params->pixelsize, vars->mapImage);
//        cv::circle(vars->mapImage, tPoint, 2, cv::Scalar(0,255,0), 2);
//    }
    ///读墙的坐标
    std::getline(pointFile, str);
    std::getline(pointFile, str);
    pointFile>>str>>vars->leftWall.start.x>>vars->leftWall.start.y;
    pointFile>>str>>vars->leftWall.end.x>>vars->leftWall.end.y;

    std::getline(pointFile, str);
    std::getline(pointFile, str);
    pointFile>>str>>vars->rightWall.start.x>>vars->rightWall.start.y;
    pointFile>>str>>vars->rightWall.end.x>>vars->rightWall.end.y;
    ///计算直线方程的系数k，b
    vars->leftWall.calcCoefficient();
    vars->rightWall.calcCoefficient();

    ///可视化墙的位置
//    ///左墙
//    cv::Point2i start = world2image(vars->leftWall.start, vars->originPoint,params->pixelsize);
//    cv::Point2i end = world2image(vars->leftWall.end, vars->originPoint,params->pixelsize);
//    cv::line(vars->mapImage, start, end, cv::Scalar(255,0,0), 1);
//    ///右墙
//    start = world2image(vars->rightWall.start, vars->originPoint,params->pixelsize);
//    end = world2image(vars->rightWall.end, vars->originPoint,params->pixelsize);
//    cv::line(vars->mapImage, start, end, cv::Scalar(255,0,0), 1);
//    cv::imwrite("tt.png" , vars->mapImage);
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	ProcessorMulti_Processor_FeatureExtract_Params * params=(ProcessorMulti_Processor_FeatureExtract_Params *)paramsPtr;
	ProcessorMulti_Processor_FeatureExtract_Vars * vars=(ProcessorMulti_Processor_FeatureExtract_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
	
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	ProcessorMulti_Processor_FeatureExtract_Params * params=(ProcessorMulti_Processor_FeatureExtract_Params *)paramsPtr;
	ProcessorMulti_Processor_FeatureExtract_Vars * vars=(ProcessorMulti_Processor_FeatureExtract_Vars *)varsPtr;
	internalTrigger=NULL;
	internalTriggerSignal=QString();
	/*======Occasionally Program above======*/
	/*
	Function: get internal trigger [defined in vars] for node.
	You need to program here when you need internal trigger (internalTrigger + internalTriggerSignal) for node.
	E.g.
	internalTrigger=&(vars->trigger);
	internalTriggerSignal=QString(SIGNAL(triggerSignal()));
	*/
}

void DECOFUNC(initializeOutputData)(void * paramsPtr, void * varsPtr, boost::shared_ptr<void> & outputDataPtr)
{
	ProcessorMulti_Processor_FeatureExtract_Params * params=(ProcessorMulti_Processor_FeatureExtract_Params *)paramsPtr;
	ProcessorMulti_Processor_FeatureExtract_Vars * vars=(ProcessorMulti_Processor_FeatureExtract_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new ProcessorMulti_Processor_FeatureExtract_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

void DECOFUNC(getMultiInputDataSize)(void * paramsPtr, void * varsPtr, QList<int> & inputDataSize)
{
	ProcessorMulti_Processor_FeatureExtract_Params * params=(ProcessorMulti_Processor_FeatureExtract_Params *)paramsPtr;
	ProcessorMulti_Processor_FeatureExtract_Vars * vars=(ProcessorMulti_Processor_FeatureExtract_Vars *)varsPtr;
	inputDataSize=QList<int>();
	/*======Please Program above======*/
	/*
	Function: get input data size to be grabbed from buffer.
	Rules:
	inputDataSize=0: grab and remove all data from buffer.
	inputDataSize>0: grab inputDataSize latest data from buffer.
	inputDataSize<0: grab and remove inputDataSize ancient data from buffer.
	E.g.
	inputDataSize=QList<int>()<<0<<1<<-1...;
	*/
}

//Input Port #0: Buffer_Size = 10, Params_Type = SensorInternalEvent_Sensor_Laser_Params, Data_Type = SensorInternalEvent_Sensor_Laser_Data
//Input Port #1: Buffer_Size = 10, Params_Type = SourceDrainMono_Sensor_stm32comm_Params, Data_Type = SourceDrainMono_Sensor_stm32comm_Data
//Input Port #2: Buffer_Size = 10, Params_Type = SensorTimer_Localization_Slam_Params, Data_Type = SensorTimer_Localization_Slam_Data
bool DECOFUNC(processMultiInputData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > inputParams, QVector<QVector<void *> > inputData, void * outputData, QList<int> & outputPortIndex)
{
	ProcessorMulti_Processor_FeatureExtract_Params * params=(ProcessorMulti_Processor_FeatureExtract_Params *)paramsPtr;
	ProcessorMulti_Processor_FeatureExtract_Vars * vars=(ProcessorMulti_Processor_FeatureExtract_Vars *)varsPtr;
	QVector<SensorInternalEvent_Sensor_Laser_Params *> inputparams_0; copyQVector(inputparams_0,inputParams[0]);
	QVector<SourceDrainMono_Sensor_stm32comm_Params *> inputparams_1; copyQVector(inputparams_1,inputParams[1]);
    QVector<SensorTimer_Localization_Slam_Params *> inputparams_2; copyQVector(inputparams_2,inputParams[2]);
	QVector<SensorInternalEvent_Sensor_Laser_Data *> inputdata_0; copyQVector(inputdata_0,inputData[0]);
	QVector<SourceDrainMono_Sensor_stm32comm_Data *> inputdata_1; copyQVector(inputdata_1,inputData[1]);
    QVector<SensorTimer_Localization_Slam_Data *> inputdata_2; copyQVector(inputdata_2,inputData[2]);
	ProcessorMulti_Processor_FeatureExtract_Data * outputdata=(ProcessorMulti_Processor_FeatureExtract_Data *)outputData;
	outputPortIndex=QList<int>();
	if(inputdata_0.size()==0){return 0;}
	if(inputdata_1.size()==0){return 0;}
    if(inputdata_2.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Step 1: process inputdata_index, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/
    outputdata->wall_detect_point.clear();
    int URGDataSize = inputdata_0.front()->datasize;
    outputdata->URGData_size = URGDataSize;
    outputdata->door_point = vars->door_point;
    outputdata->leftWall = vars->leftWall;
    outputdata->rightWall = vars->rightWall;
    double IMUorientation;// = inputdata_1.front()->theta;
    static double IMUx = 0;
    static double IMUy = 0;
    static double time1 = 0;
    static double IMUx_pre = 0;
    static double IMUy_pre = 0;
    static double time1_pre = 0;

    static double IMUx_lmsl;
    static double IMUx_lmsr;
    static double IMUy_lmsl;
    static double IMUy_lmsr;

    IMUx_pre = IMUx;
    IMUy_pre = IMUy;
    time1_pre = time1;
#if 0 //使用 IMU&Encoder
    IMUx = inputdata_1.front()->x;
    IMUy = inputdata_1.front()->y;
    IMUorientation = inputdata_1.front()->theta;
    time1 = Qtime2time(inputdata_1.front()->timestamp);
#else //使用 SLAM
    IMUx = inputdata_2.front()->x;
    IMUy = inputdata_2.front()->y;
    IMUorientation = inputdata_2.front()->theta;
    time1 = Qtime2time(inputdata_2.front()->qtimestamp);
#endif
    //4lines below:use same calculation with offline sample generation
    IMUx_lmsl = IMUx + nav_shift_f*cos(IMUorientation) - nav_shift_s*sin(IMUorientation);//*******ÕýžººÅ¿ÉÄÜÒªµ÷
    IMUy_lmsl = IMUy + nav_shift_f*sin(IMUorientation) + nav_shift_s*cos(IMUorientation);
    IMUx_lmsr = IMUx + nav_shift_f*cos(IMUorientation) + nav_shift_s*sin(IMUorientation);//*******ÕýžººÅ¿ÉÄÜÒªµ÷
    IMUy_lmsr = IMUy + nav_shift_f*sin(IMUorientation) - nav_shift_s*cos(IMUorientation);


     double temp_angle;
    for (int i = 0; i < URGDataSize; i++)//lms_l
    {
        temp_angle = IMUorientation -(double)i / 360 * vars->Pi + vars->Pi / 2;
        outputdata->urg_data_point[0][i][0] = ((IMUx_lmsl +cos(temp_angle)*inputdata_0.front()->ldata[i] / vars->unit) );//Ò»Ã×DEFINE_3žñ£¬³õÊŒÎ»ÖÃ£šDEFINE_4,DEFINE_4)
        outputdata->urg_data_point[0][i][1] = ((IMUy_lmsl + sin(temp_angle)*inputdata_0.front()->ldata[i] / vars->unit) );
    }

    for (int i = 0; i < URGDataSize; i++)//lms_r
    {
        temp_angle = IMUorientation -(double)i / 360 * vars->Pi + vars->Pi / 2 + lms_shift_from_rlms_2_llms;
        outputdata->urg_data_point[1][i][0] = ((IMUx_lmsr +cos(temp_angle)*inputdata_0.front()->rdata[i] / vars->unit) );//Ò»Ã×DEFINE_3žñ£¬³õÊŒÎ»ÖÃ£šDEFINE_4,DEFINE_4)
        outputdata->urg_data_point[1][i][1] = ((IMUy_lmsr + sin(temp_angle)*inputdata_0.front()->rdata[i] / vars->unit) );
    }


    //jian ce men de open close         //双激光检测门
    memset(outputdata->is_door_open,0,sizeof(outputdata->is_door_open));
    outputdata->lms_gap.clear();
    static double temp1_x;
    static double temp1_y;
    temp1_x = outputdata->urg_data_point[0][0][0];
    temp1_y = outputdata->urg_data_point[0][0][1];
    static double temp2_lms_gap;
    static double temp3;
    static double temp4;

    for (int i = 1, j = 0; i < URGDataSize && j < URGDataSize;)
    {
        if(DISTANCE_2(outputdata->urg_data_point[0][i][0]-IMUx,outputdata->urg_data_point[0][i][1]-IMUy) < 1)//hu lve 1m yi nei de dian
        {
            i++;
            continue;
        }
        else if(DISTANCE_2(outputdata->urg_data_point[1][j][0]-IMUx,outputdata->urg_data_point[1][j][1]-IMUy) < 1)//hu lve 1m yi nei de dian
        {
            j++;
            continue;
        }

        static double referencePoint_x;
        static double referencePoint_y;
        referencePoint_x = (IMUx_lmsl+IMUx_lmsr)/2;
        referencePoint_y = (IMUy_lmsl+IMUy_lmsr)/2;

        temp3 = (outputdata->urg_data_point[0][i][0]-referencePoint_x)*(outputdata->urg_data_point[1][j][1]-referencePoint_y)-(outputdata->urg_data_point[1][j][0]-referencePoint_x)*(outputdata->urg_data_point[0][i][1]-referencePoint_y);//select the leftest lms_point
        if(temp3 > 0)
        {//lms_r first
            temp2_lms_gap = DISTANCE_2(outputdata->urg_data_point[1][j][0]-temp1_x,outputdata->urg_data_point[1][j][1]-temp1_y);

            temp4 = min(DISTANCE_2(outputdata->urg_data_point[1][j][0]-IMUx,outputdata->urg_data_point[1][j][1]-IMUy),DISTANCE_2(temp1_x-IMUx,temp1_y-IMUy));

            if((temp2_lms_gap > door_detect_min_dis && temp4 < door_detect_max_dis_to_wheelchair)||temp2_lms_gap > must_be_an_open_door)
            {//door detect
                outputdata->lms_gap.push_back(_lms_gap(temp1_x,temp1_y,outputdata->urg_data_point[1][j][0],outputdata->urg_data_point[1][j][1]));
              for(int k = 0; k < outputdata->door_point.size(); k++)
              {
                  if(DISTANCE_2(temp1_x-IMUx,temp1_y-IMUy) > DISTANCE_2(outputdata->urg_data_point[1][i][0]-IMUx,outputdata->urg_data_point[1][i][1]-IMUy))//上一个点是远点
                  {
                      if(DISTANCE_2(outputdata->door_point[k].x - temp1_x,outputdata->door_point[k].y - temp1_y)<judge_range_of_a_door)
                          if(outputdata->is_door_open[k] != 1)
                              outputdata->is_door_open[k] = 2;
                      if(DISTANCE_2(outputdata->door_point[k].x - outputdata->urg_data_point[1][j][0],outputdata->door_point[k].y - outputdata->urg_data_point[1][j][1])<judge_range_of_a_door)
                          outputdata->is_door_open[k] = 1;
                  }
                  else
                  {
                      if(DISTANCE_2(outputdata->door_point[k].x - temp1_x,outputdata->door_point[k].y - temp1_y)<judge_range_of_a_door)
                          outputdata->is_door_open[k] = 1;
                      if(DISTANCE_2(outputdata->door_point[k].x - outputdata->urg_data_point[1][j][0],outputdata->door_point[k].y - outputdata->urg_data_point[1][j][1])<judge_range_of_a_door)
                          if(outputdata->is_door_open[k] != 1)
                              outputdata->is_door_open[k] = 2;
                  }
              }
            }
            temp1_x = outputdata->urg_data_point[1][j][0];//temp1保存上一个数据
            temp1_y = outputdata->urg_data_point[1][j][1];
            j++;
        }
        else
        {//lms_l first
            temp2_lms_gap = DISTANCE_2(outputdata->urg_data_point[0][i][0]-temp1_x,outputdata->urg_data_point[0][i][1]-temp1_y);

            temp4 = min(DISTANCE_2(outputdata->urg_data_point[0][i][0]-IMUx,outputdata->urg_data_point[0][i][1]-IMUy),DISTANCE_2(temp1_x-IMUx,temp1_y-IMUy));

            if((temp2_lms_gap > door_detect_min_dis  && temp4 < door_detect_max_dis_to_wheelchair)||temp2_lms_gap > must_be_an_open_door)
            {//door detect
                outputdata->lms_gap.push_back(_lms_gap(temp1_x,temp1_y,outputdata->urg_data_point[0][i][0],outputdata->urg_data_point[0][i][1]));
                for(int k = 0; k < outputdata->door_point.size(); k++)
                {
                    if(DISTANCE_2(temp1_x-IMUx,temp1_y-IMUy) > DISTANCE_2(outputdata->urg_data_point[0][i][0]-IMUx,outputdata->urg_data_point[0][i][1]-IMUy))//上一个点是远点
                    {
                        if(DISTANCE_2(outputdata->door_point[k].x - temp1_x,outputdata->door_point[k].y - temp1_y)<judge_range_of_a_door)
                            //                        if(outputdata->is_door_open[k] != 1)
                            outputdata->is_door_open[k] = 2;//2表示遮挡
                        if(DISTANCE_2(outputdata->door_point[k].x - outputdata->urg_data_point[0][i][0],outputdata->door_point[k].y - outputdata->urg_data_point[0][i][1])<judge_range_of_a_door)
                            if(outputdata->is_door_open[k] != 2)
                                outputdata->is_door_open[k] = 1;
                    }
                    else
                    {
                        if(DISTANCE_2(outputdata->door_point[k].x - temp1_x,outputdata->door_point[k].y - temp1_y)<judge_range_of_a_door)
                            if(outputdata->is_door_open[k] != 2)
                                outputdata->is_door_open[k] = 1;//2表示遮挡
                        if(DISTANCE_2(outputdata->door_point[k].x - outputdata->urg_data_point[0][i][0],outputdata->door_point[k].y - outputdata->urg_data_point[0][i][1])<judge_range_of_a_door)
                            //                          if(outputdata->is_door_open[k] != 1)
                            outputdata->is_door_open[k] = 2;
                    }


//                    if(DISTANCE_2(outputdata->door_point[k].x - temp1_x,outputdata->door_point[k].y - temp1_y)<judge_range_of_a_door)
//                        outputdata->is_door_open[k] = 1;
//                    if(DISTANCE_2(outputdata->door_point[k].x - outputdata->urg_data_point[0][i][0],outputdata->door_point[k].y - outputdata->urg_data_point[0][i][1])<judge_range_of_a_door)
//                        outputdata->is_door_open[k] = 1;
                }


            }
            temp1_x = outputdata->urg_data_point[0][i][0];
            temp1_y = outputdata->urg_data_point[0][i][1];
            i++;
        }
    }
    //直线碰撞检测
//    referencePoint_x = (IMUx_lmsl+IMUx_lmsr)/2;
//    referencePoint_y = (IMUy_lmsl+IMUy_lmsr)/2;
//    cv::Point temp_point;
//    for (int i = 1, j = 0; i < URGDataSize && j < URGDataSize;)
//    {
//        if(DISTANCE_2(outputdata->urg_data_point[0][i][0]-referencePoint_x,outputdata->urg_data_point[0][i][1]-referencePoint_y) < 0.4)//hu lve 0.4m yi nei de dian
//        {
//            i++;
//            continue;
//        }
//        else if(DISTANCE_2(outputdata->urg_data_point[1][j][0]-referencePoint_x,outputdata->urg_data_point[1][j][1]-referencePoint_y) < 0.4)//hu lve 0.4m yi nei de dian
//        {
//            j++;
//            continue;
//        }

//        if(DISTANCE_2(outputdata->urg_data_point[0][i][0]-referencePoint_x,outputdata->urg_data_point[0][i][1]-referencePoint_y) < min_dis_to_barrier)//hu lve 0.4m yi nei de dian
//        {
//            temp_point.x = outputdata->urg_data_point[0][i][0];
//            temp_point.y = outputdata->urg_data_point[0][i][1];
//        }
//        if(DISTANCE_2(outputdata->urg_data_point[1][j][0]-referencePoint_x,outputdata->urg_data_point[1][j][1]-referencePoint_y) < min_dis_to_barrier)//hu lve 0.4m yi nei de dian
//        {
//            temp_point.x = outputdata->urg_data_point[1][j][0];
//            temp_point.y = outputdata->urg_data_point[1][j][1];
//        }
//    }

    cv::Mat tmpMat;
    vars->mapImage.copyTo(tmpMat);

    //hough line
    cv::Point2d temp1,temp2,temp8;
    float theta;
    float rho;
    vars->img_hough_l = cv::Mat::zeros(vars->mapImage.rows,vars->mapImage.cols,CV_8UC1);//
    vars->img_hough_r = cv::Mat::zeros(vars->mapImage.rows,vars->mapImage.cols,CV_8UC1);
    vars->img.setTo(cv::Scalar(0,0,0));
    for (int j = 5; j < 150; j++)//
    {
        temp1.x = outputdata->urg_data_point[0][j][0];
        temp1.y = outputdata->urg_data_point[0][j][1];
        temp2 = world2image(temp1, vars->originPoint, params->pixelsize,vars->img_hough_l);
        vars->img_hough_l.at<unsigned char>(temp2.y,temp2.x) = 1;
    }
    for (int j = 210; j < 355; j++)//
    {
        temp1.x = outputdata->urg_data_point[1][j][0];
        temp1.y = outputdata->urg_data_point[1][j][1];
        temp2 = world2image(temp1, vars->originPoint, params->pixelsize, vars->img_hough_r);
        vars->img_hough_r.at<unsigned char>(temp2.y,temp2.x) = 1;
    }
//    cv::vector<cv::Vec2f> lines;//hough
    QVector<CvLinePolar> lines;
   cv::Point pt1,pt2;
   double a,b,x0,y0;

   cv::Point2d IMU_img = world2image(cv::Point2d(IMUx,IMUy),  vars->originPoint, params->pixelsize, vars->img_hough_r);

   //左墙
    theta = 0;
    rho = params->map_size/2;
    lines.clear();
 //   cv::HoughLines(vars->img_hough_l,lines,1, CV_PI/720,5);
    CvMat img_hough_l_c = vars->img_hough_l;
    Hough_for_wheel(&img_hough_l_c,1,CV_PI/720,5,&lines,10,CV_PI-IMUorientation-0.5,CV_PI-IMUorientation+0.5);
    if(!lines.empty())
    {
    rho = lines[0].rho ;
    theta = lines[0].angle;
    if(rho<0)//pay attention to this
    {
        rho = -rho;
        theta += 3.141592653589793;
    }
    }
    a=cos(theta);
    b=sin(theta);
    x0 = rho*a;
    y0 = rho*b;
    pt1.x = cvRound(x0+1000*(b));
    pt1.y = cvRound(y0-1000*a);
    pt2.x = cvRound(x0-1000*(b));
    pt2.y = cvRound(y0+1000*a);
 //   cv::line(outputdata->mapImage, pt1, pt2, cv::Scalar(0,0,255), 1);
    _line left_wall(pt1,pt2);
    double d2left_wall = left_wall.Dis_point2line(IMU_img.x,IMU_img.y);
    outputdata->d2leftwall = d2left_wall*params->pixelsize;
    cv::Point2d left_wall_start,left_wall_end;
    left_wall_start.x = cvRound(IMU_img.x - d2left_wall*a);
    left_wall_start.y = cvRound(IMU_img.y - d2left_wall*b);
    left_wall_end.x = cvRound(left_wall_start.x + 5/params->pixelsize*b);
    left_wall_end.y = cvRound(left_wall_start.y - 5/params->pixelsize*a);
    cv::line(tmpMat, left_wall_start, left_wall_end, cv::Scalar(0,255,255), 1);
    temp8.x = left_wall_start.x;
    temp8.y = left_wall_start.y;
    temp8 = image2world(temp8,vars->originPoint,params->pixelsize, tmpMat);
    outputdata->wall_detect_point.push_back(temp8);
    temp8.x = left_wall_end.x;
    temp8.y = left_wall_end.y;
    temp8 = image2world(temp8,vars->originPoint,params->pixelsize, tmpMat);
    outputdata->wall_detect_point.push_back(temp8);

    //右墙
    theta = 0;
    rho = params->map_size/2;
    lines.clear();
//    cv::HoughLines(vars->img_hough_r,lines,1, CV_PI/720,5);
    CvMat img_hough_r_c = vars->img_hough_r;
    Hough_for_wheel(&img_hough_r_c,1,CV_PI/720,5,&lines,10,CV_PI-IMUorientation-0.5,CV_PI-IMUorientation+0.5);
    if(!lines.empty())
    {
    rho = lines[0].rho;
    theta = lines[0].angle  ;
    if(rho<0)//pay attention to this
    {
        rho = -rho;
        theta += 3.141592653589793;
    }
    }
    a=cos(theta);
    b=sin(theta);
    x0 = rho*a;
    y0 = rho*b;
    pt1.x = cvRound(x0+1000*(b));
    pt1.y = cvRound(y0-1000*a);
    pt2.x = cvRound(x0-1000*(b));
    pt2.y = cvRound(y0+1000*a);
 //   cv::line(outputdata->mapImage, pt1, pt2, cv::Scalar(0,0,255), 1);
    _line right_wall(pt1,pt2);
    double d2right_wall = right_wall.Dis_point2line(IMU_img.x,IMU_img.y);
    outputdata->d2rightwall = d2right_wall*params->pixelsize;
    cv::Point2d right_wall_start,right_wall_end;
    right_wall_start.x = cvRound(IMU_img.x + d2right_wall*a);
    right_wall_start.y = cvRound(IMU_img.y + d2right_wall*b);
    right_wall_end.x = cvRound(right_wall_start.x + 5/params->pixelsize*b);
    right_wall_end.y = cvRound(right_wall_start.y - 5/params->pixelsize*a);
    cv::line(tmpMat, right_wall_start, right_wall_end, cv::Scalar(255,0,255), 1);
    temp8.x = right_wall_start.x;
    temp8.y = right_wall_start.y;
    temp8 = image2world(temp8,vars->originPoint,params->pixelsize, tmpMat);
    outputdata->wall_detect_point.push_back(temp8);
    temp8.x = right_wall_end.x;
    temp8.y = right_wall_end.y;
    temp8 = image2world(temp8,vars->originPoint,params->pixelsize, tmpMat);
    outputdata->wall_detect_point.push_back(temp8);




    outputdata->feature.timestamp = Qtime2time(QTime::currentTime());
    outputdata->feature.data[0] = inputdata_1.front()->theta - vars->Pi/2;
 //   outputdata->feature.data[1] = (inputdata_1.front()->leftspeed + inputdata_1.front()->rightspeed)/2;
    outputdata->feature.data[1] = DISTANCE_2(IMUx_pre-IMUx,IMUy_pre - IMUy)/((time1 - time1_pre)/1000);

 //   outputdata->feature.data[2] = point_shift(_point())
    QVector<cv::Point2d>door_point_by_wheel;
    point_shift(outputdata->door_point,cv::Point2d(IMUx,IMUy),IMUorientation,door_point_by_wheel);
    for(int j = 0; j < door_point_by_wheel.size(); j++)
    {
        if(door_point_by_wheel[j].x < 0 || DISTANCE_2(door_point_by_wheel[j].x,door_point_by_wheel[j].y) > door_detect_max_dis_to_wheelchair_meter )
            outputdata->is_door_open[j] = 3;//3表示未知
    }
    for(int j = 2; (j < door_point_by_wheel.size()*2+2) && (j < SIZE_OF_FEATURE - 1); j += 2 )
    {
        outputdata->feature.data[j] = door_point_by_wheel[(j-2)/2].x;
        outputdata->feature.data[j+1] = door_point_by_wheel[(j-2)/2].y;

    }

    int j2;
    int wall_feature_start_index = 20;
    QVector<_line>wall_line_by_wheel;
    QVector<_line>wall_line;
    wall_line.push_back(_line(vars->leftWall.start,vars->leftWall.end));
    wall_line.push_back(_line(vars->rightWall.start,vars->rightWall.end));
    wall_point_shift(wall_line,cv::Point2d(IMUx,IMUy),IMUorientation,wall_line_by_wheel);
    for(j2 =  wall_feature_start_index; (j2 <wall_feature_start_index + wall_line.size()*4) && (j2 < SIZE_OF_FEATURE - 3); j2 += 4)
    {
        outputdata->feature.data[j2] = wall_line_by_wheel[(j2-wall_feature_start_index)/4].p_start.x;
        outputdata->feature.data[j2+1] = wall_line_by_wheel[(j2-wall_feature_start_index)/4].p_start.y;
        outputdata->feature.data[j2+2] = wall_line_by_wheel[(j2-wall_feature_start_index)/4].p_end.x;
        outputdata->feature.data[j2+3] = wall_line_by_wheel[(j2-wall_feature_start_index)/4].p_end.y;
    }


    //save result for debug
    fprintf(vars->stream1,"%d ",outputdata->feature.timestamp);
    for(int j = 0; j < SIZE_OF_FEATURE; j++)
    {
        fprintf(vars->stream1,"%lf ",outputdata->feature.data[j]);
    }
    for(int j = 0; j < SIZE_OF_FEATURE/2-1; j++)
    {
        fprintf(vars->stream1,"%d ",outputdata->is_door_open[j]);
    }
    fprintf(vars->stream1,"\n");

    //可视化
//    cv::Point2i currentPos = world2image(cv::Point2d(IMUx, IMUy), vars->originPoint,
//                                         params->pixelsize, vars->mapImage);
//    cv::circle(vars->mapImage, currentPos, 1, cv::Scalar(0,0,255), 2);




    //画检测到的门的中间结果
//    cv::Point2i start, end;
//    cv::Point2d tmp;
//    for(int i = 0; i < 2; i++)
//    {
//        for(int j = 0; j < URGDataSize; j++)
//        {
//            tmp.x = outputdata->urg_data_point[i][j][0];
//            tmp.y = outputdata->urg_data_point[i][j][1];
//            start = world2image(tmp, vars->originPoint, params->pixelsize, tmpMat);
//            cv::circle(tmpMat, start, 1, cv::Scalar(0,0,255), 1);
//        }
//    }
//    cv::Point2i doorpos;
//    for(int i=0; i<outputdata->door_point.size(); i++)
//    {
//        doorpos = world2image(outputdata->door_point[i], vars->originPoint,
//                              params->pixelsize, tmpMat);
//        if(outputdata->is_door_open[i]==1)
//        {
//            cv::putText(tmpMat, "Open", doorpos, CV_FONT_HERSHEY_COMPLEX, 0.5, cv::Scalar(0,0,255), 1);
//        }
//        else
//        {
//            cv::putText(tmpMat, "Close", doorpos, CV_FONT_HERSHEY_COMPLEX, 0.5, cv::Scalar(0,0,255), 1);
//        }
//    }

//    for(int i=0; i<outputdata->lms_gap.size(); i++)
//    {
//        start = world2image(outputdata->lms_gap[i].p1, vars->originPoint, params->pixelsize, tmpMat);
//        end = world2image(outputdata->lms_gap[i].p2, vars->originPoint, params->pixelsize, tmpMat);
//        cv::line(tmpMat, start, end, cv::Scalar(255,255,0), 2);
//    }

    //
    cv::cvtColor(tmpMat, tmpMat, CV_BGR2RGB);
    //cv::resize(tmpMat, tmpMat, cv::Size(vars->mapImage.cols*2, vars->mapImage.rows*2));
    tmpMat.copyTo(outputdata->mapImage);
	return 1;
}

