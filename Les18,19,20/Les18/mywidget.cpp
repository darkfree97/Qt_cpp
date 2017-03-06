#include "mywidget.h"

#include <QPainter>
#include <QPicture>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
//    this->resize(300,150);
    this->resize(300,300);
}
void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

//    painter.setPen(QPen(Qt::cyan,3,Qt::DashLine));
//    painter.setBrush(QBrush(Qt::green,Qt::HorPattern));
//    painter.drawEllipse(0,0,300,150);

//    QLinearGradient gradient(0,0,width(),height());
//    gradient.setColorAt(0,Qt::blue);
//    gradient.setColorAt(0.5,Qt::white);
//    gradient.setColorAt(1,Qt::yellow);
//    painter.setBrush(gradient);
//    painter.drawRect(rect());

    QConicalGradient gradient(width()/2,height()/2,0);
    gradient.setColorAt(0,Qt::red);
    gradient.setColorAt(0.4,Qt::green);
    gradient.setColorAt(0.8,Qt::blue);
    gradient.setColorAt(1,Qt::red);
    painter.setBrush(gradient);
    painter.drawRect(rect());

//    QPointF ptCenter(rect().center());
//    QRadialGradient gradient(ptCenter,width()/2,ptCenter);
//    gradient.setColorAt(0,Qt::red);
//    gradient.setColorAt(0.5,Qt::yellow);
//    gradient.setColorAt(1,Qt::black);
//    painter.setBrush(gradient);
//    painter.drawRect(rect());

//    QBrush brush(Qt::red,Qt::Dense4Pattern);
//    painter.fillRect(10,10,width()-20,height()-20,brush);
//    painter.eraseRect(20,20,width()-40,height()-40);

//    painter.setRenderHint(QPainter::Antialiasing,true);
//    painter.setBrush(QBrush(Qt::red,Qt::DiagCrossPattern));
//    painter.setPen(QPen(Qt::blue,3,Qt::DashLine));
//    painter.drawRect(0,0,width(),height());

//    painter.setRenderHint(QPainter::Antialiasing,true);
//    painter.setBrush(QBrush(Qt::green));
//    painter.setPen(QPen(Qt::black));
//    painter.drawRoundRect(QRect(10,10,width()-20,height()-20),30,30);

//    painter.setRenderHint(QPainter::Antialiasing,true);
//    painter.setBrush(QBrush(Qt::green,Qt::CrossPattern));
//    painter.setPen(QPen(Qt::blue,3,Qt::DotLine));
//    painter.drawEllipse(QRect(10,10,width()-20,height()-20));

//    painter.setRenderHint(QPainter::Antialiasing,true);
//    painter.setBrush(Qt::yellow);
//    painter.setPen(Qt::blue);
//    painter.drawChord(QRect(10,10,width()-20,height()-20),45*16,180*16);

//    painter.setRenderHint(QPainter::Antialiasing,true);
//    painter.setBrush(Qt::yellow);
//    painter.setPen(Qt::blue);
//    painter.drawPie(QRect(10,10,width()-20,height()-20),45*16,270*16);

//    QPicture pic;
//    if(!pic.load("myline.dat"))
//    {
//        qDebug()<<"Can't load the file";
//    }
//    painter.drawPicture(QPoint(0,0),pic);

//    QPainterPath path;
//    QPointF pt1(width(),height()/2);
//    QPointF pt2(width()/2,-height());
//    QPointF pt3(width()/2,2*height());
//    QPointF pt4(0,height()/2);
//    path.moveTo(pt1);
//    path.cubicTo(pt2,pt3,pt4);
//    QRect rect(width()/4,height()/4,width()/2,height()/2);
//    path.addRect(rect);
//    path.addEllipse(rect);
//    painter.setPen(QPen(Qt::blue,6));
//    painter.drawPath(path);

//    painter.setRenderHint(QPainter::Antialiasing,true);
//    painter.setClipRect(100,0,100,100);
//    painter.setBrush(QBrush(Qt::green));
//    painter.setPen(QPen(Qt::black,2));
//    painter.drawEllipse(0,0,200,100);
}
