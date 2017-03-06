#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pPlayer = new QMediaPlayer;
    pPlayer->setMedia(QUrl::fromLocalFile("D:/Desktop/Education/Qt/Lessons/Les27/Les27/003. AC-DC - Back In Black.mp3"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QApplication::beep();
}

void MainWindow::on_pushButton_2_clicked()
{
    pPlayer->play();
}
