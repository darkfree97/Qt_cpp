#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <QDialog>

namespace Ui {
class StartDialog;
}

class StartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StartDialog(QWidget *parent = 0);
    ~StartDialog();
    QString f_name()const;
    QString l_name()const;

private slots:

private:
    Ui::StartDialog *ui;


};

#endif // STARTDIALOG_H
