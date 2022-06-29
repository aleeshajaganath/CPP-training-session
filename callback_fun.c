// A simple C program to demonstrate callback
#include<stdio.h>

void A(int x, int y){
	printf("I am function A\n");
}

// callback function
void B(int x, int y,void (*ptr)(int x,int y)){
	(*ptr) (x,y); // callback to A
}

int main(){
	void (*ptr)(int x ,int y) = &A;
	int x=5,y=9;
	// calling function B and passing
	// address of the function A as argument
	B(x,y,ptr);

return 0;
}
