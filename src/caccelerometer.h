#ifndef CACCELEROMETER_H
#define CACCELEROMETER_H

#include <QAccelerometer>

#include "caccelerometerfilter.h"

QTM_USE_NAMESPACE

class CAccelerometer
    : public QAccelerometer
{
    Q_OBJECT
public:
    CAccelerometer();

private:
    CAccelerometerFilter m_filter;
};

#endif // CACCELEROMETER_H
