#include "EnvRender.h"
#include <GL/glu.h>
#include <QKeyEvent>

EnvRender::EnvRender(QWidget *parent)
    : QGLWidget(parent)
{

    offset_x = default_x;
    offset_y = default_y;
    offset_z = default_z;
    z_near = 1.0;
    z_far = 500;
    bkColor_r = bkColor_g = bkColor_b = 1.0;

    sketchMapPath = "sketchMap.txt";
    offlineTrajPath = "line.txt";

    this->grabKeyboard();

    isInit = 0;

}
EnvRender::EnvRender(QString SketchPath, QString OfflinePath,
                     QWidget *parent) : QGLWidget(parent)
{
    offset_x = default_x;
    offset_y = default_y;
    offset_z = default_z;
    z_near = 1.0;
    z_far = 500;
    bkColor_r = bkColor_g = bkColor_b = 1.0;

    sketchMapPath = SketchPath;
    offlineTrajPath = OfflinePath;

    this->grabKeyboard();
    isInit = 0;

}

void EnvRender::initializeGL()
{
    glEnable( GL_DEPTH );
    glFrontFace( GL_CW );
    glEnable( GL_CULL_FACE );
    glShadeModel( GL_FLAT );

}

void EnvRender::initEnv()
{
    this->makeCurrent();
    m_list[MapID] = glGenLists(ListCount);
    m_list[OfflineID] = m_list[MapID]+1;
    m_list[CarID] = m_list[MapID]+2;

    drawCar();
    drawMap(sketchMapPath);
    drawOfflineTraj(offlineTrajPath);

    isInit = 1;
    update();
}

void EnvRender::resizeGL(int w, int h)
{
    // 此函数只在窗口创建的时候调用，因为窗口大小设为固定的了
    // 设置视口
    glViewport( 0, 0, w, h );
    // 设置投影矩阵
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    gluPerspective( 10.0,                       // 视野角度
                    double( w ) / double( h ),// 宽高比
                    z_near,                        // 近裁面z值
                    z_far );                   // 远裁面z值

    // 转为模型/视图矩阵
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
}

void EnvRender:: paintEvent( QPaintEvent *event )
{
//drawImage();
////调用下面代码后，就不能调用drawImage画图片了
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(bkColor_r, bkColor_g, bkColor_b, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
////
    if(!isInit)
    {
        qglColor(Qt::red);
        glPushMatrix();
        glTranslated(0, 0, offset_z);
        renderText(0,0,0, "No Init");
        glPopMatrix();
        swapBuffers();
        update( );
        return;
    }
    glPushMatrix( );
    glTranslated(offset_x, offset_y, offset_z);
    glRotatef(-90.0, 0,0,1);

    glCallList(m_list[MapID]);
    glCallList(m_list[OfflineID]);
    glCallList(m_list[CarID]);

    glPopMatrix();
    swapBuffers();
    update( );

}

void EnvRender::keyPressEvent(QKeyEvent* event)
{
    switch(event->key())
    {
    case Qt::Key_Up:
        offset_y += skip_y;
        break;
    case Qt::Key_Down:
        offset_y -= skip_y;
        break;
    case Qt::Key_Left:
        offset_x -= skip_x;
        break;
    case Qt::Key_Right:
        offset_x += skip_x;
        break;
    case Qt::Key_PageUp:
        offset_z += skip_z;
        break;
    case Qt::Key_PageDown:
        offset_z -= skip_z;
        break;
    case Qt::Key_Home:
        offset_x = default_x;
        offset_y = default_y;
        offset_z = default_z;
        break;
    }
    this->update();
}

void EnvRender::setOfflineTraj(const QVector<Point2D> &data)
{
//    Point2D tmp;
//    for(int i=0; i<data.size(); i++)
//    {
//        tmp = data[i];
//        this->offlineTraj.push_back(tmp);
//    }

}

void EnvRender::setBackgroundColor(QColor color)
{
    bkColor_r = color.redF()/255.0;
    bkColor_g = color.greenF()/255.0;
    bkColor_b = color.blueF()/255.0;
}

void EnvRender::drawImage()
{
//    QPainter painter(this);
//    painter.drawPixmap(40,40, m_mapImage);
}

