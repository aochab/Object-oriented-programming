#ifndef DISPLACEMENET_H
#define DISPLACEMENET_H

#include <QObject>

class Displacement: public QObject
{
    Q_OBJECT

public:
    explicit Displacement(QObject *parent = nullptr);

    Q_INVOKABLE void set(double v);

signals:
    void changed(double v);

public slots:

private:
    double value;
};

#endif // DISPLACEMENET_H
