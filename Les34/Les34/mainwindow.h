#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QLabel>
#include <QProgressBar>
#include <QMouseEvent>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    virtual void mouseMoveEvent(QMouseEvent *pe);

private slots:
    void on_action1_triggered();

    void on_action2_triggered();

    void on_action3_triggered();

    void on_action4_triggered();

    void on_action5_triggered();

    void on_action6_triggered();

    void on_action7_triggered();

    void on_action8_triggered();

    void on_action9_triggered();

    void on_action0_triggered();

    void on_actionA_triggered();

    void on_actionB_triggered();

    void on_actionC_triggered();

    void on_actionD_triggered();

    void on_actionE_triggered();

    void on_actionF_triggered();

    void on_actionClean_triggered();

    void on_dial_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QDockWidget *pdock;
    QLabel *plbl;
    QLabel *xlbl;
    QLabel *ylbl;
    QProgressBar *prBar;
};

#endif // MAINWINDOW_H
