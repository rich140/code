#include <iostream>

using namespace std;

int main() {
    long sum_of_squares = 0, square_of_sum = 0;
    for (int i = 1; i <= 100; i++) {
        cout << "adding: " << i*i << " to " << sum_of_squares << endl;
        sum_of_squares += i*i;
        square_of_sum += i;
    }
    square_of_sum *= square_of_sum;
    long diff = sum_of_squares - square_of_sum;
    cout << sum_of_squares << endl;
    cout << square_of_sum << endl;
    cout << diff << endl;
    return 0;
}
