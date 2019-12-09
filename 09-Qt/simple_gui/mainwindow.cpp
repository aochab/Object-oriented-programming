#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    displacement = new Displacement(this);
    speed = new Speed(this);
    acceleration = new Acceleration(this);


    connect(displacement, SIGNAL(changed(double)),
            speed, SLOT(onDisplacementChanged(double)));
    connect(speed, SIGNAL(changed(double)),
            acceleration, SLOT(onSpeedChange(double)));

    ui->setupUi(this);

    connect(speed, SIGNAL(changed(double)),
            ui->lcdNumberSpeed, SLOT(display(double)));

    connect(acceleration, SIGNAL(changed(double)),
            ui->lcdNumberAcceleration, SLOT(display(double)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    auto value = ui->lineEditDisplacement->text().toDouble();
    displacement->set(value);
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{

}
