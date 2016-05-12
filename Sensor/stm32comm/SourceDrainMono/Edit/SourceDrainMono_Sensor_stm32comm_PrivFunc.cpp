//You need to program this file.

#include "../NoEdit/SourceDrainMono_Sensor_stm32comm_PrivFunc.h"
#include <qmath.h>
//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	SourceDrainMono_Sensor_stm32comm_Params * params=(SourceDrainMono_Sensor_stm32comm_Params *)paramsPtr;
	SourceDrainMono_Sensor_stm32comm_Vars * vars=(SourceDrainMono_Sensor_stm32comm_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader, params, port);

     GetParamValue(xmlloader, params, recv_packhead);
     GetParamValue(xmlloader, params, recv_packtail);
     GetParamValue(xmlloader, params, send_packhead);
     GetParamValue(xmlloader, params, send_packtail);
     GetParamValue(xmlloader, params, distPerPulse);
     GetParamValue(xmlloader, params, maxpusle);
     GetParamValue(xmlloader, params, WheelBase);
     GetParamValue(xmlloader, params, WheelRadius);
     GetParamValue(xmlloader, params, ratio);
     GetParamValue(xmlloader, vars, quryinterval);
     GetParamValue(xmlloader, params, recvpacksize);


     vars->serialport->setPortName(params->port);
     vars->serialport->setBaudRate(QSerialPort::Baud115200);
     vars->serialport->setDataBits(QSerialPort::Data8);
     vars->serialport->setParity(QSerialPort::NoParity);
     vars->serialport->setStopBits(QSerialPort::OneStop);
     vars->serialport->setFlowControl(QSerialPort::NoFlowControl);

     vars->leftspeed = vars->rightspeed =0;
     vars->leftodom = vars->rightodom = 0;

     vars->x = vars->y = vars->yaw = 0;

     vars->theta = M_PI / 2; //初始化朝向，前方是y轴正方向，右方是x轴正方向-20150519

     if(!(vars->serialport->open(QIODevice::ReadWrite))) {
         return 0;
     }

     //send the transform
     ///odom ---> base_link
     geometry_msgs::TransformStamped odom_trans;

     odom_trans.header.stamp = ros::Time::now();
     odom_trans.header.frame_id = "odom";
     odom_trans.child_frame_id = "base_link";
     odom_trans.transform.translation.x = 0;
     odom_trans.transform.translation.y = 0;
     odom_trans.transform.translation.z = 0;
     odom_trans.transform.rotation = tf::createQuaternionMsgFromYaw(0);

     vars->odom_broadcaster.sendTransform(odom_trans);

    // vars->speedFile.open("speed.txt");
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	SourceDrainMono_Sensor_stm32comm_Params * params=(SourceDrainMono_Sensor_stm32comm_Params *)paramsPtr;
	SourceDrainMono_Sensor_stm32comm_Vars * vars=(SourceDrainMono_Sensor_stm32comm_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
     vars->serialport->close();

     //vars->speedFile.close();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	SourceDrainMono_Sensor_stm32comm_Params * params=(SourceDrainMono_Sensor_stm32comm_Params *)paramsPtr;
	SourceDrainMono_Sensor_stm32comm_Vars * vars=(SourceDrainMono_Sensor_stm32comm_Vars *)varsPtr;
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
	SourceDrainMono_Sensor_stm32comm_Params * params=(SourceDrainMono_Sensor_stm32comm_Params *)paramsPtr;
	SourceDrainMono_Sensor_stm32comm_Vars * vars=(SourceDrainMono_Sensor_stm32comm_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new SourceDrainMono_Sensor_stm32comm_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	SourceDrainMono_Sensor_stm32comm_Params * params=(SourceDrainMono_Sensor_stm32comm_Params *)paramsPtr;
	SourceDrainMono_Sensor_stm32comm_Vars * vars=(SourceDrainMono_Sensor_stm32comm_Vars *)varsPtr;
	SourceDrainMono_Sensor_stm32comm_Data * outputdata=(SourceDrainMono_Sensor_stm32comm_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/
    if(vars->serialport->bytesAvailable() < params->recvpacksize)
         return 0;

     QByteArray datagram = vars->serialport->readAll();
     QTime currenttime = QTime::currentTime();

     vars->current_time = ros::Time::now();

     int startid = datagram.indexOf(params->recv_packhead);
     int skip = params->recvpacksize - 1;
     if(startid >= 0)
     {
         int endid = datagram.indexOf(params->recv_packtail, startid+skip);
         if((endid - skip) == startid)
         {
             QByteArray tmpdata = datagram.mid(startid+params->recv_packhead.size(), endid-(startid+params->recv_packhead.size()));
             vars->roll = *((short*)(tmpdata.data()));
             vars->roll = vars->roll / 10.0 * M_PI / 180.0;

             vars->pitch = *((short*)(tmpdata.data() + sizeof(short)));
             vars->pitch = vars->pitch / 10.0 * M_PI / 180.0;

             vars->yaw = *((short*)(tmpdata.data() + 2 * sizeof(short)));
             vars->yaw = vars->yaw / 10.0 * M_PI / 180.0;

             vars->leftencoder = *((short*)(tmpdata.data() + 3 * sizeof(short)));
             vars->rightencoder = *((short*)(tmpdata.data() + 4 * sizeof(short)));
             //第一次初始化数据
             if(vars->isinit)
             {
                 vars->lastleftencoder = vars->leftencoder;
                 vars->lastrightencoder = vars->rightencoder;
                 vars->leftspeed = vars->rightspeed = 0;
                 vars->leftodom = vars->rightodom = 0;
                 vars->lastyaw = vars->yaw;

                 vars->x = vars->y  = vars->vx = vars->vy = vars->vtheta = 0.0;

                 vars->current_time = ros::Time::now();
                 vars->last_time = ros::Time::now();

                 vars->isinit = 0;
                 return 1;
             }

             double deltatime = (vars->current_time - vars->last_time).toSec();

             vars->deltaleft = deltatime *(vars->leftencoder + vars->lastleftencoder)  / 2 * params->distPerPulse;
             vars->leftodom += vars->deltaleft;
             vars->leftspeed = vars->leftencoder;
             vars->lastleftencoder = vars->leftencoder;

             vars->deltaright = deltatime *(vars->rightencoder + vars->rightencoder)  / 2 * params->distPerPulse;
             vars->rightodom += vars->deltaright ;
             vars->rightspeed = vars->rightencoder;
             vars->lastrightencoder = vars->rightencoder;

             ////使用编码器计算角度
             //vars->deltaEncodertheta = (vars->deltaright-vars->deltaleft)/params->WheelBase;
             ////使用IMU计算角度
             vars->deltaIMUtheta = -(vars->yaw - vars->lastyaw) * M_PI / 1800.0;

             vars->lastyaw = vars->yaw;

             ///IMU角度范围是 0~360
             double max_angle = 2 * M_PI;
             if(vars->deltaIMUtheta > max_angle / 2)
                 vars->deltaIMUtheta -= max_angle;
             else if(vars->deltaIMUtheta < -max_angle / 2)
                 vars->deltaIMUtheta += max_angle;
             ///使用那个角度？
             //vars->deltatheta = vars->deltaEncodertheta;
             vars->deltatheta = vars->deltaIMUtheta;

             double deltaodom = (vars->deltaleft + vars->deltaright) / 2;
             double dx = deltaodom * cos(vars->theta + vars->deltatheta / 2);
             double dy = deltaodom * sin(vars->theta + vars->deltatheta / 2);
             vars->x += dx;
             vars->y += dy;

             vars->theta += vars->deltatheta;
             vars->vx = dx / deltatime;
             vars->vy = dy / deltatime;
             vars->vtheta = vars->deltatheta / deltatime;

             //send the transform
             ///odom ---> base_link
             geometry_msgs::TransformStamped odom_trans;
             geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(vars->theta - M_PI/2.0);

             odom_trans.header.stamp = vars->current_time;
             odom_trans.header.frame_id = "odom";
             odom_trans.child_frame_id = "base_link";
             odom_trans.transform.translation.x = vars->x;
             odom_trans.transform.translation.y = vars->y;
             odom_trans.transform.translation.z = 0;
             odom_trans.transform.rotation = odom_quat;
             vars->odom_broadcaster.sendTransform(odom_trans);

             ///base_link ---> laser
             tf::Transform trans2;
             trans2.setOrigin(tf::Vector3(-0.287,0.68 , 0));
             tf::Quaternion quat2 = tf::createQuaternionFromYaw(M_PI/2.0);
             trans2.setRotation(quat2);

             vars->baselink2laser->sendTF(trans2);

            ///output data
            outputdata->leftodom = vars->leftodom;
            outputdata->rightodom = vars->rightodom;
            outputdata->leftspeed = vars->leftspeed;
            outputdata->rightspeed = vars->rightspeed;
            outputdata->x = vars->x;
            outputdata->y = vars->y;
            outputdata->theta = vars->theta;
            outputdata->yaw = vars->yaw;
            outputdata->timestamp = currenttime;
            vars->last_time = vars->current_time;
        }
    }
    else
    {
        return 0;
    }

    return 1;
}

void DECOFUNC(getMonoDrainDataSize)(void * paramsPtr, void * varsPtr, int & drainDataSize)
{
	SourceDrainMono_Sensor_stm32comm_Params * params=(SourceDrainMono_Sensor_stm32comm_Params *)paramsPtr;
	SourceDrainMono_Sensor_stm32comm_Vars * vars=(SourceDrainMono_Sensor_stm32comm_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 10, Params_Type = ProcessorMulti_Processor_Control_Params, Data_Type = ProcessorMulti_Processor_Control_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	SourceDrainMono_Sensor_stm32comm_Params * params=(SourceDrainMono_Sensor_stm32comm_Params *)paramsPtr;
	SourceDrainMono_Sensor_stm32comm_Vars * vars=(SourceDrainMono_Sensor_stm32comm_Vars *)varsPtr;
	QVector<ProcessorMulti_Processor_Control_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<ProcessorMulti_Processor_Control_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
    ProcessorMulti_Processor_Control_Data* inputdata = draindata.front();

    char dataput[8];
    char data_size = 5;
    dataput[0] = params->send_packhead.at(0);
    dataput[1] = data_size;
    *(short*)&dataput[2] = (short)inputdata->left_motor;
    *(short*)&dataput[4] = (short)inputdata->right_motor;
    //控制左右灯, 0 - all off; 1 - left light on; 2 - right light on; 3 - all on;
    *(short*)&dataput[6] = 0;

    dataput[7] = params->send_packtail.at(0);

    int n = vars->serialport->write(dataput, 8);
    if(n < 0)
    {
        return 0;
    }
    return 1;
}

