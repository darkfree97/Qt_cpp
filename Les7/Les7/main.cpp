#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    QWidget wgt;
//    QVBoxLayout *app = new QVBoxLayout;

//    QPixmap pix;
//    pix.load(":/Record.png");
//    QLabel *lbl = new QLabel;
//    lbl->resize(pix.size());
//    lbl->setPixmap(pix);
//    QLabel *L1 = new QLabel("&Name");
//    QLabel *L2 = new QLabel("&Age");
//    QLineEdit *name = new QLineEdit;
//    QSpinBox *spb = new QSpinBox;

//    L1->setBuddy(name);
//    L2->setBuddy(spb);

//    app->addWidget(L1);
//    app->addWidget(name);
//    app->addWidget(L2);
//    app->addWidget(spb);
//    wgt.setLayout(app);
//    QWidget *img = new QWidget;
//    QHBoxLayout *lay = new QHBoxLayout;
//    lay->addWidget(lbl);
//    img->setLayout(lay);
//    img->show();
//    wgt.show();

    QWidget wgt;
    QLCDNumber *n = new QLCDNumber;
    QSpinBox *s = new QSpinBox;

    n->setSegmentStyle(QLCDNumber::Filled);
    n->setMode(QLCDNumber::Hex);

    s->setFixedHeight(30);
    s->setMaximum(1000000);

    QObject::connect(s,SIGNAL(valueChanged(int)),n,SLOT(display(int)));

    QVBoxLayout *lay = new QVBoxLayout;
    lay->addWidget(n);
    lay->addWidget(s);
    wgt.setLayout(lay);

    wgt.resize(250,150);
    wgt.show();


    return a.exec();
}
