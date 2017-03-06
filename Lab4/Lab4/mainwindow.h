#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "strsearch.h"

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <conio.h>


using namespace std;



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow,StrSearch
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    char strSch[256];
    char keyWord[256];

private slots:    

    void on_saveStr_clicked();
    void on_findMatch_clicked();
    void on_action_triggered();
    void on_action_3_triggered();
    void on_action_2_triggered();
};

#endif // MAINWINDOW_H
