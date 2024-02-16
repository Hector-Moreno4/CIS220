// Hector Moreno
// Chapter 3 PA
#include <stdio.h>

int main() {
	int array[] = {93, 52, 72, 42, 3, 63, 100, 19, 61, 44, 21, 98, 6, 41, 78, 5, 51, 60, 67, 11}; // Declare variables
	int arraysize = sizeof(array) / sizeof(array[0]); 
	int i;
	int j;
	int temp;
	
	for (i = 0; i < arraysize - 1; i++) { // Create the sorting loops
		for (j = 0; j < arraysize - i - 1; j++) {
			if (array [j] > array [j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	
	printf("The sorted array is: ");
	for (i = 0; i < arraysize; i++) { //Print the elements of sorted array
		printf("%d ", array[i]);
	}
}