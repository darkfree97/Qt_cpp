#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;
struct node
    {
        int info; //Информационное поле
        node *l, *r;//Левая и Правая часть дерева
    };
class BinTree
{
public:

protected:
    node *tree;
public:
    BinTree();
    virtual ~BinTree();
    void Push(int);
    void Print();
    void DelElem(int a);
    node ReturnTree();
};

#endif // BINTREE_H
