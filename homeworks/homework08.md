## Homework 8

### C Exercises

[Here is a link to the ex08 directory in my repository](https://github.com/KaitlynKeil/ExercisesInC/tree/master/exercises/ex08)

### Think OS Chapter 8 reading questions

**Multitasking**

1) What is the kernel's most basic task?

To handle interrupts (events that affect/stop the normal instruction cycle).

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

The program counter, status register, and contents of data registers get saved in memory.

3) What is the difference between an interrupt and a context switch?

An interrupt only saves the registers a process is going to need/use. A context switch needs to save everything and possibly clear stored data in order to start up the other process. Thus, context switches are pretty slow.

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

Something like a disk request or some other completion-based interrupt can move a process from blocked (often, waiting for a future event) to ready (waiting to be resumed).

5) Why might a scheduler want to give higher priority to an I/O bound process?

I/O-bound processes will run faster if the input/output goes faster, but not faster with more CPU time. Thus it will regularly switch between blocking and ready, and the user will probably be more attentive to it. For all these reasons, it probably deserves a little more attention.

6) When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices. 
Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores"
to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; 
this is really how I make French toast.)

We're going to do this using 3 groups of 4: Group A, Group B, Group C. Each has side 1 and 2. A1 indicates Group A cooking side 1.

Start with A and B on the griddle. Cook side 1 for 5 minutes. (A1, B1, 5 minutes)

Flip A. Remove B and put C onto the griddle to cook the first side for 5 minutes. (A2, C1, 5 minutes)

A is now done. Remove A, put B on, flip C. Tuck A into a warm (but not hot) oven to keep it from cooling off. (B2, C2, 5 minutes)

They should now all be done, with a total of 15 minutes. Group B might be a little strange because of its break, but 5 minutes shouldn't make too much difference when you add enough syrup.

Breaking it down any further (subdividing the cook time of one side) would slow down the cooking and be counterproductive, so we do need these 5 minute chunks.
