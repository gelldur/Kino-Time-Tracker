#include <QDateTime>
#include <QInputDialog>
#include <QString>
#include <QTime>
#include <cstdio>

#include "EditWindow.h"
#include "ui_EditWindow.h"

EditWindow::EditWindow(QWidget *parent, Task *task) :
    QDialog(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);

    QString windowTitle = "Task ";
    windowTitle.append(task->getTitle());
    setWindowTitle(windowTitle);

    connect(ui->fromDay, SIGNAL(editingFinished()), this, SLOT(onFromDayEditingFinished()));
    connect(ui->fromMonth, SIGNAL(editingFinished()), this, SLOT(onFromMonthEditingFinished()));
    connect(ui->fromYear, SIGNAL(editingFinished()), this, SLOT(onFromYearEditingFinished()));
    connect(ui->toDay, SIGNAL(editingFinished()), this, SLOT(onToDayEditingFinished()));
    connect(ui->toMonth, SIGNAL(editingFinished()), this, SLOT(onToMonthEditingFinished()));
    connect(ui->toYear, SIGNAL(editingFinished()), this, SLOT(onToYearEditingFinished()));
    connect(ui->toTime, SIGNAL(editingFinished()), this, SLOT(onToTimeFinished()));

    QRegExp regExpDay("[0-9]{0,2}");
    ui->fromDay->setValidator(new QRegExpValidator(regExpDay, this));
    QString dayStart = task->getStartTime().toString("dd");
    ui->fromDay->setText(dayStart);
    ui->toDay->setValidator(new QRegExpValidator(regExpDay, this));
    QString dayEnd = task->getEndTime().toString("dd");
    ui->toDay->setText(dayEnd);

    QRegExp regExpMonth("[0-9]{0,2}");
    qDebug("%s",task->getStartTime().toString("MM").toAscii().constData());
    ui->fromMonth->setValidator(new QRegExpValidator(regExpMonth, this));
    QString monthStart = task->getStartTime().toString("MM");
    ui->fromMonth->setText(monthStart);
    ui->toMonth->setValidator(new QRegExpValidator(regExpMonth, this));
    QString monthEnd = task->getEndTime().toString("MM");
    ui->toMonth->setText(monthEnd);

    QRegExp regExpYear("[0-9]{0,4}");
    ui->fromYear->setValidator(new QRegExpValidator(regExpYear, this));
    QString yearStart = task->getStartTime().toString("yyyy");
    ui->fromYear->setText(yearStart);
    ui->toYear->setValidator(new QRegExpValidator(regExpYear, this));
    QString yearEnd = task->getEndTime().toString("yyyy");
    ui->toYear->setText(yearEnd);

    QString hourStart = task->getStartTime().toString("hhmm");
    ui->fromTime->setTime(QTime::fromString(hourStart, "hhmm"));
    QString hourEnd = task->getEndTime().toString("hhmm");
    ui->toTime->setTime(QTime::fromString(hourEnd, "hhmm"));


    ui->name->setText(task->getTitle());
    ui->description->setText(task->getDescription());
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
        day->setText(QString("").sprintf("0%d", intDay));
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
    QString stringGetMonth = month->text();
    int intMonth = stringGetMonth.toInt();
    if(intMonth <= 0)
        intMonth=1;

    if(intMonth>12)
        month->setText("12");
    else if(intMonth<10)
        month->setText(QString("").sprintf("0%d", intMonth));
}


void EditWindow::onFromYearEditingFinished()
{
    yearValid(ui->fromYear);
}

void EditWindow::onToYearEditingFinished()
{
    yearValid(ui->toYear);
    qDebug("%d",ui->fromYear->text().compare(ui->toYear->text()));
    if(ui->fromYear->text().toInt() > ui->toYear->text().toInt())
    {
        ui->toYear->setText(ui->fromYear->text());
        if(ui->fromMonth->text().toInt() > ui->toMonth->text().toInt())
        {
            ui->toMonth->setText(ui->fromMonth->text());
            if(ui->fromDay->text().toInt() > ui->toDay->text().toInt())
            {
                ui->toDay->setText(ui->fromDay->text());
            }
        }
    }
    else if(ui->fromYear->text().toInt() == ui->toYear->text().toInt())
    {
        if(ui->fromMonth->text().toInt() > ui->toMonth->text().toInt())
        {
            ui->toMonth->setText(ui->fromMonth->text());
            if(ui->fromDay->text().toInt() > ui->toDay->text().toInt())
            {
                ui->toDay->setText(ui->fromDay->text());
            }
        }
        else if(ui->fromMonth->text().toInt() == ui->toMonth->text().toInt())
        {
            if(ui->fromDay->text().toInt() > ui->toDay->text().toInt())
            {
                ui->toDay->setText(ui->fromDay->text());
            }
        }

    }
}
void EditWindow::onToTimeFinished()
{
    if(ui->fromTime->time() > ui->toTime->time())
    {
        if(ui->fromYear->text().toInt() == ui->toYear->text().toInt())
        {
            if(ui->fromMonth->text().toInt() == ui->toMonth->text().toInt())
            {
                if(ui->fromDay->text().toInt() == ui->toDay->text().toInt())
                {
                    ui->toTime->setTime(ui->fromTime->time());
                }
            }
        }
    }
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
