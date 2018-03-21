//
// Created by kisung on 15/03/18.
//

#include "BigArray.h"
#include "quickSort.h"

int main() {
    BigArray *binmanager = new BigArray();
/**
 * BigArray cre en su constructor el archivo bianrio con elementos desordenados.
 * Si el elemento ya existe en el directorio del codigo, no lo creara.
 */

///----->Comentar estas lineas para crear el archivo sin ordenar.
    int n = 4000/sizeof((*binmanager)[0]);
    quickSort quickSort1;
    quickSort1.quicksort(binmanager,0,n-1);
///------<

///----->Descomente esta linea de codigo para imprimir el array completo.
//    int i = 0;
//    while(i<1000){
//        cout<<(*binmanager)[i]<<"-";
//        i++;
//    }
//    cout<<endl;
///------<

/**
 *  Este es el algoritmo de quicksort sin modificar, se adapto para recibir la clase BigArray.
 */
    return 0;
}