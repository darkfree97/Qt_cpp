#ifndef TURTLEWORKAREA_H
#define TURTLEWORKAREA_H

#include <QWidget>
#include <QtScript/QScriptEngine>
#include <QTextEdit>
#include <QComboBox>
#include <QLayout>
#include <QMessageBox>
#include "Turtle.h"

class TurtleWorkArea : public QWidget
{
    Q_OBJECT
private:
    QTextEdit *m_ptxt;
    QScriptEngine m_scriptEngine;
    Turtle *m_pTurtle;
public:
    explicit TurtleWorkArea(QWidget *parent = 0);

signals:

public slots:
    void slotEvaluate();
    void slotApplyCode(int);
};

#endif // TURTLEWORKAREA_H
