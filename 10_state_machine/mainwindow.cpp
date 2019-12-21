#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStateMachine>
#include <QHistoryState>
#include <QFileDialog>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto stateMachine = new QStateMachine(this);

    auto unlockedState = new QState(stateMachine);
    auto startupState = new QState(unlockedState);
    auto openState = new QState(unlockedState);
    auto errorState = new QState(unlockedState);
    auto viewState = new QState(unlockedState);
    auto saveState = new QState(unlockedState);
    auto editState = new QState(unlockedState);
    auto lockedState = new QState(stateMachine);

    auto historyState = new QHistoryState(unlockedState);

    unlockedState->assignProperty(ui->pbToggle,"text","Lock");
    unlockedState->assignProperty(ui->pbOpen,"enabled",true);
    unlockedState->assignProperty(ui->pbSave,"enabled",true);
    unlockedState->assignProperty(ui->teText,"enabled",true);

    startupState->assignProperty(ui->pbOpen,"enabled", true);
    startupState->assignProperty(ui->pbSave,"enabled",false);
    startupState->assignProperty(ui->teText,"enabled",false);
    startupState->assignProperty(ui->teText,"placeholderText","Open file to start editing...");

    errorState->assignProperty(ui->pbOpen,"enabled",true);
    errorState->assignProperty(ui->pbSave,"enabled",false);
    errorState->assignProperty(ui->teText,"enabled",false);
    errorState->assignProperty(ui->teText,"placeholderText","Error ocured. Open file start editing...");

    viewState->assignProperty(ui->pbOpen,"enabled",true);
    viewState->assignProperty(ui->pbSave,"enabled",false);
    viewState->assignProperty(ui->teText,"enabled",true);

    editState->assignProperty(ui->pbOpen,"enabled",false);
    editState->assignProperty(ui->pbSave,"enabled",true);
    editState->assignProperty(ui->teText,"enabled",true);

    lockedState->assignProperty(ui->pbToggle,"text","Unlock");
    lockedState->assignProperty(ui->pbOpen,"enabled",false);
    lockedState->assignProperty(ui->pbSave,"enabled",false);
    lockedState->assignProperty(ui->teText,"enabled",false);

    unlockedState->addTransition(ui->pbToggle,SIGNAL(clicked(bool)),lockedState);

    startupState->addTransition(ui->pbOpen,SIGNAL(clicked(bool)),openState);

    openState->addTransition(this,SIGNAL(error()),errorState);
    openState->addTransition(this,SIGNAL(opened()),viewState);

    viewState->addTransition(ui->pbOpen,SIGNAL(clicked(bool)),openState);
    viewState->addTransition(ui->teText,SIGNAL(textChanged()),editState);

    editState->addTransition(ui->pbSave,SIGNAL(clicked(bool)),saveState);

    saveState->addTransition(this,SIGNAL(saved()),viewState);
    saveState->addTransition(this,SIGNAL(error()),errorState);

    errorState->addTransition(ui->pbOpen,SIGNAL(clicked(bool)),openState);

    lockedState->addTransition(ui->pbToggle,SIGNAL(clicked(bool)),historyState);

    connect(openState, SIGNAL(entered()), this, SLOT(open()));
    connect(saveState, SIGNAL(entered()), this, SLOT(save()));

    stateMachine->setInitialState(unlockedState);
    unlockedState->setInitialState(startupState);
    stateMachine->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open file"),
                                            "/home/student/OOP/oop_2019_g2_adrian_ochab/10_state_machine");
    if( fileName.isEmpty())
        emit error();
    else {
        QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly|QFile::Text)) {
            emit error();
        }
        else {
            ui->teText->setText(file.readAll());
            file.close();
            emit opened();
        }
    }
}

void MainWindow::save()
{
    if( fileName.isEmpty())
        emit error();
    else {
        QFile file(fileName);
        if(!file.open(QIODevice::WriteOnly|QFile::Text)) {
            emit error();
        } else {
            QTextStream stream(&file);
            stream << ui->teText->toPlainText();
            file.close();
            emit saved();
        }
    }
}

void MainWindow::log()
{
    qDebug() << "Inside log() dunction..";
    emit done();
}
