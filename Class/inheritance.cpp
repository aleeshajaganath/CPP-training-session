#include<iostream>
using namespace std;

class Person{

    public:
        int id;
        char name[10],course[10];
        int fee;
        int sal;

        void feeupdate(int a){
            cout<<"Fee Paid ...!"<<a<<endl;
        }

        void salupdate(int a){
            cout<<"Salary Credited ...! "<<a<<endl;
        }

};

class Student : public Person{
  public:
    int y;
    void setDerived(){
                cout<<"Derived class"<<endl;
    }
};

class Teacher : public Person{
  public:
    int y;
    void setDerived(){
                cout<<"Derived class"<<endl;
    }
};


int main(){

    Person b;
    Student st;
    st.fee=100;
    st.id=1;
    st.feeupdate(st.fee);

    Teacher t;
    t.sal=10000;
    t.id=44;
    t.salupdate(t.sal);


    return 0;
}

