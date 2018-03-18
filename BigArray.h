//
// Created by kisung on 15/03/18.
//

#ifndef TAREACORTADATOSII_BINREADER_H
#define TAREACORTADATOSII_BINREADER_H

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <string>

using namespace std;

class BigArray {
private:
    static const int maxSize = 100;
    int * leftPage[maxSize];
    int * rightPage[maxSize];
    int * midPage[maxSize];
    char buffer[100];
    const string dirLocation = "/BigArray/BigArray.bin";
    int getSize();
    void readFile();
    void writeFile();
public:
    BigArray();

};


#endif //TAREACORTADATOSII_BINREADER_H
