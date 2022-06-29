#include <iostream>
using namespace std;

int main() {
  // void pointer
  int x = 10;
  void* ptr;
  ptr = &x;
  int* ptrr = (int*)ptr;
  cout << *ptrr << endl;
  return 0;
}