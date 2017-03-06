#ifndef BLINKLABEL_H
#define BLINKLABEL_H

#include <QLabel>

class BlinkLabel : public QLabel
{
private:
    bool m_bBlink;
    QString m_strText;

protected:
    virtual void timerEvent(QTimerEvent *);

public:
    BlinkLabel(const QString& strText,int nInterval = 200,QWidget *pwgt = 0);
};

#endif // BLINKLABEL_H
