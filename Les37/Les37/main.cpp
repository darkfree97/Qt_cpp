#include "mainwindow.h"
#include <QApplication>
#include "blinklabel.h"

#include <QTimer>

void delay(int n)
{
    QEventLoop loop;
    QTimer::singleShot(n,&loop,SLOT(quit()));
    loop.exec();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

//    BlinkLabel lbl("<font color = red><center>Blink</center></font>");
//    lbl.show();

//    QLabel lbl("<font color = green><center><h1>Demo Version</h1></center></font>"
//               "<br><center>10 seconds to end</center>");
//    lbl.resize(220,140);
//    lbl.show();
//    QTimer::singleShot(10000,&a,SLOT(quit()));

    return a.exec();
}
