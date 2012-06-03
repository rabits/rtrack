#include "crotation.h"

CRotation::CRotation()
    : QRotationSensor()
{
    qDebug("[rTrack] Init rotation");
    addFilter(&m_filter);
}
