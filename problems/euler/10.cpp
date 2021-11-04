#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    double sum = 0;
    for (int i = 2; i < 2000000; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    } 
    cout << fixed;
    cout << sum << endl;
    return 0;
}
