//You need to program this file.

#include "../NoEdit/VisualizationMulti_VisualMisc_CombinedVisual_PrivFunc.h"
#include <fstream>


using namespace std;
//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...
inline double dist(double x1, double y1, double x2, double y2) {
    return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1-y2);}
bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMulti_VisualMisc_CombinedVisual_Params * params=(VisualizationMulti_VisualMisc_CombinedVisual_Params *)paramsPtr;
	VisualizationMulti_VisualMisc_CombinedVisual_Vars * vars=(VisualizationMulti_VisualMisc_CombinedVisual_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader, params, filepath);
    GetParamValue(xmlloader, params, sketchFileName);
    GetParamValue(xmlloader, params, offlineFileName);
    GetParamValue(xmlloader, vars, isSimulator);


    vars->glviewer->makeCurrent();
    vars->glviewer->setBackground(QColor(241,241,241));

    vars->glviewer->clearDisplayList();
    vars->m_list[vars->MapListID] = glGenLists(vars->ListCount);
    for(int i=0; i<vars->ListCount; i++)
    {
        vars->m_list[i] = vars->m_list[vars->MapListID]+i;
        vars->glviewer->addDisplayList(vars->m_list[vars->MapListID]+i);
    }

    //读离线地图
    ifstream file;
    file.open((params->filepath+params->sketchFileName).toStdString().c_str());
    cv::Point2d tmp;

    while(!file.eof())
    {
        file>>tmp.x>>tmp.y;
        vars->sketchMap.push_back(tmp);
    }
    file.close();

    vars->offset_x = -16; vars->offset_y = 0;
    vars->offset_z = -20;
    //缓存离线地图
    glNewList(vars->m_list[vars->MapListID], GL_COMPILE_AND_EXECUTE);
    glColor3f(0,0,0);
    glPointSize(2);
    glTranslatef(vars->offset_x,vars->offset_y ,vars->offset_z);
    glRotatef(-90, 0,0,1);
    glBegin(GL_POINTS);
    for(int i=0; i<vars->sketchMap.size(); i++)
    {
        glVertex3d(vars->sketchMap[i].x, vars->sketchMap[i].y, 0);
    }
    glEnd();
    glEndList();

    //读离线轨迹
//    file.open((params->filepath+params->offlineFileName).toStdString().c_str());
//    double ox, oy, oth;
//    int time;
//    while(!file.eof())
//    {
//        file>>time>>ox>>oy>>oth;
//        trajec_state tmpstate = {ox, oy, oth, 0};
//        vars->offlinetrajec.push_back(tmpstate);
//    }
//    file.close();
    //缓存离线轨迹
//    glNewList(vars->m_list[vars->OfflineTrajID], GL_COMPILE_AND_EXECUTE);
//    glTranslatef(vars->offset_x,vars->offset_y ,vars->offset_z);
//    glRotatef(-90, 0,0,1);
//    glLineWidth(1);
//    glColor3f(0.6,0.6,0);
//    glBegin(GL_LINE_STRIP);
//    for(int i=0; i<vars->offlinetrajec.size(); i++)
//    {
//        glVertex3f(vars->offlinetrajec[i].x, vars->offlinetrajec[i].y, 0);
//    }
//    glEnd();
//    glEndList();


    //缓存车模型
    trajec_state pos;
    pos.x = pos.y = 0;
    pos.theta =M_PI/2.0;
    vars->drawCar(pos);

    vars->glviewer->update();

	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMulti_VisualMisc_CombinedVisual_Params * params=(VisualizationMulti_VisualMisc_CombinedVisual_Params *)paramsPtr;
	VisualizationMulti_VisualMisc_CombinedVisual_Vars * vars=(VisualizationMulti_VisualMisc_CombinedVisual_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->glviewer->clearDisplayList();
    vars->glviewer->update();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMulti_VisualMisc_CombinedVisual_Params * params=(VisualizationMulti_VisualMisc_CombinedVisual_Params *)paramsPtr;
	VisualizationMulti_VisualMisc_CombinedVisual_Vars * vars=(VisualizationMulti_VisualMisc_CombinedVisual_Vars *)varsPtr;
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
	VisualizationMulti_VisualMisc_CombinedVisual_Params * params=(VisualizationMulti_VisualMisc_CombinedVisual_Params *)paramsPtr;
	VisualizationMulti_VisualMisc_CombinedVisual_Vars * vars=(VisualizationMulti_VisualMisc_CombinedVisual_Vars *)varsPtr;
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

void rotate(double &x, double &y, const double th0)
{
    double tx = x * cos(th0) + y * sin(th0);
    double ty = -x * sin(th0) + y * cos(th0);
    x = tx;
    y = ty;
}

//Input Port #0: Buffer_Size = 5, Params_Type = ProcessorMulti_Processor_FeatureExtract_Params, Data_Type = ProcessorMulti_Processor_FeatureExtract_Data
//Input Port #1: Buffer_Size = 5, Params_Type = ProcessorMulti_Processor_PathGenerator_Params, Data_Type = ProcessorMulti_Processor_PathGenerator_Data
//Input Port #2: Buffer_Size = 5, Params_Type = SourceDrainMono_Sensor_stm32comm_Params, Data_Type = SourceDrainMono_Sensor_stm32comm_Data
bool DECOFUNC(processMultiDrainData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > drainParams, QVector<QVector<void *> > drainData)
{
	VisualizationMulti_VisualMisc_CombinedVisual_Params * params=(VisualizationMulti_VisualMisc_CombinedVisual_Params *)paramsPtr;
	VisualizationMulti_VisualMisc_CombinedVisual_Vars * vars=(VisualizationMulti_VisualMisc_CombinedVisual_Vars *)varsPtr;
	QVector<ProcessorMulti_Processor_FeatureExtract_Params *> drainparams_0; copyQVector(drainparams_0,drainParams[0]);
	QVector<ProcessorMulti_Processor_PathGenerator_Params *> drainparams_1; copyQVector(drainparams_1,drainParams[1]);
	QVector<SourceDrainMono_Sensor_stm32comm_Params *> drainparams_2; copyQVector(drainparams_2,drainParams[2]);
	QVector<ProcessorMulti_Processor_FeatureExtract_Data *> draindata_0; copyQVector(draindata_0,drainData[0]);
	QVector<ProcessorMulti_Processor_PathGenerator_Data *> draindata_1; copyQVector(draindata_1,drainData[1]);
	QVector<SourceDrainMono_Sensor_stm32comm_Data *> draindata_2; copyQVector(draindata_2,drainData[2]);
	if(draindata_0.size()==0){return 0;}
	if(draindata_1.size()==0){return 0;}
	if(draindata_2.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata_index.
    */
    ProcessorMulti_Processor_PathGenerator_Data* pathdata = draindata_1.front();
    SourceDrainMono_Sensor_stm32comm_Data* stm32data = draindata_2.front();
    ProcessorMulti_Processor_FeatureExtract_Data* feature = draindata_0.front();



//    if (pathdata->stop == 1)
//    {
//        return 0;
//    }
    //
    glNewList(vars->m_list[vars->OnlineTrajID], GL_COMPILE_AND_EXECUTE);
    glTranslatef(vars->offset_x,vars->offset_y ,vars->offset_z);
    glRotatef(-90, 0,0,1);
    //显示速度状态
    QString str;
    switch (pathdata->speedState) {
    case ProcessorMulti_Processor_PathGenerator_Data::MID:
        str = "MidSpeed";
        break;
    case ProcessorMulti_Processor_PathGenerator_Data::LOW:
        str = "LowSpeed";
        break;
    case ProcessorMulti_Processor_PathGenerator_Data::HIGH:
        str = "HighSpeed";
        break;
    case ProcessorMulti_Processor_PathGenerator_Data::STOP:
        str = "Stop";
        break;
    default:
        break;
    }
    //vars->glviewer->renderText(4,0,0, str);
    str += QString("\n%1").arg(pathdata->trajSets[pathdata->index].cost);

    vars->textWidget->setText(str);
    //画离线轨迹
    glLineWidth(1);
    glColor3f(1,0,0);
    glBegin(GL_LINE_STRIP);
    for(int i=0; i<pathdata->pointList.size(); i++)
    {
        glVertex3f(pathdata->pointList[i].x,pathdata->pointList[i].y, 0);
    }
    glEnd();

//    //画激光数据
//    glColor3f(1,0,0);
//    glPointSize(2);
//    glBegin(GL_POINTS);
//    for(int j=0; j < feature->URGData_size ; j++)
//    {
//        glVertex3f(feature->urg_data_point[0][j][0], feature->urg_data_point[0][j][1], 0);
//        glVertex3f(feature->urg_data_point[1][j][0], feature->urg_data_point[1][j][1], 0);
//    }
//    glEnd();
//    //画激光视野
//    glColor3f(1,1,0);
//    glLineWidth(1);

//    for(int j=0; j < feature->lms_gap.size() ; j++)
//    {
//        glBegin(GL_LINE_STRIP);
//        glVertex3f(feature->lms_gap[j].p1.x, feature->lms_gap[j].p1.y, 0);
//        glVertex3f(feature->lms_gap[j].p2.x, feature->lms_gap[j].p2.y, 0);
//        glEnd();
//    }
    //画碰撞检测椭圆范围
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POINTS);          //用线进行图形连接

    int N = 100;
    double temp_x[100];
    double temp_y[100];
    double center_x = (pathdata->front_center.x + pathdata->back_center.x)/2;
    double center_y = (pathdata->front_center.y + pathdata->back_center.y)/2;
    double distance_of_center = DISTANCE_2(center_x - pathdata->front_center.x,center_y - pathdata->front_center.y);
    double ella = (pathdata->size / 2);
    double ellb = sqrt((pathdata->size/2)*(pathdata->size/2) - distance_of_center*distance_of_center);
    for(int i=0;i<N;i++)
    {
        temp_x[i]=ella*cos(2*i*PI/N );  //pathdata->front_center.x + pathdata->back_center.x
        temp_y[i]=ellb*sin(2*i*PI/N );
        rotate(temp_x[i],temp_y[i],-pathdata->angle);
    }
    glEnd();


    //画所有的在线轨迹
    int skip ;
    skip = vars->isSimulator ? 1 : 3;
     glColor3f(0, 1, 0);
    glLineWidth(1);
    for(int i=0; i<pathdata->trajSets.size();i=i+skip)
    {
        if(pathdata->trajSets[i].valid == true)
        {
            glColor3f(0, 1, 0);
        }
        else
        {
            //glColor3f(0.5, 0, 0);
        }
        glBegin(GL_LINE_STRIP);
        for(int j=0; j<pathdata->trajSets[i].trajdat.size(); j++)
        {
            glVertex3f(pathdata->trajSets[i].trajdat[j].x, pathdata->trajSets[i].trajdat[j].y, 0);
        }
        glEnd();
    }

    //画目标轨迹
    glLineWidth(3);
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_STRIP);
    for(int i=0; i<pathdata->trajSets[pathdata->index].trajdat.size(); i++)
    {
        glVertex3f(pathdata->trajSets[pathdata->index].trajdat[i].x, pathdata->trajSets[pathdata->index].trajdat[i].y, 0);
    }
    glEnd();

    //draw online trajectory
    //if(dist(pathdata->startPoint.x,pathdata->startPoint.y, vars->lastposition.x, vars->lastposition.y)>1e-4)
    {
        vars->onlinetrajec.push_back(cv::Point2d(pathdata->startPoint.x,pathdata->startPoint.y));
        vars->colorList.push_back(pathdata->newColor);
       // qDebug() << pathdata->startPoint.x << ' ' << pathdata->startPoint.y;
    }
    glLineWidth(3);
    glColor3f(0,0,1);
    glBegin(GL_LINE_STRIP);
    for(int i=0; i<vars->onlinetrajec.size();i++)
    {
        if (vars->colorList[i] % 2 == 1)
        {
            glColor3f(0,0,1);
        }
        else
        {
            glColor3f(0.5,0,0);
        }
        glVertex3f(vars->onlinetrajec[i].x, vars->onlinetrajec[i].y, 0);

    }
    glEnd();

    //draw target point
    glPointSize(6);
    glColor3f(0,0.3,0);
    glBegin(GL_POINTS);
    glVertex3f(pathdata->targetPoint.x,
            pathdata->targetPoint.y, 0);
    glEnd();   
    glEndList();

    vars->drawCar(pathdata->startPoint);

    //移动摄像机视角
    Eigen::Matrix4d CameraPos = vars->glviewer->getCameraPose();

    double dx = pathdata->startPoint.x - vars->lastPos.x;
    double dy = pathdata->startPoint.y  - vars->lastPos.y;
    double dyaw = pathdata->startPoint.theta - vars->lastPos.theta;

    vars->lastPos = pathdata->startPoint;
    //顺时针旋转90度
    CameraPos(0,3) += dy;
    CameraPos(1,3) -= dx;

    vars->glviewer->setCameraPose(CameraPos);

    vars->glviewer->update();

    //更新速度和角度信息
    vars->sensor->setSpeed((stm32data->leftspeed+stm32data->rightspeed)/2.0);
    vars->sensor->setOriental(-stm32data->theta + M_PI/2.0);


	return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMulti_VisualMisc_CombinedVisual_Params * params=(VisualizationMulti_VisualMisc_CombinedVisual_Params *)paramsPtr;
	VisualizationMulti_VisualMisc_CombinedVisual_Vars * vars=(VisualizationMulti_VisualMisc_CombinedVisual_Vars *)varsPtr;
    widgets=QList<QWidget *>()<<(vars->glviewer)<<(vars->sensor)<<(vars->textWidget);
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

