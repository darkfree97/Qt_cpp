#include "ContextMenu.h"

#include <QContextMenuEvent>

ContextMenu::ContextMenu(QWidget *parent) : QTextEdit(parent)
{
    setReadOnly(true);
    m_pmnu = new QMenu(this);
    m_pmnu->addAction("&Red");
    m_pmnu->addAction("&Green");
    m_pmnu->addAction("&Blue");
    connect(m_pmnu,SIGNAL(triggered(QAction*)),SLOT(slotActivated(QAction*)));
}
void ContextMenu::contextMenuEvent(QContextMenuEvent *pe)
{
    m_pmnu->exec(pe->globalPos());
}
void ContextMenu::slotActivated(QAction *pAction)
{
    QString strColor = pAction->text().remove("&");
    setHtml(QString("<body bgcolor=%1><body>").arg(strColor));
}
