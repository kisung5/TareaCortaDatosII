//
// Created by kisung on 17/03/18.
//

#ifndef TAREACORTADATOSII_QUICKSORT_H
#define TAREACORTADATOSII_QUICKSORT_H


#include "BigArray.h"

class quickSort {
private:
    int divide(int *array,int start, int end);
    int divide(BigArray *array,int start, int end);

public:
    void quicksort(int *array, int start, int end);
    void quicksort(BigArray *array, int start, int end);

};


#endif //TAREACORTADATOSII_QUICKSORT_H
