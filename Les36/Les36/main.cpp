#include "mainwindow.h"
#include <QApplication>
#include "FileFinder.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    FileFinder w;
    w.show();

    return a.exec();
}
