/* This program creates an array with a maximum set length and populates it
with user input. When the EOF character is entered, it totals the integers.
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int sum(int* array, int size);
int getInput(int* array);
int LENGTH = 64;

int main() {
	/* Creates the array to populate and calls
	the other functions.
	*/
	int numArray[LENGTH]; // Allocate memory for the array
	int size = getInput(numArray); // Populate array with user input
	if(size == -1) {return -1;} // If the program errored out, quit
	int total = sum(numArray, size); // Get the sum of the array
	printf("The total is %d\n", total); // Print results
	return 0; // Return 0 if successful
}

int getInput(int* array) {
	/* Populates the array with user input and handles
	different error cases.
	inputs: 
		array (int*)-an integer array of size LENGTH
	outputs:
		size (int)-the number of elements used in the array.
	*/
	long num; // This is long to handle the cases where the user inputs too high a number
	int size = 0; // Initialize the size variable
	printf("Enter up to %d integers, one per line.\n Hit Ctrl-D when done.\n", LENGTH);
	while(size < LENGTH) { // Continue taking input until the maximum length is reached
		int rc = scanf("%li", &num); // Scan user input as integers
		if(rc == EOF) {break;} // If Ctrl-D is entered, break
		else if(rc == 0){ // If there is a non-integer input, throw an error
			puts("value cannot be converted to int");
			return -1; // This will cause the program to quit
		}
		if(num > INT_MAX || num < INT_MIN) { // Checks to make sure the input is valid
			puts("value is too large, enter new value");
			continue; // If too large, does not add to the array
		}
		array[size] = num; // If none of the above issues trigger, add to the array
		size++; // increment size
	}
	if(size == LENGTH) {puts("maximum number of inputs reached");} // Let the user know when they have reached the limit
	return size;
}

int sum(int* array, int size) {
	/* Sums the indicated array.
	inputs:
		array (int*)-pointer to the integer array to be summed
		size (int)-number of used elements in the array
	output:
		total (int)-the sum of elements in the array
	*/
	int total = 0;
	int i;
	for(i = 0; i<size; i++) {total += array[i];}
	return total;
}