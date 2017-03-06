#include "StartDialog.h"
#include "ui_StartDialog.h"

StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartDialog)
{
    ui->setupUi(this);
}

StartDialog::~StartDialog()
{
    delete ui;
}
QString StartDialog::f_name()const
{
    return ui->firstName->text();
}
QString StartDialog::l_name()const
{
    return ui->lastName->text();
}
