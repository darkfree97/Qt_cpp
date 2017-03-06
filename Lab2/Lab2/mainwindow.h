#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTextEdit>



#include <time.h>
#include <iostream>
#include <cstring>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_Up1_triggered();
    void on_Down1_triggered();
    void on_Up2_triggered();
    void on_Down2_triggered();

private:
    Ui::MainWindow *ui;
    int n;
    bool ok;
    int *arr;
    int point;
    int porivnennia;
private slots:
    void Generate(int n,int mas[]);
    int Quick_sort(int *mas,int first, int last,int point);
    void GenEnabled();
};

#endif // MAINWINDOW_H
