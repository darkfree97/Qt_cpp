#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDesktopServices>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),m_bIconSwitcheer(false)
{
    ui->setupUi(this);
    setWindowTitle("System Tray");

    QAction *pactShowHide = new QAction("&Show/Hide Action Window",this);
    connect(pactShowHide,SIGNAL(triggered()),this,SLOT(slotShowHide()));
    QAction *pactShowMessage = new QAction("Show &Message",this);
    connect(pactShowMessage,SIGNAL(triggered()),this,SLOT(slotShowMessage()));
    QAction *pactChangeIcon = new QAction("&Change Icon",this);
    connect(pactChangeIcon,SIGNAL(triggered()),this,SLOT(slotChangeIcon()));
    QAction *pactQuit = new QAction("&Quit",this);
    connect(pactQuit,SIGNAL(triggered()),qApp,SLOT(quit()));

    m_ptrayIconMenu = new QMenu(this);
    m_ptrayIconMenu->addAction(pactShowHide);
    m_ptrayIconMenu->addAction(pactShowMessage);
    m_ptrayIconMenu->addAction(pactChangeIcon);
    m_ptrayIconMenu->addAction(pactQuit);

    m_ptrayIcon = new QSystemTrayIcon(this);
    m_ptrayIcon->setContextMenu(m_ptrayIconMenu);
    m_ptrayIcon->setToolTip("System Tray");

    slotChangeIcon();

    m_ptrayIcon->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    if(m_ptrayIcon->isVisible())
    {
        hide();
    }
}
void MainWindow::slotShowHide()
{
    setVisible(!isVisible());
}
void MainWindow::slotShowMessage()
{
    m_ptrayIcon->showMessage("For you information",
                             "You have selected the "
                             "\"Show Message!\" option",
                             QSystemTrayIcon::Information,
                             3000
                             );
}
void MainWindow::slotChangeIcon()
{
    m_bIconSwitcheer = !m_bIconSwitcheer;
    QString strPixmapName = m_bIconSwitcheer ? "://Wizard.bmp" :"://ico.bmp";
    m_ptrayIcon->setIcon(QPixmap(strPixmapName));
}

void MainWindow::on_pushButton_clicked()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(QFileDialog::getOpenFileName(this,"Відкрити","D:/")));
}
