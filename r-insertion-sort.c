/** Simple recursive implementation of insertion sort. Still Theta(n^2) worst case run-time complexity.
 */

#include <stdio.h>

/**
 * Sorts an subarray of a given array of integers in-place with a non-decreasing order. Has a worst case O(n^2) runtime complexity.
 * 
 * @param[in, out] A the array of integers to be sorted.
 * @param[in] l the index such that the subarray A[0,..,l] will be sorted.
 * 
 * @returns nothing. The array was sorted in-place. 
 */
void insertion_sort(int * A, int l){


	if (l == 0){ // Base case when size of the array we are sorting just contains one element.
		return;  
	}


	// we split the array in subarray A[0,..,l-1] and A[l]. (Divide)
	int d = l - 1;


	// sort the subarray A[0, l - 1] (Conquer)
	insertion_sort(A, d);


	// We insert A[l] in the now sorted subarray A[0,..,l-1]. (Combine)

	int val = A[l];
	int i = l - 1;

	// if you want to sort in a non-increasing order change the inequality in A[i] > val to A[i] < val. 
	while ((i >= 0) && (A[i] >  val)){
		A[i+1] = A[i];
		i = i - 1;
	}

	A[i+1] = val;



}



#define TEST // undefine this if u don't want to test it in main directly.


#ifdef TEST


/// Sorts a small array of 4 integers and prints the values of the sorted array.
int main (){

	int A[10] = {5,2,-10,10, -2, 16, 12,4,42,1};

	int size = sizeof(A) / sizeof(int);

	insertion_sort(A, size - 1);

	for (int i = 0; i < size; i++){

		printf("%d\n", A[i]);
	} 

}

#endif