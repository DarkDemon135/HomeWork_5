#include <stdio.h>
#include <stdlib.h>
#include <iostream>
typedef struct Item* pItem;
struct Item
{
    int data;
    pItem next;
};

void push(pItem* stackp, int data)
{
    pItem newp = (pItem)malloc(sizeof(struct Item));
    newp->data = data;
    newp->next = *stackp;
    *stackp = newp;
}

void pop(pItem* stackp)
{
    pItem p = (*stackp)->next;
    free(*stackp);
    *stackp = p;
}

int main()
{
    int i;
    pItem stackp = NULL;
 
    for(i = 1; i <= 10; ++i) push(&stackp, i);
 
    while(stackp)
    {
       printf("%d\n", stackp->data);
       pop(&stackp);
    }
 
    return 0;
}