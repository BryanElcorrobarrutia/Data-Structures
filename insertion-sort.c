#include <stdio.h>



void insertion_sort(int * A, int size){
	// returns a permutation of the given array with elements in a non-decreasing order.
	// assumes an array with size >= 2.

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


int main (){
	int A[4] = {5,2,1,10};

	int size = sizeof(A) / sizeof(int);

	insertion_sort(A, size);

	for (int i = 0; i < size; i++){

		printf("%d\n", A[i]);
	} 

}

