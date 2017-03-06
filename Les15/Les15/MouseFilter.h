#ifndef MOUSEFILTER_H
#define MOUSEFILTER_H

#include <QtWidgets>


class MouseFilter : public QObject
{
protected:
    virtual bool eventFilter(QObject *, QEvent *);
public:
    MouseFilter(QObject* pobj = 0);

};

#endif // MOUSEFILTER_H
