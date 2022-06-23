#include<iostream>
using namespace std;

struct  points
{
    /* data */
    int x,y;
};

struct rectangle
{
    /* data */
    struct points p1;
    struct points p2;
    struct points p3;
    struct points p4;
    
};

struct triangle
{
    /* data */
    struct points p1;
    struct points p2;
    struct points p3;
    
};


int main(){
    // points struture declaration
    struct points p1={10,20};
    struct points p2={10,30};
    struct points p3={40,20};
    struct points p4={40,30};

    // rectangle struture declaration

    struct rectangle r;
    r.p1=p1 ;
    r.p2=p2;
    r.p3=p3;
    r.p4=p4;

    // triangle struture declaration

    struct triangle t;
    t.p1=p1;
    t.p2=p2;
    t.p3=p3;

   
    cout << "rectangle points " <<endl;
    cout << "P1 " << r.p1.x<<"," <<r.p1.y<<endl;
    cout << "P4 " << r.p4.x <<","<<r.p4.y<<endl;

    cout << "triangle points " <<endl;
    cout << "P2 " << r.p2.x<<"," <<r.p2.y<<endl;
    cout << "P3 " << r.p3.x <<","<<r.p3.y<<endl;


    // structure variable refer using pointers
    struct points *p;
    p=&p1;
    cout << "Pointer P using arrow -> " << p->x<<"," <<p->y<<endl;
    cout << "Pointer P using dot . " <<(*p).x<<"," <<p->y<<endl;


    // Arrays of structures

    struct points arr[3]={{10,20},{10,30},{40,20}};
    cout << arr[0].x<<endl;
    return 0;
}