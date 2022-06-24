#include <iostream>
using namespace std;
template<class T>
struct MyTemplate {
    T f(T t) { return t + 1; }
};

extern template class MyTemplate<double>;

template class MyTemplate<double>;


// extern template class myMax<double>;

// #include "mytemplate.hpp"
// #include "notmain.hpp"

int main() {
    cout <<  MyTemplate<int>().f(1) << endl;
   

}