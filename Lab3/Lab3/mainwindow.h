#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include <iostream>
#include <time.h>

using namespace std;

struct A
{
int key;
};
struct List
{
    A a;
    List * next;
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
    List *begin;
    int value;
    int searchEl;
    int Massive[30];
    int point;

private slots:
    void Print (List *b);
    void Init(List **begin, int Mas[], int _n);
    void Free(List **begin);
    void GenEnabled();

    int Counter(List *b);

    void on_pushButton_clicked();
    void on_action_triggered();
    void on_action_2_triggered();
    void on_quit_clicked();
    void on_add_clicked();
};

#endif // MAINWINDOW_H
