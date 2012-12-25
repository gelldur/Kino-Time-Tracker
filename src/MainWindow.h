#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCompleter>
#include <QFile>
#include "Task.h"
#include "TaskManager.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:

    Ui::MainWindow *ui;
    QCompleter *pWordCompleter;
    TaskManager c;
    Task *currentTask;
    QStringList* loadTextFile();
    QStringList *setAutoCompleter();

public slots:

   void openEditWindow();

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
   void openAboutDialog();
   void clickButtonStart();
};

#endif // MAINWINDOW_H
