//You need to program this file.

#include "../NoEdit/SensorInternalEvent_Sensor_Laser_PrivFunc.h"
#include <qmath.h>
//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	SensorInternalEvent_Sensor_Laser_Params * params=(SensorInternalEvent_Sensor_Laser_Params *)paramsPtr;
	SensorInternalEvent_Sensor_Laser_Vars * vars=(SensorInternalEvent_Sensor_Laser_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/

    GetParamValue(xmlloader, vars, lLaserTopic);
    GetParamValue(xmlloader, vars, rLaserTopic);
    GetParamValue(xmlloader, vars, queuesize);
    GetParamValue(xmlloader, vars, quryinterval);
    GetParamValue(xmlloader,vars,llaser_on);
    GetParamValue(xmlloader,vars,rlaser_on);

    vars->lLaserSub->resetTopic(vars->lLaserTopic, vars->queuesize);
    vars->lLaserSub->resetQueryInterval(vars->quryinterval);
    vars->lLaserSub->startReceiveSlot();

    vars->rLaserSub->resetTopic(vars->rLaserTopic, vars->queuesize);
    vars->rLaserSub->resetQueryInterval(vars->quryinterval);
    vars->rLaserSub->startReceiveSlot();

	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	SensorInternalEvent_Sensor_Laser_Params * params=(SensorInternalEvent_Sensor_Laser_Params *)paramsPtr;
	SensorInternalEvent_Sensor_Laser_Vars * vars=(SensorInternalEvent_Sensor_Laser_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->lLaserSub->stopReceiveSlot();
    vars->rLaserSub->stopReceiveSlot();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	SensorInternalEvent_Sensor_Laser_Params * params=(SensorInternalEvent_Sensor_Laser_Params *)paramsPtr;
	SensorInternalEvent_Sensor_Laser_Vars * vars=(SensorInternalEvent_Sensor_Laser_Vars *)varsPtr;
    internalTrigger=vars->lLaserSub;
    internalTriggerSignal=QString(SIGNAL(receiveMessageSignal()));
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
	SensorInternalEvent_Sensor_Laser_Params * params=(SensorInternalEvent_Sensor_Laser_Params *)paramsPtr;
	SensorInternalEvent_Sensor_Laser_Vars * vars=(SensorInternalEvent_Sensor_Laser_Vars *)varsPtr;
    //outputDataPtr=boost::shared_ptr<void>(new SensorInternalEvent_Sensor_Laser_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
    int beamnumber=(params->last_step-params->first_step)/params->skip_step+1;
    outputDataPtr=boost::shared_ptr<void>(new SensorInternalEvent_Sensor_Laser_Data(beamnumber));
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	SensorInternalEvent_Sensor_Laser_Params * params=(SensorInternalEvent_Sensor_Laser_Params *)paramsPtr;
	SensorInternalEvent_Sensor_Laser_Vars * vars=(SensorInternalEvent_Sensor_Laser_Vars *)varsPtr;
	SensorInternalEvent_Sensor_Laser_Data * outputdata=(SensorInternalEvent_Sensor_Laser_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/
    outputdata->qtimestamp = QTime::currentTime();
    sensor_msgs::LaserScan  llaserData ;
    //left laser data, ROS提供的SLAM接口只支持标准的Laser输入，所以这里只使用左激光，并且去除了遮挡部分
    if(vars->llaser_on)
    {
        llaserData = vars->lLaserSub->getMessage();
        if(llaserData.ranges.size() == 0)
            return 0;
        int msec=(llaserData.header.stamp.sec)%(24*60*60)*1000+(llaserData.header.stamp.nsec)/1000000;
        //outputdata->qtimestamp = QTime::fromMSecsSinceStartOfDay(msec);
        outputdata->timestamp = msec;
        outputdata->datasize = llaserData.ranges.size();

        int occupyAngle = 50; //70度的遮挡
        //vars->currentllaserData = llaserData;
        int ii = 0;
        for(int i=0; i< outputdata->datasize; i++)
        {
            outputdata->ldata[i] = qRound(llaserData.ranges[i]*100.0);
            if(outputdata->ldata[i] < 5)
                outputdata->ldata[i] = 3000;
            //去遮挡
            if(i>(outputdata->datasize - occupyAngle*2) && i< outputdata->datasize)
            {
                if(llaserData.ranges[i]<0.15)
                {
                    llaserData.ranges[i] = 0.0;
                    ii++;
                }
            }
        }
        //std::cout<<ii<<std::endl;
        double temp;
        for(int i=0; i< outputdata->datasize/2; i++)
        {//翻转激光
            temp = llaserData.ranges[outputdata->datasize - i - 1];
            llaserData.ranges[outputdata->datasize - i - 1] = llaserData.ranges[i];
            llaserData.ranges[i] = temp;
        }
        vars->laserPub->sendMessage(llaserData);
    }
    //right laser data

    sensor_msgs::LaserScanConstPtr  laserPtr ;
    if(vars->rlaser_on)
    {
        laserPtr = vars->rLaserSub->getMessage();
        if(laserPtr == NULL)
            return 0;
        int msec=(laserPtr->header.stamp.sec)%(24*60*60)*1000+(laserPtr->header.stamp.nsec)/1000000;
        //outputdata->qtimestamp = QTime::fromMSecsSinceStartOfDay(msec);
        outputdata->timestamp = msec;
        outputdata->datasize = laserPtr->ranges.size();
        for(int i=0; i< outputdata->datasize; i++)
        {
            outputdata->rdata[i] = qRound(laserPtr->ranges[i]*100.0);
            if(outputdata->rdata[i] < 5)
                outputdata->rdata[i] = 3000;
        }
    }
	return 1;
}

