#include <QApplication>
#include <QThread>
#include <QProgressBar>

class MyThread : public QThread
{
    Q_OBJECT
public:
    void run()
    {
        for(int i=0;i<100;i++)
        {
            usleep(100000);
            emit progress(i);
        }
    }

signals:
    void progress(int);
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QProgressBar prb;
    prb.setRange(0,100);
    MyThread thread;

    QObject::connect(&thread,SIGNAL(progress(int)),&prb,SLOT(setValue(int)));

    prb.show();

    thread.start();

    return a.exec();
}
#include "main.moc"
