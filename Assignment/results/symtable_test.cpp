/*########################################
      definitions
#########################################*/
#include<gtest/gtest.h>
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
    // cout<<"\n**********SymTable_put**********"<<endl;
    int i=0;
    // cout<<"pcKey "<<pcKey<<endl;
    // cout<<"pvValue "<<*(int*)pvValue<<endl;
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

    // cout<<"\n**********SymTable_get**********"<<endl;
    // int i=0;
    // cout<<"pcKey "<<pcKey<<endl;
    while (prev!= NULL and prev->KEY!=NULL){
        // cout<<"KEY "<<prev->KEY<<endl;
        if (prev->KEY==pcKey){
            // cout<<"VALUE "<<*(int *)prev->VALUE<<endl;
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
    if (head->KEY==pcKey){
        tmp=head;
        head=head->next;
        free(tmp);
        return head;
    }
    iNode* prev = NULL, *NEXT=head;
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
    // if (NEXT->KEY==NULL)
        return NULL;
    // return prev;
}

// searches to locate pcKey. successful, returns 1 else 0.
int SymTable_contains ( SymTable_t *oSymTable, const char *pcKey){
    // iNode* prev = head;
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
    iNode* prev = head;
    while (prev!= NULL &&prev->KEY!=NULL){
        if (prev->KEY==pcKey){
            prev->VALUE=pvValue;
            // cout<<"REPLACED"<<*(int*)prev->VALUE<<endl;
            return prev;
        }
        prev = prev->next;
    }
    return prev;
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

void display(const char *pcKey1, const void *pvValue1){
    cout<<"key = "<<pcKey1<<" with  value = "<<*(int*)pvValue1<<endl;
    
}
// caling another function while traversal
void SymTable_map ( SymTable_t *oSymTable, 
                    void (*pfApply) (const char *pcKey1, const void *pvValue1),
                    const char *pcKey,const void *pvValue){   
    iNode* pre = head;
    int i=0;
    while (pre != NULL and pre->KEY!=NULL) {
        // cout << pre << "->"<<i<<endl;
        pfApply(pre->KEY,pre->VALUE);
        pre = pre->next;
        i++;
    }
}

typedef SymTable_t iNode;



TEST(SymTable_t1,SymTableTestOfnullptr){// ZeroShouldBeOne){
  // EXPECT_THROW(divisionTest,);
  // EXPECT_ANY_THROW({
  // int n = 5;
  // division(n);  });
  // EXPECT_PRED1(division,5);
  // EXPECT_PRED1(division,IsNull());


    iNode* pre = head;
    int i=5;
    // create 5 bindings
    if(head==NULL){
        head=SymTable_new();
    }

    // expected a nullptr
    EXPECT_TRUE(pre == nullptr);
    cout<<"checked EXPECT_TRUE"<<endl;
    // EXPECT_NO_THROW(pre->next);
    // adding values
    iNode* prev= head;
    while (i>0)    {
        prev->next=SymTable_new();
        prev=prev->next;
        // cout<<i<<endl;
        i--;
    }
    
//   EXPECT_THROW(pre ,const exception& er);

    cout<<"(SymTable_getLength)Total length including head is : "<<SymTable_getLength(head)<<endl;

}

TEST(SymTable_puttesting, SymTable_puttestingOfPositiveNos){
    /* A test program can contain multiple test suites.
     ASSERT_* versions generate fatal failures when they fail,
     and abort the current function
    */

    const char *pcKey0="i0",*pcKey1="i1",*pcKey2="i2",*pcKey3="i3",*pcKey4="i4",*pcKey5="i5";
    int *x0,y0=9,y1=19,y2=21,y3=12,y4=11,y5=33;
    x0=&y0;
    int *x1=&y1;
    int *x2=&y2;
    int *x3=&y3;
    int *x4=&y4;
    int *x5=&y5;
    ASSERT_EQ(1, SymTable_put (head,pcKey0,x0));
    ASSERT_EQ(1, SymTable_put (head,pcKey1,x1));
    ASSERT_EQ(1, SymTable_put (head,pcKey2,x2));
    ASSERT_EQ(1, SymTable_put (head,pcKey3,x3));
    ASSERT_EQ(1, SymTable_put (head,pcKey4,x4));
    ASSERT_EQ(1, SymTable_put (head,pcKey5,x5));
    Print();
    cout<<"(SymTable_put)inserted ..!"<<endl;
    ASSERT_EQ(1, SymTable_contains (head,pcKey5));
    ASSERT_EQ(7, SymTable_getLength (head));
    // Print();
}
TEST(SymTable_Pointersting, SymTableNullPointer){
    // Print();
    int y=100;
    EXPECT_TRUE(SymTable_get(head,"i2") != nullptr);
    EXPECT_TRUE(SymTable_remove(head,"i2") != nullptr);
    EXPECT_TRUE(SymTable_replace(head,"i2",&y) == nullptr);
    // EXPECT_TRUE(SymTable_get(head,"i2") != nullptr);
    // EXPECT_TRUE(SymTable_get(head,"i2") != nullptr);
    // Print();

}
TEST(SymTable_freetesting, SymTable_freeNullPointer){
    // Print();
    SymTable_free();
    EXPECT_TRUE(head == nullptr);
    // Print();

}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}