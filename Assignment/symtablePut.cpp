/*########################################
      definitions
#########################################*/

#include"symtable.h"
#include <iostream>
using namespace std;

int TOTAL_BIND=0;

/*  structure containing two boxes key (KEY) and value (VALUE)  and next binding (next)*/
struct SymTable_t {
    struct SymTable_t* next;
    // void* KEY;//[100];
    const char *KEY;
    const void*  VALUE;

};
typedef SymTable_t iNode;
iNode* head = NULL;

/*  SymTable_new should create a new SymTable structure with no bindings within it.*/
iNode* SymTable_new (){
        TOTAL_BIND++;
        iNode* Newnode = (iNode*)malloc(sizeof(iNode));
        Newnode->next = NULL;
        Newnode->KEY=NULL;
        Newnode->VALUE=NULL;
        return Newnode;
}

/*  return the total bindings within oSymTable.*/
int SymTable_getLength (SymTable_t *oSymTable){
    return TOTAL_BIND;
}

// inserts returns 1 if pcKey is absent
int SymTable_put (SymTable_t *oSymTable,const char *pcKey, const void *pvValue){
    cout<<"\n**********SymTable_put**********"<<endl;
    int i=0;
    cout<<"pcKey "<<pcKey<<endl;
    cout<<"pvValue "<<*(int*)pvValue<<endl;
    if (head->KEY==NULL){
        head->KEY=pcKey;
        // cout<<"KEY ONLY"<<head->KEY;
        head->VALUE=pvValue;
        // i++;
        // cout<<"Inserted at HEAD "<<i<<endl;
        return 1;
    }else if (head->KEY==pcKey)  {
        return 0;
    }
    // i++;

    // cout<<"2. PUT"<<endl;
    iNode* prev = head;
    while (prev->next!= NULL && prev->KEY!=NULL){
        i++;
        // cout<<i<<endl;
        if (prev->KEY==pcKey){//key present
            return 0;
        }
        prev = prev->next;
    }
    if (prev->next == NULL) {// create as no memory available
        prev->next=SymTable_new();
    }
    prev->KEY=pcKey;
    prev->VALUE=pvValue;
    // cout<<"KEY ONLY"<<(const char*)prev->KEY;

    // cout<<"Inserted at PREV"<<endl;
    return 1;
}





// searches pcKey. successful, returns the value else NULL
void* SymTable_get (SymTable_t *oSymTable, const char *pcKey){
    iNode* prev = head;

    cout<<"\n**********SymTable_get**********"<<endl;
    int i=0;
    cout<<"pcKey "<<pcKey<<endl;
    // cout<<"pvValue "<<*(int*)pvValue<<endl;

    while (prev!= NULL and prev->KEY!=NULL){
        cout<<"KEY "<<prev->KEY<<endl;
        if (prev->KEY==pcKey){
            cout<<"VALUE "<<*(int *)prev->VALUE<<endl;
            void *pointer_name;  
            pointer_name=&prev->VALUE;
            // return *pointer_name;
            return prev;//->VALUE;
        }
        prev = prev->next;
    }
    // cout<<"no value"<<endl;
    return NULL;
}






// printing the SLL
void Print() {
    int i=0;
    cout << "\n the SLL is " << endl;
    iNode* pre = head;
    while (pre != NULL && pre->KEY!=NULL){
            int* ptrr1 = (int*)pre->VALUE;
            char* ptrr2 = (char*)pre->KEY;
            const char *c =(char*)pre->KEY;
            cout << "key "<<c << " ->  value "<<*(int*)pre->VALUE<<endl;
            pre = pre->next;

        }
        // cout << pre << "->"<<i<<endl;
        pre = pre->next;
        // i++;
    }
typedef SymTable_t iNode;





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
    //complete symtable remove from header onwards
    // SymTable_free();
    // cout<<"Freed memory using SymTable_free"<<endl;
    // Print();
    // cout<<"(SymTable_getLength)Total length including head is : "<<SymTable_getLength(head)<<endl;
    const char *pcKey="i0";
    // int *pvValue=1;
    int *x,y=9;
    x=&y;
    int result=SymTable_put (head,pcKey,x);
    cout<<"(SymTable_put)inserted ..!\nkey : "<<pcKey<<"\nvalue : "<<*x<<endl;
    Print();
    // int* ptrr = (int*)head->VALUE;
    // char* ptrr = (char*)head->KEY;
    // cout<<"*ptrr";

    int xa=21;
    x=&xa;
    string key="i1";
    const char *pcKey1="i1";

    // result=SymTable_put (head,key.c_str(),x);
    result=SymTable_put (head,pcKey1,x);

    // *x=22;
    // // string 
    // key="iklkl2";
    // result=SymTable_put (head,key.c_str(),x);
    // cout<<"last"<<endl;
    // cout << &(head->next->KEY) << endl;
    // cout << *(int*)head->next->VALUE << endl;
    // int* ptrr = (int*)head->VALUE;
    // char* ptrr1 = (char*)head->KEY;
    // cout<<*ptrr1;
    Print();

    const char *pcKey2="i2";
    // int *pvValue=1;
    int *x1,y2=19;
    x1=&y2;
    result=SymTable_put (head,pcKey2,x1);
    Print();

    // const char *pcKey3="i3";
    // string ptr="st1";
    // int *pvValue=1;
    // int *x3,y3=29;
    // x3=&y3;
    // string str = "std::string to const char*";
    // result=SymTable_put (head,&str[0],x3);
    // Print();
    cout<<"calling SymTable_get() for KEY = "<<pcKey2<<endl;
    iNode* prev1 = (iNode*)SymTable_get (head , pcKey2);
    if(prev1!=NULL)
        cout<<"result Value is "<<*(int*)prev1->VALUE<<endl;

    const char *pcKey5="i5";
    cout<<"calling SymTable_get() for KEY = "<<pcKey5<<endl;
    prev1 = (iNode*)SymTable_get (head , pcKey5);
    if(prev1!=NULL)
        cout<<"result Value is "<<prev1->VALUE<<endl;

    return 0;
}