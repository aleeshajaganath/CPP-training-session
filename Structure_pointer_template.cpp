#include<iostream>
using namespace std;
template <class T>
// template<class T>
struct points {
    T x,y;
    // T f(T t) { return t + 1; }
};
// extern 
// template class points<int>;
typedef points<int> iPoints;
typedef points<float> fPoints;



int main(){
    // points struture declaration
    // struct
    fPoints p1={10.25,20.75};
    // struct
    fPoints p2={10.75,30.25};
    // struct 
    fPoints p3={40.25,20.75};
    // struct points p4={40,30};

    // rectangle struture declaration
    cout << "P1 " << p1.x <<","<<p1.y<<endl;
    cout << "P2 " << p2.x <<","<<p2.y<<endl;
    cout << "P3 " << p3.x <<","<<p3.y<<endl;

    iPoints p5={10,20};
    // struct
    iPoints p6={10,30};
    // struct 
    iPoints p7={40,20};
    // struct points p4={40,30};

    // rectangle struture declaration
    cout << "P1 " << p5.x <<","<<p5.y<<endl;
    cout << "P2 " << p6.x <<","<<p6.y<<endl;
    cout << "P3 " << p7.x <<","<<p7.y<<endl;

 

    return 0;
}