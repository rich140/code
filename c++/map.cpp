#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> m;
    m["a"] = 1;
    m["b"] = 2;
    cout << "(a, " << m["a"] << ")" << endl;
    cout << "(b, " << m["b"] << ")" << endl;
    cout << "Size of map: " << m.size() << endl;
    // Check if element exists in map
    cout << "a exists: " << m.count("a") << endl;
    cout << "c doesn't exist: " << m.count("c") << endl;
    // Remove element in map
    m.erase("a");
    // Print everything in map
    for (auto x : m) {
        cout << "(" << x.first << "," << x.second << ")" << endl;
    }
    return 0;
}
