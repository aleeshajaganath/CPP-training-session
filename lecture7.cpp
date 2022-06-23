#include<iostream>
using namespace std;


void print_multiDarray(int** arr,int row,int col){


    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){    
            cout << "r= "<<i<<" col "<<j<<"\t"<< **(arr+i) << endl;            
        }
    }
}

void printstring(char** arr,int n ){

    for (int i = 0; i < n; i++){

        cout << "Pointer at position "<<i << " is "<< *(arr+i) << endl;

    }
}
void printint(int** arr,int n ){

    for (int i = 0; i < n; i++){

        cout << "1st element of Pointer at position "<<i << " is "<< **(arr+i) << endl;

    }
}

int main(){

    char str1[]="string1";
    char str2[]="string2";
    char str3[]="string3";

    /* strArray contains only pointers, not the characters
    themselves */
    char * strArray[]={str1,str2,str3};
    cout<<"\n Printing array of pointers to char "<<endl;

    printstring(strArray,3);




    int int1[]={0,1,2};
    int int2[]={3,4};
    int int3[]={5,6};

    /* strArray contains only pointers, not the characters
    themselves */
    int * intArray[]={int1,int2,int3};
    cout<<"\n Printing array of pointers to int "<<endl;

    printint(intArray,3);



    /*multi dimentional array*/
    int x[3][4] = {{0,1,2,3}, {4,5,6,7}, {8,9,10,11}};
    // print_multiDarray(x,3,4);

    // output each array element's value
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "Element at x[" << i
                 << "][" << j << "]: ";
            cout << x[i][j]<<endl;
        }
    }
    return 0;
}
