#include "matrix.cpp"
#include <iostream>

using namespace std;

int main() {
    Matrix<int> M(); 
    M.resize(4, 5);
    cout << M.at(2, 3) << endl;
    return 0;
}
