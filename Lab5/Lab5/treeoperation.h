#ifndef TREEOPERATION_H
#define TREEOPERATION_H

# include <iostream>
# include <conio.h>

using namespace std;

//Наша структура
struct node
{
    int info; //Информационное поле
    node *l, *r;//Левая и Правая часть дерева
};

class TreeOperation
{
protected:
    node t;
public:
    void push(int a,node **t);
    void print (node *t,int u);

};

#endif // TREEOPERATION_H
