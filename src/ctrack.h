#ifndef CTRACK_H
#define CTRACK_H

#include <QObject>
#include <QSettings>
#include <QtDeclarative/QDeclarativeContext>
#include <QGraphicsObject>
#include <qplatformdefs.h> // MEEGO_EDITION_HARMATTAN

#include "qmlapplicationviewer.h"

class CTrack : public QObject
{
    Q_OBJECT
private:
    explicit CTrack(QObject *parent = 0);

    static CTrack* s_pInstance;

    QGraphicsObject*     m_root_object;
    QDeclarativeContext* m_context;

    QSettings   m_settings;

public:
    inline static CTrack* getInstance() { if( s_pInstance == NULL ) s_pInstance = new CTrack(); return s_pInstance; }
    inline static void     destroyInstance() { delete s_pInstance; }

    void initContext(QmlApplicationViewer& viewer);
    void initRoot(QmlApplicationViewer& viewer);

    Q_INVOKABLE inline QSettings* settings() { return &m_settings; }
    Q_INVOKABLE QVariant setting(QString key, QString value = "");

signals:

public slots:

};

#endif // CTRACK_H
