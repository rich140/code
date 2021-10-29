#include <iostream>

using namespace std;

int main() {
    int num = 1;
    int n = 0;
    while (n == 0) {
start:
        for (int i = 1; i <= 20; i++) {
            if (num % i != 0) {
                num++;
                goto start;
            } 
        }
        n = num;
    }
    cout << num << endl;
    return 0;
}
