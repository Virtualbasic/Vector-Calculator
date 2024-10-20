
#include <stdio.h>
#include <stdlib.h>
#include "include/func.h"

double* adding_vectors(double* v1 , double* v2 , int size){
    
    
    double* VectorRes = malloc(size*sizeof(double));
    if (VectorRes == NULL){return NULL;}

    for (int i = 0 ; i < size; i++){
        VectorRes[i] = v1[i] + v2[i];
    }
    return VectorRes;
}

void scalar_multiplication(double v[], double scalar, int size){
    for(int i=0; i < size;i++){
        v[i] = v[i] * scalar;
    }
}

void helper(double** Product, double v[] , int size, int index){
    for (int i = 0; i < size; i ++ ){
        Product[index][i] = v[i];
    }
}

double* vector_product(double* v1 , double* v2, int size, int n  ){
    double* V1xV2 = malloc(3 * sizeof(double)); 
    double** product = malloc(n*sizeof(double*));
    if (V1xV2==NULL){return NULL;}
    //double determinant = 0;
    if(product==NULL){return NULL;}
    for (int I = 0; I< n ; I++){
        product[I] = malloc(size*sizeof(double));
    }
    
    V1xV2[0] = (v1[1] * v2[2]) - (v1[2]*v2[1]);
    V1xV2[1] = (v2[0] * v1[2]) - (v1[0]*v2[2]);
    V1xV2[2] = (v1[0] * v2[1]) - (v1[1]*v2[0]);
    int S  = 3;
    
    helper(product, v1, size, 0);
    helper(product, v2, size, 1);
    helper(product, v1, size, 3);


    printf("     i     j     k     \n");
    for (int z = 0; z <2 ; z++ ){
        
        for (int Z= 0; Z <size; Z++){
            printf("  %.2lf " ,product[z][Z]);
           
        }
    
        printf("\n");
    }
    printf("     i     j     k     \n");
    printf("   %.2lf  %.2lf  %.2lf   \n\n", v1[0], v1[1], v1[2]);
    
  
         
    
    printf("the determinant of the matrix is\n\n");

    printf("[ ");
    for(int h=0; h <  S; h++){
        printf(" %.2lf " , V1xV2[h]);
    }
    printf(" ]\n\n");

    return V1xV2;
}

double scalar_product(double* v1 , double* v2 , int size){
    double V1oV2 = 0; 

    for(int i = 0; i < size ; i++){
        V1oV2 += v1[i]*v2[i];
    }

    return V1oV2;
}

double mixed_product(double* v1 , double* v2 ,double* v3, int size){
    double V1oV2xV3 = 0;
    double** handler  = malloc(5 * sizeof(double));
    double d=0;
    //double z=0;
    //double Dw = 0;
    for(int i = 0 ; i < 5; i++){
        handler[i] = malloc(3*sizeof(double));
    }

    helper(handler, v1,  3,  0);
    helper(handler, v2,  3,  1);
    helper(handler, v3,  3,  2);
    helper(handler, v1,  3,  3);
    helper(handler, v2,  3,  4);
    
    printf(" %.2lf  %.2lf  %.2lf\n" ,handler[0][0],handler[0][1],handler[0][2]);
    for (int z = 1; z <=3 ; z++ ){
        
        for (int Z= 0; Z <size; Z++){
            printf(" %.2lf " ,handler[z][Z]);
           
        }
    
        printf("\n");
    }
    printf(" %.2lf  %.2lf  %.2lf\n" ,handler[4][0],handler[4][1],handler[4][2]);



    
    for (int j= 0; j < 3; j++){
        
        d += handler[j][0] * handler[j+1][1] * handler[j+2][2]; 
    }
    for (int J = 0; J <3; J++){

        d -= handler[J][2] * handler[J+1][1] * handler[J+2][0];
        
    }
    printf("\n\n");
    printf("mixed product of v1 v2 and v3 is: ");
    printf("%.2lf\n", d);

    
    return V1oV2xV3;
}

double lengthOFV(double* v){
    double C = 0;
    for (int i =0 ; i < 3 ; i++){
        C+= v[i]*v[i];
    }
    return mySqrt(C);
}


double cosV(double V1oV2, double DV1, double DV2){
    return  V1oV2 / (DV1*DV2);
}

double sinV(double DV1xV2 , double DV1, double DV2){
    return DV1xV2/(DV1*DV2);
}

double LofV1xV2(double* V1xV2){
    double Hand;
    for (int i=0; i < 3;i++){
        Hand += V1xV2[i] * V1xV2[i];
    }
    return mySqrt(Hand);

}