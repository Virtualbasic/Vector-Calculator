#include <stdio.h>
#include "include/func.h"

void prezentation(double* F, int size ){
    printf("---------------------\n");
    printf("|");
    printf(" %.2lf" , F[0]);
    for (int i = 1 ; i < size ; i++){
        printf(", %.2lf " , F[i]);
    }
    
    printf("|\n");
    printf("---------------------\n");
}

void menu(){
    printf("what operations want you to do?\n");
    printf("| 1 - adding_vectors |\n");
    printf("| 2 - scalar_multiplication |\n");
    printf("| 3 - vector_product |\n");
    printf("| 4 - scalar_product |\n");
    printf("| 5 - mixed_product [only for 3 vectors] |\n");
    printf("| 6 - length_of_vector |\n");
    printf("| 7 - sinV1V2 |\n");
    printf("| 8 - cosV1V2 |\n");
}