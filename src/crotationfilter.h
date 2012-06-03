#ifndef CROTATIONFILTER_H
#define CROTATIONFILTER_H

#include <QRotationFilter>

QTM_USE_NAMESPACE

class CRotationFilter
    : public QObject
    , public QRotationFilter
{
    Q_OBJECT
public:
    CRotationFilter();
    bool filter(QRotationReading *reading);

private:
    qtimestamp m_stamp;
};

#endif // CROTATIONFILTER_H
