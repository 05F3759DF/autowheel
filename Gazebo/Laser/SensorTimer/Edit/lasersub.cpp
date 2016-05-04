#include "lasersub.h"

LaserSub::LaserSub(QString topicName, QObject *parent) : QObject(parent)
{
//    this->moveToThread(&_thread);
//    _thread.start();

//    gazebo::setupClient();

    gazebo::transport::NodePtr node(new gazebo::transport::Node());
    _nodeptr = node;

    _nodeptr->Init();

    _topicName = topicName;

    _sub = _nodeptr->Subscribe(_topicName.toStdString(), &LaserSub::onMsgCallback, this);

    laserOk = 1;
}

LaserSub::~LaserSub()
{
//    gazebo::shutdown();

//    _thread.exit();
//    _thread.wait();

    if((laserOk == 0) && (_ranges != NULL))
        delete _ranges;
}

void LaserSub::onMsgCallback(ConstLaserScanStampedPtr &msg)
{
    if(!msg->has_scan())
        return;

    if(msg->has_scan() && laserOk)
    {
        _range_size = msg->scan().count();
        _ranges = new double[_range_size];
        laserOk = 0;
    }

   // _lock.lockForRead();
    QVector<double>tt;
    for(int i=0; i<msg->scan().count(); i++)
    {
        _ranges[i] = msg->scan().ranges(i);
        tt.push_back(_ranges[i]);
    }
    gazebo::common::Time gazTime = gazebo::common::Time::GetWallTime();
    _timestamp = gazTime.sec*1000 + gazTime.nsec/1000000;
    //_lock.unlock();

}

void LaserSub::getLaserMessage(u_int32_t &timestamp, double *ranges, int &datasize)
{
    //ranges = _ranges;
    datasize = _range_size;
    timestamp = _timestamp;

//    _lock.lockForRead();
//    memcpy((void*)ranges, (void*)_ranges, datasize*sizeof(double));
//    _lock.unlock();
    for(int i=0; i<datasize; i++)
    {
        ranges[i] = _ranges[i];
    }
}

