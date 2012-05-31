#include "ctrack.h"

CTrack::CTrack(QObject *parent)
    : QObject(parent)
    , m_settings()
{
    // Set default settings
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

QVariant CTrack::setting(QString key, QString value)
{
    if( ! value.isEmpty() )
        m_settings.setValue(key, value);

    return m_settings.value(key);
}

CTrack* CTrack::s_pInstance = NULL;
