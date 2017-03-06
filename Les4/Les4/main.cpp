#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    //Регулятор виразів с.112
//    QRegExp reg("[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}");
//    QString str{"this is an ip-address 123.222.63.1 lets check it"};
//    qDebug()<<str.contains(reg);

    //Випадковий тип QVariant
    QVariant var1(34);
    QVariant var2(true);
    QVariant var3("String");
    QVariant var4({3,4,5,6});
    qDebug()<<QVariant::typeToName(var1.type());
    qDebug()<<QVariant::typeToName(var2.type());
    qDebug()<<QVariant::typeToName(var3.type());
    qDebug()<<QVariant::typeToName(var4.type());
    return a.exec();
}
