## Homework 4

### C Exercises

Modify the link below so it points to the `ex03` directory in your
student repository.

[Here is a link to the ex03 directory in my repository](https://github.com/KaitlynKeil/ExercisesInC/tree/master/exercises/ex02.5)

### Think OS Chapter 4 reading questions

**Files and file systems**

1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.

The file system makes it feel like you have a bunch of different parcels of isolated data, where each one is accessible only by its name. In actuality, they are just sequences of bytes on some sort of drive, same as everything else.

2) What information do you imagine is stored in an `OpenFileTableEntry`?

The file path (or index into it), the file position, whether it is read-only or write-only or any other state.

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

They might transfer large blocks of data for each access (block transfers), start loading the next block before it is requested (prefetching), only write to the disk once all modifications are done (buffering), or keep the most recent block in memory (caching).

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the file you wrote is not there.  What happened?

This is probably a case of buffering. The file was only going to write to the disk when the OpenFileTableEntry was closed, presumably later in the program, just in case you wanted to change the data you were writing before you were done. Since this point was never reached, the data in memory was never written to disk.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

The FAT sounds more direct than the inode. Rather than having 'multiple' structures (triple ib pointing to double ib pointing to ib pointing to the blocks), where each inode has this indirection block, we have just the one pointer per cluster that goes linearly to the next cluster. This is good for when you want to process a file in order, but more difficult if you want to be able to access things out of sequence. I believe this means that the inode has greater overhead than the FAT.

6) What is overhead?  What is fragmentation?

Overhead is the space used by the data structure containing the desired data.

Fragmentation is the unused space inside a file, either entire blocks or parts of blocks.

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

It helps when thinking about the way that processes can communicate, because it lets us intuitively chain together an arbitrary number of processes or communicate over networks easily. It could be an issue, however, if you assume that the bit streams contain all the information that a file system structure would, and design from there.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).