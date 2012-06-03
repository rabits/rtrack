#include "ctrack.h"

CTrack::CTrack(QObject *parent)
    : QObject(parent)
    , m_accel()
    , m_rot()
    , m_settings()
{
    qDebug("[rTrack] Init track");
    // Set default settings

    m_accel.start();
    m_rot.start();

    if( ! (m_accel.isActive() && m_rot.isActive()) )
    {
        qWarning("Some sensors is not active");
    }
}

void CTrack::initContext(QmlApplicationViewer& viewer)
{
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);

    m_context = viewer.rootContext();

    m_context->setContextProperty("ctrack", this);
}

void CTrack::initRoot(QmlApplicationViewer& viewer)
{
    m_root_object = viewer.rootObject();
}

QVector3D CTrack::orientation()
{
}

QVector3D CTrack::ground()
{
}

QVariant CTrack::setting(QString key, QString value)
{
    if( ! value.isEmpty() )
        m_settings.setValue(key, value);

    return m_settings.value(key);
}

CTrack* CTrack::s_pInstance = NULL;
