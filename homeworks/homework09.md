## Homework 9

### C Exercises

[Here is a link to the ex09 directory in my repository](https://github.com/KaitlynKeil/ExercisesInC/tree/master/exercises/ex09)

### Think OS Chapter 9 reading questions

1) Why does each thread have its own stack?

Each thread has its own stack so that it can call functions without interferring with other threads.

2) What does the gcc flag `-lpthread` do?

It lets you compile a program with the pthread library.

3) What does the argument of `pthread_exit` do?

The argument is the return value that, if its joinable, will be accessible by another thread in the same process that calls pthread_join.

4) Normally the same thread that created a thread also waits to join it.
What happens if another thread tries to join a thread it did not create?

Yeah it can do that, I think!

5) What goes wrong if several threads try to increment a shared integer at the same time?

They might access it in a different order or grab it just before one of the other threads has incremented it. Without syncronization, you can't be quite sure when they are reading/executing functions that involve the shared data.

6) What does it mean to "lock a mutex"?

It means that one thread gets to bar all the other threads from access the element until the first thread (the one that locked the mutex) has finished with it.