#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->initWiget->hide();
    ui->add->setEnabled(false);
    ui->quit->setEnabled(false);

    QRegExp exp("[0-9]{1,10}");
    ui->lineEdit->setValidator(new QRegExpValidator(exp,this));
    ui->lineEdit_2->setValidator(new QRegExpValidator(exp,this));
    connect(ui->lineEdit_2,SIGNAL(textChanged(QString)),this,SLOT(GenEnabled()));

    begin = NULL;
    int mas[10];
    srand(time(NULL));
    for(int i=0; i<10; i++)
    {
        mas[i]=rand()%10+1;
    }
    Init(&begin,mas,10);
    Print(begin);

}

MainWindow::~MainWindow()
{
    Free(&begin);
    delete ui;
}

void MainWindow::GenEnabled()
{
    ui->add->setEnabled(ui->lineEdit_2->hasAcceptableInput());
}


void MainWindow::Print(List *b)
{
    ui->textEdit->clear();
    List *print = b;
    int i=1;
    while (print)
    {
        ui->textEdit->append( QString ("Елемент списку номер [%1] = < %2 >").arg(i).arg(print->a.key));
        print=print->next;
        i++;
    }
}
void MainWindow::Init(List **begin,int Mas[],int _n)
{
    *begin= new List;
        (*begin)->a.key=Mas[0];
        (*begin)->next=NULL;
        List * end = *begin;
        for (int i = 1; i < _n; ++i) {
            end->next=new List;
            end=end->next;
            end->a.key=Mas[i];
            end->next=NULL;
        }
}
void MainWindow::Free(List **begin)
{
    if(*begin==NULL)return;
    List *t1=*begin;
    List *t2;
    while (t1)
    {
        t2=t1;
        t1=t1->next;
        delete t2;
    }
    *begin= NULL;
}

void MainWindow::on_pushButton_clicked()
{
    searchEl = ui->lineEdit->text().toInt();
    value = Counter(begin);
    QString text;
    text.append(QString ("Елемент входить в список ( %1 )- разів").arg(value));
    QMessageBox::information(this,"Кількість входженнь елемента",text);
}

int MainWindow::Counter(List *b)
{
    value = 0;
    List *cOunt = b;
    while (cOunt)
    {
        if(searchEl == cOunt->a.key )
        {
            value++;
        }
        cOunt=cOunt->next;
    }
    return value;
}

void MainWindow::on_action_triggered()
{
    ui->textInitEdit->clear();
    Free(&begin);
    ui->initWiget->show();
    ui->widget->hide();
    point=0;
}

void MainWindow::on_action_2_triggered()
{
    Free(&begin);
    int mas[10];
    for(int i=0; i<10; i++)
    {
        mas[i]=rand()%10+1;
    }
    Init(&begin,mas,10);
    Print(begin);
}

void MainWindow::on_quit_clicked()
{
    ui->initWiget->hide();
    ui->widget->show();
    Init(&begin,Massive,point);
    Print(begin);
}

void MainWindow::on_add_clicked()
{
    Massive[point]=ui->lineEdit_2->text().toInt();
    ui->textInitEdit->append( QString ("Елемент списку номер [%1] = < %2 >").arg(point+1).arg(Massive[point]));
    point++;
    ui->lineEdit_2->clear();
    ui->quit->setEnabled(true);
}
