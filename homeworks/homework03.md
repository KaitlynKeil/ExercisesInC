## Homework 3

### C Exercises

Modify the link below so it points to the `ex02.5` directory in your
student repository.

[Here is a link to the ex02.5 directory in my repository](https://github.com/KaitlynKeil/ExercisesInC/tree/master/exercises/ex02.5)

### Think OS Chapter 3 reading questions

### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

6 bits (up to 64 pieces of information!)

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?

Apparently 4,294,967,296.

3) What is the difference between "memory" and "storage" as defined in *Think OS*?

"Memory" is usually some sort of random access memory. It only lasts a session, or until the computure shuts down due to volatility. "Storage" is the information on a hard disk drive or a solid state drive. It is non-volatile, so can be used for long-term storage.

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

GiB, or 'gibibyte', is 2^30 bytes and is a binary unit. GB refers to 'gigabyte', which is 10^9 bytes. A GB is 93% of the size of a GiB.

5) How does the virtual memory system help isolate processes from each other?

Each process has its own virtual addresses. When these are translated to physical addresses by the hardware in order to be put in main memory, the virtual addresses map to different locations in physical memory. This keeps them from accessing data belonging to other processes.

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

This maximizes the amount of data both can hold before they run into each other.

7) What Python data structure would you use to represent a sparse array?

Probably a dictionary.

8) What is a context switch?

This is a mechanism that can interrupt a running process, save its state, and then run another process.