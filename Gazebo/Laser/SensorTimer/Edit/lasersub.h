#ifndef LASERSUB_H
#define LASERSUB_H

#include <QObject>

#include <gazebo/gazebo.hh>
#include <gazebo/common/common.hh>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/transport/transport.hh>

#include <qglobal.h>
#include <qapplication.h>
#include <qtimer.h>
#include <qreadwritelock.h>
#include <qthread.h>
#include <qqueue.h>
#include <qdebug.h>

class LaserSub : public QObject
{
    Q_OBJECT
public:
    explicit LaserSub(QString topicName, QObject *parent = 0);
    ~LaserSub();

    void getLaserMessage(u_int32_t& timestamp, double *ranges, int& datasize);

private:
    void onMsgCallback(ConstLaserScanStampedPtr & msg);

private:
    double *_ranges;
    int _range_size;
    bool laserOk;
    u_int32_t _timestamp;

private:
    boost::shared_ptr<gazebo::transport::Node> _nodeptr;

    gazebo::transport::SubscriberPtr _sub;



    QString _topicName;
    QReadWriteLock _lock;
    QThread _thread;
};

#endif // LASERSUB_H
