#include <QApplication>
#include <QtWidgets>

class MyApplication : public QApplication
{
public:
    MyApplication(int argc,char** argv):QApplication(argc, argv)
    {
    }
    virtual ~MyApplication()
    {
    }
    virtual void commitData(QSessionManager &sm)
    {
        QMessageBox::information(0,"Dialog","You are exiting operating system");
    }
};

int main(int argc, char *argv[])
{
    MyApplication a(argc, argv);

    QLabel lbl("Exiting the operating system to see the dialog box",0);
    lbl.show();

    return a.exec();
}
