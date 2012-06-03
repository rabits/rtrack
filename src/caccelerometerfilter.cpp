#include "caccelerometerfilter.h"

#include <math.h>

#define RADIANS_TO_DEGREES 57.2957795

CAccelerometerFilter::CAccelerometerFilter()
    : m_x(0), m_y(0), m_z(0)
{
}

bool CAccelerometerFilter::filter(QAccelerometerReading *reading)
{
    qreal rx = reading->x();
    qreal ry = reading->y();
    qreal rz = reading->z();

    qDebug(QString("Accelermeter: x:%1 y:%2 z:%3").arg(rx, 5, 'f', 1).arg(ry, 5, 'f', 1).arg(rz, 5, 'f', 1).toStdString().c_str());

    qreal divider = sqrt(rx * rx + ry * ry + rz * rz);

    // Lowpass factor
#if defined(Q_WS_MAEMO_6) || defined(Q_OS_SYMBIAN)
    float lowPassFactor = 0.10;
#else
    float lowPassFactor = 0.05;
#endif

    // Calculate the axis angles in degrees and reduce the noise in sensor
    // readings.
    m_x += (acos(rx / divider) * RADIANS_TO_DEGREES - 90 - m_x) * lowPassFactor;
    m_y += (acos(ry / divider) * RADIANS_TO_DEGREES - 90 - m_y) * lowPassFactor;
    m_z += (acos(rz / divider) * RADIANS_TO_DEGREES - 90 - m_z) * lowPassFactor;

    // The orientations of the accelerometers are different between
    // Symbian and Maemo devices so we use the different axes
    // depending on the platform.
#if defined(Q_WS_MAEMO_6) || defined(Q_OS_SYMBIAN)
    emit rotationChanged(-m_y);
#else
    emit rotationChanged(m_x);
#endif

    // Don't store the reading in the sensor.
    return false;
}
