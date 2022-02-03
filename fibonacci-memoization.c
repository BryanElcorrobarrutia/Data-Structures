/** Implementation of the fibbonaci sequence that uses memoization. However, I implemented it
 * iteratively rather than recursively so it is more accurate to say it uses tabulation rather than
 * memoization which is for recursive algorithms that save results in order to reuse them.
 * 
 * Note: In some literature the technique of using memoization is often called
 * dynamic programming. In fact the first example of dynamic programming in many
 * courses/textbooks is this implementation of the fibonacci sequence that uses
 * memoization/tabulation. 
 * 
 * I find it easier to think that memoization is NOT dynamic programming, rather dynamic programming is a 
 * a design technique that uses uses memoization. Memoization as a technique to make algorithms 
 * with overlapping subproblems more efficient. 
 * 
 * Dynamic programming as described in CLRS applies to OPTIMIZATION problems hence "optimal" substructure
 * property. Not all problems for which you can use memoization is an optimization problem (like this fibonacci
 * sequence algorithm) hence why I make the distinction.
 * 
 * This algorithm runs MUCH faster as n gets larger than the naive divide and conquer implementation. 
 * Memoization reduced the runtime from an exponential O(2^n) any-case runtime to a O(n) runtime. 
 * 
 * 
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
	int D[n+1];
	D[0] = 1;
	D[1] = 1;

	for (int i = 2; i < (n+1); i++){
		D[i] = D[i-1] + D[i-2];
	}

	return D[n];
}



#define TEST // undefine this if u don't want to test it in main directly.


#ifdef TEST


/// Sorts a small array of 4 integers and prints the values of the sorted array.
int main (){
	int n = 45;

	// print the fibbonaci sequence upto index n.
	for (int i = 0; i< n; i++){
		printf("fib(%d) = %d\n", i, fib(i));
	}
}

#endif