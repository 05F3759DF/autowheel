
#include "controlvis.h"
#include "glviewer.h"
#include "opencv2/opencv.hpp"
#include <Eigen/Dense>
void drawWheelchair(const trajec_state& currentPos)
{
    double wheelbase = 0.64, borderWidth=1.0, borderHeight=1.4;
    double wheelRadius = 0.3, carLength = 1;

    Eigen::Vector2d leftup(-borderWidth/2, borderHeight);
    Eigen::Vector2d leftbottom(-borderWidth/2, 0);
    Eigen::Vector2d rightbottom(borderWidth/2, 0);
    Eigen::Vector2d rightup(borderWidth/2, borderHeight);

    double tt = (borderHeight-carLength)/2.0;

    Eigen::Vector2d leftwheel(wheelbase/2.0, tt);
    Eigen::Vector2d rightwheel(-wheelbase/2.0,tt);

    Eigen::Vector2d carFrontPt(0, carLength);

    Eigen::Vector2d translate (currentPos.x, currentPos.y);


    double theta = currentPos.theta - PI/2 ;//+ PI/2;

    Eigen::Matrix2d rotate;
    rotate<<cos(theta), -sin(theta),
       sin(theta), cos(theta);

    Eigen::Vector2d temp = rotate*leftup + translate;
    leftup = temp;

    temp = rotate*leftbottom + translate;
    leftbottom = temp;

    temp = rotate*rightbottom + translate;
    rightbottom = temp;

    temp = rotate*rightup + translate;
    rightup = temp;

    temp = rotate*leftwheel + translate;
    leftwheel = temp;

    temp = rotate*rightwheel + translate;
    rightwheel = temp;

    temp = rotate*carFrontPt + translate;
    carFrontPt = temp;

    glColor3f(0.3,0,0);
    glLineWidth(2);
    glBegin(GL_LINES);//draw rectangle
        glVertex3f(leftup(0), leftup(1), 0); glVertex3f(leftbottom(0), leftbottom(1), 0);
        glVertex3f(rightbottom(0), rightbottom(1), 0); glVertex3f(rightup(0), rightup(1), 0);
        glVertex3f(leftup(0), leftup(1), 0);glVertex3f(rightup(0), rightup(1), 0);
        glVertex3f(leftbottom(0), leftbottom(1), 0); glVertex3f(rightbottom(0), rightbottom(1), 0);
    glEnd();

    glColor3f(0,0,1);
    glPointSize(3);
    glBegin(GL_POINTS);
        glVertex3f(leftwheel(0), leftwheel(1), 0);
        glVertex3f(rightwheel(0), rightwheel(1), 0);
        glVertex3f(carFrontPt(0), carFrontPt(1), 0);

        glColor3f(1,0,0);
        glVertex3f(currentPos.x, currentPos.y, 0);//draw current position
    glEnd();





}
