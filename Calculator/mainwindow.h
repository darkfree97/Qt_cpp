#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void slotOperation();

    void on_plus_clicked();

    void on_minus_clicked();

    void on_up_on_clicked();

    void on_down_on_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
