#include <stdio.h>
#include <stddef.h>

/**
 * adding this for completeness even though it is trivial. 
 */


/**
 * Searches for a value in an array of integers.
 * 
 * @params A the array to search.
 * @params size the size of the array A
 * @params v the value to search for
 * 
 * @returns If v is in the array returns the index of its first occurrence else returns -1.
 */

int linear_search(int * A, int size, int v){
	for (int i = 0; i < size; i++){
		if (A[i] == v){
			return i;
		}
	}
	return -1;
}




#define TEST // undefine this if u don't want to test it in main directly.


#ifdef TEST


int main(){

	int A[5] = {5, 2, 7, 12, 9};

	int v = 12; 
	int x = linear_search(A, 5, v);

	if (x != -1){
		printf("Found %d in the array at index %d\n", v, x);
	}
	else{
		printf("Could not find %d in array.", v);
	}

	v = 100;
	x = linear_search(A, 5, v);

	if (x != -1){
		printf("Found %d in the array at index %d\n", v, x);
	}
	else{
		printf("Could not find %d in the array.\n", v);
	}

}

#endif