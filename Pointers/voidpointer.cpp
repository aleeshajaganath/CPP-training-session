// C++ Program to demonstrate that a void pointer
// can hold the address of any type-castable type

#include <iostream>
using namespace std;

int main(){
	int a = 10;
	char b = 'x';	
    void* ptr = &a;   
    cout << *(int *)ptr << endl;
    int n = 4;
    double pi = 3.14;
    int *pn = &n ; 
    double *ppi = &pi;
    ppi = (double*)pn;
    cout<< "explicit convertion *pii " <<*ppi << endl;

}

