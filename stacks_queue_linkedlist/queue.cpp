
/*##########################################
implimentation of stack operation using dynamic array
##########################################*/

#include <iostream>
using namespace std;

class Stack_Operations {
 private:
  int front = -1;
  int rear = -1;
  int capacity;
  int array[100];
  int MAX_SIZE = 100;

 public:
  void Enqueue(int data);
  void Dequeue();
  void Peek();
  bool Is_empty();
  bool Is_full();
};

void Stack_Operations::Enqueue(int data) {
  if (Is_full()) cout << "Queue is full" << endl;
  if (rear == -1) {
    rear = 0;
    front = 0;
  } else {
    rear = rear + 1;
  }
  array[rear] = data;
  cout << "Enqueueed " << *(array + rear) << endl;
}

void Stack_Operations::Dequeue() {
  if (!Is_empty()) {
    int temp = *(array + front);
    cout << "Dequeue  " << *(array + front) << endl;
    front = front - 1;
  }
}

bool Stack_Operations::Is_empty() {
  if (front < 0 || front > rear) return true;
  return false;
}

bool Stack_Operations::Is_full() {
  if (rear == MAX_SIZE) return true;
  return false;
}

void Stack_Operations::Peek() {
  if (Is_empty()) {
    cout << "Empty" << endl;
    return;
  }
  cout << "front elements is "
       << " " << front << array[front] << endl;
}

int main() {
  Stack_Operations s;
  s.Enqueue(5);
  s.Enqueue(10);
  s.Enqueue(0);
  s.Enqueue(8);
  s.Peek();
  if (s.Is_empty())
    cout << " empty true" << endl;
  else
    cout << " empty false" << endl;
  s.Dequeue();
  s.Peek();
  s.Dequeue();
  s.Dequeue();
  s.Dequeue();
  s.Dequeue();

  if (s.Is_empty())
    cout << " empty true" << endl;
  else
    cout << " empty false" << endl;

  return 0;
}