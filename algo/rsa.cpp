#include <iostream>

using namespace std;

// Asymmetric Cryptography (Public != Private) Steps
// (1) Sender encrypts data using recipient's public key
// (2) Recipient decrypts cipher text using their private key

// Returns a tuple in the form (gcd, s, t) where s and t are bezout's coefficients
tuple<int,int,int> extended_gcd(int a, int b) {
    int s = 0;
    int old_s = 1;
    int r = b;
    int old_r = a;
    int quotient = 0;
    int tmp = 0;

    while (r != 0) {
        quotient = old_r / r;
        tmp = r;
        r = old_r - quotient * r;
        old_r = tmp;
        tmp = s;
        s = old_s - quotient * s;
        old_s = tmp;
    }

    int bezout_t = 0;
    if (b != 0) {
        bezout_t = (old_r - old_s * a) / b;
    } else {
        bezout_t = 0;
    }
    return make_tuple(old_r, old_s, bezout_t);
}

tuple<int,int,int> gcd(int a, int b) {
    int x = 1;
    int y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return tie (a1,a,b);
}

int main() {
    // RSA Example
    int x = 11;
    int y = 13;
    int n = x*y; // 141
    int phi_n = (x-1)*(y-1); // 120
    int e = 7; // coprime to 120
    pair<int,int> public_key = make_pair(n,e);
    
    tuple<int,int,int> t = gcd(11,13);
    tuple<int,int,int> u = gcd(240,46);
    cout << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << endl;
    cout << get<0>(u) << ", " << get<1>(u) << ", " << get<2>(u) << endl;
    return 0;
}
