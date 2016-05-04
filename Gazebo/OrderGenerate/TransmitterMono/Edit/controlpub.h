#ifndef CONTROLPUB_H
#define CONTROLPUB_H

#include <QObject>
#include <QTimer>
#include <QThread>
#include <QReadWriteLock>

#include <gazebo/gazebo.hh>
#include <gazebo/common/common.hh>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/transport/transport.hh>

class ControlPub : public QObject
{
    Q_OBJECT
public:
    explicit ControlPub(QString topicName, QObject *parent = 0);
    ~ControlPub();
    void sendMessage(double leftvelocity, double rightvelocity);
    void setSendInterval(int interval);
public slots:
    void onTimer();

private:
    boost::shared_ptr<gazebo::transport::Node> _nodeptr;

    gazebo::transport::PublisherPtr _pub;

    QString _topicName;

    double _leftvelocity, _rightvelocity;

private:
    QTimer _timer;
    QThread _thread;
    //QWriteLocker _lock;

    int _timerInterval;
};

#endif // CONTROLPUB_H
