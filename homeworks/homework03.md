## Homework 3

### C Exercises

Modify the link below so it points to the `ex03` directory in your
student repository.

<<<<<<< HEAD
[Here is a link to the ex02.5 directory in my repository](https://github.com/KaitlynKeil/ExercisesInC/tree/master/exercises/ex02.5)
=======
[Here is a link to the ex03 directory in my repository](https://github.com/YOUR_GITHUB_USERNAME_HERE/ExercisesInC/tree/master/exercises/ex03)
>>>>>>> af6015fd869d00aeb2fc4e2871b4df7a3ff9d2e7

### Think OS Chapter 4 reading questions

**Files and file systems**

1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.

<<<<<<< HEAD
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
=======
2) What information do you imagine is stored in an `OpenFileTableEntry`?

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the 
file you wrote is not there.  What happened?

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

6) What is overhead?  What is fragmentation?

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).


>>>>>>> af6015fd869d00aeb2fc4e2871b4df7a3ff9d2e7

This is a mechanism that can interrupt a running process, save its state, and then run another process.
