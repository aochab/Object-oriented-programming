#ifndef SPEED_H
#define SPEED_H

#include <QObject>

class Speed : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double displacement
               READ getSpeed
               WRITE onDisplacementChange
               NOTIFY changed)
public:
    explicit Speed(QObject *parent = nullptr);

    Q_INVOKABLE double getSpeed();

signals:
    void changed(double v);

public slots:
    void onDisplacementChange(double v);

private:
    double displacement;
    double speed;
};

#endif // SPEED_H
