//
// Created by kisung on 15/03/18.
//

#ifndef TAREACORTADATOSII_BINREADER_H
#define TAREACORTADATOSII_BINREADER_H

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class BigArray {
private:
/**
 * Las constantes usadas para calcular ciertos algoritmos dentro del paginado del archivo.
 * maxSize define cuanto tamano tiene cada pagina.
 */
    int sizeOfArray;
    static const int maxSize = 100;
    int leftPage[maxSize];
    int rightPage[maxSize];
    int midPage[maxSize];
/**
 * Se define el numero de paginas y las paginas cargadas en pages y loaded.
 * El numero de paginas empieza desde 1 hasta la cantidad de paginas.
 * loaded guarda en el indice 0 la pagina leftPage cargada,
 * en el indice 1 la pagina midPage cargada y en el indice 2 la
 * pagina rightPage cargada.
 */
    int pages;
    int loaded[3];
/**
 * Los boolean revisan si ya se han cargado las paginas.
 */
    bool leftIn, rightIn, midIn;
    string dirLocation = ("./BigArray.bin");
/**
 * Reviza el tamano del archivo binario creado.
 * @return
 * El tamano del archivo binario.
 */
    int getSize();
/**
 * Lee el archivo binario y carga en una de las paginas con el byte.
 * @param array
 * Array pagina que se quiere cargar los enteros del archivo.
 * @param ini
 * Pos en indice por la que se requiere hacer la lectura.
 */
    void readFile(int array[], int ini);
/**
 * Realiza la lectura del archivo en cierto byte y sobre escribe una pagina.
 * @param array
 * Pagina que se requiere guardar.
 * @param pos
 * Pos en indice donde se va a realizar la sobre escritura.
 */
    void writeFile(int array[],int pos);
/**
 * Reviza si un archivo existe.
 * @param name
 * El nombre en del archivo en string.
 * @return
 * False si no existe, true si existe.
 */
    inline bool exists(string& name);
/**
 * Metodo inicializado con el constructor. Crea el archivo binario con los numeros del 1 a x cantidad
 * de manera aleatoria. El nombre del archivo por defecto es "BigArray.bin".
 * @param cant
 * cantidad de ints con la que se quiere crear el archivo.
 */
    void makeBigArray(int cant);

public:
/**
 * Constructor de la clase, llama a la funcion makeBigArray().
 */
    BigArray();
/**
 * Destructor de la clase, guarda las paginas cargadas.
 */
    ~BigArray();
/**
 * Se sobrecarga el operador [] para usarlo como un array. Aqui es donde se mantiene toda la logica de
 * paginas y su cargado y guardado. Ademas define los limites de los indices para guardar los valores
 * en las paginas.
 * @param x
 * Pos de indice que se desa conseguir.
 * @return
 * Retorna el valor del indice ingrasado.
 */
    int& operator [] (int x);
};


#endif //TAREACORTADATOSII_BINREADER_H
