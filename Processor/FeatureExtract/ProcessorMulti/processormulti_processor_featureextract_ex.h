#ifndef PROCESSORMULTI_PROCESSOR_FEATUREEXTRACT_EX_H
#define PROCESSORMULTI_PROCESSOR_FEATUREEXTRACT_EX_H



#include<iostream>
#include<string>
#include <fstream>
#include<math.h>
#include<qvector.h>
#include <QPointF>
#include <QImage>
#include <opencv2/opencv.hpp>
#include<qmath.h>
using namespace cv;
#define DISTANCE_2(a,b) sqrt((a)*(a)+(b)*(b))

#define Qtime2time(a) ((((a).hour()*60 + (a).minute())*60  + (a).second()) *1000 + a.msec());

#define SIZE_OF_FEATURE 50	//¿ÉÐÞžÄ
#define A_BIG_NUMBER 99999999.0

#define nav_shift_f	0.68
#define nav_shift_s	0.29
#define lms_shift_from_rlms_2_llms (1.95/180*3.141592653589793)  //you ji guang he zuo ji guang de jiao du pian cha(rad)
#define door_detect_min_dis 1 //men jian ce yu zhi
#define door_detect_max_dis_to_wheelchair 20 // 5m
#define door_detect_max_dis_to_wheelchair_meter 5
#define must_be_an_open_door 3 //3m
#define judge_range_of_a_door 0.5

#define min_dis_to_barrier  1.8//1m

struct _feature{
    long timestamp;
    double data[SIZE_OF_FEATURE];
    _feature(){
        timestamp = 0;
        for(int i = 0; i < SIZE_OF_FEATURE; i++)
            data[i] = A_BIG_NUMBER;
    }
};

class _lms_gap{
public:
    cv::Point2d p1;
    cv::Point2d p2;
    _lms_gap(){;}
    _lms_gap(double x1,double y1,double x2, double y2){p1 = cv::Point2d(x1,y1);p2 = cv::Point2d(x2,y2);}
};


class Line
{
public:
    Line()
    {
        start.x = start.y=end.x=end.y=0;
    }
    Line(const cv::Point2d& start,const cv::Point2d& end)
    {
        this->start = start;
        this->end = end;
        calcCoefficient();
    }
    double getDistFromPoint(const cv::Point2d& pt)
    {
        if(abs(k) > 1e7)
            return abs(pt.x-start.x);
        else
        {
            double dist = abs(pt.y-k*pt.x-b)/sqrt(1+k*k);
            return dist;
        }
    }
    void calcCoefficient()
    {
        k = (start.y - end.y)/(start.x - end.x + 1e-8);
        b = start.y - k*start.x;
    }
    cv::Point2d start, end;
private:
    bool flag;
    double k,b;
};


struct _line{//Œ«×ø±ê
    double a;
    double b;
    double c;
    cv::Point2d p_start;
    cv::Point2d p_end;
    _line(){a = 0; b = 0; c = 0;p_start.x = 0; p_start.y = 0;p_end.x = 0; p_end.y = 0;}
    _line(cv::Point2d p1, cv::Point2d p2){p_start = p1; p_end = p2; a = p2.y - p1.y; b = p1.x - p2.x; c = p1.x*(p1.y - p2.y)+p1.y*(p2.x - p1.x);}
    double Dis_point2line(double x, double y){return fabs(a*x+b*y+c)/sqrt(a*a+b*b);}
    double Dis_point2line_signed(double x, double y){return (a*x+b*y+c)/sqrt(a*a+b*b);}
};

#define Dis_2D(x1,y1,x2,y2) (sqrt(((x1)-(x2))*((x1)-(x2))+((y1)-(y2))*((y1)-(y2))))
#define A_SMALL_DIS	0.1

/*
_point point_shift(_point point_data_src, _point wheel_position, double wheel_theta)//ÂÖÒÎÏîÄ¿ÓÃ£¬È«ŸÖ×ø±ê»»ËãŸÖ²¿Ëù±ê
{
    _point point_data_item;

    point_data_item.x = (point_data_src.x - wheel_position.x)*cos(wheel_theta) + (point_data_src.y - wheel_position.y)*sin(wheel_theta);
    point_data_item.y = (point_data_src.y - wheel_position.y)*cos(wheel_theta) - (point_data_src.x - wheel_position.x)*sin(wheel_theta);

    return point_data_item;
}*/

int point_shift(QVector<cv::Point2d> & point_data_src, cv::Point2d wheel_position, double wheel_theta, QVector<cv::Point2d> &  point_data_drc);//ÂÖÒÎÏîÄ¿ÓÃ£¬È«ŸÖ×ø±ê»»ËãŸÖ²¿Ëù±ê
int wall_point_shift(QVector<_line> & point_data_src, cv::Point2d wheel_position, double wheel_theta, QVector<_line> & point_data_drc);//ÂÖÒÎÏîÄ¿ÓÃ£¬È«ŸÖ×ø±ê»»ËãŸÖ²¿Ëù±ê
cv::Point2i world2image(cv::Point2d worldcoord, const cv::Point2i & originPoint,
                        const double pixelsize, const cv::Mat & image);
QPointF world2image(QPointF worldcoord, const QPointF & originPoint,
                        const double pixelsize, const QImage & image);
cv::Point2d image2world(cv::Point2d imagecoord, const cv::Point2i & originPoint,
                        const double pixelsize, const cv::Mat & image);

//ÉñÆæµÄ
#define CV_IMPLEMENT_QSORT_EX( func_name, T, LT, user_data_type )                   \
void func_name( T *array, size_t total, user_data_type aux )                        \
{                                                                                   \
    int isort_thresh = 7;                                                           \
    T t;                                                                            \
    int sp = 0;                                                                     \
                                                                                    \
    struct                                                                          \
    {                                                                               \
        T *lb;                                                                      \
        T *ub;                                                                      \
    }                                                                               \
    stack[48];                                                                      \
                                                                                    \
    aux = aux;                                                                      \
                                                                                    \
    if( total <= 1 )                                                                \
        return;                                                                     \
                                                                                    \
    stack[0].lb = array;                                                            \
    stack[0].ub = array + (total - 1);                                              \
                                                                                    \
    while( sp >= 0 )                                                                \
    {                                                                               \
        T* left = stack[sp].lb;                                                     \
        T* right = stack[sp--].ub;                                                  \
                                                                                    \
        for(;;)                                                                     \
        {                                                                           \
            int i, n = (int)(right - left) + 1, m;                                  \
            T* ptr;                                                                 \
            T* ptr2;                                                                \
                                                                                    \
            if( n <= isort_thresh )                                                 \
            {                                                                       \
            insert_sort:                                                            \
                for( ptr = left + 1; ptr <= right; ptr++ )                          \
                {                                                                   \
                    for( ptr2 = ptr; ptr2 > left && LT(ptr2[0],ptr2[-1]); ptr2--)   \
                        CV_SWAP( ptr2[0], ptr2[-1], t );                            \
                }                                                                   \
                break;                                                              \
            }                                                                       \
            else                                                                    \
            {                                                                       \
                T* left0;                                                           \
                T* left1;                                                           \
                T* right0;                                                          \
                T* right1;                                                          \
                T* pivot;                                                           \
                T* a;                                                               \
                T* b;                                                               \
                T* c;                                                               \
                int swap_cnt = 0;                                                   \
                                                                                    \
                left0 = left;                                                       \
                right0 = right;                                                     \
                pivot = left + (n/2);                                               \
                                                                                    \
                if( n > 40 )                                                        \
                {                                                                   \
                    int d = n / 8;                                                  \
                    a = left, b = left + d, c = left + 2*d;                         \
                    left = LT(*a, *b) ? (LT(*b, *c) ? b : (LT(*a, *c) ? c : a))     \
                                      : (LT(*c, *b) ? b : (LT(*a, *c) ? a : c));    \
                                                                                    \
                    a = pivot - d, b = pivot, c = pivot + d;                        \
                    pivot = LT(*a, *b) ? (LT(*b, *c) ? b : (LT(*a, *c) ? c : a))    \
                                      : (LT(*c, *b) ? b : (LT(*a, *c) ? a : c));    \
                                                                                    \
                    a = right - 2*d, b = right - d, c = right;                      \
                    right = LT(*a, *b) ? (LT(*b, *c) ? b : (LT(*a, *c) ? c : a))    \
                                      : (LT(*c, *b) ? b : (LT(*a, *c) ? a : c));    \
                }                                                                   \
                                                                                    \
                a = left, b = pivot, c = right;                                     \
                pivot = LT(*a, *b) ? (LT(*b, *c) ? b : (LT(*a, *c) ? c : a))        \
                                   : (LT(*c, *b) ? b : (LT(*a, *c) ? a : c));       \
                if( pivot != left0 )                                                \
                {                                                                   \
                    CV_SWAP( *pivot, *left0, t );                                   \
                    pivot = left0;                                                  \
                }                                                                   \
                left = left1 = left0 + 1;                                           \
                right = right1 = right0;                                            \
                                                                                    \
                for(;;)                                                             \
                {                                                                   \
                    while( left <= right && !LT(*pivot, *left) )                    \
                    {                                                               \
                        if( !LT(*left, *pivot) )                                    \
                        {                                                           \
                            if( left > left1 )                                      \
                                CV_SWAP( *left1, *left, t );                        \
                            swap_cnt = 1;                                           \
                            left1++;                                                \
                        }                                                           \
                        left++;                                                     \
                    }                                                               \
                                                                                    \
                    while( left <= right && !LT(*right, *pivot) )                   \
                    {                                                               \
                        if( !LT(*pivot, *right) )                                   \
                        {                                                           \
                            if( right < right1 )                                    \
                                CV_SWAP( *right1, *right, t );                      \
                            swap_cnt = 1;                                           \
                            right1--;                                               \
                        }                                                           \
                        right--;                                                    \
                    }                                                               \
                                                                                    \
                    if( left > right )                                              \
                        break;                                                      \
                    CV_SWAP( *left, *right, t );                                    \
                    swap_cnt = 1;                                                   \
                    left++;                                                         \
                    right--;                                                        \
                }                                                                   \
                                                                                    \
                if( swap_cnt == 0 )                                                 \
                {                                                                   \
                    left = left0, right = right0;                                   \
                    goto insert_sort;                                               \
                }                                                                   \
                                                                                    \
                n = MIN( (int)(left1 - left0), (int)(left - left1) );               \
                for( i = 0; i < n; i++ )                                            \
                    CV_SWAP( left0[i], left[i-n], t );                              \
                                                                                    \
                n = MIN( (int)(right0 - right1), (int)(right1 - right) );           \
                for( i = 0; i < n; i++ )                                            \
                    CV_SWAP( left[i], right0[i-n+1], t );                           \
                n = (int)(left - left1);                                            \
                m = (int)(right1 - right);                                          \
                if( n > 1 )                                                         \
                {                                                                   \
                    if( m > 1 )                                                     \
                    {                                                               \
                        if( n > m )                                                 \
                        {                                                           \
                            stack[++sp].lb = left0;                                 \
                            stack[sp].ub = left0 + n - 1;                           \
                            left = right0 - m + 1, right = right0;                  \
                        }                                                           \
                        else                                                        \
                        {                                                           \
                            stack[++sp].lb = right0 - m + 1;                        \
                            stack[sp].ub = right0;                                  \
                            left = left0, right = left0 + n - 1;                    \
                        }                                                           \
                    }                                                               \
                    else                                                            \
                        left = left0, right = left0 + n - 1;                        \
                }                                                                   \
                else if( m > 1 )                                                    \
                    left = right0 - m + 1, right = right0;                          \
                else                                                                \
                    break;                                                          \
            }                                                                       \
        }                                                                           \
    }                                                                               \
}


typedef struct CvLinePolar
{
    float rho;
    float angle;
} CvLinePolar;

#define hough_cmp_gt(l1,l2) (aux[l1] > aux[l2])

static CV_IMPLEMENT_QSORT_EX( icvHoughSortDescent32s, int, hough_cmp_gt, const int* )


static void Hough_for_wheel( const CvMat* img, float rho, float theta,
                       int threshold, QVector<CvLinePolar> *lines, int linesMax = 100, float theta_min = 0, float theta_max = CV_PI)//the last two params define the angle range to search lines
{
    cv::AutoBuffer<int> _accum, _sort_buf;    // _accum£ºŒÆÊýÓÃÊý×é£¬_sort_buf£¬ÅÅÐòÓÃÊý×é
    cv::AutoBuffer<float> _tabSin, _tabCos;   // ÌáÇ°ŒÆËãsinÓëcosÖµ£¬±ÜÃâÖØžŽŒÆËãŽøÀŽµÄŒÆËãÐÔÄÜÏÂœµ

    const uchar* image;
    int step, width, height;
    int numangle, numrho;
    int total = 0;
    float ang;
    int r, n;
    int i, j;
    float irho = 1 / rho;   // rhoÖžÏñËØŸ«¶È£¬³£È¡1£¬ÒòŽËirho³£Îª1
    double scale;

//    CV_Assert( CV_IS_MAT(img) && CV_MAT_TYPE(img->type) == CV_8UC1 );

    image = img->data.ptr;
    step = img->step;
    width = img->cols;
    height = img->rows;

    numangle = cvRound(CV_PI / theta);  // žùŸÝthŸ«¶ÈŒÆËãthÎ¬¶ÈµÄ³€¶È
    int numangle_min = max(0,cvRound(theta_min/theta));
    int numangle_max = min(numangle-1,cvRound(theta_max/theta));
    numrho = cvRound(((width + height) * 2 + 1) / rho);  // žùŸÝrŸ«¶ÈŒÆËãrÎ¬¶ÈµÄ³€¶È

    _accum.allocate((numangle+2) * (numrho+2));
    _sort_buf.allocate(numangle * numrho);
    _tabSin.allocate(numangle);
    _tabCos.allocate(numangle);
    int *accum = _accum, *sort_buf = _sort_buf;
    float *tabSin = _tabSin, *tabCos = _tabCos;

    memset( accum, 0, sizeof(accum[0]) * (numangle+2) * (numrho+2) );

    for( ang = 0, n = 0; n < numangle; ang += theta, n++ )   // ŒÆËãÈýœÇº¯Êý±í£¬±ÜÃâÖØžŽŒÆËã
    {
        tabSin[n] = (float)(sin(ang) * irho);
        tabCos[n] = (float)(cos(ang) * irho);
    }

    // stage 1. fill accumulator
    for( i = 0; i < height; i++ )
        for( j = 0; j < width; j++ )
        {
            if( image[i * step + j] != 0 )
                for( n = 0; n < numangle; n++ )
                {
                    r = cvRound( j * tabCos[n] + i * tabSin[n] );  // HoughŒ«×ø±ê±ä»»Êœ
                    r += (numrho - 1) / 2;
                    accum[(n+1) * (numrho+2) + r+1]++;  // ŒÆÊýÆ÷Í³ŒÆ
                }
        }

    // stage 2. find local maximums
    for( r = 0; r < numrho; r++ )
        for( n = numangle_min; n <= numangle_max; n++ )
        {
            int base = (n+1) * (numrho+2) + r+1;
            if( accum[base] > threshold &&             // ŽóÓÚãÐÖµ£¬ÇÒÊÇŸÖ²¿Œ«ŽóÖµ
                accum[base] > accum[base - 1] && accum[base] >= accum[base + 1] &&
                accum[base] > accum[base - numrho - 2] && accum[base] >= accum[base + numrho + 2] )
                sort_buf[total++] = base;
        }

    // stage 3. sort the detected lines by accumulator value
    icvHoughSortDescent32s( sort_buf, total, accum );

    // stage 4. store the first min(total,linesMax) lines to the output buffer
    linesMax = MIN(linesMax, total);  // linesMaxÊÇÊäÈë²ÎÊý£¬±íÊŸ×î¶àÊä³ö¶àÉÙžöÖ±Ïß²ÎÊý
    scale = 1./(numrho+2);
    for( i = 0; i < linesMax; i++ )
    {
        CvLinePolar line;           // Êä³öœá¹¹£¬ŸÍÊÇ(r,theta)
        int idx = sort_buf[i];
        int n = cvFloor(idx*scale) - 1;
        int r = idx - (n+1)*(numrho+2) - 1;
        line.rho = (r - (numrho - 1)*0.5f) * rho;
        line.angle = n * theta;
      //  cvSeqPush( lines, &line );  // È·¶šµÄÖ±ÏßÈë¶ÓÁÐÊä³ö
        lines->push_back(line);
    }
}



#endif // PROCESSORMULTI_PROCESSOR_FEATUREEXTRACT_EX_H
