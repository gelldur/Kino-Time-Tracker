#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class EditWindow;
}

class EditWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit EditWindow(QWidget *parent = 0);
    ~EditWindow();
    
private slots:
    void onFromDayEditingFinished();
    void onFromMonthEditingFinished();
    void onFromYearEditingFinished();
    void onToDayEditingFinished();
    void onToMonthEditingFinished();
    void onToYearEditingFinished();

private:
    Ui::EditWindow *ui;

    void dayValid(QLineEdit* day);
    void monthValid(QLineEdit* month);
    void yearValid(QLineEdit* year);

};

#endif // EDITWINDOW_H
