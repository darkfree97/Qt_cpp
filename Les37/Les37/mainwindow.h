#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QTime>

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

    void on_dateEdit_dateChanged(const QDate &date);

    void on_pushButton_2_clicked();

    void on_calendarWidget_selectionChanged();

protected:
    virtual void timerEvent(QTimerEvent*);

private:
    Ui::MainWindow *ui;
    QDate myDate;
};

#endif // MAINWINDOW_H
