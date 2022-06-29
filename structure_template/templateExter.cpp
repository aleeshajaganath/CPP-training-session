#include <iostream>
using namespace std;
template<class T>
struct MyTemplate {
    T f(T t) { return t + 1; }
};
extern template class MyTemplate<double>;
template class MyTemplate<double>;
int main() {
    cout <<  MyTemplate<int>().f(1) << endl;
}