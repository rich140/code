// Given an array and a number, find the indices of that number
// (as if it were sorted)
// Example - [22, 33, 44, 22, 11] would return [1,2]

#include <vector>
#include <unordered_map>

using namespace std;

void solve1(vector<int> vec, int target, vector<int>& indices) {
    int n_less = 0; // numbers small than target
    int n_occurances = 0; // number of occurances of target

    for (auto i : vec) {
        // Optimize by removing if statements
        // Eliminates failed branch predictions
        n_less += i < target;
        n_occurances += i == target;
    }

    // Question: How do you optimize?
    // Reserve space for vector so you don't exceed capacity
    indices.reserve(n_occurances);
    for (int i = 0; i < n_occurances; i++) {
        indices.push_back(i+n_less);
    }
}

// Followup: What if we aren't given the number?
// Instead we want to return the indices of the number with the most
// occurances. If ties, choose the greater number.
void solve2(vector<int> vec, vector<int>& indices) {
    unordered_map<int,int> occurances;
    for (auto i : vec) {
        occurances[i]++;
    }
    
    int max_count = 0;
    int max_val = 0;
    for (auto it : occurances) {
        if (max_count >= it.first && max_val >= it.second) {
            max_count = it.first;
            max_val = it.second;
        }
    }
    solve1(vec, max_val, indices);
}

int main() {
    return 0;
}
