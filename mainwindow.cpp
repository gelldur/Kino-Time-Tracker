#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "editwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->menuEdit,SIGNAL(aboutToShow()),this,SLOT(openEditWindow()));

    QStringList myList;
    myList <<"Ala" <<"Asia"<<"Bartek"<<"Basia"<<"Czarek"<<"Cecylia"<<"Michal"<<"Mateusza"<<"Mateusz";
    p_WordCompleter = new QCompleter(myList, this);
    p_WordCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(p_WordCompleter);

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
