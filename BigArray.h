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

using namespace std;

class BigArray {
private:
    int sizeOfArray;
    const int maxSize = 100;
    int * leftPage[maxSize];
    int * rightPage[maxSize];
    int * midPage[maxSize];
    string dirLocation = ("./BigArray.bin");
    int getSize();
    void readFile();
    void writeFile();
    inline bool exists(string& name);
    void makeBigArray(int cant);

public:
    BigArray();
    inline int& operator[] (int x);
};


#endif //TAREACORTADATOSII_BINREADER_H
