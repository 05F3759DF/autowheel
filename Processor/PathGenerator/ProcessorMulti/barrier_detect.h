#ifndef BARRIER_DETECT
#define BARRIER_DETECT

#include "../ProcessorMulti/NoEdit/ProcessorMulti_Processor_PathGenerator_PrivFunc.h"
QVector<cv::Point2f> colli_detect(ProcessorMono_Processor_EvaluateFunction_Data *evaluate, SensorTimer_Localization_Slam_Data *slam, double front_center_x, double front_center_y, double back_center_x, double back_center_y, double size);
int path_exclude(QVector<cv::Point2f> & barrier_point,  QVector<ONETRAJDATA > & trajSets);
int getValidTrajNum(QVector<ONETRAJDATA > & trajSets);
int getNearestTraj(QVector<ONETRAJDATA > & trajSets, int ref_index);
double calcTrajSumCost(QVector<ONETRAJDATA > & trajSets, int &trajNum);
#define lms_l_start 0
#define lms_l_end 260
#define lms_r_start 100
#define lms_r_end 360

#define half_width_for_colli_detect  0.5

#endif // BARRIER_DETECT

