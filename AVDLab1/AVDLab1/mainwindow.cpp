#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QRegExp exp1("[А-ЯІЇЄ]['а-яіїє]{2,15}-{0,1}[А-ЯІЇЄ]{0,1}['а-яіїє]{0,15}");
    ui->lname->setValidator(new QRegExpValidator(exp1,this));
    QRegExp exp2("[А-ЯІЇЄ]['а-яіїє]{2,15}-{0,1}[А-ЯІЇЄ]{0,1}['а-яіїє]{0,15}");
    ui->fname->setValidator(new QRegExpValidator(exp2,this));
    QRegExp exp3("[А-ЯІЇЄ]['а-яіїє]{2,15}-{0,1}[А-ЯІЇЄ]{0,1}['а-яіїє]{0,15}");
    ui->father->setValidator(new QRegExpValidator(exp3,this));
    QRegExp exp4("[0-9]{1,3}");
    ui->age->setValidator(new QRegExpValidator(exp4,this));
    QRegExp exp5("[A-Z,a-z,0-9]{1,20}@[a-z]*[.][a-z]{1,10}");
    ui->mail->setValidator(new QRegExpValidator(exp5,this));
    QRegExp exp6("[+]{0,1}[0-9]{1,30}");
    ui->hendy->setValidator(new QRegExpValidator(exp6,this));
    QRegExp exp7("[А-ЯІЇЄ]['а-яіїє]{2,15}-{0,1}[А-ЯІЇЄ]{0,1}['а-яіїє]{0,15}");
    ui->selo->setValidator(new QRegExpValidator(exp7,this));

    f0 = false;
    f1 = false;
    f2 = false;
    f3 = false;
    f4 = false;
    f5 = false;
    f6 = false;
    f7 = false;
    dialog = new Dialog(this);
    my_action = ui->action;
    connect(my_action,SIGNAL(triggered()),dialog,SLOT(readAllInFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_submit_clicked()
{
    QFile mFile("file.txt");

    if(!mFile.open(QFile::ReadWrite | QFile::Text))
    {
        QMessageBox::information(this,"Error","Path not correct!");
        ui->statusBar->showMessage("Error!");
        return;
    }
    ui->statusBar->showMessage("");
    QTextStream stream(&mFile);

    if(ui->lname->text()==""){
        QMessageBox::information(this,"Повідомлення","Ви не ввели прізвище!");
    }
    else{
        f0 = true;
    }
    if(ui->fname->text()==""){
        QMessageBox::information(this,"Повідомлення","Ви не ввели ім'я!");
    }
    else{
        f1 = true;
    }
    if(ui->father->text()==""){
        QMessageBox::information(this,"Повідомлення","Ви не ввели по-батькові!");
    }
    else{
        f2 = true;
    }
    if(ui->age->text()==""){
        QMessageBox::information(this,"Повідомлення","Ви не ввели групу!");
    }
    else{
        f3 = true;
    }
    if(ui->mail->text()==""){
        QMessageBox::information(this,"Повідомлення","Ви не ввели електронну пошту!");
    }
    else{
        f4 = true;
    }
    if(ui->hendy->text()==""){
        QMessageBox::information(this,"Повідомлення","Ви не ввели номер телефону!");
    }
    else{
        f5 = true;
    }
    if(ui->selo->text()==""){
        QMessageBox::information(this,"Повідомлення","Ви не ввели місто!");
    }
    else{
        f6 = true;
    }
    if(ui->dateEdit->text()==""){
        QMessageBox::information(this,"Повідомлення","Ви не ввели дату!");
    }
    else{
        f7 = true;
    }

    if(f0 && f1 && f2 && f3 && f4 && f5 && f6 && f7){
        stream.operator <<("Прізвище         - "+ui->lname->text()+"\n");
        stream.operator <<("Ім'я             - "+ui->fname->text()+"\n");
        stream.operator <<("По-Батькові      - "+ui->father->text()+"\n");
        stream.operator <<("Номер групи      - "+ui->age->text()+"\n");
        stream.operator <<("Електронна пошта - "+ui->mail->text()+"\n");
        stream.operator <<("Номер мобільного - "+ui->hendy->text()+"\n");
        stream.operator <<("Місто            - "+ui->selo->text()+"\n");
        stream.operator <<("Дата народження  - "+ui->dateEdit->text()+"\n");
        QMessageBox::information(this,"Інформація","Запис у файл здійснено успішно!");
    }

    mFile.flush();
    mFile.close();

}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this,"Інформація","\"Прізвище\", \"Ім'я\", \"По-Батькові\" введіть кирилецею з великої літери!\n"
                                         "\"Номер групи\" введіть у вигляді числа!\n"
                                         "\"Електронну пошту\" введіть у вигляді 'example@mail.com'!\n"
                                         "\"Номер Мобільного\" введіть у вигляді '+380*********'!\n"
                                         "\"Місто\" введіть кирилецею з великої літери!\n"
                                         "\"Дата народження\" - бажано змінити!");
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QConicalGradient gradient(width()/2,height()/2,0);
    gradient.setColorAt(0,Qt::yellow);
    gradient.setColorAt(0.4,Qt::green);
    gradient.setColorAt(0.7,Qt::blue);
    gradient.setColorAt(1,Qt::yellow);

    painter.setBrush(gradient);
    painter.drawRect(rect());
}

void MainWindow::on_action_triggered()
{
    dialog->show();
}

void MainWindow::on_clear_all_triggered()
{
    ui->lname->clear();
    ui->fname->clear();
    ui->father->clear();
    ui->age->clear();
    ui->mail->clear();
    ui->hendy->clear();
    ui->selo->clear();
    ui->dateEdit->clear();
}
