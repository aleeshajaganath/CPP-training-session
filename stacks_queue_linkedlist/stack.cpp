
#include <iostream>
using namespace std;

//implimentation of stack operation using dynamic array


class Stack_Operations{
    private:
        /* data */
        int top=-1;
        int array[100];

    public:
        void Push(int data);
        void Pop();
        void Peek();
        bool Is_empty();
};

void Stack_Operations::Push(int data){
    if (top==-1){
        top=0;
    }
    else{
        top=top+1;
    }
    // *(array+top)=data;
    array[top]=data;
    cout<<"pushed "<< *(array+top)<<endl;

}

void Stack_Operations::Pop(){
    if (!Is_empty()){
        int temp=*(array+top);
        cout<<"Pop  "<<*(array+top)<<endl;
        top=top-1;


    }
}

bool Stack_Operations::Is_empty(){
    if (top==-1)
        return true;
    return false;
}

void  Stack_Operations::Peek(){
    if (Is_empty()){
        cout<<"Empty"<<endl;
        return ;
    }
    cout<<"Top elements is "<<*(array+top)<<endl;
}

int main(){
    Stack_Operations s;
    s.Push(5);
    s.Push(10);
    s.Push(0);
    s.Push(8);
    s.Peek();
    // <<endl;
    if (s.Is_empty())
        cout<<" empty true"<<endl;
    else
        cout<<" empty false"<<endl;

    s.Pop();
    s.Peek();  
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();

    if (s.Is_empty())
        cout<<" empty true"<<endl;
    else
        cout<<" empty false"<<endl;

    return 0;
}