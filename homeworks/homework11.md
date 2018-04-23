## Homework 11

### C Exercises

Modify the link below so it points to the `ex11` directory in your
student repository.

[Here is a link to the ex11 directory in my repository](https://github.com/KaitlynKeil/ExercisesInC/tree/master/exercises/ex11)

### Think OS Chapter 11 reading questions

1) Why is is a bad idea to pass a `sem_t` as a parameter?

It behaves like a structure, so rather than passing the actual object, it passes a copy. Copy is undefined behavior, so you can't guarantee the outcome.

2) When you use a Semaphore as a mutex, what should its initial value be?

1, because that indicates that the mutex is unlocked. Or, to quote: "that is, one thread can pass the semaphore without blocking" (Downey).

3) Can you think of another use for a Semaphore where you might use a different initial value?

If you wanted a queue, you might want the initial value to be the number of items in the queue to start with.

4) In my solution to the producers-consumers problem using Semaphores,
what does it mean if the value of `queue->spaces` is `3` at some point in time?

There are 3 empty spaces in the queue, so 3 threads can execute queue_push without blocking.

5) What does it mean if `queue->space` is `-3`?

We just ran out of space hard. Something probably broke.

6) Why doesn't `queue_pop` have to use `queue_empty` to check whether the queue is empty?

Because we have a maximum number of threads that can execute queue_pop at a time (given by 	ueue->items), we will never have a thread that got past the semaphore that can't pop an item.

7) Any problem that can be solved with Semaphores can also be solved with mutexes and condition variables.
How can you prove that that's true?

I could create a Semaphore implementation from a mutex and conditional variables, where the condition is that there is space in the semaphore with cond_wait.

8) What is Property 3?  Hint: see *The Little Book of Semaphores*, 
[Section 4.3](http://greenteapress.com/semaphores/LittleBookOfSemaphores.pdf). 

If there are threads waiting on a semaphore when a thread signals, one of the waiting threads has to be woken. This is an assumption that lets us avoid thread starvation, because in theory, every thread will eventually be woken. This assumption prevents the same thread from receiving its own signal.


