#include "controlpub.h"

ControlPub::ControlPub(QString topicName, QObject *parent) : QObject(parent)
{
//    gazebo::setupClient();

    gazebo::transport::NodePtr node(new gazebo::transport::Node());
    _nodeptr = node;

    _nodeptr->Init();

    _topicName = topicName;

    _pub = _nodeptr->Advertise<gazebo::msgs::JointCmd>(_topicName.toStdString());

    _pub->WaitForConnection();

    _leftvelocity = _rightvelocity = 0;

    this->moveToThread(&_thread);

    connect(&_timer, SIGNAL(timeout()), this , SLOT(onTimer()));

    _timerInterval = 30;
    _timer.start(_timerInterval);

    _thread.start();
}

ControlPub::~ControlPub()
{
//    gazebo::shutdown();
    _thread.exit();
    _thread.wait();
}

void ControlPub::setSendInterval(int interval)
{
    _timerInterval = interval;
    _timer.stop();
    _timer.start(_timerInterval);
}

void ControlPub::onTimer()
{
    gazebo::msgs::JointCmd leftmsg, rightmsg;

    leftmsg.set_name("wheelchairrobot::leftrearwheel_joint");
    rightmsg.set_name("wheelchairrobot::rightrearwheel_joint");

    leftmsg.mutable_velocity()->set_target(_leftvelocity);
    rightmsg.mutable_velocity()->set_target(_rightvelocity);

    _pub->Publish(leftmsg);
    _pub->Publish(rightmsg);
}

void ControlPub::sendMessage(double leftvelocity, double rightvelocity)
{
    _leftvelocity = leftvelocity;
    _rightvelocity = rightvelocity;
}
