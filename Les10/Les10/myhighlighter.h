#ifndef MYHIGHLIGHTER_H
#define MYHIGHLIGHTER_H

#include <QSyntaxHighlighter>


class MyHighlighter : public QSyntaxHighlighter
{
public:
   void highlightBlock(const QString& str);
};

#endif // MYHIGHLIGHTER_H
