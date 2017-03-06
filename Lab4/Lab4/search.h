#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <cstring>

using namespace std;

class Search
{
private:
    char str[256];
    char keyWord[256];
    int checpoint;
    bool sucsses;
public:
    Search();
    virtual ~Search();

    char Find(char str,char keyWord) const;

};

#endif // SEARCH_H
