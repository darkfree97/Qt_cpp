#include "mypushbutton.h"

#include <QPainter>

MyPushButton::MyPushButton(QWidget *pwgt):QPushButton(pwgt)
{
}
void MyPushButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPointF ptCenter(rect().center());
    QRadialGradient gradient(ptCenter,width()/2,ptCenter);
    gradient.setColorAt(0,Qt::red);
    gradient.setColorAt(0.5,Qt::yellow);
    gradient.setColorAt(1,Qt::black);
    painter.setBrush(gradient);
    painter.drawRect(rect());

    QLinearGradient gradient1(0,0,width(),height());
    gradient1.setColorAt(0,Qt::red);
    gradient1.setColorAt(0.5,Qt::green);
    gradient1.setColorAt(1,Qt::blue);

    painter.setPen(QPen(gradient1,0));
    painter.setFont(QFont("Times",20,QFont::Normal));
    painter.drawText(0,height()/2+10,"Hello World");
}
