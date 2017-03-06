#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->delButton->hide();
    ui->seeButton->hide();
    ui->pointButton->hide();
    t = new node;
}

MainWindow::~MainWindow()
{
    delete t;
    delete ui;
}
void MainWindow::Print(node *tree,int u)
{
    if (tree==NULL) return;
    else
    {
        Print(tree->r,++u);
        QString space;
        for (int i=1;i<u;++i) space.append(QString ("   "));
        ui->textEdit->append( QString ("%1 %2").arg(space).arg(tree->info));
        space.clear();
        u--;
        Print(tree->l,++u);
    }
}
bool SearchInTree(node *tree,int d)
{
    if(tree==NULL)
    {
        return false;
    }
    if(tree->info==d)
        return true;
    if(d<tree->info)
        return SearchInTree(tree->l,d);
    else
        return SearchInTree(tree->r,d);
}
vector<int>a;
void PushToArr(node *tree)
{
    if (tree==NULL) return;
    else
    {
        PushToArr(tree->r);
        a.push_back(tree->info);
        PushToArr(tree->l);
    }
}
int PointIncludes(int n)
{
    int k=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==n)
            k++;
    }
    return k;
}

void MainWindow::on_pushButton_clicked()
{
    int k = ui->pushEdit->text().toInt();
    tree.Push(k);
    ui->pushEdit->clear();
    ui->action->triggered(true);
}

void MainWindow::on_action_triggered()
{
    (*t)=tree.ReturnTree();
    ui->textEdit->clear();
    Print(t,0);
}

void MainWindow::on_action_2_triggered()
{
    ui->delButton->show();
    ui->pushButton->hide();
}

void MainWindow::on_delButton_clicked()
{
    tree.DelElem(ui->pushEdit->text().toInt());
    ui->pushEdit->clear();
    ui->action->triggered(true);
    ui->pushButton->show();
    ui->delButton->hide();
}

void MainWindow::on_action_3_triggered()
{
    ui->pushButton->hide();
    ui->seeButton->show();
}
void MainWindow::on_action_4_triggered()
{
    ui->pushButton->hide();
    ui->pointButton->show();
}
void MainWindow::on_action_5_triggered()
{
    int k=1;
    a.clear();
    (*t)=tree.ReturnTree();
    PushToArr(t);
    for(int i=0;i<a.size();i++)
    {
        k*=a[i];
    }
    QString text;
    text.append(QString ("Добуток всіх елементів = %1").arg(k));
    QMessageBox::information(this,"Результат обчислення",text);
}
void MainWindow::on_seeButton_clicked()
{
    (*t)=tree.ReturnTree();
    if(SearchInTree(t,ui->pushEdit->text().toInt()))
    {
        QString text;
        text.append(QString ("Елемент входить в дерево !!!"));
        QMessageBox::information(this,"Входження елемента",text);
    }
    else
    {
        QString text;
        text.append(QString ("Елемент не входить в дерево !!!"));
        QMessageBox::information(this,"Входження елемента",text);
    }
    ui->seeButton->hide();
    ui->pushButton->show();
}
void MainWindow::on_pointButton_clicked()
{
    a.clear();
    (*t)=tree.ReturnTree();
    PushToArr(t);
    int k = PointIncludes(ui->pushEdit->text().toInt());
    QString text;
    text.append(QString ("Елемент входить в дерево (%1) разів !!!").arg(k));
    QMessageBox::information(this,"Входження елемента",text);
    ui->pointButton->hide();
    ui->pushButton->show();
}
