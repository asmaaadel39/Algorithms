#include <iostream>
using namespace std;
double Insertion_Sort( int n,double array[]) {
    int index = 0;
    int i=1, element, j;

    while ( i < n) {

        element = array[i];

        for (j = i - 1;j >= 0 && array[j] > element;) {
            array[j + 1] = array[j];
            j = j - 1;
            index++;
        }
        array[j + 1] = element;
        i++;
    }
    return index;
}
int main() {
    //first test case 1,1,1,2,2 output 0
    //second test case 2,1,3,1,2 output 4
    double arr[] = {1,1,1,2,2};
    cout<<Insertion_Sort(5, arr);
    return 0;
}
