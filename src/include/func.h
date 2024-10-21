#ifndef FUNC_H  
#define FUNC_H 

double* adding_vectors(double* v1 , double* v2, int size );
void prezentation(double* F, int size);
void scalar_multiplication(double v[] , double scalar,int size);
double* vector_product(double* v1 , double* v2, int size, int n  );
void helper(double** product , double v[] , int size, int index );
double scalar_product(double* v1 , double* v2 , int size);
double mixed_product(double* v1 , double* v2 ,double* v3, int size);
double lengthOFV(double* v);
double mySqrt(double n);
double sinV(double DV1xV2 , double DV1, double DV2);
double cosV(double V1oV2, double DV1, double DV2);
double LofV1xV2(double* V1xV2);
void menu();

#endif  
