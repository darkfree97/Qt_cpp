#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QProgressDialog>
#include <QErrorMessage>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    StartDialog *pStartDialog = new StartDialog(this);
    if(pStartDialog->exec()==QDialog::Accepted)
    {
        QMessageBox::information(0,"Інформація","Ім'я: "+pStartDialog->f_name()+"\nПрізвище: "+pStartDialog->l_name());
    }
}

void MainWindow::on_commandLinkButton_clicked()
{
//    QFileDialog::getOpenFileName(this,"Пошук","D:/");
//    QColorDialog::getColor(Qt::green);
//    bool bOk;
//    QFontDialog::getFont(&bOk);
//    QInputDialog::getText(this,"Text","Input your string");

//   {int n = 100000;
//    QProgressDialog *ppbd = new QProgressDialog("Processing the data...","&Cancel",0,n);

//    ppbd->setMinimumDuration(0);
//    ppbd->setWindowTitle("Please Wait");
//    for(int i=0;i<n;i++)
//    {
//        ppbd->setValue(i);
//        QApplication::processEvents();
//        if(ppbd->wasCanceled())
//            break;
//    }
//    ppbd->setValue(n);
//    delete ppbd;}

//    QMessageBox::warning(this,"Warning","Something wrong");
//    QMessageBox::critical(this,"Error","Your computer is crashed");
//    QMessageBox::question(this,"Choise","Do you want to exit?","Yes","No");

    QErrorMessage *err = new QErrorMessage(this);
    err->showMessage("Write Error");
}
