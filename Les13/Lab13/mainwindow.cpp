#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette pal = ui->spb->palette();
    pal.setBrush(QPalette::Button,QBrush(Qt::red,Qt::Dense3Pattern));
    pal.setColor(QPalette::ButtonText,Qt::blue);
    pal.setColor(QPalette::Text,Qt::magenta);
    pal.setColor(QPalette::Active,QPalette::Base,Qt::gray);
    ui->spb->setPalette(pal);
    ui->spb->resize(50,50);
}

MainWindow::~MainWindow()
{
    delete ui;
}
