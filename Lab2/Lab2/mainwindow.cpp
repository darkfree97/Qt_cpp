#include "mainwindow.h"
#include "ui_mainwindow.h"


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton->setEnabled(0);
    ui->menu->setEnabled(0);

    QRegExp exp("[1-9]{1}[0-9]{0,4}");
    ui->lineEdit->setValidator(new QRegExpValidator(exp,this));    
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(GenEnabled()));

}

MainWindow::~MainWindow()
{
    delete[]arr;
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->menu->setEnabled(1);
    delete[]arr;
    ui->genTextEdit->clear();
    n=ui->lineEdit->text().toInt(&ok,10);
    arr = new int[n];
    Generate(n,arr);
    for(int i=0;i<n;i++)
    {
        ui->genTextEdit->append( QString ("Mas[%1]=%2").arg(i+1).arg(arr[i]));
    }
    ui->statusBar->showMessage("Масив згенеровано !!!",2000);

}
void MainWindow::Generate(int n,int arr[])
{
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%100-10;
    }
}

void MainWindow::on_Up1_triggered()
{
    point =0;
    ui->resultTaxtEdit->clear();
    int i,j,value;
    int mas[n];
    for(i = 0; i < n; i++)
    {
        mas[i]=arr[i];
    }
    clock_t startTime =clock();
    for(i = 1; i < n; i++)
    {
        value = mas[i];
        for (j = i - 1; j >= 0 && mas[j] > value; j--)
        {
            mas[j + 1] = mas[j];
            point++;
        }
        mas[j+1] = value;
    }
    double timeWork = double (clock()- startTime)/(double)CLOCKS_PER_SEC;
    for(int i=0;i<n;i++)
    {
        ui->resultTaxtEdit->append( QString ("Mas[%1]=%2").arg(i+1).arg(mas[i]));
    }
    ui->statusBar->showMessage("Відсортовано методом вставки !!!");
    ui->perestanovka->display(point);
    ui->timer->display(timeWork);
    cout << point << endl;
}

void MainWindow::on_Down1_triggered()
{
    point = 0;
    ui->resultTaxtEdit->clear();
    int i,j,value;
    int mas[n];
    for(i = 0; i < n; i++)
    {
        mas[i]=arr[i];        
    }
    clock_t startTime =clock();
    for(i = 1; i < n; i++)
    {
        value = mas[i];
        for (j = i - 1; j >= 0 && mas[j] < value; j--)
        {
            mas[j + 1] = mas[j];
            point++;
        }
        mas[j+1] = value;
    }
    double timeWork = double (clock()- startTime)/(double)CLOCKS_PER_SEC;
    for(int i=0;i<n;i++)
    {
        ui->resultTaxtEdit->append( QString ("Mas[%1]=%2").arg(i+1).arg(mas[i]));
    }
    ui->statusBar->showMessage("Відсортовано методом вставки !!!");
    ui->perestanovka->display(point);
    ui->timer->display(timeWork);
    cout << point << endl;
}


void MainWindow::on_Up2_triggered()
{
    ui->resultTaxtEdit->clear();
    int mas[n];
    for(int i = 0; i < n; i++)
    {
        mas[i]=arr[i];
    }
    clock_t startTime =clock();
    point = Quick_sort(mas,0,n-1,0);
    double timeWork = double (clock()- startTime)/(double)CLOCKS_PER_SEC;
    for(int i=0;i<n;i++)
    {
        ui->resultTaxtEdit->append( QString ("Mas[%1]=%2").arg(i+1).arg(mas[i]));
    }
    ui->statusBar->showMessage("Відсортовано методом швидкого сортування !!!");
    ui->perestanovka->display(point);
    ui->timer->display(timeWork);
    cout << point << endl;
}
void MainWindow::on_Down2_triggered()
{
    ui->resultTaxtEdit->clear();
    int mas[n];
    for(int i = 0; i < n; i++)
    {
        mas[i]=arr[i];
    }
    clock_t startTime =clock();
    point = Quick_sort(mas,0,n-1,0);
    double timeWork = double (clock()- startTime)/(double)CLOCKS_PER_SEC;
    int mas2[n];
    for (int i = 0;i<n;++i)
    {
        mas2[i]=mas[(n-1)-i];
    }
    for(int i=0;i<n;i++)
    {
        ui->resultTaxtEdit->append( QString ("Mas[%1]=%2").arg(i+1).arg(mas2[i]));
    }
    ui->statusBar->showMessage("Відсортовано методом швидкого сортування !!!");
    ui->perestanovka->display(point);
    ui->timer->display(timeWork);
    cout << point << endl;
}


int MainWindow::Quick_sort(int *mas, int first, int last,int point)
{
    int mid,tmp;
    int f=first,l=last;
    mid=mas[(f+l)/2];
    do
    {
        while (mas[f]<mid) {
            f++;
        }
        while (mas[l]>mid) {
            l--;
        }
        if(f<=l)
        {
            tmp=mas[f];
            mas[f]=mas[l];
            mas[l]=tmp;
            f++;
            l--;
            point++;
        }
    }while(f<l);



    if(first<l)
    {
        point+=Quick_sort(mas,first,l,point);
    }
    if(f<last)
    {
        point+=Quick_sort(mas,f,last,point);
    }
    return point;

}
void MainWindow::GenEnabled()
{
    ui->pushButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}
