#ifndef CROTATION_H
#define CROTATION_H

#include <QObject>
#include <QRotationSensor>

#include "crotationfilter.h"

QTM_USE_NAMESPACE

class CRotation
    : public QRotationSensor
{
    Q_OBJECT
public:
    CRotation();

private:
    CRotationFilter m_filter;
};

#endif // CROTATION_H
