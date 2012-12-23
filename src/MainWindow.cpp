#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QTextStream>
#include "EditWindow.h"
#include "AboutDialog.h"
#include "Task.h"
#include "TaskManager.h"
#include "DatabaseManager.h"
#include <vector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    DatabaseManager::getInstance();

    ui->setupUi(this);

    connect(ui->menuEdit,SIGNAL(aboutToShow()),this,SLOT(openEditWindow()));
    connect(ui->ActionAbout,SIGNAL(triggered()),this,SLOT(openAboutDialog()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(clickButtonStart()));

    QStringList *myList = setAutoCompleter();
    myList->append("test");

    pWordCompleter = new QCompleter(*myList, this);
    pWordCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(pWordCompleter);


    TaskManager t;
    Task* task  = t.get(1);
    if(task != NULL)
        qDebug("Wyciagnalem taska id=%d tytul:%s dataS:%lld dataE=%lld opis: %s\n",
               task->getId(),
               task->getTitle().toAscii().constData(),
               task->getStartTime().toMSecsSinceEpoch(),
               task->getEndTime().toMSecsSinceEpoch(),
               task->getDescription().toAscii().constData());


    vector<Task*>* pTasks = t.getMostPopular(2);
    if(pTasks != NULL)
        for(int i=0;i<pTasks->size();++i)
        {
            Task* task  = pTasks->at(i);
            qDebug("Wyciagnalem taska id=%d tytul:%s dataS:%lld dataE=%lld opis: %s\n",
                   task->getId(),
                   task->getTitle().toAscii().constData(),
                   task->getStartTime().toMSecsSinceEpoch(),
                   task->getEndTime().toMSecsSinceEpoch(),
                   task->getDescription().toAscii().constData());
        }
    else
        qDebug() << "Brak wynikow";

}

QStringList *MainWindow::setAutoCompleter()
{
    QStringList *pTasksList = new QStringList();
    TaskManager autoCompleter;
    vector<Task*> *pSetTasks = autoCompleter.getMostPopular(20);

    if(pSetTasks == NULL)
    {
        return pTasksList;
    }
    for(int j=0; j<pSetTasks->size(); ++j)
    {
        Task *tasks = pSetTasks->at(j);
        QString str = tasks->getTitle();
        pTasksList->operator<<(str);
    }

    return pTasksList;
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
    Task *task = new Task("testowy", "opis testowy", QDateTime::currentMSecsSinceEpoch(), QDateTime::currentMSecsSinceEpoch());
    EditWindow* editWindow = new EditWindow(this, task);
    editWindow->show();
}

void MainWindow::openAboutDialog()
{
    /*AboutDialog aboutWindow;
    aboutWindow.setModal(true);
    aboutWindow.exec();*/
    QMessageBox::information(this, "About Time Tracker", "Created by KINO's group Adam Mickiewicz University");
}

void MainWindow::clickButtonStart()
{
    QString name = ui->lineEdit->text();
    TaskManager c;
    Task *task;
    if(name!=NULL && ui->pushButton->text()=="Start")
    {
        Task *task = new Task(name, "", QDateTime::currentMSecsSinceEpoch(),QDateTime::currentMSecsSinceEpoch());
        c.add(task);
        ui->pushButton->setText("Stop");
        return;
    }

    if(ui->pushButton->text()=="Stop")
    {
      //  c.update(task);
        ui->pushButton->setText("Start");
        return;
    }
}
