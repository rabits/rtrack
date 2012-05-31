#include <QtGui/QApplication>
#include <QtDeclarative>
#include "qmlapplicationviewer.h"

#include "src/ctrack.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("Rabits");
    QCoreApplication::setOrganizationDomain("rabits.ru");
    QCoreApplication::setApplicationName("rtrack");
    QCoreApplication::setApplicationVersion("0.0.1");

    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QmlApplicationViewer viewer;

    CTrack::getInstance()->initContext(viewer);

    viewer.setMainQmlFile(QLatin1String("qml/rtrack/main.qml"));

    CTrack::getInstance()->initRoot(viewer);

    viewer.showExpanded();
    return app->exec();
}