#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, string deli) {
	long long token = 0;
	vector<string> ret;
	while ((token = input.find(deli)) != string::npos) {
		ret.push_back(input.substr(0, token));
		input.erase(0, token + deli.size());
	}
	ret.push_back(input);
	return ret;
}

int main() {
	int t;
	string pt;
	cin >> t >> pt;
	vector<string> result = split(pt, "*");
	
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;


		if (s.size() >= result[0].size() && s.substr(0, result[0].size()) == result[0]) {
			s.erase(0, result[0].size());
			if (s.size() >= result[1].size() && s.substr(s.size() - result[1].size(), result[1].size()) == result[1]) {
				cout << "DA" << '\n';
			}
			else cout << "NE" << '\n';
		}
		else {
			cout << "NE" << '\n';
		}
	}
}