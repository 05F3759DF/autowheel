//You need to program this file.

#include "../NoEdit/SensorTimer_Localization_Slam_PrivFunc.h"
#include <qmath.h>

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	SensorTimer_Localization_Slam_Params * params=(SensorTimer_Localization_Slam_Params *)paramsPtr;
	SensorTimer_Localization_Slam_Vars * vars=(SensorTimer_Localization_Slam_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/

    GetParamValue(xmlloader, vars, storagepath);

    vars->x = vars->y = vars->z = 0.0;

    QDateTime now = QDateTime::currentDateTime();
    QString subFolder = now.toString("MMdd_hhmm");
    QString filename = "slam_"+subFolder + ".txt";
    QDir target(vars->storagepath+"/"+subFolder);
    if (!target.exists())
    {
        target.mkpath("./");
    }

    QString tmpfilename = QString("%1/%2/%3").arg(vars->storagepath).arg(subFolder).arg(filename);


    vars->slamFile.open(tmpfilename.toStdString().c_str());
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	SensorTimer_Localization_Slam_Params * params=(SensorTimer_Localization_Slam_Params *)paramsPtr;
	SensorTimer_Localization_Slam_Vars * vars=(SensorTimer_Localization_Slam_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
//    if(vars->slamSub != NULL)
//        vars->slamSub->stopReceiveSlot();

    vars->slamFile.close();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	SensorTimer_Localization_Slam_Params * params=(SensorTimer_Localization_Slam_Params *)paramsPtr;
	SensorTimer_Localization_Slam_Vars * vars=(SensorTimer_Localization_Slam_Vars *)varsPtr;
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
	SensorTimer_Localization_Slam_Params * params=(SensorTimer_Localization_Slam_Params *)paramsPtr;
	SensorTimer_Localization_Slam_Vars * vars=(SensorTimer_Localization_Slam_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new SensorTimer_Localization_Slam_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	SensorTimer_Localization_Slam_Params * params=(SensorTimer_Localization_Slam_Params *)paramsPtr;
	SensorTimer_Localization_Slam_Vars * vars=(SensorTimer_Localization_Slam_Vars *)varsPtr;
	SensorTimer_Localization_Slam_Data * outputdata=(SensorTimer_Localization_Slam_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/
//    if(vars->slamSub == NULL)
//        return 0;
//    geometry_msgs::PoseWithCovarianceStampedConstPtr msg = vars->slamSub->getMessage();
//    if(msg != NULL)
//    {
//        vars->x = msg->pose.pose.position.x;
//        vars->y = msg->pose.pose.position.y;
//        vars->z = msg->pose.pose.position.z;
//        vars->yaw = tf::getYaw(msg->pose.pose.orientation);

//        vars->slamFile<<vars->x<<'\t'<<vars->y<<'\t'<<vars->yaw<<endl;
//    }
    tf::StampedTransform transform;
    try{
       vars->listener.lookupTransform("/map", "/base_link", ros::Time(0), transform);
    }
    catch(tf::TransformException &ex)
    {
        return 0;
    }
    outputdata->x = transform.getOrigin().x();
    outputdata->y = transform.getOrigin().y();
    outputdata->z = transform.getOrigin().z();
    outputdata->theta =tf::getYaw( transform.getRotation()) + M_PI/2.0;
    outputdata->qtimestamp = QTime::currentTime();

    int timestamp=((outputdata->qtimestamp.hour()*60+outputdata->qtimestamp.minute())*60
        +outputdata->qtimestamp.second())*1000+outputdata->qtimestamp.msec();
    outputdata->timestamp = timestamp;

    vars->slamFile<<timestamp<<'\t'<<outputdata->x<<'\t'<<outputdata->y<<'\t'<<outputdata->theta<<endl;

	return 1;
}

