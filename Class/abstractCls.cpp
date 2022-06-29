#include<iostream>
using namespace std;

class Shape{
    public: 
        int l,b;
        Shape(){
            l=5;
            b=6;
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
    Rectangle s1;
    Square s2;
    s1.area();
    s2.area();
    return 0;

}