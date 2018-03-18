//
// Created by kisung on 15/03/18.
//

#include "BigArray.h"

void BigArray::readFile() {
    //getSize();
    int test;
    ifstream ofile;
    ofile.open(dirLocation, ios::in | ios::binary | ios::left);
    for (int x=1; x<10;x++ ) {
        ofile.read(reinterpret_cast<char*>(&test), sizeof(test));
    }
    if (!ofile) {
        cout<<"No"<<endl;
        cout<<ofile.gcount()<<endl;
        cout<<test;
    } else {
        cout << ofile.gcount() << endl;
        cout << test;
    }
}

void BigArray::writeFile() {

}

int BigArray::getSize() {
    struct stat results;
    if (stat("foobar.bin", &results) == 0) {
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
    ofstream ofile;
    ofile.open(dirLocation, ios::in | ios::binary | ios::left);
    for (int x=1; x<10;x++ ) {
        ofile.write(reinterpret_cast<char*>(&x), sizeof(x));
    }
}
