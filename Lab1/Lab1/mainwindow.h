#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>


#include <iostream>
#include <cstring>

using namespace std;

struct Enterprise
{
    QString *infnumauto;
    QString *infmarkauto;
    QString *infsurname;
    QString *infname;
    QString *adrstreet;
    QString *adrhouse;
    QString *adrdep;
    QString *infwarning;
};


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Enterprise e[100];
    QString seAch;
    int index;
    int pointElForEd;    
    bool shWin;
    bool schLay;
    bool chEdit;
    bool saveChangeBool;

private slots:
    void on_showAll_triggered();

    void on_addNew_triggered();

    void on_findElem_triggered();

    void on_editElem_triggered();

    void on_Close_clicked();

    void on_OK_clicked();

    void Input(Enterprise &e);

    void InitEnt(Enterprise e[]);

    void Update (Enterprise e[], int k);

    void PrintElem (Enterprise e);

    void Print(Enterprise e[],int n);

    void Free (Enterprise *e,int n);

    void Delete(Enterprise e[],int num_el_for_del,int quantity_el);

    void on_showWidget_doubleClicked(const QModelIndex &_index);


    void on_editChange_clicked();
    void on_delChange_clicked();
    void on_saveChange_clicked();
    void on_seachButton_clicked();
    void on_newSeach_clicked();
};

#endif // MAINWINDOW_H
