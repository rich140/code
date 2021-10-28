#include <iostream>

using namespace std;

// Returns sum of numbers < n that are multiples of 3 or 5
int multiples(int n) {
   int sum = 0;
   for (int i = 3; i < n; i++) {
       if (i % 3 == 0 || i % 5 == 0) {
           cout << i << endl;
           sum += i;
       }
   } 
   return sum;
}

int main() {
    cout << multiples(1000) << endl;
    return 0;
}
