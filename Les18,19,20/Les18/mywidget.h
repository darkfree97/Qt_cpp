#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class MyWidget : public QWidget
{
    Q_OBJECT
private:
public:
    explicit MyWidget(QWidget *parent = 0);

    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // MYWIDGET_H
