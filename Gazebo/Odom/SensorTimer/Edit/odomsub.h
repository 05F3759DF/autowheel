#ifndef ODOMSUB_H
#define ODOMSUB_H

#include <QObject>

#include <gazebo/gazebo.hh>
#include <gazebo/common/common.hh>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/transport/transport.hh>

struct OdomStruct
{
    double x,y,z;
    double roll, pitch, yaw;
    u_int32_t timestamp;
};

class OdomSub : public QObject
{
    Q_OBJECT
public:
    explicit OdomSub(QString topicName, QObject *parent = 0);
    ~OdomSub();
    void getOdomMessage(OdomStruct& odomstruct);

    void setPoseId(int id);

private:
    void onMsgCallback(ConstPosesStampedPtr & msg);

private:
    OdomStruct _odomstruct;

private:
    boost::shared_ptr<gazebo::transport::Node> _nodeptr;

    gazebo::transport::SubscriberPtr _sub;

    QString _topicName;

    int _poseid;
};

#endif // ODOMSUB_H
