#include<iostream>
using namespace std;


class  Student{

   public:
    int rollno,fee;
    char name[100];
    Student(){
        cout<<"****Enter following details****"<<endl;
        cout<<" Roll no"<<endl;
        cin>>rollno;
        cout<<" Name"<<endl;
        cin>>name;
        cout<<" Fee"<<endl;
        cin>>fee;
        }

    void printDetails(){
        cout<<"****Details****"<<endl;
        cout<<name<<endl<<rollno<<endl<<fee<<endl;
    }
};

int main(){

    Student S;
    S.printDetails();
    return 0;
}