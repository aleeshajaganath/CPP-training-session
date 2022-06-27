
#include <iostream>
using namespace std;
template <class T>
struct node{
    T data;
    struct node *next;
       

};
typedef node<int> iNode;

iNode* head= NULL;

// insert a node in SLL
void Insert(int data){
    cout<<data<<endl;
    // struct node*
    iNode* Newnode = (iNode*) malloc(sizeof(iNode));
    Newnode->data=data;
    Newnode->next=NULL;
    if (head==NULL){
        head=Newnode;

    }else{

        // struct node*
        iNode* prev= head;
        while (prev->next!=NULL){
            cout<<prev->data<<endl;
            prev=prev->next;
        }

        prev->next=Newnode;
    }
}

void Print(){
    //struct node *head){
    cout<<" the SLL is "<<endl;
    // struct node*
    iNode* pre=head;
    while (pre->next!=NULL)
    {
        /* code */
        cout<<pre->data<<"->\t";
        pre=pre->next;
    }
    cout<<"->\t"<<pre->data;

}

int main(){

    Insert(5);
    Insert(15);
    Insert(25);

    Print();
    cout<<endl;
    return 0;
}