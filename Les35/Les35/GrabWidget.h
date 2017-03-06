#ifndef GRABWIDGET_H
#define GRABWIDGET_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDesktopWidget>
#include <QPixmap>
#include <QLabel>

class GrabWidget : public QWidget
{
    Q_OBJECT
private:
    QLabel *m_plbl;
public:
    explicit GrabWidget(QWidget *parent = 0);

signals:

public slots:
    void slotGrabScreen();
};

#endif // GRABWIDGET_H
