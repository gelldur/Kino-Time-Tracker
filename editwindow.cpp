#include <QDateTime>
#include <QInputDialog>
#include <cstdio>

#include "editwindow.h"
#include "ui_editwindow.h"


EditWindow::EditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);

    QRegExp regExpDay("0[1-9]|[12][0-9]|3[01]");
    ui->FDay->setValidator(new QRegExpValidator(regExpDay, this));
    ui->TDay->setValidator(new QRegExpValidator(regExpDay, this));

    QRegExp regExpMonth("0[1-9]|1[012]");
    ui->FMonth->setValidator(new QRegExpValidator(regExpMonth, this));
    ui->TMonth->setValidator(new QRegExpValidator(regExpMonth, this));

    QString stringYear = QDateTime::currentDateTime().toString("yyyy");
    char buffor[256];
    sprintf(buffor,"(19)[0-9]{2}|[2-%c][0-%c][0-%c][0-%c]",
            stringYear.toStdString()[0],
            stringYear.toStdString()[1],
            stringYear.toStdString()[2],
            stringYear.toStdString()[3]);

    qDebug("%s\n",buffor);


    QRegExp regExpYear(buffor);
    ui->FYear->setValidator(new QRegExpValidator(regExpYear, this));
    ui->TYear->setValidator(new QRegExpValidator(regExpYear, this));
}

EditWindow::~EditWindow()
{
    delete ui;
}
