#include "EnvRender.h"
#include <fstream>
using namespace  std ;

void EnvRender::setSketchMapPath(QString path)
{
    this->sketchMapPath = path;
}

void EnvRender::setOfflineTrajPath(QString path)
{
    this->offlineTrajPath = path;
}

void EnvRender::drawCar()
{
    double wheelbase = 0.64, borderWidth=1.0, borderHeight=1.4;
    double carLength = 1;

    Point2D leftup(-borderWidth/2, borderHeight);
    Point2D leftbottom(-borderWidth/2, 0);
    Point2D rightbottom(borderWidth/2, 0);
    Point2D rightup(borderWidth/2, borderHeight);

    double tt = (borderHeight-carLength)/2.0;

    Point2D leftwheel(wheelbase/2.0, tt);
    Point2D rightwheel(-wheelbase/2.0,tt);

    Point2D carFrontPt(0, carLength);

    glNewList(m_list[CarID], GL_COMPILE);
    qglColor( Qt::red);
    glLineWidth(2);
    glBegin(GL_LINES);//draw rectangle
        glVertex3f(leftup.x, leftup.y, 0); glVertex3f(leftbottom.x, leftbottom.y, 0);
        glVertex3f(rightbottom.x, rightbottom.y, 0); glVertex3f(rightup.x, rightup.y, 0);
        glVertex3f(leftup.x, leftup.y, 0);glVertex3f(rightup.x, rightup.y, 0);
        glVertex3f(leftbottom.x, leftbottom.y, 0); glVertex3f(rightbottom.x, rightbottom.y, 0);
    glEnd();

    glColor3f(0,0,1);
    glPointSize(3);
    glBegin(GL_POINTS);
        glVertex3f(leftwheel.x, leftwheel.y, 0);
        glVertex3f(rightwheel.x, rightwheel.y, 0);
        glVertex3f(carFrontPt.x, carFrontPt.y, 0);
    glEnd();
    glEndList();
}

void EnvRender::drawMap(QString path)
{
    Point2D tmp;
    ifstream file;
    QVector<Point2D> sketchMap;
    file.open(path.toStdString().c_str());
    while(!file.eof())
    {
        file>>tmp.x>>tmp.y;
        sketchMap.push_back(tmp);
    }
    file.close();

    //缓存离线地图
    glNewList(m_list[MapID], GL_COMPILE);
    qglColor( Qt::black);
    glPointSize(2);
    glBegin(GL_POINTS);
    for(int i=0; i<sketchMap.size(); i++)
    {
        glVertex3d(sketchMap[i].x, sketchMap[i].y, 0);
    }
    glEnd();
    glEndList();
}

void EnvRender::drawOfflineTraj(QString path)
{
    Point2D tmp;
    ifstream file;
    QVector<Point2D> offlineTraj;
    file.open(path.toStdString().c_str());
    double theta;
    while (!file.eof())
    {
        file>>tmp.x>>tmp.y>>theta;
        offlineTraj.push_back(tmp);
    }
    file.close();

    //缓存离线轨迹
    glNewList(m_list[OfflineID], GL_COMPILE);
    qglColor( Qt::blue);
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    for(int i=0; i<offlineTraj.size(); i++)
    {
        glVertex3d(offlineTraj[i].x, offlineTraj[i].y, 0);
    }
    glEnd();
    glEndList();
}

