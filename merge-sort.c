/** Classic divide and conquer algorithm for sorting arrays of numbers.
 */
#include <stdio.h>
#include <limits.h>
#include <math.h>

/**
 * Merges two adjacent sorted (non-decreasing) subarrays of the given array into a single sorted subarray.
 * Has a O(n) runtime complexity. 
 * 
 * @param[in, out] A the array of integers where the two sorted subarrays are combined.
 * @param[in] f, m, l the boundary indices of the sorted subarrays A[f,..,m] and A[m+1,..,l] which are combined into
 *		a single sorted array that replaces A[f,..,l].
 *  
 * @returns nothing. The subarrays were merged in-place.
 */
void merge(int *A, int f, int m, int l){
	// Combines the elements of the sorted subarrays A[f,..,m] and A[m+1, f] into a single sorted subarray that replaces
	// A[f,..,l]

	// length of the first subarray A[f,..,m]
	int n_1 = m - f +  1;

	// length of the second subarray A[m+1, l]
	int n_2 =   l - m; 

	// copy the first subarray into a new array L.
	int L[n_1 + 1];
	for (int i = 0; i < n_1; i++){
		L[i] = A[i + f];

	}
	L[n_1] = INT_MAX; // placeholder to stop incrementing i.

	// copy the second subarray into new array R.
	int R[n_2 + 1];
	for (int i = 0; i < n_2; i++){
		R[i] = A[i + m + 1];
	}	
	R[n_2] = INT_MAX; // placeholder to stop incrementing j.

	int i = 0;
	int j = 0;

	// merging the two sub arrays into a single sorted array into A[f,..,l]
	for (int a = f; a <= l; a++){

		if (L[i] <= R[j]){
			A[a] = L[i];
			i = i + 1;
		}
		else{
			A[a] = R[j];
			j = j + 1;
		}
	}
}

/**
 * Sorts the numbers in a subarray of the given array of integers in-place with a non-decreasing order. 
 * Has a O(nlgn) runtime complexity the best possible worse case runtime for sorting algorithms. 
 * 
 * @param[in, out] A the array of integers from which a subarray will be sorted.
 * @param[in] f, l the boundary indices of the subarray to be sorted. Assumes that f <= l.
 *		f is the index of the start of the subarray, l is the index of the end of the subarray.
 *
 * @returns nothing. The subarray was sorted in-place. 
 */
void merge_sort(int * A,  int f, int l){
	// splits the array into two halves, recursively sorts them and then
	// merges the two halves into one final array. 
	if (f < l){
		int m = floor(((l + f) / 2.0));
		merge_sort(A, f, m);
		merge_sort(A, m+1, l);
		merge(A, f , m, l);
	}
	// else f == l then its just subarray of length 1 which is already sorted.
	// this is our base case for the recursion.
}



#define TEST // undefine this if u don't want to test it in main directly.


#ifdef TEST


int main(){
	int A[10] = {1,3,5,7,9,2,4,6,8,10};
	int size = 10;


	// testing merge
	merge(A, 0, 4, 9);

	for (int i = 0; i < size; i++){

		printf("%d\n", A[i]);
	} 

	int B[10] = {69, 96, 10, 32, 43, 20, 52, 36, 40, 20};

	printf("Sorted array [ ");
	for (int i = 0; i < size; i ++){
		printf("%d ", B[i]);
	}
	printf("]");

	merge_sort(B, 0, 9);

	printf(" into array [ ");
	for (int i = 0; i < size; i++){
		printf("%d ", B[i]);
	} 
	printf("].\n");

}

#endif