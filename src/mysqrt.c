#include "include/func.h"
#include "stdbool.h"
#include <math.h>
double mySqrt(double n){
    if (n<0){return -1;}
    double eps = 0.00001;
    double guess = n / 2.0;

    while(true){
        double next_g = (guess+n/guess)/2;

        if (fabs(next_g - guess)<eps){
            return next_g;
        }
        guess = next_g;
    }

}