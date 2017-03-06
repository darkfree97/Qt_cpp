#include <QApplication>
#include <QtWidgets>
#include "mywidget.h"
#include "mypushbutton.h"

#include <QPainter>
#include <QPicture>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QPainter painter;
//    QPicture pic;
//    painter.begin(&pic);
//    painter.setPen(QPen(Qt::green,3,Qt::SolidLine));
//    painter.drawLine(20,20,150,240);
//    painter.end();
//    if(!pic.save("myline.dat"))
//    {
//        qDebug()<<"Can't save the file";
//    }
    MyPushButton *pbt = new MyPushButton;
    QLayout *lay = new QHBoxLayout;
    MyWidget wgt;
    QObject::connect(pbt,SIGNAL(clicked()),&wgt,SLOT(close()));
    lay->addWidget(pbt);
    wgt.setLayout(lay);
    wgt.show();

    return a.exec();
}
