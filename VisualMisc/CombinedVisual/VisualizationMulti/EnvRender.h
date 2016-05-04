#ifndef MYGLDRAWER_H
#define MYGLDRAWER_H

#include <QtOpenGL/QGLWidget>
#include <QPixmap>
struct Point2D
{
    double x,y;
    Point2D(){x=y=0;}
    Point2D(double xx, double yy)
    {
        x = xx;
        y = yy;
    }
};



class EnvRender : public QGLWidget
{
public:
    EnvRender(QString SketchPath, QString OfflinePath, QWidget *parent = 0);
    EnvRender(QWidget *parent = 0);

public:
    void drawImage();
    void loadImage(QString path);
    void setBackgroundColor(QColor color);
    void setSketchMapPath(QString path);
    void setOfflineTrajPath(QString path);
    void setOfflineTraj(const QVector<Point2D> & data);
protected:

    void initializeGL();

    void resizeGL(int w, int h);

    void paintEvent( QPaintEvent *event );

    void keyPressEvent(QKeyEvent *event);

private:
    double offset_x;
    double offset_y;
    double offset_z;
    double z_near, z_far;
    double bkColor_r, bkColor_g, bkColor_b;
    enum  {default_x = -20, default_y=0, default_z= -170};
    enum  {skip_x = 3, skip_y=3, skip_z=10};
    enum  {MapID=0, OfflineID, CarID,ListCount};
private:
     GLuint m_list[ListCount];
     bool isInit;
     QString sketchMapPath, offlineTrajPath;
public:
     void initEnv();
     void drawCar();
     void drawMap(QString path);
     void drawOfflineTraj(QString path);

};

#endif // MYGLDRAWER_H
