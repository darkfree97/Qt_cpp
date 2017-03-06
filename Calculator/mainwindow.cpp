#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSpinBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSpinBox *sp1,*sp2;
    sp1 = ui->spinBox;
    sp2 = ui->spinBox_2;
    connect(sp1,SIGNAL(valueChanged(int)),SLOT(slotOperation()));
    connect(sp2,SIGNAL(valueChanged(int)),SLOT(slotOperation()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotOperation()
{
    QString op = ui->oporator->text();
    if(op=="+")
    {
        ui->spinBox_3->setValue(ui->spinBox->value()+ui->spinBox_2->value());
    }
    else if(op=="-")
    {
        ui->spinBox_3->setValue(ui->spinBox->value()-ui->spinBox_2->value());
    }
    else if(op=="*")
    {
        ui->spinBox_3->setValue(ui->spinBox->value()*ui->spinBox_2->value());
    }
    else if(op=="/")
    {
        if(ui->spinBox_2->value())
        {
            ui->spinBox_3->setValue(ui->spinBox->value()/ui->spinBox_2->value());
        }
    }
}

void MainWindow::on_plus_clicked()
{
    ui->oporator->setText("+");
    slotOperation();
}

void MainWindow::on_minus_clicked()
{
    ui->oporator->setText("-");
    slotOperation();
}

void MainWindow::on_up_on_clicked()
{
    ui->oporator->setText("*");
    slotOperation();
}

void MainWindow::on_down_on_clicked()
{
    ui->oporator->setText("/");
    slotOperation();
}
