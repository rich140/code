#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int size;
        cin >> size;
        int arr[size];
        while (size--) {
            int tmp;
            cin >> tmp;
            int[arr.size() - size] = tmp;
        }
        for (int i = 0; i < arr.size()-1; i++) {
            if (arr[i] > arr[i+1]) {
                int t;
                t = arr[0];
                int tt = arr[0];
                for (int j = 1; j < i+1; j++) {
                    arr[j] = tt;
                    tt = arr[j];
                }
            }
        }
    }    
}
