#include <iostream>
using namespace std;

template <class T, class U>
T add(U x, U y) {
  return x + y;
}
int main() {
  cout << add<int>(3, 7) << endl;
  return 0;
}