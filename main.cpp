//
// Created by kisung on 15/03/18.
//

#include "BigArray.h"
#include "quickSort.h"

int main() {
    BigArray *binmanager = new BigArray();
    cout<<endl;
    int num;
    int counter;
    while(counter < 100) {
        cin >> num;
        cout << (*binmanager)[num] << endl;
        counter++;
    }
    /*int array [] = {5,3,8,0,1,45,2};
    quickSort quickSort1;
    quickSort1.quicksort(array,0,6);*/
    return 0;
}