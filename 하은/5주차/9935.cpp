#include <bits/stdc++.h>
using namespace std;

int main() {
	string str, bomb;
	cin >> str >> bomb;

	stack<char> ret;
	for (int i = 0; i < str.size(); i++) {
		ret.push(str[i]);
		string s = "";
		if (ret.size() >= bomb.size()) {
			for (int i = 0; i < bomb.size(); i++) {
				s += ret.top();
				ret.pop();
			}
			reverse(s.begin(), s.end());
			if (s != bomb) {
				for (int i = 0; i < bomb.size(); i++) {
					ret.push(s[i]);
				}
			}
		}
	
	}

	if (ret.empty()) cout << "FRULA";
	else {
		string s = "";
		while (!ret.empty()) {
			s += ret.top();
			ret.pop();
		}
		reverse(s.begin(), s.end());
		cout << s;
	}
}