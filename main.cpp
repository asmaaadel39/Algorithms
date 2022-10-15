#include <iostream>
using namespace std;
#include <bits/stdc++.h>
// given function
long long m_w, m_z;
long long get_random() {
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    long long res = (m_z << 16) + m_w;
    return res % 1000000000;
}

void swap(int *z, int *y) {
    int  tmp = *z;
    *z = *y;
    *y = tmp;
}


double divide(int a,int b,int array[])
{
    int var = array[b];
    int  index = a;
    int j = a;
    while ( j <= b - 1)
    {

        if (array[j] <= var) {
            swap(&array[index], &array[j]);
            index ++;
        }
        j++;
    }
    swap(&array[index], &array[b]);
    return index;
}




int kthminimum(int array[], int a, int b, int j) {

   int index = divide(a, b, array);

    if ( index- a == j - 1)
        return array[index];
    while(index - a > j - 1)
    {
      index--;
        return kthminimum(array, a, index, j);
    }

    return kthminimum(array, index + 1, b, j - index + a - 1);
}

int main() {
    int N,K,array[N],i=0;
    cin >> N >> K >> m_w >> m_z;
    while(i<N)
    {
        array[i] = get_random();
        i++;

    }
    cout << kthminimum(array, 0, N - 1, K);
    return 0;
}



