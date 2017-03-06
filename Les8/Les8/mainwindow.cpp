#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenu *pmnu = new QMenu(ui->pushButton_4);
    pmnu->addAction("Item1");
    pmnu->addAction("Item2");
    pmnu->addAction("&Quit",this,SLOT(close()));

    QPixmap pix(":/you.png");
    ui->pushButton_4->setIcon(pix);
    ui->pushButton_4->setIconSize(pix.size());
    ui->pushButton_4->setMenu(pmnu);
    constPal = this->palette();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioButton_clicked()
{
    int nLight = ui->light->isChecked() ? 150 : 80 ;
    pal.setColor(backgroundRole(),QColor(Qt::red).light(nLight));
    this->setPalette(pal);
}

void MainWindow::on_radioButton_2_clicked()
{
    int nLight = ui->light->isChecked() ? 150 : 80 ;
    pal.setColor(backgroundRole(),QColor(Qt::green).light(nLight));
    this->setPalette(pal);
}

void MainWindow::on_radioButton_3_clicked()
{
    int nLight = ui->light->isChecked() ? 150 : 80 ;
    pal.setColor(backgroundRole(),QColor(Qt::blue).light(nLight));
    this->setPalette(pal);
}

void MainWindow::on_groupBox_clicked(bool checked)
{
    if(!checked)
    {
        this->setPalette(constPal);
    }
    else {
        ui->radioButton->click();
    }
}
