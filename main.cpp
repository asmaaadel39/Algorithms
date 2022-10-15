
#include <iostream>

using namespace std;

int m_alg(int left, int right, int middle,int array[] ) {

    int x = 0;
    int numLeft = middle - left + 1;
    int numRight = right - middle;
    int *l = new int[numLeft];
    int *r = new int[numRight];
     int idx=0,idx2=0;
     while( idx < numLeft) {
        l[idx] = array[left + idx];
        idx++;
    }
    while ( idx2 < numRight) {
        r[idx2] = array[middle + 1 + idx2];
        idx2++;
    }
    int i = 0, j = 0, y = left;

    while (i < numLeft && j < numRight) {
        if (r[j] < l[i]) {
            x += numLeft - i;
            array[y] = r[j];
            j++;
        } else {
            array[y] = l[i];
            i++;
        }
        y++;
    }
    while ( i < numLeft) {
        array[y] = l[i];
        i++;
    }
    while ( j < numRight) {
        array[y] = r[j];
        j++;
    }
    return x;

}
void printArray(int Array[], int size)
{
    int i = 0;
    while (i < size)
    {
        cout << Array[i] << " ";
        i++;
    }

}

int Merge_Sort(int array[], int const begin, int end) {
    int element = 0;
    if (begin >= end) return element;
    int m = (begin + end) / 2;
    element += Merge_Sort(array, begin, m);
    element += Merge_Sort(array, m + 1, end);
    element += m_alg( begin, end, m,array);
    return element;
}


int main() {
    int size;
    cout<<"Enter size"<<endl;
    cin >> size;
    cout<<"Enter Elements"<<endl;
    int *arr = new int[size];
    int i = 0;
    while(i < size) {
        cin >> arr[i];
        i++;
    }
    cout<<"the number of inversions =";
    cout << Merge_Sort(arr, 0, size - 1)<<endl;
 //   printArray(arr,size);
    return 0;
    // 4
    // 1 2 3 4
    // output 0
}
