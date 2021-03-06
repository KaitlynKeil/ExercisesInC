/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "mutex.h"

<<<<<<< HEAD
#define NUM_CHILDREN 2

void perror_exit(char *s)
{
  perror(s);  
  exit(-1);
}

void *check_malloc(int size)
{
  void *p = malloc(size);
  if (p == NULL) {
      perror_exit("malloc failed");
  }
  return p;
}

typedef struct {
  int counter;
  int end;
  int *array;
  Mutex *mutex;
} Shared;

Shared *make_shared(int end)
{
  int i;
  Shared *shared = check_malloc(sizeof(Shared));

  shared->counter = 0;
  shared->end = end;
  shared->mutex = make_mutex();

  shared->array = check_malloc(shared->end * sizeof(int));
  for (i=0; i<shared->end; i++) {
    shared->array[i] = 0;
  }
  return shared;
}

pthread_t make_thread(void *(*entry)(void *), Shared *shared)
{
  int ret;
  pthread_t thread;

  ret = pthread_create(&thread, NULL, entry, (void *) shared);
  if (ret != 0) {
      perror_exit("pthread_create failed");
  }
  return thread;
}

void join_thread(pthread_t thread)
{
  int ret = pthread_join(thread, NULL);
  if (ret == -1) {
      perror_exit("pthread_join failed");
  }
}

void child_code(Shared *shared)
{
  // mutex_lock(shared->mutex);
  // printf("Starting child at counter %d\n", shared->counter);

  while (1) {
    if (shared->counter >= shared->end) {
      // mutex_unlock(shared->mutex);
      return;
    }
    mutex_lock(shared->mutex);
    shared->array[shared->counter]++;
    shared->counter++;

    // mutex_lock(shared->mutex);
    if (shared->counter % 10000 == 0) {
    	int t = shared->counter;
    	mutex_unlock(shared->mutex);
      printf("%d\n", t);
    } else {mutex_unlock(shared->mutex);}
  }
}

void *entry(void *arg)
{
  Shared *shared = (Shared *) arg;
  child_code(shared);
  // printf("Child done.\n");
  pthread_exit(NULL);
}

void check_array(Shared *shared)
{
  int i, errors=0;

  // printf("Checking...\n");

  for (i=0; i<shared->end; i++) {
    if (shared->array[i] != 1) errors++;
  }
  printf("%d errors.\n", errors);
=======
#define NUM_CHILDREN 5

/* Print an error message and exit.
*/
void perror_exit(char *s)
{
    perror(s);
    exit(-1);
}

/* Call malloc and exit if it fails.
*/
void *check_malloc(int size)
{
    void *p = malloc(size);
    if (p == NULL) {
        perror_exit("malloc failed");
    }
    return p;
}

/* Structure that contains variables shared between threads.
*/
typedef struct {
    int counter;
    Mutex *mutex;
} Shared;

/* Allocate the shared structure.
*/
Shared *make_shared()
{
    Shared *shared = check_malloc(sizeof(Shared));
    shared->counter = 0;
    shared->mutex = make_mutex();
    return shared;
}

/* Create a child thread.
*/
pthread_t make_thread(void *(*entry)(void *), Shared *shared)
{
    int ret;
    pthread_t thread;

    ret = pthread_create(&thread, NULL, entry, (void *) shared);
    if (ret != 0) {
        perror_exit("pthread_create failed");
    }
    return thread;
}

/* Wait for a child thread.
*/
void join_thread(pthread_t thread)
{
    int ret = pthread_join(thread, NULL);
    if (ret == -1) {
        perror_exit("pthread_join failed");
    }
}

/* Code run by the child threads.
*/
void child_code(Shared *shared)
{
    mutex_lock(shared->mutex);
    printf("counter = %d\n", shared->counter);
    shared->counter++;
    mutex_unlock(shared->mutex);
}

/* Entry point for the child threads.
*/
void *entry(void *arg)
{
    Shared *shared = (Shared *) arg;
    child_code(shared);
    pthread_exit(NULL);
>>>>>>> 11affb695925a51c1001d42b33853f1da8c9880d
}

int main()
{
<<<<<<< HEAD
  int i;
  pthread_t child[NUM_CHILDREN];

  Shared *shared = make_shared(1000000);

  for (i=0; i<NUM_CHILDREN; i++) {
    child[i] = make_thread(entry, shared);
  }

  for (i=0; i<NUM_CHILDREN; i++) {
    join_thread(child[i]);
  }

  check_array(shared);
  return 0;
=======
    int i;
    pthread_t child[NUM_CHILDREN];

    Shared *shared = make_shared();

    for (i=0; i<NUM_CHILDREN; i++) {
        child[i] = make_thread(entry, shared);
    }

    for (i=0; i<NUM_CHILDREN; i++) {
        join_thread(child[i]);
    }

    printf("Final value of counter is %d\n", shared->counter);
    return 0;
>>>>>>> 11affb695925a51c1001d42b33853f1da8c9880d
}
