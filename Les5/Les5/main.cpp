#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//    QWidget wgt;

//    QWidget *pwgt1 = new QWidget(&wgt);
//    QPalette pall;
//    pall.setColor(pwgt1->backgroundRole(),Qt::blue);
//    pwgt1->setPalette(pall);
//    pwgt1->resize(100,100);
//    pwgt1->move(25,25);
//    pwgt1->setCursor(Qt::CrossCursor);
//    pwgt1->setAutoFillBackground(true);

//    QWidget *pwgt2 = new QWidget(&wgt);
//    QPalette pal2;
//    pal2.setBrush(pwgt2->backgroundRole(),QBrush(QPixmap(":/stone.jpg")));
//    pwgt2->setPalette(pal2);
//    pwgt2->resize(1920,1080);
//    pwgt2->move(75,75);
//    pwgt2->setCursor(Qt::WaitCursor);
//    pwgt2->setAutoFillBackground(true);

//    wgt.resize(2220,1380);
//    wgt.show();


//    QFrame *fra = new QFrame;
//    fra->setFrameStyle(QFrame::Box|QFrame::Sunken);
//    fra->setLineWidth(3);
//    fra->show();

//    QScrollArea sa;
//    QWidget *pwgt = new QWidget;
//    QPixmap pix(":/stone.jpg");
//    QPalette pal;
//    pal.setBrush(pwgt->backgroundRole(),QBrush(pix));
//    pwgt->setPalette(pal);
//    pwgt->setAutoFillBackground(true);
//    pwgt->setFixedSize(pix.width(),pix.height());

//    sa.setWidget(pwgt);
//    sa.resize(350,150);
//    sa.show();

    return app.exec();
}
