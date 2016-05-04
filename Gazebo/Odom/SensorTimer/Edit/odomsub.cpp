#include "odomsub.h"
#include <string>
#include <iostream>
using namespace std;
OdomSub::OdomSub(QString topicName, QObject *parent) : QObject(parent)
{
//    gazebo::setupClient();

    gazebo::transport::NodePtr node(new gazebo::transport::Node());
    _nodeptr = node;

    _nodeptr->Init();

    _topicName = topicName;

    _poseid = 0; //0-base index, in Topic Visualization of gazebo, the first pose index is 0.

    _sub = _nodeptr->Subscribe(_topicName.toStdString(), &OdomSub::onMsgCallback, this);
}

OdomSub::~OdomSub()
{
 //   gazebo::shutdown();
}

void OdomSub::setPoseId(int id)
{
    _poseid = id;
}

void OdomSub::onMsgCallback(ConstPosesStampedPtr &msg)
{
    _odomstruct.x = msg->pose(_poseid).position().x();
    _odomstruct.y = msg->pose(_poseid).position().y();
    _odomstruct.z = msg->pose(_poseid).position().z();

    gazebo::msgs::Quaternion dd = msg->pose(_poseid).orientation();
    gazebo::math::Quaternion qua;
    qua.Set(dd.w(),dd.x(),dd.y(),dd.z());

    _odomstruct.pitch = qua.GetPitch();
    _odomstruct.roll = qua.GetRoll();
    _odomstruct.yaw = qua.GetYaw();

     gazebo::common::Time gazTime = gazebo::common::Time::GetWallTime();
    _odomstruct.timestamp = gazTime.sec*1000 + gazTime.nsec/1000000;
}

void OdomSub::getOdomMessage(OdomStruct &odomstruct)
{
    odomstruct = _odomstruct;

}

