#ifndef SIMPLEINCLUDE_H
#define SIMPLEINCLUDE_H

#include <QDialog>

namespace Ui {
class SimpleInclude;
}

class SimpleInclude : public QDialog
{
    Q_OBJECT

public:
    explicit SimpleInclude(QWidget *parent = 0);
    ~SimpleInclude();

private:
    Ui::SimpleInclude *ui;
};

#endif // SIMPLEINCLUDE_H
