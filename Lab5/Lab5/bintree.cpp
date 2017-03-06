#include "bintree.h"

void push(int a,node **t)
{
    if ((*t)==NULL)
    {
        (*t)=new node;
        (*t)->info=a;
        (*t)->l=(*t)->r=NULL;
        return;
    }
    if (a>(*t)->info) push(a,&(*t)->r);
    else push(a,&(*t)->l);
}

void print (node *t,int u)
{
    if (t==NULL) return;
    else
    {
        print(t->r,++u);
        for (int i=0;i<u;++i) cout<<" ";
        cout<<t->info<<endl;
        u--;
        print(t->l,++u);
    }
}


int MultTree(node *t)
{
   if (t==NULL)
     return 1;
   return MultTree(t->l) * MultTree(t->r) * t->info;
}

void delElFromTree(node *&t,int d)
{
    if(t!=NULL)
    {
        if(t->info==d)
        {
            node *p=t;
            t=p->r;
            node *q=p->r;
            while (q->l!=NULL) {
                q=q->l;
                q->l=p->l;
                t=p->l;
                delete p;
            }
        }
        else if(d<t->info)
        {
            delElFromTree(t->l,d);
        }
        else
        {
            delElFromTree(t->r,d);
        }
    }
}
void SearchDelete(node** pNode, int key)
{

    node *delNode;
    if(*pNode==NULL)
    {
        return;
        cout<<"node is not found"<<endl;
    }
    else if(key<(*pNode)->info)
    {
        SearchDelete(&((*pNode)->l), key);
    }
    else if(key>(*pNode)->info)
    {
        SearchDelete(&((*pNode)->r), key);
    }
    else
    {
        delNode=*pNode;
        if(delNode->r==NULL)
        {
            *pNode=delNode->l;
        }
        else if(delNode->l==NULL)
        {
            *pNode=delNode->r;
        }
        else
        {
            return;
        }
        delete delNode;
    }
}
void del(node *t)
{
    if (t==NULL) return;
    else
    {
        if(t->r!=NULL)
        {
            del(t->r);
        }
        if(t->l!=NULL)
        {
            del(t->l);
        }
        delete t;
    }
}

BinTree::BinTree()
{
    tree = NULL;
}

BinTree::~BinTree()
{
    del(tree);
}
void BinTree::Push(int a)
{
    try
    {
        push(a,&tree);
    }
    catch(...)
    {
        cerr<<"Memory Error"<<endl;
    }
}
void BinTree::Print()
{
    print(tree,0);
}
void BinTree::DelElem(int a)
{
    SearchDelete(&tree,a);
}
node BinTree::ReturnTree()
{
    return *tree;
}
