#include "search.h"

Search::Search()
{

}
Search::Search(char _str)
{
    strcpy(str,_str);
}
char Search::Find(char str, char keyWord) const
{


    char findString[256];
    char *buf=NULL;
    char *bufForSafe;
    buf = strtok(str," .,:;!?\n\t");
    while (buf) {
        bufForSafe = buf;
        sucsses = false;
        checpoint = 0;
        int i=0;
        bool f = true;
        while (i<strlen(keyWord)&&f)
        {
            keyWord[i]=toupper(keyWord[i]);

            for(int j=checpoint; j<strlen(buf);j++)
            {
                buf[j]=toupper(buf[j]);
                if(keyWord[i]==buf[j]&&keyWord[i+1]!=NULL)
                {
                    checpoint = j;
                    i++;
                    break;
                }
                else if(keyWord[i]==buf[j]&&keyWord[i+1]==NULL)
                {
                    sucsses = true;
                    break;
                }
                else if(buf[j+1]=NULL&&keyWord[i+1]!=NULL)
                {
                    f=false;
                }
            }
        }
        if(sucsses)
        {
            strcat(findString,bufForSafe);
            strcat(findString,"\n");
        }

        buf = strtok(0," .,:;!?\n\t");
    }
    if(!sucsses)
    {
        strcat(findString,"Sorry");
    }
    return findString;
}
