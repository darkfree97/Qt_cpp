#ifndef MYSERVER_H
#define MYSERVER_H

#include <QWidget>

#include <QTcpServer>
#include <QTcpSocket>
#include <QTextEdit>

class MyServer : public QWidget
{
    Q_OBJECT
private:
public:
    explicit MyServer(QWidget *parent = 0);

signals:

public slots:
};

#endif // MYSERVER_H
