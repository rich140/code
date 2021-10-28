#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string n;
	string line;
	vector<string> words;
	cin >> n;
	while (getline(cin, line)){
		words.push_back(line);
	}
	for (int i = 0; i < stoi(n); i++){
		int len = words.at(i).length();
		if (len > 10){
			cout << words.at(i)[0]+ to_string(stoi(n)-2) + words.at(i)[len-1] + '\n';
		}else{
			cout << words[i] + '\n';
		}
	}
}
