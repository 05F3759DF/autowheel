//You need to program this file.

#include "../NoEdit/VisualizationMono_Processor_PathGenerator_PrivFunc.h"
#include "controlvis.h"
//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...
inline double dist(double x1, double y1, double x2, double y2) {
    return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1-y2);}

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMono_Processor_PathGenerator_Params * params=(VisualizationMono_Processor_PathGenerator_Params *)paramsPtr;
	VisualizationMono_Processor_PathGenerator_Vars * vars=(VisualizationMono_Processor_PathGenerator_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader, vars, offlineTrajecPath);
    GetParamValue(xmlloader, vars, offlineTrajecFilename);
    FILE *fp = fopen((vars->offlineTrajecPath+vars->offlineTrajecFilename).toStdString().c_str(), "r");
    double ox, oy, oth;
    while (fscanf(fp, "%lf %lf %lf", &ox, &oy, &oth) == 3)
    {
        trajec_state tmp = {ox, oy, oth, 0};
        vars->offlinetrajec.push_back(tmp);
    }
    fclose(fp);

    vars->glviewer->makeCurrent();
    vars->glviewer->setBackground(QColor(241,241,241));

    vars->glviewer->clearDisplayList();
    vars->displaylistbase = glGenLists(vars->shownum);
    int i;
    for(i=0; i<vars->shownum; i++)
        vars->glviewer->addDisplayList(vars->displaylistbase + i);
    vars->lastPos.x = vars->lastPos.y = 0;

	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMono_Processor_PathGenerator_Params * params=(VisualizationMono_Processor_PathGenerator_Params *)paramsPtr;
	VisualizationMono_Processor_PathGenerator_Vars * vars=(VisualizationMono_Processor_PathGenerator_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->glviewer->clearDisplayList();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMono_Processor_PathGenerator_Params * params=(VisualizationMono_Processor_PathGenerator_Params *)paramsPtr;
	VisualizationMono_Processor_PathGenerator_Vars * vars=(VisualizationMono_Processor_PathGenerator_Vars *)varsPtr;
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
	VisualizationMono_Processor_PathGenerator_Params * params=(VisualizationMono_Processor_PathGenerator_Params *)paramsPtr;
	VisualizationMono_Processor_PathGenerator_Vars * vars=(VisualizationMono_Processor_PathGenerator_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 10, Params_Type = ProcessorMulti_Processor_PathGenerator_Params, Data_Type = ProcessorMulti_Processor_PathGenerator_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	VisualizationMono_Processor_PathGenerator_Params * params=(VisualizationMono_Processor_PathGenerator_Params *)paramsPtr;
	VisualizationMono_Processor_PathGenerator_Vars * vars=(VisualizationMono_Processor_PathGenerator_Vars *)varsPtr;
	QVector<ProcessorMulti_Processor_PathGenerator_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<ProcessorMulti_Processor_PathGenerator_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
    ProcessorMulti_Processor_PathGenerator_Data* drawdata = draindata.front();

    vars->indexLabel->setText(QString::number(drawdata->index) + " " + QString::number(drawdata->timestamp));
    glNewList(vars->displaylistbase,GL_COMPILE_AND_EXECUTE);
    glTranslatef(0, 0, -10);

    drawWheelchair(drawdata->startPoint);


    //draw offline trajectory
    glLineWidth(1);
    glColor3f(0.6,0.6,0);
    glBegin(GL_LINE_STRIP);
    for(int i=0; i<vars->offlinetrajec.size(); i++)
    {
        glVertex3f(vars->offlinetrajec[i].x, vars->offlinetrajec[i].y, 0);
    }
    glEnd();

    //draw map
    glColor3f(0, 0, 0);
    glPointSize(1);
    glBegin(GL_POINTS);
    for (int i = 0; i < 1600; i++) {
        for (int j = 0; j < 1600; j++) {
            if (vars->map[i][j] > 0) {
                glVertex3f((i - vars->offsetx) / 10.0, (j - vars->offsety) / 10.0, 0);
            }
        }
    }
    glEnd();

    //  laser point
    glColor3f(1, 0, 0);
    glPointSize(1.5);
    glBegin(GL_POINTS);
    cout << drawdata->URGData_size << endl;
    for (int i = 0; i < drawdata->URGData_size; i++) {
        if (drawdata->urg_valid[0][i]) {
            double lx = drawdata->urg_data_point[0][i][0];
            double ly = drawdata->urg_data_point[0][i][1];
            glVertex3f(lx, ly, 0);
        }
        if (drawdata->urg_valid[1][i]) {
            double rx = drawdata->urg_data_point[1][i][0];
            double ry = drawdata->urg_data_point[1][i][1];
            glVertex3f(rx, ry, 0);
        }
    }
    glEnd();

    for (int i = 0; i < drawdata->URGData_size; i++) {
        if (drawdata->urg_valid[0][i]) {
            double lx = drawdata->urg_data_point[0][i][0];
            double ly = drawdata->urg_data_point[0][i][1];
            int gridx = int(lx * 10);
            int gridy = int(ly * 10);
            vars->map[gridx + vars->offsetx][gridy + vars->offsety] = 1;
        }
        if (drawdata->urg_valid[1][i]) {
            double rx = drawdata->urg_data_point[1][i][0];
            double ry = drawdata->urg_data_point[1][i][1];
            int gridx = int(rx * 10);
            int gridy = int(ry * 10);
            vars->map[gridx + vars->offsetx][gridy + vars->offsety] = 1;
        }
    }

    //draw online trajectory
    if(dist(drawdata->startPoint.x,drawdata->startPoint.y, vars->lastPos.x, vars->lastPos.y)>1e-4)
    {
        vars->onlinetrajec.push_back(cv::Point2d(drawdata->startPoint.x,drawdata->startPoint.y));
    }
    glLineWidth(3);
    glColor3f(0,0,1);
    glBegin(GL_LINES);
    for(int i=0; i<vars->onlinetrajec.size();i++)
    {
         glVertex3f(vars->onlinetrajec[i].x, vars->onlinetrajec[i].y, 0);
    }
    glEnd();

    if (!drawdata->stop) {

        glColor3f(0, 1, 0);
        glLineWidth(1);
        for(int i=0; i < drawdata->trajSets.size();i++)
        {
            glBegin(GL_LINE_STRIP);
            for(int j=0; j < drawdata->trajSets[i].trajdat.size(); j++)
            {
                glVertex3f(drawdata->trajSets[i].trajdat[j].x, drawdata->trajSets[i].trajdat[j].y, 0);
            }
            glEnd();
        }

        glLineWidth(3);
        if (drawdata->trajSets[drawdata->index].valid) {
            glColor3f(1, 0, 0);
        } else {
            glColor3f(0, 0, 0);
        }
        glBegin(GL_LINE_STRIP);
        for(int i=0; i<drawdata->trajSets[drawdata->index].trajdat.size(); i++)
        {
            glVertex3f(drawdata->trajSets[drawdata->index].trajdat[i].x, drawdata->trajSets[drawdata->index].trajdat[i].y, 0);
        }
        glEnd();

        //draw target point
//        glPointSize(6);
//        glColor3f(0,0.3,0);
//        glBegin(GL_POINTS);
//        glVertex3f(drawdata->targetPoint.x, drawdata->targetPoint.y, 0);
//        glEnd();
    }

    glEndList();


    Eigen::Matrix4d CameraPos = vars->glviewer->getCameraPose();

    double dx = drawdata->startPoint.x - vars->lastPos.x;
    double dy = drawdata->startPoint.y  - vars->lastPos.y;


    vars->lastPos = cv::Point2f(drawdata->startPoint.x, drawdata->startPoint.y);

    cout << dx << ' ' << dy << endl;
    CameraPos(0,3) += dx;
    CameraPos(1,3) += dy;

    vars->glviewer->setCameraPose(CameraPos);

//    vars->glviewer->makeCurrent();
    vars->glviewer->update();
	return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMono_Processor_PathGenerator_Params * params=(VisualizationMono_Processor_PathGenerator_Params *)paramsPtr;
	VisualizationMono_Processor_PathGenerator_Vars * vars=(VisualizationMono_Processor_PathGenerator_Vars *)varsPtr;

    widgets=QList<QWidget *>()<<(vars->glviewer) << (vars->indexLabel);
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

