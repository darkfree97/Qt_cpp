#include <QApplication>
#include <QtWidgets>

//#include "Calculator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget wgt;

    QPushButton *pcmdA = new QPushButton("A");
    QPushButton *pcmdB = new QPushButton("B");
    QPushButton *pcmdC = new QPushButton("C");
    QPushButton *pcmdD = new QPushButton("D");

//    QBoxLayout *pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
//    pbxLayout->addWidget(pcmdA,1);
//    pbxLayout->addWidget(pcmdB,2);
//    pbxLayout->addStretch(4);
//    pbxLayout->addWidget(pcmdC,2);
//    wgt.setLayout(pbxLayout);
//    wgt.resize(450,40);

//    QHBoxLayout *phbxLayout = new QHBoxLayout;
//    phbxLayout->setMargin(10);
//    phbxLayout->setSpacing(20);
//    phbxLayout->addWidget(pcmdA);
//    phbxLayout->addWidget(pcmdB);
//    phbxLayout->addWidget(pcmdC);
//    wgt.setLayout(phbxLayout);

//    QVBoxLayout *pvbxLayout = new QVBoxLayout;
//    pvbxLayout->setMargin(10);
//    pvbxLayout->setSpacing(20);
//    pvbxLayout->addWidget(pcmdA);
//    pvbxLayout->addWidget(pcmdB);
//    pvbxLayout->addWidget(pcmdC);
//    wgt.setLayout(pvbxLayout);

//    QVBoxLayout *pvbxLayout = new QVBoxLayout;
//    QHBoxLayout *phbxLayout = new QHBoxLayout;
//    phbxLayout->setMargin(5);
//    phbxLayout->setSpacing(15);
//    phbxLayout->addWidget(pcmdC);
//    phbxLayout->addWidget(pcmdD);

//    pvbxLayout->setMargin(5);
//    pvbxLayout->setSpacing(15);
//    pvbxLayout->addWidget(pcmdA);
//    pvbxLayout->addWidget(pcmdB);
//    pvbxLayout->addLayout(phbxLayout);
//    wgt.setLayout(pvbxLayout);

    QGridLayout *pgrdLayout = new QGridLayout;
    pgrdLayout->setMargin(5);
    pgrdLayout->setSpacing(15);
    pgrdLayout->addWidget(pcmdA,0,0);
    pgrdLayout->addWidget(pcmdB,0,1);
    pgrdLayout->addWidget(pcmdC,1,0);
    pgrdLayout->addWidget(pcmdD,1,1);
    wgt.setLayout(pgrdLayout);

    wgt.show();

//    Calculator calculator;

//    calculator.setWindowTitle("Калькулятор");
//    calculator.resize(230,200);

//    calculator.show();

//    //QSplitter spl(Qt::Vertical);
//    QSplitter spl(Qt::Horizontal);
//    QTextEdit *ptxt1 = new QTextEdit;
//    QTextEdit *ptxt2 = new QTextEdit;
//    spl.addWidget(ptxt1);
//    spl.addWidget(ptxt2);

//    ptxt1->setPlainText("Line1\n"
//                  "Line2\n"
//                  "Line3\n"
//                  "Line4\n"
//                  "Line5\n"
//                  "Line6\n"
//                  "Line7\n"
//                  );
//    ptxt2->setPlainText(ptxt1->toPlainText());
//    spl.resize(200,200);
//    spl.show();


    return a.exec();
}
