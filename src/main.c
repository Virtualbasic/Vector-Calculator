
#include "include/func.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>


int main(){

    char decision; 
    do{

        system("clear");
        printf("ener 2 or 3 vectors\n\n");
        int howm;
        scanf("%d",&howm);
        double** Vectors = malloc(howm * sizeof(double)); 
        while (1){
            if (howm == 2  || howm == 3){
                break;
            }
            printf("ener 2 or 3 vectors\n\n");
            scanf("%d",&howm);
            printf("%d", howm);
            howm = 0;
        }

        for(int  i =0 ; i < howm; i++){
            Vectors[i] = malloc(3 *sizeof(double));
        }
        int I = 0;
        while(howm>0){
            for (int j = 0 ; j <3 ; j++){
                printf("enter coordinate: ");
                scanf("%lf", &Vectors[I][j]);
                printf("\n");
            }
            printf("\n------------\n");
            howm-=1;
            I+=1;
        }


        
        int chose = 0;

        menu();

        printf("enter number from 1 to 8:");
        scanf("%d", &chose);
        double* W;
        double Scalar;
        
        switch (chose) {
            case 1:
                W = adding_vectors(Vectors[0],  Vectors[1], 3);
                prezentation(W, 3);
                break;
            case 2:
                Scalar = 0;
                printf("enter scalar:");
                scanf("%lf",&Scalar);
                printf("\n");
                scalar_multiplication(Vectors[0],  Scalar, 3);
                break;
            case 3:
                vector_product(Vectors[0], Vectors[1], 3, 5);
                break;
            case 4:
                printf("%.2lf", scalar_product(Vectors[0] , Vectors[1] , 3));
                printf("\n");
                break;
            case 5:
                if (I!=3){
                    printf("cannot perform 3 vectors are needed");
                    break;
                }{
                    mixed_product(Vectors[0], Vectors[1], Vectors[2],3);
                }
                
                break;
            case 6:
                int d = 0;
                printf("the length of which vector you want to check: ");
                scanf("%d",&d);
                printf("%lf",lengthOFV(Vectors[d-1]));
                printf("\n");
                break;
            case 7:
                int A,B;
                printf("which vector you want to check: \n");
                printf("first: ");
                scanf("%d",&A);
                printf("\n");
                printf("second: ");
                scanf("%d",&B);
                printf("\n");
                printf("%lf", sinV(LofV1xV2(vector_product(Vectors[A-1], Vectors[B-1],3,5)),lengthOFV(Vectors[A-1]), lengthOFV(Vectors[B-1])));
                printf("\n");
                break;
            case 8:
                int a,b;
                printf("which vector you want to check: \n");
                printf("first: ");
                scanf("%d",&a);
                printf("\n");
                printf("second: ");
                scanf("%d",&b);
                printf("\n");
                printf("%lf", cosV(scalar_product(Vectors[a-1] , Vectors[b-1] , 3), lengthOFV(Vectors[a-1]), lengthOFV(Vectors[b-1])));
                printf("\n");
                break;

        }
        
        printf("do you want to enter new vectors and contiune if yes enter Y else enter anything?:");
        scanf("%s", &decision);
    }while(strcasecmp(&decision, "Y") == 0 );
    
}
