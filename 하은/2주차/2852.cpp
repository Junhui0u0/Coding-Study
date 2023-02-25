#include <bits/stdc++.h>
using namespace std;

int changeToInt(string a) {
	return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}

string print(int a) {
	string d = "00" + to_string(a / 60);
	string e = "00" + to_string(a % 60);
	return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2);
}

int main() {
	int t;
	cin >> t;

	int a_score = 0;
	int a_time = 0;
	int b_score = 0;
	int b_time = 0;

	string temp_str = "00:00";
	int temp_score = 0;
	string prev_str = "00:00";
	int prev_score = 0;

	for (int i = 0; i < t; i++) {

		cin >> temp_score >> temp_str;

		if (a_score > b_score) {
			a_time += (changeToInt(temp_str) - changeToInt(prev_str));
		}
		else if (a_score < b_score) {
			b_time += (changeToInt(temp_str) - changeToInt(prev_str));
		}

		if (temp_score == 1) {
			a_score++;
		}
		else if (temp_score == 2) {
			b_score++;
		}
		
		prev_str = temp_str;
	}

	if (a_score > b_score) a_time += (changeToInt("48:00") - changeToInt(prev_str));
	else if (b_score > a_score) b_time += (changeToInt("48:00") - changeToInt(prev_str));
	cout << print(a_time) << "\n";
	cout << print(b_time) << "\n";

}