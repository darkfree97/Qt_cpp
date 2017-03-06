#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <math.h>

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

private slots:

    void on_a_disactivator_clicked();
    void on_b_disactivator_clicked();
    void on_c_disactivator_clicked();

    void valueChanged();

};

#endif // MAINWINDOW_H
