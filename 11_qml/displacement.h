#ifndef DISPLACEMENT_H
#define DISPLACEMENT_H

#include <QObject>

class Displacement : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double value WRITE set READ get NOTIFY changed)

public:
    explicit Displacement(QObject *parent = nullptr);

    void set(double v);
    double get();

signals:
    void changed(double v);

public slots:

private:
    double value;
};

#endif // DISPLACEMENT_H
