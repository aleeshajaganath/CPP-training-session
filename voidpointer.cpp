// C++ Program to demonstrate that a void pointer
// can hold the address of any type-castable type

#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	char b = 'x';
	
    void* ptr = &a;
   
    cout << *(int *)ptr << endl;
    int n = 4;
    double pi = 3.14;// . 1 4 1 5 9 ;
    int *pn = &n ; // ∗ address o f i n t e g e r n ∗ /
    double *ppi = &pi;// ∗ address o f double p i ∗ /    ppi = (double ∗)pn;/ /∗ pn originally of type ( int ∗) ∗/
    ppi = (double*)pn;
    cout<< "explicit convertion *pii " <<*ppi << endl;

}

// This code is contributed by sarajadhav12052009
