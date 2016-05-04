//You need to program this file.

#include "../NoEdit/ProcessorMulti_Processor_CameraLaser_PrivFunc.h"
#include "../../Calib_c/CAL_MAIN.H"
//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	ProcessorMulti_Processor_CameraLaser_Params * params=(ProcessorMulti_Processor_CameraLaser_Params *)paramsPtr;
	ProcessorMulti_Processor_CameraLaser_Vars * vars=(ProcessorMulti_Processor_CameraLaser_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader, params, calibfilename);
    GetParamValue(xmlloader, params, calibfilepath);

    GetParamValue(xmlloader, params, pixelsize);

    //vars->cameralaserMat.create(params->imageHeight, params->imageWidth, CV_8UC3);

    QString filename = params->calibfilepath +"/"+ params->calibfilename;
    std::string str = filename.toStdString();

    if(!LoadCameraCalib(filename.toStdString().c_str()))
        return 0;

	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	ProcessorMulti_Processor_CameraLaser_Params * params=(ProcessorMulti_Processor_CameraLaser_Params *)paramsPtr;
	ProcessorMulti_Processor_CameraLaser_Vars * vars=(ProcessorMulti_Processor_CameraLaser_Vars *)varsPtr;
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
	ProcessorMulti_Processor_CameraLaser_Params * params=(ProcessorMulti_Processor_CameraLaser_Params *)paramsPtr;
	ProcessorMulti_Processor_CameraLaser_Vars * vars=(ProcessorMulti_Processor_CameraLaser_Vars *)varsPtr;
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
	ProcessorMulti_Processor_CameraLaser_Params * params=(ProcessorMulti_Processor_CameraLaser_Params *)paramsPtr;
	ProcessorMulti_Processor_CameraLaser_Vars * vars=(ProcessorMulti_Processor_CameraLaser_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new ProcessorMulti_Processor_CameraLaser_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

void DECOFUNC(getMultiInputDataSize)(void * paramsPtr, void * varsPtr, QList<int> & inputDataSize)
{
	ProcessorMulti_Processor_CameraLaser_Params * params=(ProcessorMulti_Processor_CameraLaser_Params *)paramsPtr;
	ProcessorMulti_Processor_CameraLaser_Vars * vars=(ProcessorMulti_Processor_CameraLaser_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 10, Params_Type = SensorInternalEvent_Sensor_Camera_Params, Data_Type = SensorInternalEvent_Sensor_Camera_Data
//Input Port #1: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_Laser_Params, Data_Type = SensorTimer_Sensor_Laser_Data
bool DECOFUNC(processMultiInputData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > inputParams, QVector<QVector<void *> > inputData, void * outputData, QList<int> & outputPortIndex)
{
	ProcessorMulti_Processor_CameraLaser_Params * params=(ProcessorMulti_Processor_CameraLaser_Params *)paramsPtr;
	ProcessorMulti_Processor_CameraLaser_Vars * vars=(ProcessorMulti_Processor_CameraLaser_Vars *)varsPtr;
	QVector<SensorInternalEvent_Sensor_Camera_Params *> inputparams_0; copyQVector(inputparams_0,inputParams[0]);
	QVector<SensorTimer_Sensor_Laser_Params *> inputparams_1; copyQVector(inputparams_1,inputParams[1]);
	QVector<SensorInternalEvent_Sensor_Camera_Data *> inputdata_0; copyQVector(inputdata_0,inputData[0]);
	QVector<SensorTimer_Sensor_Laser_Data *> inputdata_1; copyQVector(inputdata_1,inputData[1]);
	ProcessorMulti_Processor_CameraLaser_Data * outputdata=(ProcessorMulti_Processor_CameraLaser_Data *)outputData;
	outputPortIndex=QList<int>();
	if(inputdata_0.size()==0){return 0;}
	if(inputdata_1.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Step 1: process inputdata_index, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/
    cv::Size dsize = cv::Size(640,480);
    cv::Mat vis(dsize,CV_8UC3);
    cv::resize(inputdata_0.front()->cvimage,vis,dsize);
    double pixelsize = params->pixelsize;
    cv::Mat map(cv::Size(1000,500),CV_8UC3,cv::Scalar::all(0));

    for(int i = 0 ; i < map.rows ; ++i)//video
    {
        for(int j = 0 ; j < map.cols ; ++j)
        {
            double xw = (j - map.cols/2) * pixelsize * 1000;
            double yw = (map.rows - i) * pixelsize * 1000;

            double zw = -0.435 * 1000;
            cv::Point2d bmp;
            WC2IC(xw,yw,zw,&bmp.x, &bmp.y);
            bmp.y = vis.rows - 1 - bmp.y;
            if(bmp.x < 0 || bmp.x >= vis.cols || bmp.y < 0 || bmp.y >= vis.rows)
                continue;
            map.at<cv::Vec3b>(i,j) = vis.at<cv::Vec3b>(bmp.y,bmp.x);
        }
    }

    for(int i = 0.0 ; i < 361 ; i ++ )//h-urg
    {
        double angle = CV_PI * (i) / 360;// - dxangle;
        double length = inputdata_1.front()->ldata[(int)i];
        if(length==0 || length > 4500)//有效距离为45米
            length =4500;
        cv::Point2d lp;
        lp.x = cos(angle) * length / 100 / pixelsize;
        lp.y = sin(angle) * length / 100 / pixelsize;
        lp.x += map.cols/2;
        lp.y = map.rows - 1 - lp.y;
        cv::circle(map,lp,1,CV_RGB(255,0,0));
    }

    map.copyTo(outputdata->cameralaserMat);


	return 1;
}

