#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),SLOT(valueUp()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::valueUp()
{
    value = ui->progressBar->value();
    if(value!=100)
    {
        value+=5;
        ui->progressBar->setValue(value);
    }
    else {
        close();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    value = 0;
    ui->progressBar->setValue(value);
}
