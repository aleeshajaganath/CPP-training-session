#include<iostream>
using namespace std;

class Shape{

    public: 
    int l,b;
    Shape(){

        // cout<<"Enter length";
        // cin>>l;
        l=5;
        b=6;

        // cout<<"Enter width";
        // cin>>l;

    }
    virtual void area()=0;

};




class Rectangle: public Shape{

    public:
        void area(){

            int ans=l*b;
            cout<<l<<b;

            cout<<" Rectangle Area is "<<ans<<endl;
        }

};


class Square:  public Shape{

    public:
    
        void  area(){

            int ans=(l*b)/2;
            cout<<l<<b;
            cout<<" Square Area is "<<ans<<endl;
        }

};




int main(){

    // Shape *s1, *s2;// *s3;

    Rectangle s1;// = Rectangle;
    Square s2;// =  Square;

    // s3 = new Shape;
    s1.area();
    s2.area();
    // s3->area();
    return 0;

}