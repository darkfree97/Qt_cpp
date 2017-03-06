#include "mainwindow.h"
#include <QApplication>
#include <GrabWidget.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    QApplication::setQuitOnLastWindowClosed(false);

//    GrabWidget wgt;
//    wgt.show();

    return a.exec();
}
