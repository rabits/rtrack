#include "crotationfilter.h"
#include <QTextStream>

CRotationFilter::CRotationFilter()
{
}

bool CRotationFilter::filter(QRotationReading *reading)
{
    int diff = ( reading->timestamp() - m_stamp );
    m_stamp = reading->timestamp();
    qDebug(QString("Rotation: x:%1 y:%2 z:%3 (%4 ms since last, %5 Hz)")
           .arg(reading->x(), 4, 'f', 0).arg(reading->y(), 4, 'f', 0).arg(reading->z(), 4, 'f', 0)
           .arg(diff / 1000, 4).arg( 1000000.0 / diff, 4, 'f', 1).toStdString().c_str());

    // Don't store the reading in the sensor.
    return false;
}
