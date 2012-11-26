#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "editwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->menuEdit,SIGNAL(aboutToShow()),this,SLOT(openEditWindow()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openEditWindow()
{

    EditWindow* editWindow = new EditWindow(this);
    editWindow->show();
}
