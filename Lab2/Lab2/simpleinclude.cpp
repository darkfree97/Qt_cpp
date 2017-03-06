#include "simpleinclude.h"
#include "ui_simpleinclude.h"

SimpleInclude::SimpleInclude(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SimpleInclude)
{
    ui->setupUi(this);
}

SimpleInclude::~SimpleInclude()
{
    delete ui;
}
