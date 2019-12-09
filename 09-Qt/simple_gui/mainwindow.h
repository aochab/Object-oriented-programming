#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "displacement.h"
#include "acceleration.h"
#include "speed.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Displacement *displacement;
    Speed *speed;
    Acceleration *acceleration;
};

#endif // MAINWINDOW_H
