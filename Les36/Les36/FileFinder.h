#ifndef FILEFINDER_H
#define FILEFINDER_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QLayout>
#include <QLabel>
#include <QDir>

class FileFinder : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *m_ptxtDir;
    QLineEdit *m_ptxtMask;
    QTextEdit *m_ptxtResult;
    void start(const QDir& dir);
public:
    explicit FileFinder(QWidget *parent = 0);

signals:

public slots:
    void slotFind();
    void slotBrowse();
};

#endif // FILEFINDER_H
