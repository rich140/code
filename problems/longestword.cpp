#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_subsequence(const string S, const string word) {
    string str = S;
    for (int i = 0; i < word.size(); i++) {
        if (str.size() < word.size()) {
            return false;
        }
        if (str[i] != word[i]) {
            str.erase(str.begin()+i);
            i--;
        }
    }
    return true;
}

string find_longest_word(string S, vector<string> D) {
    bool b = is_subsequence(S, D[0]); 
    string longest_word = "";
    for (string word: D) {
        if (is_subsequence(S, word) && word.size() > longest_word.size()) {
            longest_word = word;
        }
    }
    return longest_word;
}


int main() {
    string S = "abbpppplppppee";
    vector<string> D = {"able", "ale", "apple", "bale", "kangaroo"};
    cout << find_longest_word(S, D) << endl;
    return 0;
}
