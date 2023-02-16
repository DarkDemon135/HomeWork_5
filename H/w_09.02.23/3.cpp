#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct Listitem
{
    int value;
    Listitem *next;
    Listitem ();
};
 
class Stack 
{
private:
    Listitem *head;
    Listitem *tail;
public:
    Stack ();
    void push (int value);
    void pop ();
    int top();
    void show ();
    ~Stack ();
};
 
Listitem::Listitem ()
{
    next=NULL;
    this->value=0;
}
Stack::Stack()
{
    head=tail=NULL;
}
void Stack::push (int value) 
{
    Listitem *temp=new Listitem;
    temp->value=value;
    if(tail==NULL)
        tail=temp;
    else{
        temp->next=tail;
        tail=temp;
    }
}
void Stack::pop () 
{
    if(tail==NULL){
        cout<<"Стек пуст";
        return;
    }
    Listitem *temp=tail;
    tail=tail->next;
    delete temp;
}
int Stack::top ()
{
    if(tail==NULL){
        cout<<"Стек пуст";
        return 0;
    }
    return tail->value;
}
void Stack::show () 
{
    if(tail==NULL){
        cout<<"Стек пуст";
        return;
    }
    Listitem *temp=tail;
    while (temp!=NULL){
        cout<<temp->value<<" ";
        temp=temp->next;
    }
}
Stack::~Stack ()
{
    delete head;
    delete tail;
}