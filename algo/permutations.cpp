#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {1,2,3,4,5};
    do {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));
    return 0;
}
