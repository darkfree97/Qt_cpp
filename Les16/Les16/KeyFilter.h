#ifndef KEYFILTER_H
#define KEYFILTER_H

#include <QtWidgets>

class KeyFilter : public QObject
{
protected:
    virtual bool eventFilter(QObject *, QEvent *);
public:
    KeyFilter(QObject *);

};

#endif // KEYFILTER_H
