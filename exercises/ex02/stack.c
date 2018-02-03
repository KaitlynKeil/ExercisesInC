/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i; // creates a local variable i
    int array[SIZE]; // creates a local variable that is the address of the first value in an array of size 5

    printf("%p\n", array); // This cements where array is by forcing it to have a value

    for (i=0; i<SIZE; i++) {
        array[i] = 42; // for each piece of allocated memory, stores 42
    }
    return array;
}

void bar() {
    int i; // sets up local variable i
    int array[SIZE]; // portions off this section of memory again

    //printf("%p\n", array); // this would prove that it is looking at the same piece of memory on the stack as the one above

    for (i=0; i<SIZE; i++) {
        array[i] = i; // assigns those spaces in memory increasing values from 0 to 4
    }
}

int main()
{
    int i; // creates the FIRST instance of a local variable i
    int *array = foo(); // creates a pointer to the first element of 'array' from foo
    bar(); // writes into that same, local memory space

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
