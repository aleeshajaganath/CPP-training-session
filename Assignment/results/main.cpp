#include"symtable.h"
#include <iostream>
using namespace std;
#include<gtest/gtest.h>

// int TOTAL_BIND=0;

/*  structure containing two boxes key (KEY) and value (VALUE)  and next binding (next)*/
struct SymTable_t {
    struct SymTable_t* next;
    // void* KEY;//[100];
    const char *KEY;
    const void*  VALUE;

};

iNode* head;


int main(){
    int i=2;

    // create 5 bindings
    if(head==NULL){
        head=SymTable_new();

    }
    iNode* prev= head;
    while (i>0)    {
        prev->next=SymTable_new();
        prev=prev->next;
        cout<<i<<endl;
        i--;
    }
    
    cout<<"(SymTable_getLength)Total length including head is : "<<SymTable_getLength(head)<<endl;
    const char *pcKey="i0";
    int *x,y=9;
    x=&y;
    int result=SymTable_put (head,pcKey,x);
    cout<<"(SymTable_put)inserted ..!\nkey : "<<pcKey<<"\nvalue : "<<*x<<endl;
    Print(head);

    int xa=21;
    x=&xa;
    string key="i1";
    const char *pcKey1="i1";
    result=SymTable_put (head,pcKey1,x);
    Print(head);
    const char *pcKey2="i2";
    // int *pvValue=1;
    int *x1,y2=19;
    x1=&y2;
    result=SymTable_put (head,pcKey2,x1);
    Print(head);

    cout<<"calling SymTable_get() for KEY = "<<pcKey2<<endl;
    iNode* prev1 = (iNode*)SymTable_get (head , pcKey2);
    if(prev1!=NULL)
        cout<<"result Value is "<<*(int*)prev1->VALUE<<endl;

    const char *pcKey5="i5";
    cout<<"calling SymTable_get() for KEY = "<<pcKey5<<endl;
    prev1 = (iNode*)SymTable_get (head , pcKey5);
    if(prev1!=NULL)
        cout<<"result Value is "<<prev1->VALUE<<endl;

    cout<<"calling SymTable_remove() for KEY = "<<pcKey2<<endl;
    prev1 =(iNode*) SymTable_remove(head,pcKey2);
    if(prev1!=NULL){
        cout<<"Removed Value is "<<*(int*)prev1->VALUE<<endl;
        free(prev1);
    }
    Print(head);

    cout<<"calling SymTable_contains() for KEY = "<<pcKey1<<endl;
    result =SymTable_contains(head,pcKey1);
    cout<<"result  is "<<result<<endl;

    cout<<"calling SymTable_contains() for KEY = "<<pcKey<<endl;
    result =SymTable_contains(head,pcKey);
    cout<<"result  is "<<result<<endl;

    cout<<"calling SymTable_contains() for KEY = "<<pcKey5<<endl;
    result =SymTable_contains(head,pcKey5);
    cout<<"result  is "<<result<<endl;

    Print(head);
    int y5=5;
    cout<<"calling SymTable_replace() for KEY = "<<pcKey2<<endl;
    prev1 =(iNode*)SymTable_replace(head,pcKey2,&y);
    if(prev1!=NULL){       cout<<"Replaced key = "<<pcKey2<<" with new value = "<<*(int*)prev1->VALUE<<endl;
    }else
    cout<<"Key Not Found"<<endl;


    cout<<"calling SymTable_replace() for KEY = "<<pcKey<<"new value = "<<y<<endl;
    int m=10, *re=&m;
    prev1 =(iNode*)SymTable_replace(head,pcKey,&m);
    if(prev1!=NULL){       cout<<"Replaced key = "<<pcKey<<" with new value = "<<*(int*)prev1->VALUE<<endl;
    }else
    cout<<"Key Not Found"<<endl;

    // const char *pcKey=NULL;
    // const void *pvValue=NULL;
    SymTable_map(head,&display);
    //Print();
    return 0;
}