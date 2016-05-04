#ifndef SENSORWIDGETS_H
#define SENSORWIDGETS_H

#include <QWidget>
#include <QLabel>
#include "qwt_thermo.h"

#include "qwt_dial.h"
#include "qwt_dial_needle.h"
#include "qwt_color_map.h"
#include "qwt_round_scale_draw.h"
#include "qwt_compass.h"
class SensorWidgets : public QWidget
{
    Q_OBJECT
public:
    explicit SensorWidgets(QWidget *parent = 0);
    ~SensorWidgets();

signals:

public slots:

public:
    void setSpeed(double speed);
    void setOriental(double ori);
private:
    QWidget *createSpeedWidget();
    QWidget *createOrientWidget();
    QWidget *createCompassWidget();
private:
    QwtThermo *speedThermo;
    QwtCompass *orientDial;
    QLabel *speedLabel;
    QLabel *orientLabel;
};

#endif // SENSORWIDGETS_H
