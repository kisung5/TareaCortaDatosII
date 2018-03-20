//
// Created by kisung on 15/03/18.
//

#include "BigArray.h"
#include "quickSort.h"

int main() {
    BigArray *binmanager = new BigArray();

    int n = 4000/sizeof((*binmanager)[0]);
    quickSort quickSort1;
    quickSort1.quicksort(binmanager,0,n-1);

    /*int num;
    int counter;
    while(counter < 100) {
        cin >> num;
        cout << (*binmanager)[num] << endl;
        counter++;
    }*/
    return 0;
}