#include <QDateTime>
#include <QInputDialog>
#include <QString>
#include <cstdio>

#include "EditWindow.h"
#include "ui_EditWindow.h"
#include "Task.h"

EditWindow::EditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);

    connect(ui->fromDay, SIGNAL(editingFinished()), this, SLOT(onFromDayEditingFinished()));
    connect(ui->toDay, SIGNAL(editingFinished()), this, SLOT(onToDayEditingFinished()));
    connect(ui->fromYear, SIGNAL(editingFinished()), this, SLOT(onFromYearEditingFinished()));
    connect(ui->toYear, SIGNAL(editingFinished()), this, SLOT(onToYearEditingFinished()));

    QRegExp regExpDay("[0-9]{0,2}");
    ui->fromDay->setValidator(new QRegExpValidator(regExpDay, this));
    ui->toDay->setValidator(new QRegExpValidator(regExpDay, this));

    QRegExp regExpMonth("[0-9]{0,2}");
    ui->fromMonth->setValidator(new QRegExpValidator(regExpMonth, this));
    ui->toMonth->setValidator(new QRegExpValidator(regExpMonth, this));

    QRegExp regExpYear("[0-9]{0,4}");
    ui->fromYear->setValidator(new QRegExpValidator(regExpYear, this));
    ui->toYear->setValidator(new QRegExpValidator(regExpYear, this));    
}

EditWindow::~EditWindow()
{
    delete ui;
}

void EditWindow::onFromDayEditingFinished()
{
    dayValid(ui->fromDay);
}

void EditWindow::onToDayEditingFinished()
{
    dayValid(ui->toDay);
}

void EditWindow::dayValid(QLineEdit *day)
{
    QString stringGetDay = day->text();
    int intDay = stringGetDay.toInt();
    if(intDay <= 0)
        intDay=1;

    if(intDay>31)
        day->setText("31");
    else if(intDay<10)
        day->setText(QString("").sprintf("0%d",intDay));
}

void EditWindow::onFromMonthEditingFinished()
{
    monthValid(ui->fromMonth);
}

void EditWindow::onToMonthEditingFinished()
{
    monthValid(ui->toMonth);
}

void EditWindow::monthValid(QLineEdit *month)
{
}


void EditWindow::onFromYearEditingFinished()
{
    yearValid(ui->fromYear);
}

void EditWindow::onToYearEditingFinished()
{
    yearValid(ui->toYear);
}

void EditWindow::yearValid(QLineEdit* year)
{
    QString stringYear = QDateTime::currentDateTime().toString("yyyy");
    int intStringYear = stringYear.toInt();

    QString stringGetYear = year->text();
    int intYear = stringGetYear.toInt();
    if(intYear>intStringYear)
        year->setText(stringYear);
    else if(intYear<1900)
        year->setText("1900");

}
