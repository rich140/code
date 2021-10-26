#include <iostream>

using namespace std;

void modify(int* arr) {
    arr[2] = 69;
    arr[3] = 42;
    arr[4] = 1337;
}

void modify2d(int** arr) {
    arr[1][1] = 69;
    arr[1][2] = 42;
    arr[2][1] = 1337;
    arr[2][2] = 9001;
}

int main() {
    int *a = new int[7];
    modify(a);
    for (int i = 0; i < 7; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    delete[] a;
    
    // 2d array
    int **b = new int*[4];
    for (int i = 0; i < 4; i++) {
        b[i] = new int[4];
    }
    modify2d(b);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 4; i++) {
        delete[] b[i];
    }
    delete[] b;
    return 0;
}
