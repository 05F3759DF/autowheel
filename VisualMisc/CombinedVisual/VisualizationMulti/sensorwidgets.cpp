#include "sensorwidgets.h"
#include <QBoxLayout>
#include <cmath>
SensorWidgets::SensorWidgets(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setSpacing(0);

    QWidget *orientBox = createOrientWidget();
    layout->addWidget(orientBox);

    QWidget *speedBox = createSpeedWidget();
    layout->addWidget(speedBox);


}
SensorWidgets::~SensorWidgets()
{
    if(speedLabel->parent() == NULL)
        delete speedLabel;
    if(speedThermo->parent() == NULL)
        delete speedThermo;
    if(orientDial->parent() == NULL)
        delete orientDial;
    if(orientLabel->parent() == NULL)
        delete orientLabel;

}

QWidget* SensorWidgets::createSpeedWidget()
{
    speedLabel = new QLabel();
    speedLabel->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    speedThermo = new QwtThermo();
    speedThermo->setOrientation(Qt::Vertical);
    speedThermo->setScalePosition(QwtThermo::TrailingScale);

    QwtLinearColorMap *colorMap = new QwtLinearColorMap();
    colorMap->setColorInterval(Qt::blue, Qt::red);
    speedThermo->setColorMap(colorMap);
    speedThermo->setScale(0.0, 0.6);
    //speedThermo->setMaximumHeight(400);
    speedThermo->setFixedHeight(200);
    setSpeed(0.6);

    QWidget *box = new QWidget();

    QBoxLayout *layout = new QVBoxLayout(box);

    layout->addWidget(speedThermo, Qt::AlignCenter);

    layout->addWidget(speedLabel);

    return box;
}

QWidget* SensorWidgets::createCompassWidget()
{

}

QWidget* SensorWidgets::createOrientWidget()
{
    orientLabel = new QLabel();
    orientLabel->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    orientDial = new QwtCompass();

//    QwtRoundScaleDraw *scaleDraw = new QwtRoundScaleDraw();
//    scaleDraw->setSpacing( 4 );
//    scaleDraw->enableComponent( QwtAbstractScaleDraw::Backbone, false );
//    scaleDraw->setTickLength( QwtScaleDiv::MinorTick, 0 );
//    scaleDraw->setTickLength( QwtScaleDiv::MediumTick, 4 );
//    scaleDraw->setTickLength( QwtScaleDiv::MajorTick, 8 );
//    orientDial->setScaleDraw( scaleDraw );

    //orientDial->setScale(-3.14, 3.14);

//    orientDial->setWrapping( false );
//    orientDial->setReadOnly( true );



    orientDial->setMaximumHeight(200);

//    QwtDialSimpleNeedle* needle = new QwtDialSimpleNeedle(
//        QwtDialSimpleNeedle::Arrow, true, Qt::red,
//        QColor( Qt::gray ).light( 130 ) );
    QwtCompassMagnetNeedle* needle = new QwtCompassMagnetNeedle();

    orientDial->setNeedle(needle);

    orientDial->setScale( -180, 180.0);

    orientDial->setOrigin( 90.0 );


    //setOriental(0.0);

    QWidget *box = new QWidget();

    QBoxLayout *layout = new QVBoxLayout(box);

    layout->addWidget(orientDial, Qt::AlignBottom);

    layout->addWidget(orientLabel);

    return box;
}

void SensorWidgets::setSpeed(double speed)
{
    speedThermo->setValue((speed));
    QString str;
    str.setNum(std::fabs(speed), 'f', 2);
    str += " m/s";
    speedLabel->setText(str);
}

void SensorWidgets::setOriental(double ori)
{
    orientDial->setValue(ori*180.0/3.1415926);
    QString text;
    text.setNum(ori, 'f', 3);
    text += " rad";
    orientLabel->setText(text);
}

