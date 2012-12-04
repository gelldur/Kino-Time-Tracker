#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include "editwindow.h"
#include "about.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->menuEdit,SIGNAL(aboutToShow()),this,SLOT(openEditWindow()));

    QStringList* myList =  loadTextFile();
    /*QStringList myList;
    //myList <<"Ala" <<"Asia"<<"Bartek"<<"Basia"<<"Czarek"<<"Cecylia"<<"Michal"<<"Mateusza"<<"Mateusz";
    p_WordCompleter = new QCompleter(myList, this);*/
    p_WordCompleter = new QCompleter(*myList, this);
    p_WordCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(p_WordCompleter);
}

QStringList* MainWindow::loadTextFile()
{
    QFile inputFile(":/resources/list.txt");
    inputFile.open(QIODevice::ReadOnly);

    QStringList* list = new QStringList();
    QTextStream in(&inputFile);
    while ( !in.atEnd() )
    {
        QString line = in.readLine();
        list->push_back(line);
    }

    inputFile.close();
    return list;
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

void MainWindow::on_actionAbout_triggered()
{
    About aboutWindow;
    aboutWindow.setModal(true);
    aboutWindow.exec();
}
