#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "bintree.h"

#include <iostream>
#include <vector>

using namespace std;

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

    void on_action_triggered();

    void on_action_2_triggered();

    void on_delButton_clicked();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_action_5_triggered();

    void on_seeButton_clicked();

    void on_pointButton_clicked();

private:
    Ui::MainWindow *ui;
    BinTree tree;
    node *t;
    void Print(node *tree,int u);

};

#endif // MAINWINDOW_H
