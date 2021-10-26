#include <string>
#include <iostream>

using namespace std;

class Person {
    public:
        Person(string name):name(name){};
        string name;
};

void change_name(Person& p, string name) {
    p.name = name;
}

int main() {
    Person a = Person("Alice");
    cout << a.name << endl;
    change_name(a, "Bob");
    cout << a.name << endl;
    return 0;
}
