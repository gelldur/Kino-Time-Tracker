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
    ui->fromDay->setValidator(new QRegExpValidator(regExpDay, this));
    ui->toDay->setValidator(new QRegExpValidator(regExpDay, this));

    QRegExp regExpMonth("0[1-9]|1[012]");
    ui->fromMonth->setValidator(new QRegExpValidator(regExpMonth, this));
    ui->toMonth->setValidator(new QRegExpValidator(regExpMonth, this));

    QString stringYear = QDateTime::currentDateTime().toString("yyyy");
    QRegExp regExpYear(stringYear);
    ui->fromYear->setValidator(new QRegExpValidator(regExpYear, this));
    ui->toYear->setValidator(new QRegExpValidator(regExpYear, this));
}

EditWindow::~EditWindow()
{
    delete ui;
}


