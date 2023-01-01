#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	map<char, int> m;
	for (int i = 0;i < s.size();i++) {
		m[s[i]]++;
	}

	int odd = 0;
	char c = '0';
	for (auto map : m) {
		if (map.second % 2 == 1) {
			odd++;
			c = map.first;
		}
	}

	string str = "";
	if (odd > 1) cout << "I'm Sorry Hansoo\n";
	else {
		for (auto map : m) {
			for (int i = 1;i <= map.second / 2;i++) {
				str += map.first;
			}
		}
		string re_str = str;
		reverse(re_str.begin(), re_str.end());
		if (c != '0') cout << str + c + re_str << "\n";
		else cout << str + re_str << "\n";
	}

	return 0;
}