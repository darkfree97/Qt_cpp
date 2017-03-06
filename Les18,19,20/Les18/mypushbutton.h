#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
public:
    MyPushButton(QWidget *pwgt = 0);
    void paintEvent(QPaintEvent *);
};

#endif // MYPUSHBUTTON_H
