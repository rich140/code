#include <iostream>
#include <math.h>

using namespace std;

// Asymmetric Cryptography (Public != Private) Steps
// (1) Sender encrypts data using recipient's public key
// (2) Recipient decrypts cipher text using their private key

// Returns a tuple (gcd, s, t) where s and t are bezout's coefficients
tuple<int,int,int> extended_euclidean(int a, int b) {
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

int encrypt(int m, pair<int,int> public_key) {
    return (int)pow(m,public_key.first) % public_key.second;
}

int getDecryptionKey(int e, int tot_n) {
    return get<1>(extended_euclidean(e,tot_n));
}

int decrypt(int c, pair<int,int> private_key) {
    return (int)pow(c,private_key.first) % private_key.second;
}

int main() {
    // RSA Example
    int p = 3;
    int q = 11;
    int n = p*q;
    int tot_n = (p-1)*(q-1); // totient of n
    int e = 7; // coprime to n 
    int d = getDecryptionKey(e, tot_n);
    pair<int,int> public_key = make_pair(e,n);
    pair<int,int> private_key = make_pair(d,n); 
    int m = 2; // original message
    int c = encrypt(m, public_key); // encrypted ciphertext
    cout << "Encrypted Message: " << to_string(c) << endl;
    cout << "Decrypted Message: " << decrypt(c, private_key) << endl;
    return 0;
}
