//You need to program this file.

#include "../NoEdit/VisualizationMono_Calibration_Laser_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMono_Sensor_Laser_Params * params=(VisualizationMono_Sensor_Laser_Params *)paramsPtr;
	VisualizationMono_Calibration_Laser_Vars * vars=(VisualizationMono_Calibration_Laser_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
	
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMono_Sensor_Laser_Params * params=(VisualizationMono_Sensor_Laser_Params *)paramsPtr;
	VisualizationMono_Calibration_Laser_Vars * vars=(VisualizationMono_Calibration_Laser_Vars *)varsPtr;
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
	VisualizationMono_Sensor_Laser_Params * params=(VisualizationMono_Sensor_Laser_Params *)paramsPtr;
	VisualizationMono_Calibration_Laser_Vars * vars=(VisualizationMono_Calibration_Laser_Vars *)varsPtr;
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
	VisualizationMono_Sensor_Laser_Params * params=(VisualizationMono_Sensor_Laser_Params *)paramsPtr;
	VisualizationMono_Calibration_Laser_Vars * vars=(VisualizationMono_Calibration_Laser_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_Laser_Params, Data_Type = SensorTimer_Sensor_Laser_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	VisualizationMono_Sensor_Laser_Params * params=(VisualizationMono_Sensor_Laser_Params *)paramsPtr;
	VisualizationMono_Calibration_Laser_Vars * vars=(VisualizationMono_Calibration_Laser_Vars *)varsPtr;
	QVector<SensorTimer_Sensor_Laser_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<SensorTimer_Sensor_Laser_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
    double dth = -0.035;
    double dw = -9.39;
    double dh = -0.299;

    SensorTimer_Sensor_Laser_Data * laser = draindata.front();
    short *ldata = laser->ldata;
    short *rdata = laser->rdata;
    double startangle = 90 + drainparams.front()->first_step * 0.25;
    double endtangle  = 90 + drainparams.front()->last_step  * 0.25;
    double resolution = drainparams.front()->skip_step * 0.25;
    double pi=3.1415926535897932384626433832795 / 180.0;
    double ratio=double(params->imageradius)/double(params->range);


    double kl1, bl1, kr1, br1;
    vars->getkb(ldata, laser->datasize, -60, -25,
                startangle, resolution, ratio, -1000.0, -10.0, -1000.0, -10.0, kl1, bl1);
    vars->getkb(rdata, laser->datasize, -65, -30,
                startangle, resolution, ratio, -1000.0, -10.0, -1000.0, -10.0, kr1, br1,
                dth, dw, dh);

    double kl2, bl2, kr2, br2;
    vars->getkb(ldata, laser->datasize, -245, -200,
                startangle, resolution, ratio, 10.0, 1000.0, -1000.0, -10.0, kl2, bl2);
    vars->getkb(rdata, laser->datasize, -245, -200,
                startangle, resolution, ratio, 10.0, 1000.0, -1000.0, -10.0, kr2, br2,
                dth, dw, dh);

    double xl = -(bl2 - bl1) / (kl2 - kl1);
    double yl = kl1 * xl + bl1;
    double xr = -(br2 - br1) / (kr2 - kr1);
    double yr = kr1 * xr + br1;

    vars->startangle=90+drainparams.front()->first_step*0.25;
    vars->endtangle=90+drainparams.front()->last_step*0.25;
    vars->resolution=drainparams.front()->skip_step*0.25;

    QImage image;
    if(params->frontonly)
    {
        image=QImage(params->imageradius*2,params->imageradius + 10,QImage::Format_RGBA8888);
    }
    else
    {
        image=QImage(params->imageradius*2,params->imageradius*2,QImage::Format_RGBA8888);
    }
    image.fill(32);
    vars->painter.begin(&image);

    QPen centerpen(QColor(255,0,0,255));
    QPen gridpen(QColor(0,255,0,128));
    QPen lbeampen(QColor(0,0,255,196));
    QPen rbeampen(QColor(0,120,196,255));
    QPen textpen(Qt::black);
    QPen linePen(Qt::red);
    int n;

    vars->painter.setPen(gridpen);
    vars->painter.setBrush(Qt::NoBrush);
    n=params->range/params->interval;
    int radiusstep=params->imageradius/n;

    int centerx=params->imageradius ;
    int centery=params->imageradius ;
    for(int i=1;i<=n;i++)
    {
        int radius=i*radiusstep;
        vars->painter.drawEllipse(QPoint(centerx,centery),radius,radius);
    }





    vars->painter.setPen(lbeampen);

    n=draindata.front()->datasize;

    //left laser visual
    for(int i = laser->datasize - laser->datasize; i < laser->datasize - 0; i++)
    {
        double theta=(vars->startangle+vars->resolution*i)*pi;
        double distance=ratio*(draindata.front()->ldata[i]);
        int x=round(distance*cos(theta));
        int y=round(-distance*sin(theta));
        if(params->laserbeam)
        {
            vars->painter.drawLine(centerx,centery,x+centerx,y+centery);
        }
        else
        {
            vars->painter.drawEllipse(x+centerx,y+centery,2,2);
        }
    }
/*    for(int i = laser->datasize - 250; i < laser->datasize - 180; i++)
    {
        double theta=(vars->startangle+vars->resolution*i)*pi;
        double distance=ratio*(draindata.front()->ldata[i]);
        int x=int(distance*cos(theta)+0.5);
        int y=int(-distance*sin(theta)+0.5);
        if(params->laserbeam)
        {
            vars->painter.drawLine(centerx,centery,x+centerx,y+centery);
        }
        else
        {
            vars->painter.drawEllipse(x+centerx,y+centery,2,2);
        }
    }
*/

    //right laser visual



    vars->painter.setPen(rbeampen);
    for(int i = laser->datasize - laser->datasize; i < laser->datasize - 0; i++)
    {
        double theta=(vars->startangle+vars->resolution*i)*pi + dth;
        double distance=ratio*(draindata.front()->rdata[i]);
        int x=round(dw + distance*cos(theta));
        int y=round(dh - distance*sin(theta));
        if(params->laserbeam)
        {
            vars->painter.drawLine(centerx+dw,centery+dh,x+centerx,y+centery);
        }
        else
        {
            vars->painter.drawEllipse(x+centerx,y+centery,2,2);
        }
    }
/*    for(int i = laser->datasize - 250; i < laser->datasize - 180; i++)
    {
        double theta=(vars->startangle+vars->resolution*i)*pi + dth;
        double distance=ratio*(draindata.front()->rdata[i]);
        int x=int(dw + distance*cos(theta)+0.5);
        int y=int(dh - distance*sin(theta)+0.5);
        if(params->laserbeam)
        {
            vars->painter.drawLine(centerx+dw,centery+dh,x+centerx,y+centery);
        }
        else
        {
            vars->painter.drawEllipse(x+centerx,y+centery,2,2);
        }
    }
*/
    vars->painter.setPen(linePen);

    vars->painter.drawLine(round(centerx - bl1 / kl1), round(centery), round(centerx) , round(centery + bl1) );
    vars->painter.drawLine(round(centerx - br1 / kr1), round(centery), round(centerx) , round(centery + br1) );
    vars->painter.drawLine(round(centerx - bl2 / kl2), round(centery), round(centerx) , round(centery + bl2) );
    vars->painter.drawLine(round(centerx - br2 / kr2), round(centery), round(centerx) , round(centery + br2) );

    vars->painter.setPen(centerpen);
    vars->painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
    vars->painter.drawEllipse(QPoint(centerx,centery),2,2);
    vars->painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
    vars->painter.drawEllipse(QPoint(centerx+dw,centery+dh),2,2);



    QFontMetrics fm=vars->painter.fontMetrics();
    int height=fm.ascent()+fm.descent();
    vars->painter.setPen(textpen);
    vars->painter.drawText(0,height,QString("Interval = %1 cm").arg(params->interval));
    vars->painter.drawText(0,height*2,QString("System Time: %1").arg(draindata.front()->qtimestamp.toString("HH:mm:ss:zzz")));
    vars->painter.drawText(0,height*3,QString("URG Time: %1").arg(draindata.front()->timestamp));
    vars->painter.drawText(0,height*4,QString("kl1 = %1 bl1 = %2").arg(kl1).arg(bl1));
    vars->painter.drawText(0,height*5,QString("kr1 = %1 br1 = %2").arg(kr1).arg(br1));
    vars->painter.drawText(0,height*6,QString("kl2 = %1 bl2= %2").arg(kl2).arg(bl2));
    vars->painter.drawText(0,height*7,QString("kr2 = %1 br2 = %2").arg(kr2).arg(br2));
    vars->painter.drawText(0,height*8,QString("recommand theta = %1").arg(atan(kr1) - atan(kl1)));
    vars->painter.drawText(0,height*9,QString("recommand theta = %1").arg(atan(kr2) - atan(kl2)));
    vars->painter.drawText(0,height*10,QString("recommand width = %1").arg(xl - xr));
    vars->painter.drawText(0,height*11,QString("recommand height = %1").arg(yl - yr));


    if (vars->frameNum < 10) vars->frameNum++;
    else
    {
        vars->thVector.pop_front();
        vars->xVector.pop_front();
        vars->yVector.pop_front();
    }
    vars->thVector.push_back(atan(kr1) - atan(kl1));
    vars->xVector.push_back(xr-xl);
    vars->yVector.push_back(yl-yr);

    double averageth = vars->average(vars->thVector);
    double averagex = vars->average(vars->xVector);
    double averagey = vars->average(vars->yVector);
    vars->painter.drawText(0,height*12,QString("recommand theta = %1").arg(averageth));
    vars->painter.drawText(0,height*13,QString("recommand width = %1").arg(averagex));
    vars->painter.drawText(0,height*14,QString("recommand height = %1").arg(averagey));

    vars->painter.end();
    vars->beams->setPixmap(QPixmap::fromImage(image));
	return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMono_Sensor_Laser_Params * params=(VisualizationMono_Sensor_Laser_Params *)paramsPtr;
	VisualizationMono_Calibration_Laser_Vars * vars=(VisualizationMono_Calibration_Laser_Vars *)varsPtr;
    widgets=QList<QWidget *>()<<(vars->beams);
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

