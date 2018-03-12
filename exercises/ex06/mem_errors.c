/* Example code for Exercises in C.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void free_anything(int *p) {
    free(p);
}

int read_element(int *array, int index) {
    int x = array[index];
    return x;
}

int main()
{
    int never_allocated; // allocated never_allocated
    int *free_twice = malloc(sizeof (int));
    int *use_after_free = malloc(sizeof (int));
    int *never_free = malloc(sizeof (int));
    int array1[100];
    int *array2 = malloc(100 * sizeof (int));

    // Put elements into reasonable bounds
    read_element(array1, 50);
    read_element(array1, 99);

    read_element(array2, 50);
    read_element(array2, 99);

    *use_after_free = 17; // switched order
    free(use_after_free);

    // never_free is no longer lost
    *never_free = 17;
    free(never_free); // freed it

    // Removed never_allocated freeing (stack variable)
    // free_anything(never_allocated);

    free_anything(array2); // freed array2 (but not array1)

    free(free_twice); // deleted one free(free_twice)

    return 0;
}
