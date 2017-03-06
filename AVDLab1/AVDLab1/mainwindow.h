#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPainter>
#include <QConicalGradient>
#include <QFile>
#include <QTextStream>
#include "dialog.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);

private slots:
    void on_submit_clicked();

    void on_pushButton_clicked();

    void on_action_triggered();

    void on_clear_all_triggered();

private:
    Ui::MainWindow *ui;
    Dialog *dialog;
    QAction *my_action;
    bool f0,f1,f2,f3,f4,f5,f6,f7;
};

#endif // MAINWINDOW_H
