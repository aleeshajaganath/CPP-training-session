#include<iostream>
using namespace std;

//pgm combining structure pointer and template
template <class T>
struct Points {
    T x,y;
};
typedef Points<int> iPoints;
typedef Points<float> fPoints;

int main(){
    // points struture declaration
    fPoints p1={10.25,20.75};
    fPoints p2={10.75,30.25}; 
    fPoints p3={40.25,20.75};
    // rectangle struture declaration
    cout << "P1 " << p1.x <<","<<p1.y<<endl;
    cout << "P2 " << p2.x <<","<<p2.y<<endl;
    cout << "P3 " << p3.x <<","<<p3.y<<endl;
    iPoints p5={10,20};
    iPoints p6={10,30}; 
    iPoints p7={40,20};
    // rectangle struture declaration
    cout << "P1 " << p5.x <<","<<p5.y<<endl;
    cout << "P2 " << p6.x <<","<<p6.y<<endl;
    cout << "P3 " << p7.x <<","<<p7.y<<endl;
    return 0;
}