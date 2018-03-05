## Homework 5

### C Exercises

Modify the link below so it points to the `ex05` directory in your
student repository.

[Here is a link to the ex05 directory in my repository](https://github.com/KaitlynKeil/ExercisesInC/tree/master/exercises/ex05)

### Think OS Chapter 5 reading questions

**Bits and bytes**

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert 
it to a 16-bit number and accidentally apply sign extension?

You'll get something negative and incorrect (if it got converted to signed) or just massive, because the 1 at the front of the 8-bit version will get extended out into infinity, which 

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator. 
Try it out and confirm that the result is interpreted as -12.

I think that this works?

```
int twos_compliment(int orig) {
	return (orig - 1)^-1;
}
```

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

It allows for the full use of 8 bits, rather than the furthest left bit being reserved for sign extension. This basically doubles what it can represent.

4) Following the example in Section 5.3, write the 32-bit binary representation of -13 in single precision 
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

11000000000000000000000000000011, where
sign: 1
exp:  10000000
val:  00000000000000000000011

This, as an integer, is either -1,073,741,821 (if signed) or 3,221,225,475 (unsigned).

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.



