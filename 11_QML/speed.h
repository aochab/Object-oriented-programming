#ifndef SPEED_H
#define SPEED_H

#include <QObject>

class Speed : public QObject
{
    Q_OBJECT

public:
    explicit Speed(QObject *parent = nullptr);

signals:
    void changed(double v);

public slots:
    void onDisplacementChange(double v);

private:
    double displacement;
};

#endif // SPEED_H
