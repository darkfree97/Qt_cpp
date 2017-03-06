#include <QCoreApplication>
#include <iostream>
#include <conio.h>
#include <QDebug>
#include <QPoint>

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    system("chcp 1251 > nul");
    QPoint pt1(10,20);
    QPoint pt2(20,10);
    QPoint pt3;
    qDebug()<<"Pt1("<<pt1.x()<<"."<<pt1.y()<<")";
    qDebug()<<"Pt2("<<pt2.x()<<"."<<pt2.y()<<")";
    pt3 = pt1+pt2;
    qDebug()<<"Pt3("<<pt3.x()<<"."<<pt3.y()<<")";
    return a.exec();
}
