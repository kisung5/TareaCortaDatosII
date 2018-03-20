//
// Created by kisung on 15/03/18.
//

#include "BigArray.h"

#include <random>


BigArray::BigArray() {
    makeBigArray(1000);
}

BigArray::~BigArray() {

}

void BigArray::readFile(int array[], int ini) {
    int test = 0;
    ifstream ofile(dirLocation.c_str(), ios::in | ios::binary);
    if (ini != 0) {
        ofile.seekg(ini*sizeof(int));
    }
    for (int x=0; x<maxSize;x++ ) {
        ofile.read(reinterpret_cast<char*>(&test), sizeof(int));
//        cout<< test << "-";
        array[x] = test;
    }
    cout<< endl;
    ofile.close();
}

void BigArray::writeFile(int array[],int pos) {
    fstream ofile;
    ofile.open(dirLocation.c_str(), ios::binary | ios::out | ios::in);
    ofile.seekp(pos*sizeof(int), ios::beg);
    for (int loop = 0; loop < maxSize; ++loop) {
        int num =array[loop];
        ofile.write(reinterpret_cast<char *>(&num), sizeof(int));
    }
    ofile.close();
//    cout<<"pagina guardada"<<endl;
}

int BigArray::getSize() {
    struct stat results;
    if (stat(dirLocation.c_str(), &results) == 0) {
        cout<< results.st_size<<endl;
        return 0;
    }
        // The size of the file in bytes is in
        // results.st_size
    else{
        return 0;
    }
    // An error occurred
}


bool BigArray::exists(string & name) {
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}

void BigArray::makeBigArray(int cant) {
    sizeOfArray = cant;
    pages = (int)lround(sizeOfArray/maxSize+0.5f);
    if (!exists(dirLocation)) {
        ofstream ofile(dirLocation.c_str(), ios::binary | ios::out);

        int data[cant];
        for (int i; i < cant; i++) {
            data[i] = i + 1;
        };
        int size = sizeof(data) / sizeof(data[0]);

        shuffle(data, data + size, std::mt19937(std::random_device()()));

        for (int loop = 0; loop < size; ++loop) {
            ofile.write(reinterpret_cast<char *>(&data[loop]), 4);
            //cout<< data[loop] << "-";
        }

        ofile.close();
    }
}

int &BigArray::operator[](int x) {
    if (x > sizeOfArray-1) {
        cout<<"El indice esta fuera del rango."<<endl;
        int *num = new int(0);
        return *num;
    } else {
        for (int i=0;i<pages;i++){
            if (x>=(i)*maxSize & x<maxSize*(i+1)){
                if (loaded[0] == i+1){
                   return leftPage[x-i*maxSize];
                } else if(loaded[1] == i+1) {
                    return midPage[x-i*maxSize];
                } else if(loaded[2] == i+1) {
                    return rightPage[x-i*maxSize];
                } else {
                    if (i<pages/3) {
                        if (leftIn){
                           writeFile(leftPage,(loaded[0]-1)*maxSize);
                        }
                        readFile(leftPage,i*maxSize);
                        loaded[0] = i+1;
//                        cout<<"cambio de pagina"<<endl;
                        leftIn = true;
                        return leftPage[x-i*maxSize];
                    } else if (i>pages*2/3) {
                        if (rightIn){
                            writeFile(rightPage,(loaded[2]-1)*maxSize);
                        }
                        readFile(rightPage,i*maxSize);
                        loaded[2] = i+1;
//                        cout<<"cambio de pagina"<<endl;
                        rightIn = true;
                        return rightPage[x-i*maxSize];
                    } else {
                        if (midIn){
                            writeFile(midPage,(loaded[1]-1)*maxSize);
                        }
                        readFile(midPage,i*maxSize);
                        loaded[1] = i+1;
//                        cout<<"cambio de pagina"<<endl;
                        midIn = true;
                        return midPage[x-i*maxSize];
                    }
                }
            }
        }
    }
}

