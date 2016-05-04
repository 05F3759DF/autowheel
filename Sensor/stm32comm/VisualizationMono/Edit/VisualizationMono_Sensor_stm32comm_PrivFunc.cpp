//You need to program this file.

#include "../NoEdit/VisualizationMono_Sensor_stm32comm_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMono_Sensor_stm32comm_Params * params=(VisualizationMono_Sensor_stm32comm_Params *)paramsPtr;
	VisualizationMono_Sensor_stm32comm_Vars * vars=(VisualizationMono_Sensor_stm32comm_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
     //vars->comm_label->setText("open");
    GetParamValue(xmlloader,params,mapsize);
    GetParamValue(xmlloader,params,pixelsize);
    GetParamValue(xmlloader,vars,showheight);

    vars->mapzero.x = 0;
    vars->mapzero.y = 0;
    vars->map.create(cv::Size(params->mapsize,params->mapsize),CV_8UC3);
    vars->map.setTo(0);
    vars->qmap->setText("Opened");
     return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMono_Sensor_stm32comm_Params * params=(VisualizationMono_Sensor_stm32comm_Params *)paramsPtr;
	VisualizationMono_Sensor_stm32comm_Vars * vars=(VisualizationMono_Sensor_stm32comm_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
     //vars->comm_label->setText("closed");
    vars->qmap->setText("Closed");
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMono_Sensor_stm32comm_Params * params=(VisualizationMono_Sensor_stm32comm_Params *)paramsPtr;
	VisualizationMono_Sensor_stm32comm_Vars * vars=(VisualizationMono_Sensor_stm32comm_Vars *)varsPtr;
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

void DECOFUNC(getMonoDrainDataSize)(void * paramsPtr, void * varsPtr, int & drainDataSize)
{
	VisualizationMono_Sensor_stm32comm_Params * params=(VisualizationMono_Sensor_stm32comm_Params *)paramsPtr;
	VisualizationMono_Sensor_stm32comm_Vars * vars=(VisualizationMono_Sensor_stm32comm_Vars *)varsPtr;
	drainDataSize=0;
	/*======Please Program above======*/
	/*
	Function: get drain data size to be grabbed from buffer.
	Rules:
	drainDataSize=0: grab and remove all data from buffer.
	drainDataSize>0: grab drainDataSize latest data from buffer.
	drainDataSize<0: grab and remove drainDataSize ancient data from buffer.
	*/
}

//Input Port #0: Buffer_Size = 1, Params_Type = SourceDrainMono_Sensor_stm32comm_Params, Data_Type = SourceDrainMono_Sensor_stm32comm_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	VisualizationMono_Sensor_stm32comm_Params * params=(VisualizationMono_Sensor_stm32comm_Params *)paramsPtr;
	VisualizationMono_Sensor_stm32comm_Vars * vars=(VisualizationMono_Sensor_stm32comm_Vars *)varsPtr;
	QVector<SourceDrainMono_Sensor_stm32comm_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<SourceDrainMono_Sensor_stm32comm_Data *> draindata; copyQVector(draindata,drainData);
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
//    vars->comm_label->setText(QString("YAW: %1\nrightodom: %2\nleftodom: %3\nrightspeed: %4\nleftspeed: %5\n").
//                              arg(draindata.front()->yaw).
//                                arg(draindata.front()->rightodom).arg(draindata.front()->leftodom).
//                              arg(draindata.front()->rightspeed).arg(draindata.front()->leftspeed));
    if(draindata.size()==0)
    {
        vars->qmap->setText("No Data");
        return 0;
    }
    /*======Please Program below======*/
    /*
    Function: process draindata.
    */
    int minshiftx = 1, minshifty = 1;
    int i,j,dx,dy;
    cv::Point2d p;
    p.x = ((int) (draindata.front()->x / params->pixelsize)) * params->pixelsize;
    p.y = ((int) (draindata.front()->y / params->pixelsize)) * params->pixelsize;
    dx = (p.x-vars->mapzero.x)/params->pixelsize;
    dy = (p.y-vars->mapzero.y)/params->pixelsize;
    if ( ! (abs(dx)<=minshiftx && abs(dy)<=minshifty))//ÐèÒªÒÆ¶¯
    {
        vars->mapzero = p;
        if (abs(dx)>=vars->map.cols/2 || abs(dy)>=vars->map.rows/2)//ÒÆ¶¯¹ýŽó£¬Ö±œÓÖØÖÃ
        {
            vars->map.setTo(0);
        }
        else
        {
            cv::Mat M(2,3,CV_32F);
            M.at<float>(0,0)=1;M.at<float>(0,1)=0;M.at<float>(0,2)=-dx;
            M.at<float>(1,0)=0;M.at<float>(1,1)=1;M.at<float>(1,2)=dy;
            cv::warpAffine(vars->map,vars->map,M,vars->map.size());
        }
    }

    //QtÊÇbgrµÄÑÕÉ«
    cv::Scalar c_red = CV_RGB(0,0,255);
    cv::Scalar c_blue = CV_RGB(255,144,30);
    cv::Scalar c_green = CV_RGB(37,225,132);
    cv::Scalar c_gold = CV_RGB(1,215,255);


    cv::Point2d mapp = cv::Point2d(draindata.front()->x,draindata.front()->y);
    mapp -= vars->mapzero;
    mapp.x = mapp.x / params->pixelsize + params->mapsize/2;
    mapp.y = mapp.y / params->pixelsize + params->mapsize/2;
    circle(vars->map,mapp,2,c_gold,-1);

    //Ê®Ã×Ò»žöÍøžñ
    cv::Mat gridmap3(cv::Size(params->mapsize,params->mapsize),CV_8UC3);
    gridmap3.setTo(0);
    cv::Mat gridmap1(cv::Size(params->mapsize,params->mapsize),CV_8UC1);
    gridmap1.setTo(0);
    int grid = 10.0 / params->pixelsize;

    for(int i = params->mapsize % grid ; i < params->mapsize ; i+= grid)
    {
        cv::line(gridmap3,cv::Point(i,0),cv::Point(i,params->mapsize),c_blue,1);
        cv::line(gridmap1,cv::Point(i,0),cv::Point(i,params->mapsize),cv::Scalar(255),1);
    }
    for(int i = params->mapsize - grid ; i > 0 ; i -= grid)
    {
        cv::line(gridmap3,cv::Point(0,i),cv::Point(params->mapsize,i),c_blue,1);
        cv::line(gridmap1,cv::Point(0,i),cv::Point(params->mapsize,i),cv::Scalar(255),1);
    }
    cv::bitwise_not(gridmap1,gridmap1);
    vars->map.copyTo(gridmap3,gridmap1);
    cv::circle(gridmap3,cv::Point(params->mapsize/2,params->mapsize/2),1,c_red);

    //compass
    gridmap3(cv::Rect(params->mapsize-grid+1,0,grid-1,grid-1)).setTo(0);
    cv::Point composso = cv::Point(params->mapsize-grid/2,grid/2);
    cv::circle(gridmap3,composso,grid/2-1,c_green,1,CV_AA);
    cv::line(gridmap3,composso,cv::Point(composso.x + cos(draindata.front()->theta)*(grid-1)/2-1, composso.y - sin(draindata.front()->theta)*(grid-1)/2-1), c_green,1,CV_AA);

    //speed + odometry + (x,y)
    gridmap3(cv::Rect(0,0,2*grid-1,grid-1)).setTo(0);

    cv::putText(gridmap3,QString("(%1, %2)").arg(draindata.front()->x).arg(draindata.front()->y).toStdString(),
        cv::Point(0,20),CV_FONT_HERSHEY_SCRIPT_SIMPLEX,0.5,c_red,1,CV_AA);
    cv::putText(gridmap3,QString("leftspeed: %1 m/s").arg(draindata.front()->theta).toStdString(),
        cv::Point(0,40),CV_FONT_HERSHEY_SCRIPT_SIMPLEX,0.5,c_red,1,CV_AA);
    cv::putText(gridmap3,QString("rightspeed: %1 m").arg(draindata.front()->rightodom).toStdString(),
        cv::Point(0,60),CV_FONT_HERSHEY_SCRIPT_SIMPLEX,0.5,c_red,1,CV_AA);
    cv::putText(gridmap3,QString("leftodom: %1 m").arg(draindata.front()->leftodom).toStdString(),
        cv::Point(0,80),CV_FONT_HERSHEY_SCRIPT_SIMPLEX,0.5,c_red,1,CV_AA);
    cv::putText(gridmap3,QString("angle: %1 deg").arg(draindata.front()->theta).toStdString(),
        cv::Point(0,100),CV_FONT_HERSHEY_SCRIPT_SIMPLEX,0.5,c_red,1,CV_AA);
    int timestamp=((draindata.front()->timestamp.hour()*60+draindata.front()->timestamp.minute())*60
            +draindata.front()->timestamp.second())*1000+draindata.front()->timestamp.msec();
    cv::putText(gridmap3,QString("%1 ms").arg(timestamp).toStdString(),
        cv::Point(0,120),CV_FONT_HERSHEY_SCRIPT_SIMPLEX,0.5,c_red,1,CV_AA);

    int showWidth = vars->showheight;
    cv::Mat showImage (cv::Size(showWidth, vars->showheight),CV_8UC3);
    cv::resize(gridmap3,showImage,showImage.size());

    QImage colorimg=QImage((const uchar*)(showImage.data),showImage.cols,showImage.rows, showImage.cols*showImage.channels(),QImage::Format_RGB888);
//	QImage colorimg=QImage((const uchar*)(vars->map.data),vars->map.cols,vars->map.rows,QImage::Format_RGB888);
    vars->qmap->setPixmap(QPixmap::fromImage(colorimg));


	return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMono_Sensor_stm32comm_Params * params=(VisualizationMono_Sensor_stm32comm_Params *)paramsPtr;
	VisualizationMono_Sensor_stm32comm_Vars * vars=(VisualizationMono_Sensor_stm32comm_Vars *)varsPtr;
   widgets=QList<QWidget *>()<<(vars->qmap);
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

