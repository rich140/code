#include <iostream>
#include <set>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<string> s;
    s.insert("a");
    s.insert("b");
    s.insert("c");
    // Size of set
    cout << "Size: " << s.size() << endl;
    // Check whether element exists
    cout << "Does a exist: " << s.count("a") << endl;
    cout << "Does d exist: " << s.count("d") << endl;
    // Remove a
    s.erase("a");
    cout << "New size: " << s.size() << endl;
    return 0;
}
