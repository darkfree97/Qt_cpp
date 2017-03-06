#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pdock = new QDockWidget("Меню+",this);
    plbl = new QLabel("Label is dock",pdock);
    pdock->setWidget(plbl);
    addDockWidget(Qt::LeftDockWidgetArea,pdock);
    prBar = new QProgressBar;
    prBar->setRange(0,100);
    ui->statusBar->addWidget(prBar);
    xlbl = new QLabel;
    ylbl = new QLabel;
    ui->statusBar->addWidget(xlbl);
    ui->statusBar->addWidget(ylbl);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action1_triggered()
{
    ui->lineEdit->setText(ui->lineEdit->text().append(QString::number(1,16)));
}

void MainWindow::on_action2_triggered()
{
    ui->lineEdit->setText(ui->lineEdit->text().append(QString::number(2,16)));
}

void MainWindow::on_action3_triggered()
{
    ui->lineEdit->setText(ui->lineEdit->text().append(QString::number(3,16)));
}

void MainWindow::on_action4_triggered()
{
    ui->lineEdit->setText(ui->lineEdit->text().append(QString::number(4,16)));
}

void MainWindow::on_action5_triggered()
{
    ui->lineEdit->setText(ui->lineEdit->text().append(QString::number(5,16)));
}

void MainWindow::on_action6_triggered()
{
    ui->lineEdit->setText(ui->lineEdit->text().append(QString::number(6,16)));
}

void MainWindow::on_action7_triggered()
{
    ui->lineEdit->setText(ui->lineEdit->text().append(QString::number(7,16)));
}

void MainWindow::on_action8_triggered()
{
    ui->lineEdit->setText(ui->lineEdit->text().append(QString::number(8,16)));
}

void MainWindow::on_action9_triggered()
{
    ui->lineEdit->setText(ui->lineEdit->text().append(QString::number(9,16)));
}

void MainWindow::on_action0_triggered()
{
    ui->lineEdit->setText(ui->lineEdit->text().append(QString::number(0,16)));
}

void MainWindow::on_actionA_triggered()
{
    ui->lineEdit->setText(ui->lineEdit->text().append(QString::number(10,16)).toUpper());
}

void MainWindow::on_actionB_triggered()
{
    ui->lineEdit->setText(ui->lineEdit->text().append(QString::number(11,16)).toUpper());
}

void MainWindow::on_actionC_triggered()
{
    ui->lineEdit->setText(ui->lineEdit->text().append(QString::number(12,16)).toUpper());
}

void MainWindow::on_actionD_triggered()
{
    ui->lineEdit->setText(ui->lineEdit->text().append(QString::number(13,16)).toUpper());
}

void MainWindow::on_actionE_triggered()
{
    ui->lineEdit->setText(ui->lineEdit->text().append(QString::number(14,16)).toUpper());
}

void MainWindow::on_actionF_triggered()
{
    ui->lineEdit->setText(ui->lineEdit->text().append(QString::number(15,16)).toUpper());
}

void MainWindow::on_actionClean_triggered()
{
    ui->lineEdit->clear();
}

void MainWindow::on_dial_valueChanged(int value)
{
    prBar->setValue(value);
}
void MainWindow::mouseMoveEvent(QMouseEvent *pe)
{
    xlbl->setText("X = "+QString().setNum(pe->x()));
    ylbl->setText("Y = "+QString().setNum(pe->y()));
}
