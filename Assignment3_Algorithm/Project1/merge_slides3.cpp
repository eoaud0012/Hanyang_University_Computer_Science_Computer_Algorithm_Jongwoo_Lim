#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


void merge_slides(char ch) {
	int token_int = 0;
	int sum = 0;
	int i, j, k = 0;
	string input_str = "";
	string buffer = "";

	vector<string> v_result;
	vector<int> v_int;

	getline(cin, input_str);
	input_str = ch + input_str;

	stringstream ss(input_str);
	while (ss >> buffer) {
		v_result.push_back(buffer);
	}

	for (auto it_str = v_result.begin(); it_str != v_result.end(); it_str++) {

		token_int = stoi(*it_str);
		v_int.push_back(token_int);
	}

	i = v_int.size();

	cout << "merging procedures" << endl;


	vector<int>::iterator it = v_int.begin();


	for (it = v_int.begin(); it != v_int.end(); ++it) {
		cout << *it << ' ';
	}

	cout << endl;

	while (i - 1) {

		int b_point = 0;
		int minimum = v_int.at(0) + v_int.at(1);
		for (j = 0; j < i - 1; ++j) {
			if (minimum > v_int.at(j) + v_int.at(j + 1)) {
				minimum = v_int.at(j) + v_int.at(j + 1);
				b_point = j;
			}
		}
		i--;

		sum += v_int.at(b_point) + v_int.at(b_point + 1);

		v_result.at(b_point) = "(" + v_result.at(b_point) + "," + v_result.at(b_point + 1) + ")";

		v_int.at(b_point) = v_int.at(b_point) + v_int.at(b_point + 1);

		v_int.erase(v_int.begin() + (b_point + 1));

		v_result.erase(v_result.begin() + (b_point + 1));


		for (k = 0; k < i; ++k) {
			cout << v_int.at(k);
			cout << ' ';
		}
		cout << endl;


	}

	cout << "minimum cost of sum of slides  :  ";
	cout << sum << endl;
	cout << "result of merging procedures  :  ";
	cout << v_result[0] << endl;

	return;
}

int main() {
		char ch;
		while (true) {

			cout << "추가할 슬라이드 입력(공백으로 구분, 엔터 입력 시 종료): ";

			cin.get(ch);
			if (ch == '\n') {
				cout << "종료" << endl;
				return 0;
			}
			else {
				merge_slides(ch);
			}
		}

		return 0;


}