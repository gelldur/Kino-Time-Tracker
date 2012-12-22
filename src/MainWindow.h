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
    QCompleter *pWordCompleter;
    QStringList* loadTextFile();
    QStringList *setAutoCompleter();

public slots:

   void openEditWindow();

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
   void openAboutDialog();
};

#endif // MAINWINDOW_H
