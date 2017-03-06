#include <QApplication>
#include <QtWidgets>
//=========================================================
class SimpleDelegate : public QStyledItemDelegate
{
public:
    SimpleDelegate(QObject *pobj=0):QStyledItemDelegate(pobj)
    {

    }
    void pint(QPainter *pPainter,const QStyleOptionViewItem &option,const QModelIndex &index)const
    {
        if(option.state & QStyle::State_MouseOver)
        {
            QRect rect = option.rect;
            QLinearGradient gradient(0,0,rect.width(),rect.height());

            gradient.setColorAt(0,Qt::white);
            gradient.setColorAt(0.5,Qt::blue);
            gradient.setColorAt(1,Qt::green);
            pPainter->setBrush(gradient);
            pPainter->drawRect(rect);
        }
        QStyledItemDelegate::paint(pPainter,option,index);
    }
};
//=========================================================

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QWidget wgt;

//    QStringListModel model;
//    model.setStringList(QStringList()<<"Item1"<<"Item2"<<"Item3");

//    QTreeView *pTreeView = new QTreeView;
//    pTreeView->setModel(&model);

//    QListView *pListView = new QListView;
//    pListView->setModel(&model);

//    QTableView *pTableView = new QTableView;
//    pTableView->setModel(&model);

//    QItemSelectionModel selection(&model);
//    pTreeView->setSelectionModel(&selection);
//    pListView->setSelectionModel(&selection);
//    pTableView->setSelectionModel(&selection);

//    //Layout setup
//    QHBoxLayout *phbLayout = new QHBoxLayout;
//    phbLayout->addWidget(pTreeView);
//    phbLayout->addWidget(pListView);
//    phbLayout->addWidget(pTableView);
//    wgt.setLayout(phbLayout);

//    wgt.show();

//    QStringListModel model;
//    model.setStringList(QStringList()<<"Item1"<<"Item2"<<"Item3");

//    QListView listView;
//    SimpleDelegate *delg = new SimpleDelegate(&listView);
//    listView.setModel(&model);
//    listView.setItemDelegate(delg);
//    listView.viewport()->setAttribute(Qt::WA_Hover);
//    listView.show();


//    QStandardItemModel model(5,3);

//    for (int nTopRow =0; nTopRow<5; nTopRow++)
//    {
//        QModelIndex index = model.index(nTopRow,0);
//        model.setData(index,"item"+QString::number(nTopRow+1));

//        model.insertRows(0,4,index);
//        model.insertColumns(0,3,index);
//        for(int nRow =0; nRow<4; nRow++)
//        {
//            for(int nCow =0; nCow<3; nCow++)
//            {
//                QString strPos = QString("%1,%2").arg(nRow).arg(nCow);
//                model.setData(model.index(nRow,nCow,index),strPos);

//            }
//        }
//    }
//    QTreeView treeView;
//    treeView.setModel(&model);
//    treeView.show();

//    QFileSystemModel model;
//    QTreeView treeView;

//    model.setRootPath(QDir::rootPath());
//    treeView.setModel(&model);
//    treeView.show();

    QSplitter spl(Qt::Horizontal);
    QFileSystemModel model;

    model.setRootPath(QDir::rootPath());

    QTreeView *pTreeView = new QTreeView;
    pTreeView->setModel(&model);

    QTableView *pTableView = new QTableView;
    pTableView->setModel(&model);

    QObject::connect(pTreeView,SIGNAL(clicked(const QModelIndex&)),pTableView,SLOT(setRootIndex(const QModelIndex&)));
    QObject::connect(pTableView,SIGNAL(activated(const QModelIndex&)),pTreeView,SLOT(setCurrentIndex(const QModelIndex&)));
    QObject::connect(pTableView,SIGNAL(activated(const QModelIndex&)),pTableView,SLOT(setRootIndex(const QModelIndex&)));

    spl.addWidget(pTreeView);
    spl.addWidget(pTableView);
    spl.show();

    return a.exec();
}
