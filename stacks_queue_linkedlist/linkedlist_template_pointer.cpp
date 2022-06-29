
#include <iostream>
using namespace std;
template <class T>
struct node {
  T data;
  struct node* next;
};
typedef node<int> iNode;

iNode* head = NULL;
void Print() {
  cout << "the SLL is " << endl;
  iNode* pre = head;
  while (pre->next != NULL) {
    cout << pre->data << "->";
    pre = pre->next;
  }
  cout << " " << pre->data << endl;
}

// insert a node in SLL
void Insert_end(int data) {
  iNode* Newnode = (iNode*)malloc(sizeof(iNode));
  Newnode->data = data;
  Newnode->next = NULL;
  if (head == NULL) {
    head = Newnode;

  } else {
    iNode* prev = head;
    while (prev->next != NULL) {
      prev = prev->next;
    }

    prev->next = Newnode;
  }
}

void Delete_end() {
  iNode* prev = head;
  iNode* NEXT = head->next;
  while (NEXT->next != NULL) {
    prev = prev->next;
    NEXT = prev->next;
  }
  free(NEXT);
  prev->next = NULL;
  cout << "Deleted end element" << endl;
  Print();
}

int main() {
  Insert_end(5);
  Insert_end(15);
  Insert_end(25);
  Insert_end(8);

  Print();
  Delete_end();
  cout << endl;
  return 0;
}