
#include "control.h"

void generateControlCmd(ProcessorMulti_Processor_Control_Vars* vars,
                        double sx, double sy,
                        double hx, double hy,
                        double tx, double ty)
{
    double vec_x = tx - sx;
    double vec_y = ty - sy;
    double cos_theta = (vec_x*hx + vec_y*hy)/(sqrt(hx*hx+hy*hy)*sqrt(vec_x*vec_x+vec_y*vec_y) + 1e-10);

    if(cos_theta < 0 )//
    {
        if((hx>0 && vec_x < 0 && vec_y<0) || (hx<0 && vec_x > 0 && vec_y>0)) //第三象限，向左转
        {
            vars->left_vel = -vars->targetSpeed/2;
            vars->right_vel = vars->targetSpeed/2;
            return;
        }
        else
        {
            vars->left_vel = vars->targetSpeed/2;
            vars->right_vel = -vars->targetSpeed/2;
            return;
        }
    }

    double sin_theta = sqrt(1-cos_theta*cos_theta);

    //left or right: left:-, right:+
    if ( hx <1E-8 && hx > -1E-8 ) {
        if ( ( hy > 0 && vec_x < 0 ) || ( hy < 0  && vec_x > 0 ) )
            sin_theta = -1*sin_theta ;
    }
    else {
        double a = hy / hx ;
        if ( ( hx > 0 && (a*vec_x - vec_y) < 0 ) || ( hx < 0 && (a*vec_x - vec_y) > 0 ) )
            sin_theta = -1*sin_theta ;
    }

    double d = sqrt(vec_x*vec_x+vec_y*vec_y + 1e-10);

//    if(d < 0.8)
//    {//已到达
//        vars->left_vel = vars->right_vel = 0;
//        return;
//    }

    double curvature = 2*sin_theta/d;

    double angularVel = vars->targetSpeed*curvature*vars->KpAngle; //4.5 ok

    vars->left_vel = vars->targetSpeed + angularVel*vars->WheelBase/2;
    vars->right_vel = vars->targetSpeed - angularVel*vars->WheelBase/2;
}
