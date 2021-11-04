#include <iostream>

using namespace std;

// Find sum of even Fibonacci numbers <= 4m
int even_fibs(int max) {
   int sum = 0;
   int a = 1;
   int b = 2;
   int fn = 2;
   while (fn <= max) {
       if (fn % 2 == 0) {
           sum += fn;
       }
       fn = a+b;
       a = b;
       b = fn;
   } 
   return sum;
}

int main() {
    cout << even_fibs(4000000) << endl;
    return 0;
}
