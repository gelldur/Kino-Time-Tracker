#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QTextStream>
#include "EditWindow.h"
#include "AboutDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->menuEdit,SIGNAL(aboutToShow()),this,SLOT(openEditWindow()));

    QStringList* myList =  loadTextFile();
    /*QStringList myList;
    //myList <<"Ala" <<"Asia"<<"Bartek"<<"Basia"<<"Czarek"<<"Cecylia"<<"Michal"<<"Mateusza"<<"Mateusz";
    pWordCompleter = new QCompleter(myList, this);*/
    pWordCompleter = new QCompleter(*myList, this);
    pWordCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(pWordCompleter);
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

void MainWindow::onActionAboutTriggered()
{
    /*About aboutWindow;
    aboutWindow.setModal(true);
    aboutWindow.exec();*/
    QMessageBox::information(this, "About Time Tracker", "Created by KINO's group Adam Mickiewicz University");
}