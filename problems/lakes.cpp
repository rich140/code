#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int compute_volume(int arr[], int length) {
    if (length <= 2) {
        return 0;
    }
    // curr (0), max_left (1), max_right (2)
    int data[3][length];
    // initialize 
    data[0][0] = arr[0];
    data[1][0] = 0;
    data[2][length-1] = 0;
    // populate curr height, max_left height
    for (int i = 1; i < length; i++) {
        data[0][i] = arr[i];
        data[1][i] = max(arr[i-1], data[1][i-1]);
    }
    // populate max_right height
    for (int i = length-2; i >= 0; i--) {
        data[2][i] = max(arr[i+1], data[2][i+1]);
    }
    // compute volume
    int total_volume = 0;
    for (int i = 0; i < length; i++) {
        total_volume += max(0, min(data[1][i], data[2][i]) - data[0][i]);
    }
    return total_volume;
}

int main() {
   // volume is 15
   int test1[] = {1,3,2,4,1,3,1,4,5,2,2,1,4,2,2}; 
   // volume is 10
   int test2[] = {10,7,2,7,8,2,4}; 
   // volume is 3
   int test3[] = {3,0,5}; 
   cout << compute_volume(test1, 15) << endl;
   cout << compute_volume(test2, 7) << endl;
   cout << compute_volume(test3, 3) << endl;
   return 0;
}
