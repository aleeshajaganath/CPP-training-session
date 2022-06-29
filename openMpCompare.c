#include <omp.h>
#include<stdio.h>
#include <time.h>



void subdomain(float *x, int istart, int ipoints)
{
    int i;
    for (i = 0; i < ipoints; i++)
        x[istart+i] = 123.456;
    printf("\n row = %d and column = %d",istart,ipoints);

}


void sub(float *x, int npoints)
{
    int iam, nt, ipoints, istart;

    // #pragma omp <directive> [clause[ [,] clause]...]
    // directives specify either work-sharing or synchronization constructs.
    #pragma omp parallel default(shared) private(iam,nt,ipoints,istart)
    {
        iam = omp_get_thread_num();
        nt = omp_get_num_threads();
        ipoints = npoints / nt;   /* size of partition */
        istart = iam * ipoints; /* starting array index */
        if (iam == nt-1)
            /* last thread may do more */
            ipoints = npoints - istart;
        printf("\n thread no = %d ",iam);

        subdomain(x, istart, ipoints);
    }
}



void subnormal(float *x, int npoints)
{
    int iam, nt, ipoints, istart;

    // #pragma omp <directive> [clause[ [,] clause]...]
    // directives specify either work-sharing or synchronization constructs.
    // #pragma omp parallel default(shared) private(iam,nt,ipoints,istart)
    // {
        // iam = omp_get_thread_num();
        // nt = omp_get_num_threads();
        nt=4;
        ipoints = npoints / nt;   /* size of partition */
        for (int iam = 0; iam < nt; iam++)
        {           
            printf("\n i no = %d ",iam);

            istart = iam * ipoints; /* starting array index */
            if (iam == nt-1){
                printf("\n last i no = %d ",iam);

                /* last thread may do more */
                ipoints = npoints - istart;
            // printf("\n thread no = %d ",iam);
            }
            subdomain(x, istart, ipoints);
    }
}



int main()
{




// Calculate the time taken  normal function
        clock_t t1;

        t1 = clock();

        float array1[10000];
        subnormal(array1, 10000);

        t1 = clock() - t1;
        // double 
        double time_taken1 = ((double)t1)/CLOCKS_PER_SEC; // in seconds
    
        printf("\n Normal function took %f seconds to execute \n", time_taken1);



// Calculate the time taken by openMP fun()
        clock_t t;
        t = clock();

        float array[10000];
        sub(array, 10000);

        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    
        printf("\n openMP took %f seconds to execute \n", time_taken);


        return 0;
}