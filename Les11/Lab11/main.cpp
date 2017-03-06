#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    QStringList lst;
//    lst<<"Linux"<<"Windows"<<"Mac OC"<<"Android";
//    QListWidget lwg;
//    QListWidgetItem *pitem = 0;
//    lwg.setSelectionMode(QAbstractItemView::MultiSelection);
//    lwg.setViewMode(QListView::IconMode);
//    for(auto str : lst)
//    {
//        pitem = new QListWidgetItem(str,&lwg);
//        pitem->setFlags(Qt::ItemIsEnabled|Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled);

//    }
//    lwg.resize(125,175);
//    lwg.show();

//    QTreeWidget twg;
//    QStringList lst;
//    lst<<"Folders"<<"Used space";
//    twg.setHeaderLabels(lst);
//    twg.setSortingEnabled(true);

//    QTreeWidgetItem *ptwgItem = new QTreeWidgetItem(&twg);
//    ptwgItem->setText(0,"Local Disc (C)");

//    QTreeWidgetItem *ptwgItemDir = 0;
//    for(int i=1;i<20;i++)
//    {
//        ptwgItemDir = new QTreeWidgetItem(ptwgItem);
//        ptwgItemDir->setText(0,"Directory"+QString::number(i));
//        ptwgItemDir->setText(1,QString::number(i)+" MB");

//    }
//    twg.setItemExpanded(ptwgItem,true);
//    twg.resize(250,110);
//    twg.show();

//    const int n = 3;
//    QTableWidget tbl(n,n);
//    QTableWidgetItem *ptwi = 0;
//    QStringList lst;
//    lst<<"First"<<"Second"<<"Third";
//    tbl.setHorizontalHeaderLabels(lst);
//    tbl.setVerticalHeaderLabels(lst);
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<n;j++)
//        {
//            ptwi = new QTableWidgetItem(QString("%1,%2").arg(i).arg(j));
//            tbl.setItem(i,j,ptwi);
//        }
//    }
//    tbl.resize(370,135);
//    tbl.show();

//    QComboBox cbo;
//    QStringList lst;
//    lst<<"John"<<"Paul"<<"George"<<"Ringo";
//    cbo.addItems(lst);
//    cbo.setEditable(true);
//    cbo.show();

//    QTabWidget tab;
//    QStringList lst;

//    lst<<"Linux"<<"Windows"<<"Mac OS"<<"Andrid";
//    foreach (QString str, lst)
//    {
//        tab.addTab(new QLabel(str,&tab),QPixmap(":/"+str+".jpg"),str);
//    }
//    tab.resize(360,100);
//    tab.show();

    QToolBox tbx;
    QStringList lst;

    lst<<"Linux"<<"Windows"<<"Mac OS"<<"Andrid";
    foreach (QString str, lst)
    {
        tbx.addItem(new QLabel(str,&tbx),QPixmap(":/"+str+".jpg"),str);
    }
    tbx.resize(100,80);
    tbx.show();
    return a.exec();
}
