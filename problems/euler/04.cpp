// Find the largest palindrom number made from the product of two 3-digit numbers
#include <iostream>

using namespace std;

int main() {
    int largest = 0;
    for (int i = 999; i > 100; i--) {
        for (int j = 999; j > 100; j--) {
            // 6 digits
            int prod = i * j;
            if ((prod/100000)%10 == prod%10 
                    && (prod/10000)%10 == (prod/10)%10
                    && (prod/1000)%10 == (prod/100)%10
                    && prod > largest) {
                cout << i << " " << j << endl;
                largest = prod;
            } 
        }
    }
    cout << largest << endl;
    return 0;
}
