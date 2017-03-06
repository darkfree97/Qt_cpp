#include <QtWidgets>
#include "MouseFilter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLineEdit txt("QLineEdit");
    txt.installEventFilter(new MouseFilter(&txt));
    txt.show();

    QLabel lbl("QLabel");
    lbl.installEventFilter(new MouseFilter(&txt));
    lbl.show();

    QPushButton cmd("QPushButton");
    cmd.installEventFilter(new MouseFilter(&txt));
    cmd.show();


    return a.exec();
}
