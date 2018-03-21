//
// Created by kisung on 17/03/18.
//

#ifndef TAREACORTADATOSII_QUICKSORT_H
#define TAREACORTADATOSII_QUICKSORT_H


#include "BigArray.h"

class quickSort {
private:
    /**
     * Funcion que divide el array y hace los swaps.
     * @param array
     * arreglo a ordenar
     * @param start
     * indice inicial
     * @param end
     * indice final
     * @return
     * retorna el pivote
     */
    int divide(int *array,int start, int end);
    /**
     * La misma funcion pero con BigArray.
     * @param array
     * arreglo a ordenar
     * @param start
     * indice inicial
     * @param end
     * indice final
     * @return
     * retorna el pivote
     */
    int divide(BigArray *array,int start, int end);

public:
    /**
     * Metodo donde se hace todo el ordrnamiento.
     * @param array
     * el array a ordrnar
     * @param start
     * indice inicial
     * @param end
     * indice final
     */
    void quicksort(int *array, int start, int end);
    /**
     * El mismo metodo de ordenamiento pero para BigArray.
     * @param array
     * el array a ordrnar
     * @param start
     * indice inicial
     * @param end
     * indice final
     */
    void quicksort(BigArray *array, int start, int end);

};


#endif //TAREACORTADATOSII_QUICKSORT_H
