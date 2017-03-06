#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget_2->hide();
    setlocale(LC_ALL,"Russian");
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_saveStr_clicked()
{
    strcpy(strSch,ui->strForSearch->text().toUtf8().data());
    ui->textEditShowStr->append( QString ("%1").arg(strSch));
    char wer[256];
    strcpy(wer,strSch);
}

void MainWindow::on_findMatch_clicked()
{

    strcpy(keyWord,ui->keyWord->text().toUtf8().data());
    char *buf;
    char *buf2;
    buf=strtok(strSch," .,:;!?\n\t");
    ui->textEditShowFind->append(QString ("%1").arg(keyWord));
    ui->textEditShowFind->append(QString ("%1").arg("Знайдено відповідні:\n"));
    while(buf)
    {
        ui->textEditShowFind->append(QString ("%1").arg("------------------------"));
        if(Search(buf,keyWord))
        {
            ui->textEditShowFind->append(QString ("%1").arg(buf));
        }
        buf=strtok(0," .,:;!?\n\t");
    }
    ui->findMatch->setEnabled(0);
}

void MainWindow::on_action_triggered()
{

    ui->widget->hide();
    ui->widget_2->show();
    ui->keyWord->clear();
    ui->findMatch->setEnabled(1);
    ui->textEditShowFind->append( QString ("%1%2").arg(strSch).arg("\n"));

}

void MainWindow::on_action_3_triggered()
{
    ui->widget->show();
    ui->widget_2->hide();
    ui->strForSearch->clear();
    ui->textEditShowStr->clear();
    ui->textEditShowFind->clear();
}

void MainWindow::on_action_2_triggered()
{
    int point=0;
    for(int i=0;i<strlen(strSch);i++)
    {
        if(isdigit(strSch[i])>0)
        {
            point++;
        }
    }
    cout<<point<<endl;
}
