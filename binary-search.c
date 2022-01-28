/** Simple recursive implementation of binary search on an array of integers.
 */

#include <stdio.h>



/**
 * Searches for a value in a subarray of the given array of integers that is assumed to be sorted (non-decreasing). 
 * 
 * @param[in] A the sorted array.
 * @param[in] f, l first and last indices of the subarray to search.
 * @param[in] val the value to search for.
 * 
 * @returns The index of where val was found if the subarray contained it, else -1. 
 */
int binary_search(int *A, int f, int l, int val){

	// Base case subarray to search is just length 1. 
	if (f == l){
		if (A[f] == val){
			return f;
		}
		else {
			return -1;
		}
	}

	// Index that is approximately half of the array.
	int d = (f + l) / 2; // This automatically applies a floor since C will round 
		// the result towards 0 (which is a floor for positive results). (Divide)


	// Search hakf of the array that the value could be in. (Conquer)
	if (val <= A[d]){
		return binary_search(A, f, d, val);
	}
	else {
		return binary_search(A, d + 1, l, val);
	}	

	// Combine happens implicitly, the half that didnt get searched couldn't possibly contain val
	// so we only return the result of searching the half that can contain val.
}


#define TEST // undefine this if u don't want to test it in main directly.


#ifdef TEST


/// Sorts a small array of 4 integers and prints the values of the sorted array.
int main (){

	int A[6] = {1,5,6,10,23,51};

	int size = sizeof(A) / sizeof(int);

	int val = 23;





	int i = binary_search(A, 0, size - 1, val);

	if (i == -1){

		printf("Did not find %d in the array.\n", val);
	}
	else {
		printf("Found %d in array at index %d.\n", val, i);
	}
	
}

#endif

