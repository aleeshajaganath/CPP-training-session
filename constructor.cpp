#include<iostream>
using namespace std;


class  Student
{

public:
    int rollno,fee;
    char name[100];
    Student(/* args */){

        cout<<"Enter roll no"<<endl;
        cin>>rollno;
        cout<<"Enter Name"<<endl;
        cin>>name;
        cout<<"Enter Fee"<<endl;
        cin>>fee;
     }

    void printDetails(){
        cout<<name<<endl<<rollno<<endl<<fee<<endl;
    }
    // ~ Strudent();
};




int main(){

    Student S;
    S.printDetails();

    return 0;
}