#include<iostream>
using namespace std;


void print(int* arr,int n ){

    for (int i = 0; i < n; i++){

        // cout<<endl;
        cout << "Value at position "<<i << " is "<< *(arr+i) << endl;

    }
}
int main(){

    int *arr, n=10;

    //malloc

    // ptr = (cast-type*) malloc(byte-size)
    //returns a pointer to unitialized block of memory
    arr = (int*)malloc(n*sizeof(int));
    cout<<"allocating 10 memory block using malloc "<<endl;

    for (int i = 0; i < 10; i++)
    {
        /* code */
        *(arr+i)=i;
    }

    cout << "Lets see the values" << endl << endl;
    print(arr,n);



    // calloc 
    int *arr_calloc;
    n=5;
    arr_calloc = (int*)calloc(n,sizeof(int));
    cout<<"\nallocating 10 memory block using calloc "<<endl;

    print(arr_calloc,n);

    // free memory
    free(arr_calloc);
    cout<<"\n free memory "<<endl;
	cout << "Garbage Value" << endl;

    print(arr_calloc,n);

    return 0;   


}