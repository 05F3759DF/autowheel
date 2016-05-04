#include "processormulti_processor_featureextract_ex.h"

int point_shift(QVector<cv::Point2d> & point_data_src, cv::Point2d wheel_position,
                double wheel_theta, QVector<cv::Point2d> &  point_data_drc)
{
    cv::Point2d point_data_item;
    point_data_drc.clear();
    for(int i = 0; i < point_data_src.size(); i++)
    {
        point_data_item.x = (point_data_src[i].x - wheel_position.x)*cos(wheel_theta) + (point_data_src[i].y - wheel_position.y)*sin(wheel_theta);
        point_data_item.y = (point_data_src[i].y - wheel_position.y)*cos(wheel_theta) - (point_data_src[i].x - wheel_position.x)*sin(wheel_theta);
        point_data_drc.push_back(point_data_item);
    }
    return 1;
}

cv::Point2i world2image(cv::Point2d worldcoord, const cv::Point2i & originPoint,
                        const double pixelsize, const cv::Mat & image)
{
    cv::Point2i imgPt;
    imgPt.x = qRound(worldcoord.y/pixelsize);
    imgPt.y = qRound(worldcoord.x/pixelsize);
    imgPt.x += originPoint.x;
    imgPt.y += originPoint.y;

    if(imgPt.x > (image.cols-1))
        imgPt.x = image.cols-1;
    if(imgPt.y > (image.rows - 1))
        imgPt.y = image.rows - 1;
    if(imgPt.x < 0)
        imgPt.x = 0;
    if(imgPt.y < 0)
        imgPt.y = 0;
    return imgPt;
}

cv::Point2d image2world(cv::Point2d imagecoord, const cv::Point2i & originPoint,
                        const double pixelsize, const cv::Mat & image)
{
    cv::Point2d imgPt;
    imgPt.x = imagecoord.x - originPoint.x;
    imgPt.y = imagecoord.y - originPoint.y;
    double temp;
    temp = imgPt.x;
    imgPt.x = imgPt.y * pixelsize;
    imgPt.y = temp * pixelsize;

    return imgPt;
}


QPointF world2image(QPointF worldcoord, const QPointF & originPoint,
                        const double pixelsize, const QImage & image)
{
    cv::Point2d imgPt;
    imgPt.x = qRound(worldcoord.y()/pixelsize);
    imgPt.y = qRound(worldcoord.x()/pixelsize);
    imgPt.x += originPoint.x();
    imgPt.y += originPoint.y();

    if(qRound(imgPt.x) > (image.width()-1))
        imgPt.x = image.width()-1;
    if(qRound(imgPt.y) > (image.height() - 1))
        imgPt.y = image.height() - 1;
    if(imgPt.x < 0)
        imgPt.x = 0;
    if(imgPt.y < 0)
        imgPt.y = 0;

    QPointF pp(imgPt.x, imgPt.y);
    return pp;
}

int wall_point_shift(QVector<_line> & point_data_src, cv::Point2d wheel_position, double wheel_theta, QVector<_line> & point_data_drc)//ÂÖÒÎÏîÄ¿ÓÃ£¬È«ŸÖ×ø±ê»»ËãŸÖ²¿Ëù±ê
{
    _line point_data_item;
    point_data_drc.clear();
    for(int i = 0; i < point_data_src.size(); i++)
    {
        point_data_item.p_start.x = (point_data_src[i].p_start.x - wheel_position.x)*cos(wheel_theta) + (point_data_src[i].p_start.y - wheel_position.y)*sin(wheel_theta);
        point_data_item.p_start.y = (point_data_src[i].p_start.y - wheel_position.y)*cos(wheel_theta) - (point_data_src[i].p_start.x - wheel_position.x)*sin(wheel_theta);
        point_data_item.p_end.x = (point_data_src[i].p_end.x - wheel_position.x)*cos(wheel_theta) + (point_data_src[i].p_end.y - wheel_position.y)*sin(wheel_theta);
        point_data_item.p_end.y = (point_data_src[i].p_end.y - wheel_position.y)*cos(wheel_theta) - (point_data_src[i].p_end.x - wheel_position.x)*sin(wheel_theta);
        point_data_item.a = point_data_src[i].a;
        point_data_item.b = point_data_src[i].b;
        point_data_item.c = point_data_src[i].c;
        point_data_drc.push_back(point_data_item);
    }
    return 1;
}
