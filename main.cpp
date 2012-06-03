#include <QtGui/QApplication>
#include <QtDeclarative>
#include "qmlapplicationviewer.h"

#include "src/ctrack.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    qDebug("[rTrack] Init rTrack v"PROJECT_VERSION);

    QCoreApplication::setOrganizationName("Rabits");
    QCoreApplication::setOrganizationDomain("rabits.ru");
    QCoreApplication::setApplicationName("rtrack");
    QCoreApplication::setApplicationVersion(PROJECT_VERSION);

    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QmlApplicationViewer viewer;

    CTrack::getInstance()->initContext(viewer);

    viewer.setMainQmlFile(QLatin1String("qml/rtrack/main.qml"));

    CTrack::getInstance()->initRoot(viewer);

    qDebug("[rTrack] Init done, starting");
    viewer.showExpanded();
    return app->exec();
}
