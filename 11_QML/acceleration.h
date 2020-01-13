#ifndef ACCELERATION_H
#define ACCELERATION_H

#include <QObject>

class Acceleration : public QObject
{
    Q_OBJECT

public:
    explicit Acceleration(QObject *parent = nullptr);


signals:
    void changed(double v);

public slots:
    void onSpeedChange(double v);

private:
    double speed;
};

#endif // ACCELERATION_H
