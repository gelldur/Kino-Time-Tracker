#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCompleter>
#include <QFile>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:

    Ui::MainWindow *ui;
    QCompleter *p_WordCompleter;
    QStringList* loadTextFile();

public slots:

   void openEditWindow();

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

};

#endif // MAINWINDOW_H