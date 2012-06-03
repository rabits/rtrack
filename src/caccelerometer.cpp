#include "caccelerometer.h"

CAccelerometer::CAccelerometer()
    : QAccelerometer()
{
    qDebug("[rTrack] Init accelerometer");
    addFilter(&m_filter);

#ifdef Q_WS_MAEMO_6
    setDataRate(50); // Hz
#endif
}
