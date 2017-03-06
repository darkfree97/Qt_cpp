#include "mainwindow.h"
#include <QApplication>

#include <QSplashScreen>
#include <QTime>

void loadModules(QSplashScreen *psplash)
{
    QTime time;
    time.start();

    for(int i=0;i<100;)
    {
        if(time.elapsed()>40)
        {
            time.start();
            i++;
        }
        psplash->showMessage("Loading Modules"+QString::number(i)+"%",Qt::AlignHCenter|Qt::AlignBottom,Qt::white);
        qApp->processEvents();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen splash(QPixmap("://Murica.jpg"));

    splash.show();

    MainWindow w;

    loadModules(&splash);
    splash.finish(&w);

    w.show();

    return a.exec();
}
