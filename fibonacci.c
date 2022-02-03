/** Naive implementation of the fibbonaci sequence. Takes more than a second on my 
 * computer for n >= 40. It has a O(2^n) any-case runtime complexity. Very slow.
 */



#include <stdio.h>

/**
 * Computes the nth fibbonaci number. 
 * 
 * @param n the index of the fibbonaci number we want.
 *
 * @returns the nth fibbonaci number.
 */
	
int fib(int n){

	// base cases
	if (n==0 || n == 1){
		return 1;
	}
		
	// using the recursive definition of the fibbonaci sequence.	
	return fib(n-1) + fib(n-2);
}






#define TEST // undefine this if u don't want to test it in main directly.


#ifdef TEST


/// Sorts a small array of 4 integers and prints the values of the sorted array.
int main (){
	int n = 30;

	// print the fibbonaci sequence upto index n.
	for (int i = 0; i< n; i++){
		printf("fib(%d) = %d\n", i, fib(i));
	}
}

#endif