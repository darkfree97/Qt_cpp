#include "myhighlighter.h"

void MyHighlighter::highlightBlock(const QString &str)
{
    for(int i=0;i<str.length();i++)
    {
        if(str.at(i).isNumber())
        {
            setFormat(i,1,Qt::red);
        }
    }
}
