#include "strsearch.h"


bool StrSearch::Search(char stringSch[], char keyWord[])
{
    int i=0,j=0;
        int n=0,m=0;
        char str[256];
        strcpy(str,stringSch);
        n=strlen(keyWord);
        m=strlen(str);
        while (i<n)
        {
            while(j<m)
            {
                if(tolower(keyWord[i])==tolower(str[j])&&str[j+1]!=NULL && keyWord[i+1]!=NULL)
                {
                    i++;
                    j++;
                }
                else if(tolower(keyWord[i])!=tolower(str[j])&&str[j+1]!=NULL)
                {
                    j++;
                }
                else if(tolower(keyWord[i])==tolower(str[j])&&keyWord[i+1]==NULL)
                {
                    return true;
                    break;
                }
                else if(tolower(keyWord[i])!=tolower(str[j])&&keyWord[i+1]==NULL)
                {
                    if(str[j+1]==NULL)
                    {
                        return false;
                    }
                    else j++;
                }
                else if(str[j+1]==NULL&&keyWord[i+1]!=NULL)
                {
                    return false;
                    break;
                }
            }
        }
}
