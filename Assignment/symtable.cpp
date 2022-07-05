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
    void* KEY;//[100];
    // string *KEY;
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

/*  free all the memory occupied by the symbol table */
void SymTable_free (){
    struct SymTable_t* tmp = head;
    while (head!=NULL)    {
        tmp=head;
        head=head->next;
        free(tmp);
    } 
    TOTAL_BIND=0;    
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
        head->KEY=&pcKey;
        head->VALUE=pvValue;
        // i++;
        cout<<"Inserted at HEAD "<<i<<endl;
        return 1;
    }else if (head->KEY==pcKey)  {
        return 0;
    }
    // i++;

    // cout<<"2. PUT"<<endl;
    iNode* prev = head;
    while (prev->next!= NULL && prev->KEY!=NULL){
        i++;
        cout<<i<<endl;
        if (prev->KEY==pcKey){//key present
            return 0;
        }
        prev = prev->next;
    }

    if (prev->next == NULL) {// create as no memory available
        prev->next=SymTable_new();
    }
        // if (prev==NULL)
        //     return 0;
    prev->KEY=&pcKey;
    prev->VALUE=pvValue;
    cout<<"Inserted at PREV"<<endl;
    return 1;
}
// searches through oSymTable to locate the binding with pcKey
// if success replace else return NULL
void *SymTable_replace (SymTable_t *oSymTable,
                        const char *pcKey,
                        const void *pvValue){    
    iNode* prev = head;
    while (prev!= NULL){
        if (prev->KEY==pcKey){
            prev->VALUE=pvValue;
        }
        prev = prev->next;
    }
    return prev;
}

// searches to locate pcKey. successful, returns 1 else 0.
int SymTable_contains ( SymTable_t *oSymTable, const char *pcKey){
    iNode* prev = head;
    while (prev->next!= NULL){
        if (prev->KEY==pcKey){
            return 1;
        }
        prev = prev->next;
    }
    return 0;
}

// searches pcKey. successful, returns the value else NULL
void* SymTable_get (SymTable_t oSymTable, const char *pcKey){
    iNode* prev = head;
    while (prev->next!= NULL){
        if (prev->KEY==pcKey){
            return (void*)prev->VALUE;
        }
        prev = prev->next;
    }
    return prev;
}

// searches pcKey. successful, returns removes the binding else NULL
void *SymTable_remove ( SymTable_t oSymTable,
                        const char *pcKey){
    iNode* tmp = NULL;
    if (head->KEY==pcKey){
        tmp=head;
        head=head->next;
        free(tmp);
        return head;
    }
    iNode* prev = NULL, *NEXT=head;
    while (NEXT!=NULL)    {
        
        if (NEXT->KEY!=pcKey){
            prev=NEXT;
            NEXT=NEXT->next;
        }else{
            tmp=prev->next;
            prev->next=NEXT->next;
            free(tmp);
            return prev;
            break;
        }
    }    
    return prev;
}
// caling another function while traversal
void SymTable_map ( SymTable_t *oSymTable, 
                    void (*pfApply) (const char *pcKey1, const void *pvValue1),
                    const char *pcKey,const void *pvValue){   
    iNode* pre = head;
    int i=0;
    while (pre != NULL) {
        cout << pre << "->"<<i<<endl;
        pfApply(pcKey,pvValue);
        pre = pre->next;
        i++;
    }
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
            cout << "key "<<&ptrr2 << " ->  value "<<*(int*)pre->VALUE<<endl;
            pre = pre->next;

        }
        // cout << pre << "->"<<i<<endl;
        pre = pre->next;
        // i++;
    }
    // cout << " " << pre << endl;
// }
typedef SymTable_t iNode;

int main(){
    int i=5;

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
    const char *pcKey="iklkl";
    // int *pvValue=1;
    int *x,y=9;
    x=&y;
    int result=SymTable_put (head,pcKey,x);
    cout<<"(SymTable_put)inserted ..!\nkey : "<<pcKey<<"\nvalue : "<<*x<<endl;
    Print();
    // int* ptrr = (int*)head->VALUE;
    // char* ptrr = (char*)head->KEY;
    // cout<<*ptrr;

    *x=21;
    string key="iklkl1";
    const char *pcKey1="iklkl234";

    // result=SymTable_put (head,key.c_str(),x);
    result=SymTable_put (head,pcKey1,x);

    // *x=22;
    // // string 
    // key="iklkl2";
    // result=SymTable_put (head,key.c_str(),x);
    cout<<"last"<<endl;
    cout << &(head->next->KEY) << endl;
    cout << *(int*)head->next->VALUE << endl;
    // int* ptrr = (int*)head->VALUE;
    // char* ptrr1 = (char*)head->KEY;
    // cout<<*ptrr1;
    Print();

    const char *pcKey2="iklkl2";
    // int *pvValue=1;
    int *x1,y2=9;
    x1=&y2;
    result=SymTable_put (head,pcKey2,x1);
    Print();

    const char *pcKey3="iklkl3";
    // int *pvValue=1;
    int *x3,y3=19;
    x3=&y3;
    result=SymTable_put (head,pcKey3,x3);
    Print();
    return 0;
}