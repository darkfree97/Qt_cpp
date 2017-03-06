#ifndef TURTLE_H
#define TURTLE_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QPushButton>
#include <math.h>

class Turtle : public QWidget
{
    Q_OBJECT
private:
    QPixmap m_pix;
    QPainter m_painter;

public:
    explicit Turtle(QWidget *parent = 0):QWidget(parent),m_pix(400,400),m_painter(&m_pix)
    {
        setFixedSize(m_pix.size());
        m_painter.setRenderHint(QPainter::Antialiasing,true);

        init();
    }
protected:
    void init()
    {
        m_pix.fill(Qt::yellow);
        m_painter.translate(rect().center());
        m_painter.rotate(-90);
    }

    virtual void paintEvent(QPaintEvent *)
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing,true);
        painter.drawPixmap(rect(),m_pix);
    }

signals:

public slots:
    void forvard(int n)
    {
        m_painter.drawLine(0,0,n,0);
        m_painter.translate(n,0);
        repaint();
    }
    void back(int n)
    {
        m_painter.drawLine(0,0,-n,0);
        m_painter.translate(-n,0);
        repaint();
    }
    void left(int nAngle)
    {
        m_painter.rotate(-nAngle);
    }
    void right(int nAngle)
    {
        m_painter.rotate(nAngle);
    }
    void reset()
    {
        m_painter.resetMatrix();
        init();
        repaint();
    }
};

#endif // TURTLE_H
