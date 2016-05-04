//You need to program this file.

#include "../NoEdit/VisualizationMulti_Calibration_Laser_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
    XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
    VisualizationMono_Sensor_Laser_Params * params=(VisualizationMono_Sensor_Laser_Params *)paramsPtr;
    VisualizationMulti_Calibration_Laser_Vars * vars=(VisualizationMulti_Calibration_Laser_Vars *)varsPtr;
    /*======Please Program below======*/
    /*
    Function: open node.
    Procedure:
    1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
    2: initialize variables (vars).
    3: If everything is OK, return 1 for successful opening and vice versa.
    */
    GetParamValue(xmlloader,params,range);
    GetParamValue(xmlloader,params,interval);
    GetParamValue(xmlloader,params,imageradius);
    GetParamValue(xmlloader,params,frontonly);
    GetParamValue(xmlloader,params,laserbeam);
    return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
    VisualizationMono_Sensor_Laser_Params * params=(VisualizationMono_Sensor_Laser_Params *)paramsPtr;
    VisualizationMulti_Calibration_Laser_Vars * vars=(VisualizationMulti_Calibration_Laser_Vars *)varsPtr;
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
    VisualizationMulti_Calibration_Laser_Vars * vars=(VisualizationMulti_Calibration_Laser_Vars *)varsPtr;
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

void DECOFUNC(getMultiDrainDataSize)(void * paramsPtr, void * varsPtr, QList<int> & drainDataSize)
{
    VisualizationMono_Sensor_Laser_Params * params=(VisualizationMono_Sensor_Laser_Params *)paramsPtr;
    VisualizationMulti_Calibration_Laser_Vars * vars=(VisualizationMulti_Calibration_Laser_Vars *)varsPtr;
    drainDataSize=QList<int>();
    /*======Please Program above======*/
    /*
    Function: get drain data size to be grabbed from buffer.
    Rules:
    drainDataSize=0: grab and remove all data from buffer.
    drainDataSize>0: grab drainDataSize latest data from buffer.
    drainDataSize<0: grab and remove drainDataSize ancient data from buffer.
    E.g.
    drainDataSize=QList<int>()<<0<<1<<-1...;
    */
}

//Input Port #0: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_Laser_Params, Data_Type = SensorTimer_Sensor_Laser_Data
//Input Port #1: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_Laser_Params, Data_Type = SensorTimer_Sensor_Laser_Data
bool DECOFUNC(processMultiDrainData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > drainParams, QVector<QVector<void *> > drainData)
{
    VisualizationMono_Sensor_Laser_Params * params=(VisualizationMono_Sensor_Laser_Params *)paramsPtr;
    VisualizationMulti_Calibration_Laser_Vars * vars=(VisualizationMulti_Calibration_Laser_Vars *)varsPtr;
    QVector<SensorTimer_Sensor_Laser_Params *> drainparams_0; copyQVector(drainparams_0,drainParams[0]);
    QVector<SensorTimer_Sensor_Laser_Params *> drainparams_1; copyQVector(drainparams_1,drainParams[1]);
    QVector<SensorTimer_Sensor_Laser_Data *> draindata_0; copyQVector(draindata_0,drainData[0]);
    QVector<SensorTimer_Sensor_Laser_Data *> draindata_1; copyQVector(draindata_1,drainData[1]);
    if(draindata_0.size()==0){return 0;}
    if(draindata_1.size()==0){return 0;}
    /*======Please Program below======*/
    /*
    Function: process draindata_index.
    */
    SensorTimer_Sensor_Laser_Data * laser = draindata_0.front();
    short *ldata = laser->ldata;
    double linefilter = 1000;
    double startangle = 90 + drainparams_0.front()->first_step * 0.25;
    double endtangle  = 90 + drainparams_0.front()->last_step  * 0.25;
    double resolution = drainparams_0.front()->skip_step * 0.25;
    double pi=3.1415926535897932384626433832795 / 180.0;

    double line1datax[1000], line1datay[1000];
    int dotnum = 0;
    for (int i = 0; i < laser->datasize; i++)
    {
        double theta = (startangle + resolution * i) * pi;
        double distance = ldata[i];
        int x = int(distance * cos(theta) + 0.5);
        int y = int(-distance * sin(theta) + 0.5);
        if (y < linefilter)
        {
            line1datax[dotnum] = x;
            line1datay[dotnum] = y;
            dotnum++;
        }
    }
    double kl, bl;
    vars->lineSquare(line1datax, line1datay, dotnum, kl, bl);


    vars->startangle=90+drainparams_0.front()->first_step*0.25;
    vars->endtangle=90+drainparams_0.front()->last_step*0.25;
    vars->resolution=drainparams_0.front()->skip_step*0.25;

    QImage image;
    if(params->frontonly)
    {
        image=QImage(params->imageradius*2,params->imageradius,QImage::Format_RGBA8888);
    }
    else
    {
        image=QImage(params->imageradius*2,params->imageradius*2,QImage::Format_RGBA8888);
    }
    image.fill(32);
    vars->painter.begin(&image);

    QPen centerpen(QColor(255,0,0,255));
    QPen gridpen(QColor(0,255,0,128));
    QPen beampen(QColor(0,0,255,196));
    QPen textpen(Qt::black);
    int i,n;

    vars->painter.setPen(gridpen);
    vars->painter.setBrush(Qt::NoBrush);
    n=params->range/params->interval;
    int radiusstep=params->imageradius/n;
    int centerx=params->imageradius;
    int centery=params->imageradius;
    for(i=1;i<=n;i++)
    {
        int radius=i*radiusstep;
        vars->painter.drawEllipse(QPoint(centerx,centery),radius,radius);
    }

    centerx=params->imageradius-params->calib_width/2;
    centery=params->imageradius - params->calib_height;

    vars->painter.setPen(centerpen);
    vars->painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
    vars->painter.drawEllipse(QPoint(centerx,centery),2,2);

    vars->painter.setPen(beampen);
    double ratio=double(params->imageradius)/double(params->range);
    n=draindata_0.front()->datasize;

    //left laser visual
    for(i=0;i<n;i++)
    {
        double theta=(vars->startangle+vars->resolution*i)*pi;
        double distance=ratio*(draindata_0.front()->ldata[i]);
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
    //right laser visual
    centerx=params->imageradius + params->calib_width/2;
    centery=params->imageradius - params->calib_height;

    vars->painter.setPen(centerpen);
    vars->painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
    vars->painter.drawEllipse(QPoint(centerx,centery),2,2);


    vars->painter.setPen(beampen);
    for(i=0;i<n;i++)
    {
        double theta=(vars->startangle+vars->resolution*i)*pi;
        double distance=ratio*(draindata_0.front()->rdata[i]);
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

    QFontMetrics fm=vars->painter.fontMetrics();
    int height=fm.ascent()+fm.descent();
    vars->painter.setPen(textpen);
    vars->painter.drawText(0,height,QString("Interval = %1 cm").arg(params->interval));
    vars->painter.drawText(0,height*2,QString("System Time: %1").arg(draindata_0.front()->qtimestamp.toString("HH:mm:ss:zzz")));
    vars->painter.drawText(0,height*3,QString("URG Time: %1").arg(draindata_0.front()->timestamp));

    vars->painter.end();
    vars->beams->setPixmap(QPixmap::fromImage(image));
    return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
    VisualizationMono_Sensor_Laser_Params * params=(VisualizationMono_Sensor_Laser_Params *)paramsPtr;
    VisualizationMulti_Calibration_Laser_Vars * vars=(VisualizationMulti_Calibration_Laser_Vars *)varsPtr;
    widgets=QList<QWidget *>();
    /*======Please Program above======*/
    /*
    Function: get visualization widgets [defined in vars].
    You need to program here when you need visualization widgets.
    E.g.
    widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
    */
}

