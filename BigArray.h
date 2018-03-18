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
    static const int maxSize = 100;
    int * leftPage[maxSize];
    int * rightPage[maxSize];
    int * midPage[maxSize];
    int getSize();
    void readFile();
    void writeFile();
    string dirLocation = ("./BigArray.bin");

public:
    BigArray();

};


#endif //TAREACORTADATOSII_BINREADER_H
