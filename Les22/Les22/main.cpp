#include <QtWidgets>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QLabel lbl1("Animated window1");
//    QLabel lbl2("Animated window2");

//    QPropertyAnimation *panim1 = new QPropertyAnimation(&lbl1,"geometry");
//    panim1->setDuration(3000);
//    panim1->setStartValue(QRect(120,0,100,100));
//    panim1->setEndValue(QRect(480,380,200,200));
//    panim1->setEasingCurve(QEasingCurve::InOutExpo);

//    QPropertyAnimation *panim2 = new QPropertyAnimation(&lbl2,"pos");
//    panim1->setDuration(3000);
//    panim1->setStartValue(QPoint(240,0));
//    panim1->setEndValue(QPoint(240,480));
//    panim1->setEasingCurve(QEasingCurve::OutBounce);

//    QParallelAnimationGroup group;
//    group.addAnimation(panim1);
//    group.addAnimation(panim2);
//    group.setLoopCount(3);
//    group.start();

//    lbl1.show();
//    lbl2.show();

    QWidget wgt;
    wgt.setFixedSize(300,50);
    wgt.show();

    QLabel *plblOff = new QLabel("OFF");
    QLabel *plblOn = new QLabel("ON");

    QHBoxLayout *phbl = new QHBoxLayout;
    phbl->addWidget(plblOn);
    phbl->addStretch(1);
    phbl->addWidget(plblOff);
    wgt.setLayout(phbl);

    QPushButton *pcmd = new QPushButton("Turn",&wgt);
    pcmd->setAutoFillBackground(true);
    pcmd->show();

    int nButtonWidth = wgt.width() / 2;

    QStateMachine *psm = new QStateMachine;

    QState *pStateOff = new QState(psm);
    QRect rect1(0,0,nButtonWidth,wgt.height());
    pStateOff->assignProperty(pcmd,"geometry",rect1);
    pStateOff->assignProperty(plblOff,"visible",true);
    pStateOff->assignProperty(plblOn,"visible",false);
    psm->setInitialState(pStateOff);

    QState *pStateOn = new QState(psm);
    QRect rect2(nButtonWidth,0,nButtonWidth,wgt.height());
    pStateOn->assignProperty(pcmd,"geometry",rect2);
    pStateOn->assignProperty(plblOff,"visible",false);
    pStateOn->assignProperty(plblOn,"visible",true);

    QSignalTransition *ptrans1 = pStateOff->addTransition(pcmd,SIGNAL(clicked()),pStateOn);

    QSignalTransition *ptrans2 = pStateOn->addTransition(pcmd,SIGNAL(clicked()),pStateOff);

    QPropertyAnimation *panim1 = new QPropertyAnimation(pcmd,"geometry");
    ptrans1->addAnimation(panim1);

    QPropertyAnimation *panim2 = new QPropertyAnimation(pcmd,"geometry");
    ptrans2->addAnimation(panim2);

    psm->start();

    return a.exec();
}
