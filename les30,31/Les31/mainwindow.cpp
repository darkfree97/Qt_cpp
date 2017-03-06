#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cMenu = new ContextMenu;
    ui->gridLayout_2->addWidget(cMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_About_Qt_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::on_action_Exit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionCheckable_Item_triggered(bool checked)
{
    (!checked)?cMenu->setText("Checkable Item not active"):cMenu->setText("Checkable Item is active");
}
