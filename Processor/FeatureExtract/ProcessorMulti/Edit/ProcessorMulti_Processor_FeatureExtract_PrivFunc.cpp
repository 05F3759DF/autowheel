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

//    vars->mapImage = cv::imread((vars->filePath+vars->mapImageName).toStdString());
//    std::ifstream pointFile;
//    pointFile.open((vars->filePath+vars->keyPointFilename).toStdString().c_str());

//    string str;
//    pointFile>>str>>params->ox;
//    pointFile>>str>>params->oy;
//    pointFile>>str>>params->pixelsize;
    ///计算坐标远点
//    vars->originPoint.x = qRound(params->ox/params->pixelsize);
//    vars->originPoint.y = vars->mapImage.rows-1-qRound(params->oy/params->pixelsize);
    ///忽略起点和终点-3行
//    std::getline(pointFile, str);
//    std::getline(pointFile, str);
//    std::getline(pointFile, str);
//    std::getline(pointFile, str);
//    cv::Point2d startPoint, endPoint;
//    pointFile>>str>>startPoint.x>>startPoint.y;
//    pointFile>>str>>endPoint.x>>endPoint.y;
//    cv::Point2i tmpStart = world2image(startPoint, vars->originPoint, params->pixelsize);
//    cv::circle(vars->mapImage, tmpStart, 3, cv::Scalar(0,0,255), 3);
//    tmpStart = world2image(endPoint, vars->originPoint, params->pixelsize);
//    cv::circle(vars->mapImage, tmpStart, 3, cv::Scalar(0,0,255), 3);
    ///读门的坐标
//    int doornums=0;
//    pointFile>>str>>doornums;
//    if(str == "DOORS")
//    {
//        for(int i=0; i<doornums; i++)
//        {
//            cv::Point2d temp;
//            pointFile>>str>>temp.x>>temp.y;
//            vars->door_point.push_back(temp);
//        }
//    }
//    else
//        return 0;
    ///画门的位置
//    for(int i=0; i<vars->door_point.size(); i++)
//    {
//        cv::Point2i tPoint = world2image(vars->door_point[i], vars->originPoint,
//                                         params->pixelsize, vars->mapImage);
//        cv::circle(vars->mapImage, tPoint, 2, cv::Scalar(0,255,0), 2);
//    }
    ///读墙的坐标
//    std::getline(pointFile, str);
//    std::getline(pointFile, str);
//    pointFile>>str>>vars->leftWall.start.x>>vars->leftWall.start.y;
//    pointFile>>str>>vars->leftWall.end.x>>vars->leftWall.end.y;

//    std::getline(pointFile, str);
//    std::getline(pointFile, str);
//    pointFile>>str>>vars->rightWall.start.x>>vars->rightWall.start.y;
//    pointFile>>str>>vars->rightWall.end.x>>vars->rightWall.end.y;
//    ///计算直线方程的系数k，b
//    vars->leftWall.calcCoefficient();
//    vars->rightWall.calcCoefficient();

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
    inputDataSize=QList<int>() << 10 << 10;
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
//    if(inputdata_2.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Step 1: process inputdata_index, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/
    int URGDataSize = inputdata_0.front()->datasize;
    outputdata->URGData_size = URGDataSize;
    double IMUorientation;
    double IMUx = 0;
    double IMUy = 0;

 //使用 IMU&Encoder
    IMUx = inputdata_1.front()->x;
    IMUy = inputdata_1.front()->y;
    IMUorientation = inputdata_1.front()->theta;
//使用 SLAM
//    IMUx = inputdata_2.front()->x;
//    IMUy = inputdata_2.front()->y;
//    IMUorientation = inputdata_2.front()->theta;

    double IMUx_lmsl;
    double IMUx_lmsr;
    double IMUy_lmsl;
    double IMUy_lmsr;
    IMUx_lmsl = IMUx + nav_shift_f*cos(IMUorientation) - nav_shift_s*sin(IMUorientation);//*******ÕýžººÅ¿ÉÄÜÒªµ÷
    IMUy_lmsl = IMUy + nav_shift_f*sin(IMUorientation) + nav_shift_s*cos(IMUorientation);
    IMUx_lmsr = IMUx + nav_shift_f*cos(IMUorientation) + nav_shift_s*sin(IMUorientation);//*******ÕýžººÅ¿ÉÄÜÒªµ÷
    IMUy_lmsr = IMUy + nav_shift_f*sin(IMUorientation) - nav_shift_s*cos(IMUorientation);

    cout << "laser " << IMUx_lmsl << ' ' << IMUy_lmsl << endl;
    double temp_angle;
    for (int i = 0; i < URGDataSize; i++)//lms_l
    {
        temp_angle = IMUorientation -(double)i / 360 * vars->Pi + vars->Pi / 2;
        outputdata->urg_data_point[0][i][0] = ((IMUx_lmsl +cos(temp_angle)*inputdata_0.front()->ldata[i] / vars->unit) );//Ò»Ã×DEFINE_3žñ£¬³õÊŒÎ»ÖÃ£šDEFINE_4,DEFINE_4)
        outputdata->urg_data_point[0][i][1] = ((IMUy_lmsl + sin(temp_angle)*inputdata_0.front()->ldata[i] / vars->unit) );
        outputdata->urg_valid[0][i] = (inputdata_0.front()->ldata[i] > 20);
    }

    for (int i = 0; i < URGDataSize; i++)//lms_r
    {
        temp_angle = IMUorientation -(double)i / 360 * vars->Pi + vars->Pi / 2 + lms_shift_from_rlms_2_llms;
        outputdata->urg_data_point[1][i][0] = ((IMUx_lmsr +cos(temp_angle)*inputdata_0.front()->rdata[i] / vars->unit) );//Ò»Ã×DEFINE_3žñ£¬³õÊŒÎ»ÖÃ£šDEFINE_4,DEFINE_4)
        outputdata->urg_data_point[1][i][1] = ((IMUy_lmsr + sin(temp_angle)*inputdata_0.front()->rdata[i] / vars->unit) );
        outputdata->urg_valid[1][i] = (inputdata_0.front()->rdata[i] > 20);
    }
    outputdata->feature.timestamp = Qtime2time(QTime::currentTime());


	return 1;
}

