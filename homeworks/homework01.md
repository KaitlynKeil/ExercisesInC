## Homework 1

### C Exercises

[Here is a link to the ex01 directory in my repository](https://github.com/KaitlynKeil/ExercisesInC/tree/master/exercises/ex01)

=======

### Think OS Chapter 1 reading questions

For each of the reading questions below, write answers in the form of
a clear, concise, complete sentence or two.

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

Interpreted languages often support dynamic types, whereas few compiled languages do.

2) Name two advantages of static typing over dynamic typing.

Static typing lets you know the type of the variables needed, which cuts down on runtime errors. It also lets you find errors in code that isn't actively running.

Since these checks occur at compile time, not runtime, it helps the program run faster later.

3) Give an example of a static semantic error.

Trying to pass a char to a function that wants an int.

4) What are two reasons you might want to turn off code optimization?

Optimization tends to make debugging less clear, since all the steps are written out. Optimization can also cause subtle bugs to get overlooked.

5) When you run `gcc` with `-S`, why might the results look different on different computers?

Different machines run on different architectures, which will use different assembly languages.

6) If you spell a variable name wrong, or if you spell a function name wrong, the error messages you get might look very different.  Why?

An incorrect variable name will complain about the variable not having been defined. Calling a misspelled function will search through all the included files and return that it couldn't find it.

7) What is a segmentation fault?

Attempting to read or write in an incorrect memory location.
