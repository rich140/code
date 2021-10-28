#include <iostream>

#include <string>
#include <algorithm>

using namespace std;

void run(string s) {
	size_t a = count(s.begin(), s.end(), 'A');
	size_t b = count(s.begin(), s.end(), 'B');
	size_t c = count(s.begin(), s.end(), 'C');
	if (a + c == b) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
	int n;
	cin >> n;
	while (n > 0) {
		string s;
		cin >> s;
		run(s);
		n--;
	}
	return 0;
}
