#include <iostream>
#include <vector>

using namespace std;

void modify(vector< vector<int> >& vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[0].size(); j++) {
            vec[i][j] = 5;
        }
    }
}
int main() {
    int n_row = 3, n_col = 4;
    vector< vector<int> > v;
    v.resize(n_row, vector<int>(n_col));
    modify(v);
    for (int i = 0; i < n_row; i++) {
        for (int j = 0; j < n_col; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    } 
    return 0;
}
