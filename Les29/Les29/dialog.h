#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QClipboard>
#include <QCheckBox>
#include <QDebug>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_plainTextEdit_textChanged();

private:
    Ui::Dialog *ui;
    QClipboard *pcb;
    QCheckBox *plt;
};

#endif // DIALOG_H
