#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myDate = QDate::currentDate();
    ui->dateEdit->setDate(myDate);
    startTimer(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
int valueCoef(QString *str)
{
    QString::iterator it = str->end();
    while(!it->isDigit()&&it!=str->begin())
    {
        it--;
    }
    if(*it=='0'||(*it>='5'&&*it<='9'))
    {
        return 0;
    }
    else if(*it=='1')
    {
        return 1;
    }
    else if(*it>='2'&&*it<='4')
    {
        return 2;
    }
    else
    {
        return -1;
    }
}
void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
    QDate dateNewYear(ui->dateEdit->date().year(),12,31);
    QString days;
    days.append(QString("%1").arg(myDate.daysTo(dateNewYear)));
    if(days.toInt()==364||days.toInt()==365)
    {
        ui->textEdit->append(QString("<h1><p><span style=\" color:#00ff00;\">З Новим Роком!!!</span></p></h1>"));
    }
    else if(days.toInt()==0)
    {
        ui->textEdit->append(QString("<h1><p><span style=\" color:#00ff00;\">Завтра Новий Рік!</span></p></h1>"));
    }
    else
    {
        ui->textEdit->append(QString("До нового року залишилось:"));
        ui->textEdit->append(QString("<h1><p><span style=\" color:#00ff00;\">%1</span></p></h1>").arg(days));
        switch (valueCoef(&days)) {
        case 0:
            ui->textEdit->append(QString("днів!"));
            break;
        case 1:
            ui->textEdit->append(QString("день!"));
            break;
        case 2:
            ui->textEdit->append(QString("дні!"));
        default:
            break;
        }
    }
}

void MainWindow::on_dateEdit_dateChanged(const QDate &date)
{
    myDate = date;
}
void MainWindow::timerEvent(QTimerEvent *)
{
    ui->statusBar->showMessage(QTime::currentTime().toString("hh:mm:ss"));
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->calendarWidget->setSelectedDate(QDate::currentDate());
}
void MainWindow::on_calendarWidget_selectionChanged()
{
    ui->dateEdit->setDate(ui->calendarWidget->selectedDate());
}
