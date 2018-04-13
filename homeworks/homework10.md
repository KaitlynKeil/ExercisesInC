## Homework 10

### C Exercises

Modify the link below so it points to the `ex12` directory in your
student repository.  That's right, Homework 10 is to do Exercise 12.

[Here is a link to the ex12 directory in my repository](https://github.com/KaitlynKeil/ExercisesInC/tree/master/exercises/ex12)

### Think OS Chapter 10 reading questions

1) What does it mean to say that a data structure is thread safe?

Multiple threads can share/access the data structure concurrently and it will not break.

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`, if `n` is the size of the array?

There must be a space so that "next_in" never wraps around to catch up with "next_out", as having these be equivalent is how we check for an empty queue. Thus we have to stop one element before the arbitrary end of the queue, leaving it with n-1 elements.

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave the queue in an inconsistent state.

Two threads try to enter a new value into the queue concurrently. They both check the number of items in the queue and find it to be n-2. They both enter an item and suddenly we have n items in the queue instead, and everything is sad!

4) When a thread calls `cond_wait`, why does it have to unlock the mutex before blocking?

If we don't, the thread will sit on the locked mutex, keeping all the other threads for progressing while it waits for one of them to do something. Whoops.

5) When a thread returns from `cond_wait`, what do we know is definitely true?  What do we think is probably true?

We know the condition is true, and we know the mutex is locked (so we've got to unlock it again when we're done). Or at least, we know the condition was true a moment ago. Someone else might have snagged it first. So we need to check it again.

6) What happens if you signal a condition variable when there are no waiting threads?

The signal has no effect.

7) Do you have to lock the mutex to signal a condition variable?

Only if you are using a cond_wait, which is taken care of by the thread calling cond_wait.

8) Does the condition have to be true when you signal a condition variable?

No, the condition is connected to the cond structure in a kind of nebulous way and more by how you use. So yes, you probably should think of it this way, but it isn't strictly mandatory.
