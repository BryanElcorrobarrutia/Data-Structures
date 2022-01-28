/** This algorithm is worse than insertion sort since its order of growth remains O(n^2) 
 * in the worst and best case. At least insertion sort in the best case is O(n). 
 */



#include <stdio.h>
#include <limits.h>






/**
 * Sorts an array of integers in-place with a non-decreasing order. Just like insertion sort 
 * has a O(n^2) worst case runtime complexity. In fact its performance does not depend on 
 * the input like insertion sort. Thus its average and best case runtime complexity is also O(n^2).
 * 
 * @param[in, out] A the array of integers to be sorted.
 * @param[in] size the size of the array of integers A.  
 *
 * @returns nothing. The array was sorted in-place. 
 */
void selection_sort(int * A, int size){
	// Idea is to find the smallest value in the array and swap it with A[0],
	// then find the second smallest swap it with A[1],
	// find the third smallest value and swap it with A[2],.... and so on.

	int f = 0; 
	int l = size - 1;

	int smallest = INT_MAX;
	int smallest_i = 0;

	while (f < l){
		smallest = INT_MAX;

		// Finds the smallest value in the sub-array A[f,..,l].
		for (int i = f; i <= l; i++){
			if (A[i] <= smallest){
				smallest = A[i];
				smallest_i = i;
			}

		}	

		// swaps the smallest value in the array with the value in index f.
		int x = A[f];
		A[f] = A[smallest_i];
		A[smallest_i] = x; 

		// Makes the part of the array we need to search smaller.
		f =  f + 1;
	}

}


// TODO: a recursive implementation of selection sort.


#define TEST // undefine this if u don't want to test it in main directly.


#ifdef TEST


/// Sorts a small array of 4 integers and prints the values of the sorted array.
int main (){

	int A[4] = {5,2,1,10};

	int size = sizeof(A) / sizeof(int);

	selection_sort(A, size);

	for (int i = 0; i < size; i++){

		printf("%d\n", A[i]);
	} 

}

#endif


