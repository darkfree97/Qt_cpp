#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QBrush>
#include <QPointF>
#include <QRadialGradient>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->c_disactivator->click();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_a_disactivator_clicked()
{
    ui->a_val->setReadOnly(true);
    ui->b_val->setReadOnly(false);
    ui->c_val->setReadOnly(false);
}

void MainWindow::on_b_disactivator_clicked()
{
    ui->a_val->setReadOnly(false);
    ui->b_val->setReadOnly(true);
    ui->c_val->setReadOnly(false);
}

void MainWindow::on_c_disactivator_clicked()
{
    ui->a_val->setReadOnly(false);
    ui->b_val->setReadOnly(false);
    ui->c_val->setReadOnly(true);
}
void MainWindow::valueChanged()
{
    int a = ui->a_val->value(),b = ui->b_val->value(),c = ui->c_val->value();
    if(ui->a_val->isReadOnly())
    {
        ui->a_val->setValue(sqrt((c*c)-(b*b)));
    }
    else if(ui->b_val->isReadOnly())
    {
        ui->b_val->setValue(sqrt((c*c)-(a*a)));
    }
    else if (ui->c_val->isReadOnly()) {
        ui->c_val->setValue(sqrt((a*a)+(b*b)));
    }
}
