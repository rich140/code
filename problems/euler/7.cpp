#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i < sqrt(n)+1; i++) {
        if (n % i == 0) return false;    
    }
    return true;
}

int main() {
    int n_prime = 6;
    int n = 13;
    while (n_prime != 10001) {
        n++;
        if (isPrime(n)) {
            n_prime++;
        }
    }
    cout << n << endl;
    return 0;
}
