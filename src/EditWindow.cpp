#include <QDateTime>
#include <QInputDialog>
#include <cstdio>

#include "EditWindow.h"
#include "ui_EditWindow.h"

EditWindow::EditWindow(QWidget *parent, Task *task) :
    QDialog(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);

    QRegExp regExpDay("0[1-9]|[12][0-9]|3[01]");
    ui->fromDay->setValidator(new QRegExpValidator(regExpDay, this));
    QString dayStart = task->getStartTime().toString("dd");
    ui->fromDay->setText(dayStart);
    ui->toDay->setValidator(new QRegExpValidator(regExpDay, this));
    QString dayEnd = task->getStartTime().toString("dd");
    ui->toDay->setText(dayEnd);

    QRegExp regExpMonth("0[1-9]|1[012]");
    ui->fromMonth->setValidator(new QRegExpValidator(regExpMonth, this));
    QString monthStart = task->getStartTime().toString("mm");
    ui->fromMonth->setText(monthStart);
    ui->toMonth->setValidator(new QRegExpValidator(regExpMonth, this));
    QString monthEnd = task->getStartTime().toString("mm");
    ui->toMonth->setText(monthEnd);

    //QString stringYear = QDateTime::currentDateTime().toString("yyyy");
    QRegExp regExpYear("[0-9]{4}");
    ui->fromYear->setValidator(new QRegExpValidator(regExpYear, this));
    QString yearStart = task->getStartTime().toString("yyyy");
    ui->fromDay->setText(yearStart);
    ui->toYear->setValidator(new QRegExpValidator(regExpYear, this));
    QString yearEnd = task->getStartTime().toString("yyyy");
    ui->fromDay->setText(yearEnd);
}

EditWindow::~EditWindow()
{
    delete ui;
}

void EditWindow::on_fromYear_editingFinished()
{
    QString stringYear = QDateTime::currentDateTime().toString("yyyy");
    int intStringYear = stringYear.toInt();

    QString stringFromYear = ui->fromYear->text();
    int yearFrom = stringFromYear.toInt();
    if(yearFrom>intStringYear) ui->fromYear->setText(stringYear);
    if(yearFrom<1900) ui->fromYear->setText("1900");
}

void EditWindow::on_toYear_editingFinished()
{
    QString stringYear = QDateTime::currentDateTime().toString("yyyy");
    int intStringYear = stringYear.toInt();

    QString stringToYear = ui->toYear->text();
    int yearTo = stringToYear.toInt();
    if(yearTo>intStringYear) ui->toYear->setText(stringYear);
    if(yearTo<1900) ui->toYear->setText("1900");
}
