## Homework 2

### C Exercises

[Here is a link to the ex02 directory in my repository](https://github.com/KaitlynKeil/ExercisesInC/tree/master/exercises/ex02)

### Think OS Chapter 2 reading questions

For each of the reading questions below, write answers in the form of
a clear, concise, complete sentence or two.

1. Give a real-world example of virtualization (ideally not one of 
the ones in the book).  What is abstractly true about the system that
is not literally true about the implementation?

The modern bank system could be considered virtualization. There is no actual vault that has all of my money in it, and when I pay for something with a credit card, no one goes into my vault and moves the money physically to a different place. However, because I can pay for things and add more money to my account, there is the illusion of having some sort of hoard.

2. What is the difference between a program and a process?

A process represents a running program. The program itself is a sequence of instructions. The process contains these instructions, the associated data, the state of input or output operations, and the hardware state of the program.

3. What is the primary purpose of the process abstraction? 

Process abstraction allows users to use complicated systems without having to know all the details of the process. Particularly when it is isolation, it allows the programmer to not have to think about every possible interaction. 

4. What illusion does the process abstraction create?

That each process is running continuously on a dedicated processor, all memory is stored in entirely separate areas, and everything is essentially running on its own device.

5. What is the kernel?

The kernel is the part of the OS that creates threads and takes care of other core capabilities. It also can create other processes to do (gasp) processing for it.

6. What is a daemon?

This is a background process that provides OS services.