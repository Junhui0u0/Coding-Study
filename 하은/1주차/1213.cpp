#include <bits/stdc++.h>
using namespace std;

int main() {
	int list[26] = { 0, };
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		list[s[i] - 65]++;
	}

	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (list[i] & 1) cnt++;
	}

	if (cnt >= 2) cout << "I'm Sorry Hansoo";
	else {
		string special = "";
		string s1 = "", s2 = "";
		for (int i = 0; i < 26; i++) {
			if (list[i] & 1) special = (char)(i + 65);

		}

		for (int i = 0; i < 26; i++) {
				for (int j = 0; j < list[i] / 2; j++) {
					s1 += (char)(i + 65);
				}
		}

		s2 = s1;
		reverse(s1.begin(), s1.end());

		cout << s2 + special + s1 << endl;
	}

}