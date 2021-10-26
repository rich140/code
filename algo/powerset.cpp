#include <iostream>
#include <vector>

using namespace std;

void search(int k, vector<int>& subset) {
    if (k == 3) {
        for (auto v: subset) {
            cout << v << " ";
        }
        cout << endl;
    } else {
       search(k+1, subset);
       subset.push_back(k);
       search(k+1, subset);
       subset.pop_back();
    }
}
int main() {
    vector<int> v;
    search(0, v);
    // Bit Sequence
    cout << "Bit Sequence" << endl;
    for (int b = 0; b < (1<<3); b++) {
        cout << b << endl;
    }
    return 0;
}
