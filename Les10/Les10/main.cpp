#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include "myhighlighter.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    QTextEdit *ptxt = new QTextEdit("This is a <b>TEST</>");
//    QTextDocumentWriter writer;
//    writer.setFormat("odf");
//    writer.setFileName("output.odf");
//    writer.write(ptxt->document());
//    ptxt->show();

//    QPrinter printer(QPrinter::HighResolution);
//    printer.setOutputFormat(QPrinter::PdfFormat);
//    printer.setOutputFileName("output.pdf");
//    ptxt->document()->print(&printer);

//    QSpinBox spb;
//    spb.setRange(1,100);
//    spb.setSuffix(" MB");
//    spb.setButtonSymbols(QSpinBox::PlusMinus);
//    spb.setWrapping(true);
//    spb.resize(100,30);
//    spb.show();

    QDateTimeEdit datt(QDateTime::currentDateTime());
    datt.show();

    return a.exec();
}
