#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pcb = QApplication::clipboard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    pcb->setText(ui->lineEdit->text());
}

void MainWindow::on_actionEdit_Window_triggered()
{
    Dialog *ed = new Dialog(this);
    ed->show();
}
