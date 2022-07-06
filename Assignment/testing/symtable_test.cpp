/*########################################
      definitions
#########################################*/
#include<gtest/gtest.h>
#include"../src/symtable.h"
#include"../src/symtable.cpp"
#include <iostream>
using namespace std;
iNode* head;
TEST(SymTable_t1,SymTableTestOfnullptr){
    iNode* pre = head;
    int i=5;
    // create 5 bindings
    if(head==NULL){
        head=SymTable_new();
    }

    // expected a nullptr
    EXPECT_TRUE(pre == nullptr);
    cout<<"checked EXPECT_TRUE"<<endl;
    // adding values
    iNode* prev= head;
    while (i>0)    {
        prev->next=SymTable_new();
        prev=prev->next;
        i--;
    }
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
    Print(head);
    cout<<"(SymTable_put)inserted ..!"<<endl;
    ASSERT_EQ(1, SymTable_contains (head,pcKey5));
    ASSERT_EQ(7, SymTable_getLength (head));
}
TEST(SymTable_Pointersting, SymTableNullPointer){
    int y=100;
    EXPECT_TRUE(SymTable_get(head,"i2") != nullptr);
    EXPECT_TRUE(SymTable_remove(head,"i2") != nullptr);
    EXPECT_TRUE(SymTable_replace(head,"i2",&y) == nullptr);
}
TEST(SymTable_freetesting, SymTable_freeNullPointer){
    SymTable_free(head);
    EXPECT_TRUE(head != nullptr);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}