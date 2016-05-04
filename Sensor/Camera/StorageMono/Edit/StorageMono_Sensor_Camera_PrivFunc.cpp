//You need to program this file.

#include "../NoEdit/StorageMono_Sensor_Camera_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	StorageMono_Sensor_Camera_Params * params=(StorageMono_Sensor_Camera_Params *)paramsPtr;
	StorageMono_Sensor_Camera_Vars * vars=(StorageMono_Sensor_Camera_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/

    GetParamValue(xmlloader, params, filename);
    GetParamValue(xmlloader, params, storagepath);
    GetParamValue(xmlloader, params, fps);
    GetParamValue(xmlloader, params, width);
    GetParamValue(xmlloader, params, height);
    GetParamValue(xmlloader, params, cameraID);

    QDateTime now = QDateTime::currentDateTime();
    QString subFolder = now.toString("MMdd_hhmm");
    QDir target(params->storagepath+"/"+subFolder);
    if (!target.exists())
    {
        target.mkpath("./");
    }

    QString filename = QString("%1/%2/%3").arg(params->storagepath).arg(subFolder).arg(params->filename);

   // QString filename = QString("%1/%2%3").arg(params->storagepath).arg(params->cameraID).arg(params->filename);
    vars->timestampwriter.setFileName(QString("%1.log").arg(filename));

    if(vars->timestampwriter.open(QFile::WriteOnly | QFile::Text))
    {
        cv::Size framesize(params->width, params->height);
        if(vars->imagewriter.open(filename.toStdString(), CV_FOURCC('D', 'I', 'V', 'X'), params->fps, framesize))
        {
            return 1;
        }
        else
        {
            vars->timestampwriter.close();
            return 0;
        }
    }

	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	StorageMono_Sensor_Camera_Params * params=(StorageMono_Sensor_Camera_Params *)paramsPtr;
	StorageMono_Sensor_Camera_Vars * vars=(StorageMono_Sensor_Camera_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->imagewriter.release();
    vars->timestampwriter.close();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	StorageMono_Sensor_Camera_Params * params=(StorageMono_Sensor_Camera_Params *)paramsPtr;
	StorageMono_Sensor_Camera_Vars * vars=(StorageMono_Sensor_Camera_Vars *)varsPtr;
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
	StorageMono_Sensor_Camera_Params * params=(StorageMono_Sensor_Camera_Params *)paramsPtr;
	StorageMono_Sensor_Camera_Vars * vars=(StorageMono_Sensor_Camera_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 0, Params_Type = SensorInternalEvent_Sensor_Camera_Params, Data_Type = SensorInternalEvent_Sensor_Camera_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	StorageMono_Sensor_Camera_Params * params=(StorageMono_Sensor_Camera_Params *)paramsPtr;
	StorageMono_Sensor_Camera_Vars * vars=(StorageMono_Sensor_Camera_Vars *)varsPtr;
	QVector<SensorInternalEvent_Sensor_Camera_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<SensorInternalEvent_Sensor_Camera_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
    int i, n=draindata.size();
    cv::Mat tmpimage;
    for(i=n-1; i>=0; i--)
    {
        int timestamp = ((draindata[i]->timestamp.hour()*60 + draindata[i]->timestamp.minute())*60 + draindata[i]->timestamp.second())*1000
                    + draindata[i]->timestamp.msec();
        vars->timestampwriter.write(QString("%1\n").arg(timestamp).toUtf8());
        draindata[i]->cvimage.copyTo(tmpimage);
        cv::cvtColor(tmpimage, tmpimage, CV_RGB2BGR);
        vars->imagewriter.write(tmpimage);
    }
//    int timestamp = ((draindata.front()->timestamp.hour()*60 + draindata.front()->timestamp.minute())*60 + draindata.front()->timestamp.second())*1000
//                + draindata.front()->timestamp.msec();
//    vars->timestampwriter.write(QString("%1\n").arg(timestamp).toUtf8());
//    draindata.front()->cvimage.copyTo(tmpimage);
//    cv::cvtColor(tmpimage, tmpimage, CV_RGB2BGR);
//    vars->imagewriter.write(tmpimage);
	return 1;
}

