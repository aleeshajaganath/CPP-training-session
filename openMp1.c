#include<omp.h>
#include<stdio.h>

/*
    export OMP_NUM_THREADS=4 #set on terminal for contralling no of threads
    gcc -fopenmp  openMp.c -o openMp # compile code on a terminal
    ./openMp #run the code
*/

int main(){

    //outside parallel part variables are shared variable
    int no_threads=omp_get_num_threads();
    int threads_id=omp_get_thread_num();

    // specify the block to be executed
    #pragma omp parallel //compiler directive
    {
        // // printf("hello world\n");
        // int no_threads=omp_get_num_threads();
        // int threads_id=omp_get_thread_num();

        // no_threads,threads_id inside stack each copy
        printf("\nno threads :\t%d",no_threads);
        printf("\nthreads id :\t%d",threads_id);

    }

    return 0;
}