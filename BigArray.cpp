//
// Created by kisung on 15/03/18.
//

#include "BigArray.h"

#include <random>


BigArray::BigArray() {
    makeBigArray(1000);
}

void BigArray::readFile(int array[maxSize], int ini) {
    int test;
    ifstream ofile;
    ofile.open(dirLocation.c_str(), ios::in | ios::binary);
    ofile.seekg(ini*sizeof(int));
    for (int x=0; x<maxSize;x++ ) {
        ofile.read(reinterpret_cast<char*>(&test), sizeof(int));
        array[x] = test;
    }

    /*for (int x=1; x<=10;x++ ) {
        cout << *array[x - 1] << "-";
    }*/
    ofile.close();
}

void BigArray::writeFile() {

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
            ofile.write(reinterpret_cast<char *>(&data[loop]), sizeof(int));
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
        for (int i=1;i<pages;i++){
            if (x>=(i-1)*maxSize & x<maxSize*(i)){
                if (loaded[0] == i){
                   return leftPage[x];
                } else if(loaded[1] == i) {
                    return midPage[x];
                } else if(loaded[2] == i) {
                    return rightPage[x];
                } else {
                    if (i<pages/3) {
                        readFile(leftPage,i*maxSize);
                        loaded[0] = i;
                        return leftPage[x];
                    } else if (i>pages*2/3) {
                        readFile(rightPage,i*maxSize);
                        loaded[2] = i;
                        return rightPage[x];
                    } else {
                        readFile(midPage,i*maxSize);
                        loaded[1] = i;
                        return midPage[x];
                    }
                }
            } else if (x == sizeOfArray-1) {
                if (loaded[2] == pages){
                    return rightPage[x];
                }
            }
        }
    }
}
