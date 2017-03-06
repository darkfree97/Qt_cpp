#include "ui_MyForm.h"
#include <QApplication>
#include "MyForm.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QWidget *form = new QWidget;
//    Ui::MyForm ui;
//    ui.setupUi(form);

//    form->show();
    MyForm wgt;
    wgt.show();

    return a.exec();
}
