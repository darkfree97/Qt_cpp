#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QScriptEngine scriptEngine;
    QScriptValue value = scriptEngine.evaluate("2 * 2");
    ui->lcdNumber->display(value.toInt32());
}

MainWindow::~MainWindow()
{
    delete ui;
}
