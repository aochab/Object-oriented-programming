#ifndef ACCELERATION_H
#define ACCELERATION_H

#include <QObject>

class Acceleration : public QObject
{
    Q_OBJECT
public:
    explicit Acceleration(QObject *parent = nullptr);

signals:

public slots:
    void onSpeedChanged(double v);
};

#endif // ACCELERATION_H
