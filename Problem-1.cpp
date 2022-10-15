#include <iostream>
#include <algorithm>
using namespace std;


int diskScheduler(int arr[], int head, int size) {
    int seekCount = 0;
    int distance, currentTrack;

    for (int i = 0; i < size; i++) {
        currentTrack = arr[i];

        // calculate distance
        distance = abs(currentTrack - head);

        // update the total count
        seekCount += distance;

        // accessed track is now the new head
        head = currentTrack;
    }
    return seekCount;
}


int main() {

    int head, size, totalCount;
    int arr[] = { 100, 50, 190 };

    // sort the array in descending order (n log n) time complexity
    sort(arr, arr + 4, greater<int>());

    size = sizeof(arr) / sizeof(arr[0]);
    head = 140;
    totalCount = diskScheduler(arr, head, size);

    cout << "Total number of seek operations = " << totalCount << endl;
}