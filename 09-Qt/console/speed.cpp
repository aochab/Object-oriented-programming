#include "speed.h"
#include <QDebug>

Speed::Speed(QObject *parent) : QObject(parent)
{

}

void Speed::onDisplacementChanged(double v)
{
    qDebug() << "[Speed] Value: " << v;
    emit changed(v);
}
