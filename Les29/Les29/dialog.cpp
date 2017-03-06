#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    pcb = QApplication::clipboard();
    plt = ui->checkBox;
    connect(pcb,SIGNAL(dataChanged()),plt,SLOT(click()));
    ui->plainTextEdit->setPlainText(pcb->text());
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_plainTextEdit_textChanged()
{
    pcb->setText(ui->plainTextEdit->toPlainText());
}
