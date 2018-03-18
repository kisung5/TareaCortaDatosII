//
// Created by kisung on 15/03/18.
//

#include "BigArray.h"

#include <random>

void BigArray::readFile() {
    getSize();
    int test;
    ifstream ofile;
    int array[10];
    ofile.open(dirLocation.c_str(), ios::in | ios::binary);
    for (int x=1; x<=10;x++ ) {
        ofile.read(reinterpret_cast<char*>(&test), sizeof(int));
        array[x-1] = test;
    }
    cout<<ofile.gcount()<<endl;
    for (int x=1; x<=10;x++ ) {
        cout << array[x - 1] << "-";
    }
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

BigArray::BigArray() {
    ofstream ofile(dirLocation.c_str(),ios::binary | ios::out);
    int data [1000];
    for (int i; i<1000; i++){
        data[i] = i+1;
    };
    int size   =  sizeof(data)/sizeof(data[0]);

    shuffle(data, data + size, std::mt19937(std::random_device()()));

    for(int loop = 0; loop < size; ++loop) {
        //cout << data[loop] << endl;
        ofile.write(reinterpret_cast<char *>(&data[loop]), sizeof(int));
    }
    /*
    for (int x=1; x<=10;x++ ) {
        ofile.write(reinterpret_cast<char *>(&x), sizeof(int));
    }*/
    ofile.close();
    readFile();
}
