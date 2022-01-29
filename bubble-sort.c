#include <stdio.h>
/**
 * Sorts an array of integers in-place with a non-decreasing order. Has a worst case O(n^2) runtime complexity.
 * 
 * @param[in, out] A the array of integers to be sorted.
 * @param[in] size the size of the array of integers A.
 * 
 * @returns nothing. The array was sorted in-place. 
 */
void bubble_sort(int * A, int size){
    for (int i = 0; i < size - 1; i++){
        for (int j = size - 1; j >= i+1; j--){
            if (A[j] < A[j-1]){
                int temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
            }
        }
    }
}

#define TEST // undefine this if u don't want to test it in main directly.
#ifdef TEST

/// Sorts a small array of 10 integers and prints the values of the sorted array.
int main (){

    int A[10] = {5,2,-10,10, -2, 16, 12,4,42,1};

    int size = sizeof(A) / sizeof(int);

    bubble_sort(A, size);

    for (int i = 0; i < size; i++){

        printf("%d\n", A[i]);
    } 

}

#endif