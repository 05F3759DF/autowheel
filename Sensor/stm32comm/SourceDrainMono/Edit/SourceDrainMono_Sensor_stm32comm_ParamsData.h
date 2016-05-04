//You need to modify this file.

#ifndef SOURCEDRAINMONO_SENSOR_STM32COMM_PARAMSDATA_H
#define SOURCEDRAINMONO_SENSOR_STM32COMM_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup SourceDrainMono_Sensor_stm32comm_ParamsData SourceDrainMono_Sensor_stm32comm_ParamsData
	\ingroup SourceDrainMono_Sensor_stm32comm
	\brief SourceDrainMono_Sensor_stm32comm_ParamsData defines the ParamsData in SourceDrainMono_Sensor_stm32comm.
*/

/*! \addtogroup SourceDrainMono_Sensor_stm32comm_ParamsData
	@{
*/

/*! \file SourceDrainMono_Sensor_stm32comm_ParamsData.h
	 Defines the ParamsData of SourceDrainMono_Sensor_stm32comm
*/

//*******************Please add other headers below*******************

//1 input data header(s) refered
#include <QtSerialPort/qserialport.h>
//Defines Params ProcessorMulti_Processor_Control_Params and Input Data ProcessorMulti_Processor_Control_Data
#include<wheelchair/Processor/Control/ProcessorMulti/Edit/ProcessorMulti_Processor_Control_ParamsData.h>

//0 new input data type(s) created

/*! \def SourceDrainMono_Sensor_stm32comm_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = ProcessorMulti_Processor_Control_Params, Data_Type = ProcessorMulti_Processor_Control_Data
*/
#define SourceDrainMono_Sensor_stm32comm_INPUTPORTSSIZE QList<int>()<<10

//The Params is defined as below
/*! \class SourceDrainMono_Sensor_stm32comm_Params 
	\brief The Params of SourceDrainMono_Sensor_stm32comm.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SourceDrainMono_Sensor_stm32comm_Params 
{
public:
	/*! \fn SourceDrainMono_Sensor_stm32comm_Params()
		\brief The constructor of SourceDrainMono_Sensor_stm32comm_Params. [required]
		\details ****Please add details below****

	*/
	SourceDrainMono_Sensor_stm32comm_Params() 
	{
        port = "/dev/ttyS0";

        recvpacksize = 12;
        recv_packhead = QByteArray(char(0xA2), 1);
        recv_packtail = QByteArray(char(0x2A), 1);

        send_packhead = QByteArray(char(0xF8), 1);
        send_packtail = QByteArray(char(0x8F), 1);

        distPerPulse = 1.0;
        maxpusle = 30000;

        ratio = 0.9926008126;
	}
	/*! \fn ~SourceDrainMono_Sensor_stm32comm_Params()
		\brief The destructor of SourceDrainMono_Sensor_stm32comm_Params. [required]
		\details *****Please add details below*****

	*/
	~SourceDrainMono_Sensor_stm32comm_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QString port;

    //串口接受数据头，和数据大小
    QByteArray recv_packhead;
    QByteArray recv_packtail;
    int recvpacksize;
    //串口发送数据头
    QByteArray send_packtail;
    QByteArray send_packhead;

    double WheelBase, WheelRadius, ratio;

    int maxpusle;
    double distPerPulse;
};

//The Output Data is defined as below
/*! \class SourceDrainMono_Sensor_stm32comm_Data 
	\brief The Data of SourceDrainMono_Sensor_stm32comm.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SourceDrainMono_Sensor_stm32comm_Data 
{
public:
	/*! \fn SourceDrainMono_Sensor_stm32comm_Data()
		\brief The constructor of SourceDrainMono_Sensor_stm32comm_Data. [required]
		\details ****Please add details below****

	*/
	SourceDrainMono_Sensor_stm32comm_Data() 
	{
		
	}
	/*! \fn ~SourceDrainMono_Sensor_stm32comm_Data()
		\brief The destructor of SourceDrainMono_Sensor_stm32comm_Data. [required]
		\details *****Please add details below*****

	*/
	~SourceDrainMono_Sensor_stm32comm_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    double yaw;
    double leftspeed, leftodom;
    double rightspeed, rightodom;
    double x, y, theta;
//    short leftencoder;
//    short rightencoder;
    QTime timestamp;
};

/*! \def SourceDrainMono_Sensor_stm32comm_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define SourceDrainMono_Sensor_stm32comm_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
