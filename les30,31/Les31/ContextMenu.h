#ifndef CONTEXTMENU_H
#define CONTEXTMENU_H

#include <QObject>
#include <QWidget>
#include <QTextEdit>
#include <QMenu>

class ContextMenu : public QTextEdit
{
    Q_OBJECT
private:
    QMenu *m_pmnu;
protected:
    virtual void contextMenuEvent(QContextMenuEvent *pe);
public:
    explicit ContextMenu(QWidget *parent = 0);

signals:

public slots:
    void slotActivated(QAction *pAction);
};

#endif // CONTEXTMENU_H
