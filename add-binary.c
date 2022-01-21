#include <stdio.h>


/**
 * Adds two binary strings of the same length and returns the result. 
 * 
 * @param[in] A an array of integers representing one of the binary strings.
 * @param[in] B an array of integers representing one the other binary string.
 * @param[in] size the length of both input arrays. 
 * @param[out] result the array of integers of size size + 1 that is the binary sum of A and B.
 */
void add_binary(int * A, int * B, int size, int * result){

    int carry = 0;
    for (int i = size - 1; i >= 0 ; i--){
        if (carry == 0){
            if (A[i] == 1 && B[i] == 1){
                result[i+1] = 0;
                carry = 1;
            }

            else if (A[i] == 1 || B[i] == 1 ){
                result[i+1] = 1;
            }

            else {
                result[i+1] = 0;
            }
        }

        else {
            if (A[i] == 1 && B[i] == 1){
                result[i+1] = 1;
                carry = 1;
            }

            else if (A[i] == 1 || B[i] == 1 ){
                result[i+1] = 0;
                carry = 1;
            }

            else {
                result[i+1] = 1;
                carry = 0;
            }
        }

    }

    if (carry == 1){
        result[0] = 1;
    }
}   




#define TEST // undefine this if u don't want to test it in main directly.


#ifdef TEST


int main(){

    int A[5] = {1,0,1,0,1};
    int B[5] = {1,1,1,1,0};

    int result[6];
    int size = 5;


    add_binary(A, B, size, result);

    for (int i = 0 ; i < size + 1 ; i++){

        printf("%d", result[i]);
    } 
    printf("\n");

}

#endif