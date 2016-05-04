#include "barrier_detect.h"


int is_in_colli_detect_range(double x, double y, double front_center_x, double front_center_y, double back_center_x, double back_center_y, double size)//椭圆
{
    if( DISTANCE_2(x-front_center_x,y-front_center_y)+DISTANCE_2(x-back_center_x,y-back_center_y) < size )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



QVector<cv::Point2f> colli_detect(ProcessorMono_Processor_EvaluateFunction_Data *evaluate, SensorTimer_Localization_Slam_Data *slam, double front_center_x, double front_center_y, double back_center_x, double back_center_y,double size)
{

    QVector<cv::Point2f>output;
    //直线碰撞检测
    cv::Point2f temp_point;
    for (int i = lms_l_start, j = lms_r_start; i < lms_l_end && j < lms_r_end;)
    {
//        if(DISTANCE_2(evaluate->urg_data_point[0][i][0]-referencePoint_x,evaluate->urg_data_point[0][i][1]-referencePoint_y) < 0.4)//hu lve 0.4m yi nei de dian
//        {
//            i++;
//            continue;
//        }
//        else if(DISTANCE_2(evaluate->urg_data_point[1][j][0]-referencePoint_x,evaluate->urg_data_point[1][j][1]-referencePoint_y) < 0.4)//hu lve 0.4m yi nei de dian
//        {
//            j++;
//            continue;
//        }

 //       if(DISTANCE_2(evaluate->urg_data_point[0][i][0]-referencePoint_x,evaluate->urg_data_point[0][i][1]-referencePoint_y) < min_dis_to_barrier)//
       if(is_in_colli_detect_range(evaluate->urg_data_point[0][i][0],evaluate->urg_data_point[0][i][1],front_center_x,front_center_y,back_center_x,back_center_y,size))//长轴2.5m
        {
            temp_point.x = evaluate->urg_data_point[0][i][0];
            temp_point.y = evaluate->urg_data_point[0][i][1];
            output.push_back(temp_point);
        }
 //       if(DISTANCE_2(evaluate->urg_data_point[1][j][0]-referencePoint_x,evaluate->urg_data_point[1][j][1]-referencePoint_y) < min_dis_to_barrier)//
        if(is_in_colli_detect_range(evaluate->urg_data_point[1][j][0],evaluate->urg_data_point[1][j][1],front_center_x,front_center_y,back_center_x,back_center_y,size))
        {
            temp_point.x = evaluate->urg_data_point[1][j][0];
            temp_point.y = evaluate->urg_data_point[1][j][1];
            output.push_back(temp_point);
        }
        i++;
        j++;

    }
    return output;
}

int path_exclude(QVector<cv::Point2f> & barrier_point,  QVector<ONETRAJDATA > & trajSets)
{
    int is_blocked;
    double dis;
    for(int i = 0; i < trajSets.size(); i++)
    {
        is_blocked = 0;
//        if(trajSets[i].valid)
        {
            for(int j = 0; j < trajSets[i].trajdat.size(); j++)
            {
                for(int k = 0; k < barrier_point.size(); k++)
                {
                    dis = DISTANCE_2(trajSets[i].trajdat[j].x - barrier_point[k].x , trajSets[i].trajdat[j].y - barrier_point[k].y);
                    if(dis < half_width_for_colli_detect && dis > 0.05 )
                    {
                        is_blocked ++;
                    }
                }
            }
            if(is_blocked > 3)
            {
                trajSets[i].valid = false;
            }
            else
            {
                trajSets[i].valid = true;
            }
        }

    }
    return 1;
}

int getValidTrajNum(QVector<ONETRAJDATA > & trajSets)
{
    int num = 0;
    for(int i=0; i< trajSets.size(); i++)
    {
        if(trajSets[i].valid)
            num++;
    }
    return num;
}

int getNearestTraj(QVector<ONETRAJDATA > & trajSets, int ref_index)
{
    int validLowIndex, validHighIndex;
    validLowIndex = validHighIndex = ref_index;
    if(!trajSets[ref_index].valid)//如果评估模块给出的轨迹不可用，那就找最近的一条可用轨迹
    {
        int i, j;
        for(i=validLowIndex-1; i>=0; i--)
        {
            if(trajSets[i].valid)
                break;
        }
        for(j=validHighIndex+1; j<trajSets.size(); j++)
        {
            if(trajSets[j].valid)
                break;
        }
        if(i>=0 || j<trajSets.size())//确定是否有可用轨迹
        {
            if(((ref_index - i) < (j - ref_index)) && (i>=0))
                return i;
            else
                return j;
        }
    }
    return ref_index;
}

double calcTrajSumCost(QVector<ONETRAJDATA > & trajSets, int& trajNum)
{
    trajNum = 0;
    double averageCost = 0.0;
    for(int k=0; k< trajSets.size(); k++)
    {
        int size = trajSets[k].trajdat.size();
        ONETRAJDATA trajdat = trajSets[k];
        bool isInit = 0;
        double tempcost = 0, offsetcost=0;

        if(size < 3)
        {
            trajSets[k].cost = INT_MAX;
            trajSets[k].valid = false;
            continue;
        }

        for(int i=0; i<size; i++)
        {
            if(isInit==0)
            {
                tempcost = fabs(atan2(trajdat.trajdat[1].y - trajdat.trajdat[0].y,trajdat.trajdat[1].x - trajdat.trajdat[0].x));
                offsetcost = tempcost;
                isInit = 1;
                continue;
            }

            tempcost = fabs(atan2((trajdat.trajdat[i].y - trajdat.trajdat[i-1].y),(trajdat.trajdat[i].x - trajdat.trajdat[i-1].x)));

            trajSets[k].cost += fabs(tempcost - offsetcost);
        }

        averageCost += trajSets[k].cost;
        trajNum++;
    }
    return averageCost;
}


