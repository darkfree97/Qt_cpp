#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ContextMenu.h"

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
    void on_action_About_Qt_triggered();

    void on_action_Exit_triggered();

    void on_actionCheckable_Item_triggered(bool checked);

private:
    Ui::MainWindow *ui;
    ContextMenu *cMenu;
};

#endif // MAINWINDOW_H
