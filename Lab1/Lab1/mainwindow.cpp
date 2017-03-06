#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(545,345);
    ui->mainEditNew->setEnabled(false);
    ui->showWidget->hide();
    shWin = true;
    ui->seachEdit->hide();
    ui->seachButton->hide();
    ui->newSeach->hide();
    schLay = true;
    ui->OK->setVisible(false);

    ui->saveChange->hide();
    ui->delChange->hide();
    ui->editChange->hide();
    ui->saveChange->setEnabled(false);
    ui->delChange->setEnabled(false);
    saveChangeBool = false;

    ui->showWidget->setRowCount(100);
    ui->showWidget->setColumnCount(8);
    ui->showWidget->setHorizontalHeaderLabels(QStringList() <<"Номер автомобіля"<<"Марка"<<"Прізвище власника"<<"Ім'я власника"<<"Вулиця"<<"Будинок"<<"Квартира"<<"К-ть штрафів");

    QRegExp numAexp("[А-Я]{2}[0-9]{4}[А-Я]{2}");
    ui->numAEdit->setValidator(new QRegExpValidator(numAexp,this));

    QRegExp markAexp("[0-9a-zA-ZА-ІЇ-Яа-ії-я ]{1,50}");
    ui->markAEdit->setValidator(new QRegExpValidator(markAexp,this));

    QRegExp snameexp("[А-ІЇ-Я]{0,1}[а-ії-я]{1,10}");
    ui->Surname->setValidator(new QRegExpValidator(snameexp,this));

    QRegExp nameexp("[А-ІЇ-Я]{0,1}[а-ії-я]{1,10}");
    ui->Name->setValidator(new QRegExpValidator(nameexp,this));

    QRegExp strtexp("[0-9a-zA-ZА-ІЇ-Яа-ії-я -]{1,15}");
    ui->street->setValidator(new QRegExpValidator(strtexp,this));

    QRegExp housexp("[0-9]{1,4}[A-ZА-ІЇ-Я ]{0,1}");
    ui->house->setValidator(new QRegExpValidator(housexp,this));

    QRegExp depexp("[0-9]{1,4}[A-ZА-ІЇ-Я ]{0,1}");
    ui->department->setValidator(new QRegExpValidator(depexp,this));

    QRegExp warexp("[0-9]{1,5}");
    ui->warning->setValidator(new QRegExpValidator(warexp,this));

    index=10;
    InitEnt(e);
    Print(e,index);

}

MainWindow::~MainWindow()
{
    Free(e,index);
    delete ui;
}


void MainWindow::on_showAll_triggered()
{
    if(shWin)
    {
        ui->showWidget->show();
        this->resize(545,this->height()+180);
        shWin = false;
    }
    else
    {
        ui->showWidget->hide();
        this->resize(545,this->height()-180);
        shWin = true;
    }
}

void MainWindow::on_addNew_triggered()
{
    ui->OK->setEnabled(true);
    ui->numAEdit->clear();
    ui->markAEdit->clear();
    ui->Surname->clear();
    ui->Name->clear();
    ui->house->clear();
    ui->street->clear();
    ui->department->clear();
    ui->warning->clear();
    ui->mainEditNew->setEnabled(true);
    ui->editChange->hide();
    ui->saveChange->hide();
    ui->delChange->hide();
    ui->OK->show();
    ui->statusBar->showMessage("Введіть потрібні дані.");

}

void MainWindow::on_findElem_triggered()
{    
    if(schLay)
    {
        ui->statusBar->showMessage("Введіть дані для пошуку!!!");
        ui->seachEdit->show();
        ui->seachButton->show();
        this->resize(545,this->height()+20);
        schLay = false;
    }
    else
    {
        ui->statusBar->showMessage(" ");
        ui->seachEdit->hide();
        ui->seachButton->hide();
        this->resize(545,this->height()-20);
        schLay = true;

    }
}

void MainWindow::on_editElem_triggered()
{
    ui->mainEditNew->setEnabled(false);
    if(chEdit)
    {
        ui->OK->hide();
        ui->saveChange->show();
        ui->delChange->show();
        ui->editChange->show();
        if(shWin){
            ui->showWidget->show();
            this->resize(545,this->height()+180);
            shWin=false;
        }
        chEdit = false;
        ui->statusBar->showMessage("Ви в режимі редагування!!!");
    }
    else
    {
        ui->OK->show();
        ui->saveChange->hide();
        ui->delChange->hide();
        ui->editChange->hide();
        if(!shWin)
        {
            ui->showWidget->hide();
            this->resize(545,this->height()-180);
            shWin=true;
        }
        chEdit = true;
        ui->statusBar->showMessage(" ");
    }
}

void MainWindow::on_Close_clicked()
{
    close();
}

void MainWindow::on_OK_clicked()
{
    ui->mainEditNew->setEnabled(false);

    Input(e[index]);    
    index++;

    Print(e,index);

    ui->statusBar->showMessage("Запис збережено!!!");
    ui->OK->setVisible(false);
}

void MainWindow::Input(Enterprise &e)
{

    e.infnumauto=new QString[100];
    e.infnumauto->append(QString ("%1").arg(ui->numAEdit->text()));

    e.infmarkauto=new QString[100];
    e.infmarkauto->append(QString ("%1").arg(ui->markAEdit->text()));

    e.infsurname=new QString[100];
    e.infsurname->append(QString ("%1").arg(ui->Surname->text()));

    e.infname=new QString[100];
    e.infname->append(QString ("%1").arg(ui->Name->text()));

    e.adrstreet=new QString[100];
    e.adrstreet->append(QString ("%1").arg(ui->street->text()));

    e.adrhouse=new QString[100];
    e.adrhouse->append(QString ("%1").arg(ui->house->text()));

    e.adrdep=new QString[100];
    e.adrdep->append(QString ("%1").arg(ui->department->text()));

    e.infwarning=new QString[100];
    e.infwarning->append(QString ("%1").arg(ui->warning->text()));

}

void MainWindow::Update(Enterprise e[], int k)
{
    Input (e[k]);
}

void MainWindow::PrintElem(Enterprise e)
{
    qDebug()<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
    qDebug()<<"Номер авто: "<<*e.infnumauto<<endl;
    qDebug()<<"Марка авто: "<<*e.infmarkauto<<endl;
    qDebug()<<"Прізвище: "<<*e.infsurname<<endl;
    qDebug()<<"Ім'я:"<<*e.infname<<endl;
    qDebug()<<"Вулиця: "<<*e.adrstreet<<endl;
    qDebug()<<"Будинок: "<<*e.adrhouse<<endl;
    qDebug()<<"Квартира: "<<*e.adrdep<<endl;
    qDebug()<<"Кількість штрафів: "<<*e.infwarning<<endl;
    qDebug()<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
}

void MainWindow::Print(Enterprise e[], int n)
{
    for (int i = 0; i <n; ++i)
    {
        //PrintElem(e[i]);
        QTableWidgetItem *itmNM = new QTableWidgetItem(e[i].infnumauto->toHtmlEscaped());
        ui->showWidget->setItem(i,0,itmNM);
        QTableWidgetItem *itmMM = new QTableWidgetItem(e[i].infmarkauto->toHtmlEscaped());
        ui->showWidget->setItem(i,1,itmMM);
        QTableWidgetItem *itmSN = new QTableWidgetItem(e[i].infsurname->toHtmlEscaped());
        ui->showWidget->setItem(i,2,itmSN);
        QTableWidgetItem *itmNN = new QTableWidgetItem(e[i].infname->toHtmlEscaped());
        ui->showWidget->setItem(i,3,itmNN);
        QTableWidgetItem *itmAS = new QTableWidgetItem(e[i].adrstreet->toHtmlEscaped());
        ui->showWidget->setItem(i,4,itmAS);
        QTableWidgetItem *itmAH = new QTableWidgetItem(e[i].adrhouse->toHtmlEscaped());
        ui->showWidget->setItem(i,5,itmAH);
        QTableWidgetItem *itmAD = new QTableWidgetItem(e[i].adrdep->toHtmlEscaped());
        ui->showWidget->setItem(i,6,itmAD);
        QTableWidgetItem *itmWR = new QTableWidgetItem(e[i].infwarning->toHtmlEscaped());
        ui->showWidget->setItem(i,7,itmWR);
    }
}
void MainWindow::Delete(Enterprise e[], int num_el_for_del, int quantity_el)
{
    swap(e[num_el_for_del],e[quantity_el-1]);
    delete []e[quantity_el-1].infnumauto;
    delete []e[quantity_el-1].infmarkauto;
    delete []e[quantity_el-1].infsurname;
    delete []e[quantity_el-1].infname;
    delete []e[quantity_el-1].adrstreet;
    delete []e[quantity_el-1].adrhouse;
    delete []e[quantity_el-1].adrdep;
    delete []e[quantity_el-1].infwarning;

    QTableWidgetItem *itmNM = new QTableWidgetItem("");
    ui->showWidget->setItem(quantity_el-1,0,itmNM);
    QTableWidgetItem *itmMM = new QTableWidgetItem("");
    ui->showWidget->setItem(quantity_el-1,1,itmMM);
    QTableWidgetItem *itmSN = new QTableWidgetItem("");
    ui->showWidget->setItem(quantity_el-1,2,itmSN);
    QTableWidgetItem *itmNN = new QTableWidgetItem("");
    ui->showWidget->setItem(quantity_el-1,3,itmNN);
    QTableWidgetItem *itmAS = new QTableWidgetItem("");
    ui->showWidget->setItem(quantity_el-1,4,itmAS);
    QTableWidgetItem *itmAH = new QTableWidgetItem("");
    ui->showWidget->setItem(quantity_el-1,5,itmAH);
    QTableWidgetItem *itmAD = new QTableWidgetItem("");
    ui->showWidget->setItem(quantity_el-1,6,itmAD);
    QTableWidgetItem *itmWR = new QTableWidgetItem("");
    ui->showWidget->setItem(quantity_el-1,7,itmWR);

    delete itmNM;
    delete itmMM;
    delete itmSN;
    delete itmNN;
    delete itmAS;
    delete itmAH;
    delete itmAD;
    delete itmWR;

    index--;
}
void MainWindow::Free(Enterprise *e, int n)
{
    for (int i = 0; i <n; ++i)
    {
        delete []e[i].infnumauto;
        delete []e[i].infmarkauto;
        delete []e[i].infsurname;
        delete []e[i].infname;
        delete []e[i].adrstreet;
        delete []e[i].adrhouse;
        delete []e[i].adrdep;
        delete []e[i].infwarning;
    }
}

void MainWindow::on_showWidget_doubleClicked(const QModelIndex &_index)
{
    try
    {
        saveChangeBool = true;
        ui->OK->setEnabled(false);
        pointElForEd = _index.row();
        if(pointElForEd > index)
        {
            pointElForEd = index-1;
        }
        ui->mainEditNew->setEnabled(false);
        ui->numAEdit->setText(e[pointElForEd].infnumauto->toHtmlEscaped());
        ui->markAEdit->setText(e[pointElForEd].infmarkauto->toHtmlEscaped());
        ui->Surname->setText(e[pointElForEd].infsurname->toHtmlEscaped());
        ui->Name->setText(e[pointElForEd].infname->toHtmlEscaped());
        ui->street->setText(e[pointElForEd].adrstreet->toHtmlEscaped());
        ui->house->setText(e[pointElForEd].adrhouse->toHtmlEscaped());
        ui->department->setText(e[pointElForEd].adrdep->toHtmlEscaped());
        ui->warning->setText(e[pointElForEd].infwarning->toHtmlEscaped());
    }
    catch(...)
    {
        ui->statusBar->showMessage("Error",5000);
    }
}

void MainWindow::on_editChange_clicked()
{
    if(saveChangeBool)
    {
        ui->mainEditNew->setEnabled(true);
        ui->saveChange->setEnabled(true);
        ui->delChange->setEnabled(true);
    }
    else
    {

        ui->statusBar->showMessage("Ви не виділили елемент для редагування !!!",2000);
    }
}

void MainWindow::on_delChange_clicked()
{
    Delete(e,pointElForEd,index);
    ui->statusBar->showMessage("Запис було успішно видалено!!!",2000);
    Print(e,index);
    ui->saveChange->setEnabled(false);
    ui->delChange->setEnabled(false);
    saveChangeBool = false;
    ui->numAEdit->clear();
    ui->markAEdit->clear();
    ui->Surname->clear();
    ui->Name->clear();
    ui->house->clear();
    ui->street->clear();
    ui->department->clear();
    ui->warning->clear();
    ui->mainEditNew->setEnabled(false);
}

void MainWindow::InitEnt(struct Enterprise e[])
{
    e[0].infnumauto=new QString[100];
    e[0].infnumauto->append(QString ("%1").arg("СЕ7777АА"));


    e[0].infmarkauto=new QString[100];
    e[0].infmarkauto->append(QString ("%1").arg("PaganiZonda"));

    e[0].infsurname=new QString[100];
    e[0].infsurname->append(QString ("%1").arg("Палій"));

    e[0].infname=new QString[100];
    e[0].infname->append(QString ("%1").arg("Ігор"));

    e[0].adrstreet=new QString[100];
    e[0].adrstreet->append(QString ("%1").arg("Тильчинська"));

    e[0].adrhouse=new QString[100];
    e[0].adrhouse->append(QString ("%1").arg("36"));

    e[0].adrdep=new QString[100];
    e[0].adrdep->append(QString ("%1").arg("5"));

    e[0].infwarning=new QString[100];
    e[0].infwarning->append(QString ("%1").arg("0"));

    /////////////////////////////////////////////////////////////////////


    e[1].infnumauto=new QString[100];
    e[1].infnumauto->append(QString ("%1").arg("СЕ3748АА"));

    e[1].infmarkauto=new QString[100];
    e[1].infmarkauto->append(QString ("%1").arg("Chevrolet"));

    e[1].infsurname=new QString[100];
    e[1].infsurname->append(QString ("%1").arg("Захаров"));

    e[1].infname=new QString[100];
    e[1].infname->append(QString ("%1").arg("Олег"));

    e[1].adrstreet=new QString[100];
    e[1].adrstreet->append(QString ("%1").arg("Головна"));

    e[1].adrhouse=new QString[100];
    e[1].adrhouse->append(QString ("%1").arg("49"));

    e[1].adrdep=new QString[100];
    e[1].adrdep->append(QString ("%1").arg("4"));

    e[1].infwarning=new QString[100];
    e[1].infwarning->append(QString ("%1").arg("9"));

    /////////////////////////////////////////////////////////////////////

    e[2].infnumauto=new QString[100];
    e[2].infnumauto->append(QString ("%1").arg("СЕ5374АА"));

    e[2].infmarkauto=new QString[100];
    e[2].infmarkauto->append(QString ("%1").arg("Maserati"));

    e[2].infsurname=new QString[100];
    e[2].infsurname->append(QString ("%1").arg("Прокопчук"));

    e[2].infname=new QString[100];
    e[2].infname->append(QString ("%1").arg("Ганна"));

    e[2].adrstreet=new QString[100];
    e[2].adrstreet->append(QString ("%1").arg("Гагаріна"));

    e[2].adrhouse=new QString[100];
    e[2].adrhouse->append(QString ("%1").arg("16"));

    e[2].adrdep=new QString[100];
    e[2].adrdep->append(QString ("%1").arg("2"));

    e[2].infwarning=new QString[100];
    e[2].infwarning->append(QString ("%1").arg("6"));

    /////////////////////////////////////////////////////////////////////

    e[3].infnumauto=new QString[100];
    e[3].infnumauto->append(QString ("%1").arg("СЕ3684АА"));

    e[3].infmarkauto=new QString[100];
    e[3].infmarkauto->append(QString ("%1").arg("Bugatti"));

    e[3].infsurname=new QString[100];
    e[3].infsurname->append(QString ("%1").arg("Писарюк"));

    e[3].infname=new QString[100];
    e[3].infname->append(QString ("%1").arg("Дм'ян"));

    e[3].adrstreet=new QString[100];
    e[3].adrstreet->append(QString ("%1").arg("Ватутіна"));

    e[3].adrhouse=new QString[100];
    e[3].adrhouse->append(QString ("%1").arg("6"));

    e[3].adrdep=new QString[100];
    e[3].adrdep->append(QString ("%1").arg("3"));

    e[3].infwarning=new QString[100];
    e[3].infwarning->append(QString ("%1").arg("5"));

    /////////////////////////////////////////////////////////////////////

    e[4].infnumauto=new QString[100];
    e[4].infnumauto->append(QString ("%1").arg("СЕ9473АА"));

    e[4].infmarkauto=new QString[100];
    e[4].infmarkauto->append(QString ("%1").arg("BMW"));

    e[4].infsurname=new QString[100];
    e[4].infsurname->append(QString ("%1").arg("Скрипчук"));

    e[4].infname=new QString[100];
    e[4].infname->append(QString ("%1").arg("Олена"));

    e[4].adrstreet=new QString[100];
    e[4].adrstreet->append(QString ("%1").arg("Червоноармійська"));

    e[4].adrhouse=new QString[100];
    e[4].adrhouse->append(QString ("%1").arg("124"));

    e[4].adrdep=new QString[100];
    e[4].adrdep->append(QString ("%1").arg("1"));

    e[4].infwarning=new QString[100];
    e[4].infwarning->append(QString ("%1").arg("2"));

    /////////////////////////////////////////////////////////////////////

    e[5].infnumauto=new QString[100];
    e[5].infnumauto->append(QString ("%1").arg("СЕ3672АА"));

    e[5].infmarkauto=new QString[100];
    e[5].infmarkauto->append(QString ("%1").arg("Mersedes"));

    e[5].infsurname=new QString[100];
    e[5].infsurname->append(QString ("%1").arg("Ольжич"));

    e[5].infname=new QString[100];
    e[5].infname->append(QString ("%1").arg("Степан"));

    e[5].adrstreet=new QString[100];
    e[5].adrstreet->append(QString ("%1").arg("НебесноїСотні"));

    e[5].adrhouse=new QString[100];
    e[5].adrhouse->append(QString ("%1").arg("60"));

    e[5].adrdep=new QString[100];
    e[5].adrdep->append(QString ("%1").arg("6"));

    e[5].infwarning=new QString[100];
    e[5].infwarning->append(QString ("%1").arg("4"));

    /////////////////////////////////////////////////////////////////////

    e[6].infnumauto=new QString[100];
    e[6].infnumauto->append(QString ("%1").arg("СЕ3342АА"));

    e[6].infmarkauto=new QString[100];
    e[6].infmarkauto->append(QString ("%1").arg("Marussia"));

    e[6].infsurname=new QString[100];
    e[6].infsurname->append(QString ("%1").arg("Хлись"));

    e[6].infname=new QString[100];
    e[6].infname->append(QString ("%1").arg("Вікторія"));

    e[6].adrstreet=new QString[100];
    e[6].adrstreet->append(QString ("%1").arg("ПівдКільцева"));

    e[6].adrhouse=new QString[100];
    e[6].adrhouse->append(QString ("%1").arg("4"));

    e[6].adrdep=new QString[100];
    e[6].adrdep->append(QString ("%1").arg("3"));

    e[6].infwarning=new QString[100];
    e[6].infwarning->append(QString ("%1").arg("0"));

    /////////////////////////////////////////////////////////////////////

    e[7].infnumauto=new QString[100];
    e[7].infnumauto->append(QString ("%1").arg("СЕ5332АА"));

    e[7].infmarkauto=new QString[100];
    e[7].infmarkauto->append(QString ("%1").arg("Maybach"));

    e[7].infsurname=new QString[100];
    e[7].infsurname->append(QString ("%1").arg("Стефананик"));

    e[7].infname=new QString[100];
    e[7].infname->append(QString ("%1").arg("Володимир"));

    e[7].adrstreet=new QString[100];
    e[7].adrstreet->append(QString ("%1").arg("Руська"));

    e[7].adrhouse=new QString[100];
    e[7].adrhouse->append(QString ("%1").arg("88"));

    e[7].adrdep=new QString[100];
    e[7].adrdep->append(QString ("%1").arg("7"));

    e[7].infwarning=new QString[100];
    e[7].infwarning->append(QString ("%1").arg("1"));

    /////////////////////////////////////////////////////////////////////

    e[8].infnumauto=new QString[100];
    e[8].infnumauto->append(QString ("%1").arg("СЕ3212АА"));

    e[8].infmarkauto=new QString[100];
    e[8].infmarkauto->append(QString ("%1").arg("Toyota"));

    e[8].infsurname=new QString[100];
    e[8].infsurname->append(QString ("%1").arg("Гончарюк"));

    e[8].infname=new QString[100];
    e[8].infname->append(QString ("%1").arg("Марина"));

    e[8].adrstreet=new QString[100];
    e[8].adrstreet->append(QString ("%1").arg("Галицька"));

    e[8].adrhouse=new QString[100];
    e[8].adrhouse->append(QString ("%1").arg("190"));

    e[8].adrdep=new QString[100];
    e[8].adrdep->append(QString ("%1").arg("2"));

    e[8].infwarning=new QString[100];
    e[8].infwarning->append(QString ("%1").arg("4"));

    /////////////////////////////////////////////////////////////////////

    e[9].infnumauto=new QString[100];
    e[9].infnumauto->append(QString ("%1").arg("СЕ3432АА"));

    e[9].infmarkauto=new QString[100];
    e[9].infmarkauto->append(QString ("%1").arg("Rolls-Royce"));

    e[9].infsurname=new QString[100];
    e[9].infsurname->append(QString ("%1").arg("Лебідка"));

    e[9].infname=new QString[100];
    e[9].infname->append(QString ("%1").arg("Анастасія"));

    e[9].adrstreet=new QString[100];
    e[9].adrstreet->append(QString ("%1").arg("Хотинська"));

    e[9].adrhouse=new QString[100];
    e[9].adrhouse->append(QString ("%1").arg("56"));

    e[9].adrdep=new QString[100];
    e[9].adrdep->append(QString ("%1").arg("9"));

    e[9].infwarning=new QString[100];
    e[9].infwarning->append(QString ("%1").arg("12"));
}


void MainWindow::on_saveChange_clicked()
{
    delete []e[pointElForEd].infnumauto;
    delete []e[pointElForEd].infmarkauto;
    delete []e[pointElForEd].infsurname;
    delete []e[pointElForEd].infname;
    delete []e[pointElForEd].adrstreet;
    delete []e[pointElForEd].adrhouse;
    delete []e[pointElForEd].adrdep;
    delete []e[pointElForEd].infwarning;

    e[pointElForEd].infnumauto=new QString[100];
    e[pointElForEd].infnumauto->append(QString ("%1").arg(ui->numAEdit->text()));

    e[pointElForEd].infmarkauto=new QString[100];
    e[pointElForEd].infmarkauto->append(QString ("%1").arg(ui->markAEdit->text()));

    e[pointElForEd].infsurname=new QString[100];
    e[pointElForEd].infsurname->append(QString ("%1").arg(ui->Surname->text()));

    e[pointElForEd].infname=new QString[100];
    e[pointElForEd].infname->append(QString ("%1").arg(ui->Name->text()));

    e[pointElForEd].adrstreet=new QString[100];
    e[pointElForEd].adrstreet->append(QString ("%1").arg(ui->street->text()));

    e[pointElForEd].adrhouse=new QString[100];
    e[pointElForEd].adrhouse->append(QString ("%1").arg(ui->house->text()));

    e[pointElForEd].adrdep=new QString[100];
    e[pointElForEd].adrdep->append(QString ("%1").arg(ui->department->text()));

    e[pointElForEd].infwarning=new QString[100];
    e[pointElForEd].infwarning->append(QString ("%1").arg(ui->warning->text()));

    Print(e,index);
    ui->statusBar->showMessage("Зміни у записі збережено!!!",3000);
    ui->saveChange->setEnabled(false);
    ui->delChange->setEnabled(false);
    saveChangeBool = false;
}

void MainWindow::on_seachButton_clicked()
{
    seAch.append(QString ("%1").arg(ui->seachEdit->text()));
    for(int i=0; i<index; i++)
    {
        if((seAch.toHtmlEscaped().toUpper())==(e[i].infnumauto->toHtmlEscaped().toUpper()))
        {
            ui->showWidget->item(i,0)->setBackgroundColor(Qt::blue);
            for(int j=0; j<8; j++)
            {
                ui->showWidget->item(i,j)->setBackgroundColor(Qt::blue);
            }
        }
        if((seAch.toHtmlEscaped().toUpper())==(e[i].infmarkauto->toHtmlEscaped().toUpper()))
        {
            ui->showWidget->item(i,0)->setBackgroundColor(Qt::blue);
            for(int j=0; j<8; j++)
            {
                ui->showWidget->item(i,j)->setBackgroundColor(Qt::blue);
            }
        }
        if((seAch.toHtmlEscaped().toUpper())==(e[i].infsurname->toHtmlEscaped().toUpper()))
        {
            ui->showWidget->item(i,0)->setBackgroundColor(Qt::blue);
            for(int j=0; j<8; j++)
            {
                ui->showWidget->item(i,j)->setBackgroundColor(Qt::blue);
            }
        }
        if((seAch.toHtmlEscaped().toUpper())==(e[i].infname->toHtmlEscaped().toUpper()))
        {
            ui->showWidget->item(i,0)->setBackgroundColor(Qt::blue);
            for(int j=0; j<8; j++)
            {
                ui->showWidget->item(i,j)->setBackgroundColor(Qt::blue);
            }
        }
        if((seAch.toHtmlEscaped().toUpper())==(e[i].adrstreet->toHtmlEscaped().toUpper()))
        {
            ui->showWidget->item(i,0)->setBackgroundColor(Qt::blue);
            for(int j=0; j<8; j++)
            {
                ui->showWidget->item(i,j)->setBackgroundColor(Qt::blue);
            }
        }
        if((seAch.toHtmlEscaped().toUpper())==(e[i].adrhouse->toHtmlEscaped().toUpper()))
        {
            ui->showWidget->item(i,0)->setBackgroundColor(Qt::blue);
            for(int j=0; j<8; j++)
            {
                ui->showWidget->item(i,j)->setBackgroundColor(Qt::blue);
            }
        }
        if((seAch.toHtmlEscaped().toUpper())==(e[i].adrdep->toHtmlEscaped().toUpper()))
        {
            ui->showWidget->item(i,0)->setBackgroundColor(Qt::blue);
            for(int j=0; j<8; j++)
            {
                ui->showWidget->item(i,j)->setBackgroundColor(Qt::blue);
            }
        }
        if((seAch.toHtmlEscaped().toUpper())==(e[i].infwarning->toHtmlEscaped().toUpper()))
        {
            ui->showWidget->item(i,0)->setBackgroundColor(Qt::blue);
            for(int j=0; j<8; j++)
            {
                ui->showWidget->item(i,j)->setBackgroundColor(Qt::blue);
            }
        }

    }
    ui->statusBar->showMessage("Знайдені дані виділено синім фоном!!!");
    ui->seachEdit->setEnabled(0);
    ui->seachButton->setEnabled(0);
    ui->newSeach->show();
}

void MainWindow::on_newSeach_clicked()
{
    for(int i=0; i<index; i++)
    {
        if((seAch.toHtmlEscaped().toUpper())==(e[i].infnumauto->toHtmlEscaped().toUpper()))
        {
            for(int j=0; j<8; j++)
            {
                ui->showWidget->item(i,j)->setBackgroundColor(Qt::white);
            }
        }
        if((seAch.toHtmlEscaped().toUpper())==(e[i].infmarkauto->toHtmlEscaped().toUpper()))
        {
            for(int j=0; j<8; j++)
            {
                ui->showWidget->item(i,j)->setBackgroundColor(Qt::white);
            }
        }
        if((seAch.toHtmlEscaped().toUpper())==(e[i].infsurname->toHtmlEscaped().toUpper()))
        {
            for(int j=0; j<8; j++)
            {
                ui->showWidget->item(i,j)->setBackgroundColor(Qt::white);
            }
        }
        if((seAch.toHtmlEscaped().toUpper())==(e[i].infname->toHtmlEscaped().toUpper()))
        {
            for(int j=0; j<8; j++)
            {
                ui->showWidget->item(i,j)->setBackgroundColor(Qt::white);
            }
        }
        if((seAch.toHtmlEscaped().toUpper())==(e[i].adrstreet->toHtmlEscaped().toUpper()))
        {
            for(int j=0; j<8; j++)
            {
                ui->showWidget->item(i,j)->setBackgroundColor(Qt::white);
            }
        }
        if((seAch.toHtmlEscaped().toUpper())==(e[i].adrhouse->toHtmlEscaped().toUpper()))
        {
            for(int j=0; j<8; j++)
            {
                ui->showWidget->item(i,j)->setBackgroundColor(Qt::white);
            }
        }
        if((seAch.toHtmlEscaped().toUpper())==(e[i].adrdep->toHtmlEscaped().toUpper()))
        {
            for(int j=0; j<8; j++)
            {
                ui->showWidget->item(i,j)->setBackgroundColor(Qt::white);
            }
        }
        if((seAch.toHtmlEscaped().toUpper())==(e[i].infwarning->toHtmlEscaped().toUpper()))
        {
            for(int j=0; j<8; j++)
            {
                ui->showWidget->item(i,j)->setBackgroundColor(Qt::white);
            }
        }

    }
    seAch.clear();
    ui->seachEdit->setEnabled(1);
    ui->seachButton->setEnabled(1);
    ui->seachEdit->clear();
    ui->newSeach->hide();
}
