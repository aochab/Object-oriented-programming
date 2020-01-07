#ifndef ACCELERATION_H
#define ACCELERATION_H

#include <QObject>

class Acceleration : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double speed
               READ getValue
               WRITE onSpeedChange
               NOTIFY changed)
public:
    explicit Acceleration(QObject *parent = nullptr);

    Q_INVOKABLE double getValue();

signals:
    void changed(double v);

public slots:
    void onSpeedChange(double v);

private:
    double speed;
    double acceleration;
};

#endif // ACCELERATION_H
