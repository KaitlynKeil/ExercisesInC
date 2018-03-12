/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

void stacktester();

int var1;

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
<<<<<<< HEAD
    void *p2 = malloc(128);
    char *s = "Literal string";
=======
    char *s = "Hello, World";
>>>>>>> f1730219000dea2729d3a9625259830250492bea

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
<<<<<<< HEAD
    printf ("Address of p is %p\n", p);
    printf ("Address of p2 is %p\n", p2);
    printf ("Address of s is %p\n", s);
=======
    printf ("p points to %p\n", p);
    printf ("s points to %p\n", s);
>>>>>>> f1730219000dea2729d3a9625259830250492bea

    stacktester();

    void *r1 = malloc(4);
    void *r2 = malloc(4);
    printf ("Address of r1 is %p\n", r1);
    printf ("Address of r2 is %p\n", r2);

    return 0;
}

void stacktester() {
	int x = 4;
	int y = 5;

	printf ("Address of x is %p\n", &x);
    printf ("Address of y is %p\n", &y);
}
