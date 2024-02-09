// Hector Moreno
// Chapter 2 PA
#include <stdio.h>

int power (double base, int exponent) { //Creating recursive method

if (exponent == 0) { //Set value to 1 if exponent is 0
return 1; 
}
 else if (exponent == 1) { // Set value to base if exponent is 1
return base; 
 }
 else if (exponent > 1) { //Calculating value
return base * power(base, exponent - 1); 
}
}

int main() {
	double base;//Declare base and exponent
	int exponent;

	printf("Enter base: ");
	scanf("%lf", &base);
	
	printf("Enter exponent: ");
	scanf("%d", &exponent);
	
	printf("Value is %d\n", power(base,exponent));//Call recursive method
}
