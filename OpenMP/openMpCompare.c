#include <omp.h>
#include <stdio.h>
#include <time.h>

/*
time comparision with openMP and noraml function
*/

void subdomain(float *x, int istart, int ipoints) {
  int i;
  for (i = istart; i < ipoints; i++) x[istart + i] = 123.456;
}

void sub(float *x, int npoints) {
  int iam, nt, ipoints, istart;

// #pragma omp <directive> [clause[ [,] clause]...]
// directives specify either work-sharing or synchronization constructs.
#pragma omp parallel default(shared) private(iam, nt, ipoints, istart)
#pragma omp for ordered
  for (int i = 0; i < 1000; i++)

  {
    iam = omp_get_thread_num();
    nt = omp_get_num_threads();
    ipoints = npoints / nt; /* size of partition */
    istart = iam * ipoints; /* starting array index */
    if (iam == nt - 1)      /* last thread may do more */
      ipoints = npoints - istart;
    subdomain(x, istart, ipoints);
  }
}

void subnormal(float *x, int npoints) {
  int iam, nt, ipoints, istart;
  nt = 4;
  ipoints = npoints / nt; /* size of partition */
  for (int iam = 0; iam < nt; iam++) {
    istart = iam * ipoints; /* starting array index */
    if (iam == nt - 1) {
      /* last thread may do more */
      ipoints = npoints - istart;
    }
    subdomain(x, istart, ipoints);
  }
}

int main() {
  // Calculate the time taken  normal function
  clock_t t1;
  t1 = clock();
  float array1[10000];
  for (int i = 0; i < 1000; i++) {
    subnormal(array1, 10000);
  }
  t1 = clock() - t1;
  double time_taken1 = ((double)t1) / CLOCKS_PER_SEC;  // in seconds
  printf("\n Normal function took %f seconds to execute \n", time_taken1);

  // Calculate the time taken by openMP fun()
  clock_t t;
  t = clock();
  float array[10000];
  sub(array, 10000);
  t = clock() - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC;  // in seconds
  printf("\n openMP took %f seconds to execute \n", time_taken);
  return 0;
}