#include "MyForm.h"
#include "ui_MyForm.h"

MyForm::MyForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyForm)
{
    ui->setupUi(this);
}

MyForm::~MyForm()
{
    delete ui;
}
void MyForm::on_pushButton_clicked()
{
    ui->horizontalSlider->setValue(0);
}
