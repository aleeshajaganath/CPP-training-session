#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.

void *Justprint(void *threadID) {
  long tid;
  tid = (long)threadID;
  printf("\t thread id no is %ld ", tid);
}
int main() {
  int count = 10;
  pthread_t threads[10];

  for (long i = 0; i < count; i++) {
    printf(" \n In main creating thread  %ld \n", i);
    int rc = pthread_create(&threads[i], NULL, Justprint, (void *)i);
    if (rc) {
      printf("ERROR CODE %d", rc);
      exit(-1);
    }
  }

  return 0;
}