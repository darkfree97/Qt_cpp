#include <QtWidgets>
#include "KeyFilter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QLineEdit txt("User input:");
//    txt.resize(300,20);
//    txt.show();

//    int i;
//    for(i=0;i<Qt::Key_Z-Qt::Key_A+1;i++)
//    {
//        QChar ch = 65+i;
//        int nKey = Qt::Key_A+i;
//        QKeyEvent keyPress(QEvent::KeyPress,nKey,Qt::NoModifier,ch);
//        QApplication::sendEvent(&txt,&keyPress);

//        QKeyEvent keyRelease(QEvent::KeyRelease,nKey,Qt::NoModifier,ch);
//        QApplication::sendEvent(&txt,&keyRelease);
//    }

    QLineEdit txt;
    txt.show();

    KeyFilter *pFielter = new KeyFilter(&txt);
    txt.installEventFilter(pFielter);

    return a.exec();
}
