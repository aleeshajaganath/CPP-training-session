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
// iNode* oSymTable = NULL;

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
void SymTable_free (SymTable_t *oSymTable){
    struct SymTable_t* tmp = oSymTable;
    while (oSymTable!=NULL)    {
        tmp=oSymTable;
        oSymTable=oSymTable->next;
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
    int i=0;
    if (oSymTable->KEY==NULL){
        oSymTable->KEY=pcKey;
        oSymTable->VALUE=pvValue;
        return 1;
    }else if (oSymTable->KEY==pcKey)  {
        return 0;
    }
    iNode* prev = oSymTable;
    while (prev->next!= NULL && prev->KEY!=NULL){
        i++;
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
    return 1;
}





// searches pcKey. successful, returns the value else NULL
void* SymTable_get (SymTable_t *oSymTable, const char *pcKey){
    iNode* prev = oSymTable;
    while (prev!= NULL and prev->KEY!=NULL){
        if (prev->KEY==pcKey){
            void *pointer_name;  
            pointer_name=&prev->VALUE;
            return prev;
        }
        prev = prev->next;
    }
    return NULL;
}

// searches pcKey. successful, returns removes the binding else NULL
void *SymTable_remove ( SymTable_t *oSymTable,
                        const char *pcKey){
    iNode* tmp = NULL;
    if (oSymTable->KEY==pcKey){
        tmp=oSymTable;
        oSymTable=oSymTable->next;
        free(tmp);
        return oSymTable;
    }
    iNode* prev = NULL, *NEXT=oSymTable;
    while (NEXT!=NULL &&NEXT->KEY!=NULL)    {
        
        if (NEXT->KEY!=pcKey){
            prev=NEXT;
            NEXT=NEXT->next;
        }else{
            tmp=prev->next;
            prev->next=NEXT->next;
            // free(tmp);
            return tmp;
            // break;
        }
    }   
    return NULL;
}

// searches to locate pcKey. successful, returns 1 else 0.
int SymTable_contains ( SymTable_t *oSymTable, const char *pcKey){
    iNode* prev =(iNode*)SymTable_get (oSymTable , pcKey);
    if (prev!=NULL)
        return 1;
    return 0;
}

// searches through oSymTable to locate the binding with pcKey
// if success replace else return NULL
void *SymTable_replace (SymTable_t *oSymTable,
                        const char *pcKey,
                        const void *pvValue){ 
    if (SymTable_contains(oSymTable,pcKey)==0)
        return NULL;
    iNode* prev = oSymTable;
    while (prev!= NULL &&prev->KEY!=NULL){
        if (prev->KEY==pcKey){
            prev->VALUE=pvValue;
            cout<<"REPLACED"<<*(int*)prev->VALUE<<endl;
            return prev;
        }
        prev = prev->next;
    }
    return prev;
}
// printing the SLL
void Print(SymTable_t *oSymTable) {
    int i=0;
    cout << "\n the SLL is " << endl;
    iNode* pre = oSymTable;
    while (pre != NULL && pre->KEY!=NULL){
            int* ptrr1 = (int*)pre->VALUE;
            char* ptrr2 = (char*)pre->KEY;
            const char *c =(char*)pre->KEY;
            cout << "key "<<c << " ->  value "<<*(int*)pre->VALUE<<endl;
            pre = pre->next;

        }
        pre = pre->next;
    }

void display(const char *pcKey1, const void *pvValue1){
    cout<<"key = "<<pcKey1<<" with  value = "<<*(int*)pvValue1<<endl;
    
}
// caling another function while traversal
void SymTable_map ( SymTable_t *oSymTable, 
                    void (*pfApply) (const char *pcKey1, const void *pvValue1)){
                    // const char *pcKey,const void *pvValue){   
    iNode* pre = oSymTable;
    int i=0;
    while (pre != NULL and pre->KEY!=NULL) {
        pfApply(pre->KEY,pre->VALUE);
        pre = pre->next;
        i++;
    }
}
typedef SymTable_t iNode;

