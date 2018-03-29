## Homework 7

### C Exercises

[Here is a link to the ex07 directory in my repository](https://github.com/KaitlynKeil/ExercisesInC/tree/master/exercises/ex07)

### Think OS Chapter 7 reading questions

### Caching

1) What happens if a program writes a new value into the program counter?

The program would no longer run as intended, because it would jump to that 'line', which could be absolutely anything.

2) What is the fundamental problem caches are meant to solve?

Fetching data from memory is expensive in terms of time, so having the data in the cache makes it run more efficiently.

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

50%: 5.5 ns
90%: 1.9 ns

4) The book gives several examples of programming language features, like loops, that tend 
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

Processing one thing in multiple ways (computing mean, median, and std on one array before moving onto the next) as opposed to processing many things in one way and then repeating (finding the mean of several arrays, then the median, etc) would improve locality. Using arrays also probably improves locality over using, say, linked lists, where the data could stay anywhere.

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

Not necessarily. It depends on the behavior of the cache itself, so the program would need to also consider block size of the cache.

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.

I seemed to find from intel core CPUs that 2 MB worth of cache memory increased the price from $203 to $349, or basically $150. So... $75 per MB of cache? That seems excessive.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

There's a bigger risk of causing thrashing, as larger data are being moved around and the access time is so much more expensive.

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

Potentially only reading pieces of the page that are being used, though this could also make it worse. 

