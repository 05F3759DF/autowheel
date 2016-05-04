    INCLUDEPATH += $$(HOME)/SDK/ROSInterface/include
    INCLUDEPATH += $$(HOME)/SDK/GLViewer/include
    INCLUDEPATH += $$(HOME)/SDK/serialport_lib/include
    INCLUDEPATH += $$(HOME)/SDK/serialport_lib/serialport/include
    INCLUDEPATH += $$(HOME)/SDK/PathPlanning/include

    INCLUDEPATH +=/usr/local/include/urg_c/
    INCLUDEPATH += /usr/include/eigen3

    INCLUDEPATH += /usr/local/qwt-6.1.2/include
    LIBS += -L/usr/local/qwt-6.1.2/lib -lqwt

    CONFIG(debug, debug|release){
        LIBS += -L$$(HOME)/SDK/GLViewer/lib -lGLViewer_Debug
        LIBS += -L$$(HOME)/SDK/ROSInterface/lib/ -lROSInterface_Debug
        LIBS += -L$$(HOME)/SDK/serialport_lib/lib/ -lserialport_lib_Debug
        LIBS += -L$$(HOME)/SDK/PathPlanning/lib/ -lPathPlanning
    }else{
        LIBS += -L$$(HOME)/SDK/GLViewer/lib -lGLViewer_Release
        LIBS += -L$$(HOME)/SDK/ROSInterface/lib/ -lROSInterface_Release
        LIBS += -L$$(HOME)/SDK/serialport_lib/lib/ -lserialport_lib_Release
        LIBS += -L$$(HOME)/SDK/PathPlanning/lib/ -lPathPlanning
    }

    LIBS += -L/usr/lib/x86_64-linux-gnu -lopencv_core
    LIBS += -L/usr/lib/x86_64-linux-gnu -lopencv_highgui
    LIBS += -L/usr/lib/x86_64-linux-gnu -lopencv_features2d
    LIBS += -L/usr/lib/x86_64-linux-gnu -lopencv_objdetect
    LIBS += -L/usr/lib/x86_64-linux-gnu -lopencv_contrib

    INCLUDEPATH += /opt/ros/indigo/include

    LIBS += -L/usr/local/lib/ -lurg_c

    LIBS += -L/opt/ros/indigo/lib -lroscpp
    LIBS += -L/opt/ros/indigo/lib -lrosconsole
    LIBS += -L/opt/ros/indigo/lib -lroscpp_serialization
    LIBS += -L/opt/ros/indigo/lib -lrostime
    LIBS += -L/opt/ros/indigo/lib -lxmlrpcpp
    LIBS += -L/opt/ros/indigo/lib -lcpp_common
    LIBS += -L/opt/ros/indigo/lib -lrosconsole_log4cxx
    LIBS += -L/opt/ros/indigo/lib -lrosconsole_backend_interface
    LIBS += -L/opt/ros/indigo/lib -ltf
    LIBS += -L/opt/ros/indigo/lib -ltf2
    LIBS += -L/opt/ros/indigo/lib -ltf2_ros
    LIBS += -L/opt/ros/indigo/lib -lpcl_ros_tf
    LIBS += -L/opt/ros/indigo/lib -ltf_conversions
    LIBS += -L/opt/ros/indigo/lib -lactionlib
    LIBS += -L/usr/lib/x86_64-linux-gnu -lboost_system
    LIBS += -L/usr/lib -lgsl
    LIBS += -L/usr/lib -lgslcblas



HEADERS += wheelchair.h\
        wheelchair_global.h \


SOURCES += wheelchair.cpp \

PROJNAME = wheelchair
INSTTYPE = MOD

QT += multimedia







include(RobotSDK_Main.pri)