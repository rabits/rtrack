#ifndef CACCELEROMETERFILTER_H
#define CACCELEROMETERFILTER_H

#include <QObject>
#include <QAccelerometerFilter>

QTM_USE_NAMESPACE

class CAccelerometerFilter
    : public QObject
    , public QAccelerometerFilter
{
    Q_OBJECT
public:
    CAccelerometerFilter();
    bool filter(QAccelerometerReading *reading);

signals:
    void rotationChanged(const QVariant &deg);

protected:
    qreal m_x;
    qreal m_y;
    qreal m_z;

private:
    qtimestamp m_stamp;
};

#endif // CACCELEROMETERFILTER_H
