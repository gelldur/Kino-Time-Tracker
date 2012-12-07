#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QDialog>
#include "Task.h"

namespace Ui {
class EditWindow;
}

class EditWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit EditWindow(QWidget *parent, Task *task);
    ~EditWindow();
    
private slots:
    void on_fromYear_editingFinished();

    void on_toYear_editingFinished();

private:
    Ui::EditWindow *ui;
};

#endif // EDITWINDOW_H
