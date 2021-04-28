#include <iostream>
#include <vector>
using namespace std;

void LCS(char ch) {
	string input_str = "";
	int n = 0;
	int i = 0;
	int j = 0;

	cin >> input_str;
	input_str = ch + input_str;
	n = input_str.length();
	vector < vector<int >> v(n);

	v[0].push_back(input_str[0]);

	for (i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (input_str[i] > input_str[j] && v[i].size() < v[j].size() + 1) {
				v[i] = v[j];
			}
		}
		v[i].push_back(input_str[i]);

	}

	vector<int> max = v[0];

	for (vector<int>x : v) {
		if (x.size() > max.size()) {
			max = x;
		}
	}

	for (int x : max) {
		cout << (char)x;
	}
	cout << endl;
}
int main() {
	char ch;
	while (true) {

		cout << "알파벳 또는 숫자 입력(공백 없이, 엔터 입력 시 종료): ";

		cin.get(ch);
		if (ch == '\n') {
			cout << "종료" << endl;
			return 0;
		}
		else {
			LCS(ch);
		}
	}

	return 0;
}