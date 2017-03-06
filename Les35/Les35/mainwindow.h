#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QAction>
#include <QMenu>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *m_ptrayIcon;
    QMenu *m_ptrayIconMenu;
    bool m_bIconSwitcheer;
protected:
    virtual void closeEvent(QCloseEvent *);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void slotShowHide();
    void slotShowMessage();
    void slotChangeIcon();

private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
