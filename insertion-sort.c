#include <stdio.h>


/**
 * Sorts an array of integers in-place with O(n^2) runtime complexity.
 * 
 * @param[in, out] A the array of integers to be sorted.
 * @param[in] size the size of the array of integers A.  
 *
 * @returns nothing. The array was sorted in-place. 
 */

void insertion_sort(int * A, int size){
	for (int j = 1; j < size; j++){

		int val = A[j];
		int i = j - 1;

		while ((i >= 0) && (A[i] >  val)){
			A[i+1] = A[i];
			i = i - 1;
		}

		A[i+1] = val;
	}

}

#define TEST // undefine this if u don't want to test it in main directly.


#ifdef TEST


/// Sorts a small array of 4 integers and prints the values of the sorted array.
int main (){

	int A[4] = {5,2,1,10};

	int size = sizeof(A) / sizeof(int);

	insertion_sort(A, size);

	for (int i = 0; i < size; i++){

		printf("%d\n", A[i]);
	} 

}

#endif