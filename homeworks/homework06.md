## Homework 6

### C Exercises

Modify the link below so it points to the `ex06` directory in your
student repository.

[Here is a link to the ex06 directory in my repository](https://github.com/KaitlynKeil/ExercisesInC/tree/master/exercises/ex06)

### Think OS Chapter 6 reading questions

**Memory management**

1) Which memory management functions would you expect to take constant time?
Which ones take time proportional to the size of the allocated chunk?

malloc: not quite either. It depends on how many free chunks there are.
calloc: proportional, as it clears all of the chunks.
free: constant time, as it doesn't have to do anything but release the memory
realloc: constant if the new size is smaller or there is available area nearby. Otherwise, if it must copy data elsewhere, it is proportional.

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory: there might be something else already there which could either break everything or go undetected and throw nonsense values.

b) Writing to unallocated memory: You could cause problems further down the road and mangle other data structures, causing something like malloc to fail well down the line.

c) Reading from a freed chunk: this is essentially like reading from unallocated memory, and would do the same things.

d) Writing to a freed chunk: again, this is basically writing to unallocated memory.

e) Failing to free a chunk that is no longer needed: you could run out of available space through way too many memory leaks.


3) Run

```
    ps aux --sort rss
```

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical 
memory a process has.  Which processes are using the most memory?

IntelliJ is the most by quite a bit, followed by various internet-related things.

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem? 

Allocating a large number of small chunks fragmentizes the memory, which means that free space is broken into a bunch of small chunks. These take longer to allocate and generally slow down the program. To avoid this, you could always try to allocate the next available space without a gap, but this could slow down realloc if you need to make the space bigger, and also could cause more issues with accessing off-limits areas.

If you want to know more about how malloc works, read 
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)
