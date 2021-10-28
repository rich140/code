// Find the largest prime factor of a number

#include <iostream>
#include <math.h>
#include <time.h>
#include <vector>

using namespace std;

// Returns true if n is prime
bool isPrime(long n) {
    for (long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Finds all prime factors for a number n
void find_prime_factors(long n, vector<int>& factors) {
    for (int i = 2; i <= n/2+1; i++) {
        if (n % i == 0 && isPrime(i)) {
            factors.push_back(i);
            n = n / i;
        }
    }
} 

int main() {
    clock_t time = clock();
    vector<int> res;
    find_prime_factors(13195, res);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    cout << "Time: " << (clock()-time)/(double) CLOCKS_PER_SEC << endl;
    return 0;
}
