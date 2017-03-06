#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::readAllInFile(){
    QFile mFile("file.txt");

    if(!mFile.open(QFile::ReadWrite | QFile::Text))
    {
        QMessageBox::information(this,"Error","Path not correct!");
        return;
    }
    QTextStream stream(&mFile);
    QString buffer = stream.readAll();

    ui->textEdit->setText(buffer);
    mFile.flush();
    mFile.close();
}
