//You need to program this file.

#include "../NoEdit/VisualizationMulti_VisualMisc_ControlJoy_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMulti_VisualMisc_ControlJoy_Params * params=(VisualizationMulti_VisualMisc_ControlJoy_Params *)paramsPtr;
	VisualizationMulti_VisualMisc_ControlJoy_Vars * vars=(VisualizationMulti_VisualMisc_ControlJoy_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader, vars, leftArrowPath);
    GetParamValue(xmlloader, vars, rightArrowPath);
    GetParamValue(xmlloader, vars, forwardArrowPath);
    GetParamValue(xmlloader, vars, backArrowPath);
    GetParamValue(xmlloader, vars, width);
    GetParamValue(xmlloader, vars, height);
    GetParamValue(xmlloader, vars, fontSize);
    std::cout<<"open Joystick\n";
    vars->label->setText("Open");


    bool flag = vars->leftArrowImg.load(vars->leftArrowPath);
    flag &= vars->rightArrowImg.load(vars->rightArrowPath);
    flag &= vars->forwardArrowImg.load(vars->forwardArrowPath);
    flag &= vars->backArrowImg.load(vars->backArrowPath);
    if(!flag)
    {
        std::cout<<"load image error: VisualizationMulti_ControlJoy !"<<std::endl;
        return 0;
    }
    return 1;

}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMulti_VisualMisc_ControlJoy_Params * params=(VisualizationMulti_VisualMisc_ControlJoy_Params *)paramsPtr;
	VisualizationMulti_VisualMisc_ControlJoy_Vars * vars=(VisualizationMulti_VisualMisc_ControlJoy_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->label->setText("closed");
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMulti_VisualMisc_ControlJoy_Params * params=(VisualizationMulti_VisualMisc_ControlJoy_Params *)paramsPtr;
	VisualizationMulti_VisualMisc_ControlJoy_Vars * vars=(VisualizationMulti_VisualMisc_ControlJoy_Vars *)varsPtr;
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
	VisualizationMulti_VisualMisc_ControlJoy_Params * params=(VisualizationMulti_VisualMisc_ControlJoy_Params *)paramsPtr;
	VisualizationMulti_VisualMisc_ControlJoy_Vars * vars=(VisualizationMulti_VisualMisc_ControlJoy_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 1, Params_Type = ProcessorMulti_Processor_Control_Params, Data_Type = ProcessorMulti_Processor_Control_Data
//Input Port #1: Buffer_Size = 1, Params_Type = SensorInternalEvent_Sensor_Joystick_Params, Data_Type = SensorInternalEvent_Sensor_Joystick_Data
bool DECOFUNC(processMultiDrainData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > drainParams, QVector<QVector<void *> > drainData)
{
	VisualizationMulti_VisualMisc_ControlJoy_Params * params=(VisualizationMulti_VisualMisc_ControlJoy_Params *)paramsPtr;
	VisualizationMulti_VisualMisc_ControlJoy_Vars * vars=(VisualizationMulti_VisualMisc_ControlJoy_Vars *)varsPtr;
	QVector<ProcessorMulti_Processor_Control_Params *> drainparams_0; copyQVector(drainparams_0,drainParams[0]);
	QVector<SensorInternalEvent_Sensor_Joystick_Params *> drainparams_1; copyQVector(drainparams_1,drainParams[1]);
	QVector<ProcessorMulti_Processor_Control_Data *> draindata_0; copyQVector(draindata_0,drainData[0]);
	QVector<SensorInternalEvent_Sensor_Joystick_Data *> draindata_1; copyQVector(draindata_1,drainData[1]);
	if(draindata_0.size()==0){return 0;}
	if(draindata_1.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata_index.
	*/
    ProcessorMulti_Processor_Control_Data* controldata = draindata_0.front();
    SensorInternalEvent_Sensor_Joystick_Data* joystick_data = draindata_1.front();

    if(controldata->isManualControl == 1)//manual control
    {
        QImage image(vars->width, vars->height, QImage::Format_ARGB32);

        QPainter painter;

        //vars->joystick_label->resize(vars->width, vars->height);
        painter.begin(&image);
        painter.setBackground(QBrush(QColor(241,241,241)));
        painter.eraseRect(0,0, vars->width, vars->height);


         if(joystick_data->forward)
            painter.drawImage(vars->width/2-16, vars->height/2-56, vars->forwardArrowImg);

        if(joystick_data->left)
            painter.drawImage(vars->width/2 -56, vars->height/2-16, vars->leftArrowImg);

        if(joystick_data->right)
            painter.drawImage(vars->width/2+24, vars->height/2-16, vars->rightArrowImg);

        if(joystick_data->back)
            painter.drawImage(vars->width/2-16, vars->height/2+24, vars->backArrowImg);

        painter.end();

        vars->label->setPixmap(QPixmap::fromImage(image));
    }
    else //Auto control
    {
        QFont serifFont("Times", vars->fontSize);
        vars->label->setFont(serifFont);
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::red);
        vars->label->setPalette(pa);
        //vars->label->setAlignment(Qt::AlignLeft);

        QString outputstr = QString("Left_Motor: %1\nRight_Motor: %2\n").arg(controldata->left_motor).arg(controldata->right_motor);
        vars->label->setText(outputstr);
    }

    //vars->label->setFixedHeight(250);
	return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMulti_VisualMisc_ControlJoy_Params * params=(VisualizationMulti_VisualMisc_ControlJoy_Params *)paramsPtr;
	VisualizationMulti_VisualMisc_ControlJoy_Vars * vars=(VisualizationMulti_VisualMisc_ControlJoy_Vars *)varsPtr;
    widgets=QList<QWidget *>()<<(vars->label);
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

