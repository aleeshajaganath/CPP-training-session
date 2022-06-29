

#include <omp.h>
#include<stdio.h>



/*
Syntax
#pragma omp parallel for schedule(static,thread) for(conditions){
*/
//pgm for implimenting dynamic scheduler
int main()
{
#pragma omp parallel for schedule(static,1) 	
for (int i = 0; i < 20; i++)
	{
		printf("Thread %d is running number %d\n", omp_get_thread_num(), i);
	}
	return 0;
}