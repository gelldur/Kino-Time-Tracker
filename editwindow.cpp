#include "editwindow.h"
#include "ui_editwindow.h"
#include <QInputDialog>

EditWindow::EditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);

    QRegExp regExpDay("[0-3][0-9]");
    ui->FDay->setValidator(new QRegExpValidator(regExpDay, this));
    ui->TDay->setValidator(new QRegExpValidator(regExpDay, this));

    QRegExp regExpMonth("[0-1][0-9]");
    ui->FMonth->setValidator(new QRegExpValidator(regExpMonth, this));
    ui->TMonth->setValidator(new QRegExpValidator(regExpMonth, this));

    QRegExp regExpYear("[2][0][1][2-9]");
    ui->FYear->setValidator(new QRegExpValidator(regExpYear, this));
    ui->TYear->setValidator(new QRegExpValidator(regExpYear, this));
}

EditWindow::~EditWindow()
{
    delete ui;
}
