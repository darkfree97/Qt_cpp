#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <QDialog>

namespace Ui {
class QuickSort;
}

class QuickSort : public QDialog
{
    Q_OBJECT

public:
    explicit QuickSort(QWidget *parent = 0);
    ~QuickSort();

private:
    Ui::QuickSort *ui;
//private slots:
//    void Mass(int k);
};

#endif // QUICKSORT_H
