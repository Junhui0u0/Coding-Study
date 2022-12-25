#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		stack<char> c;
		for (int j = 0; j < s.size(); j++) {
			if (c.empty()) c.push(s[j]);
			else {
				if (c.top() == s[j]) c.pop();
				else c.push(s[j]);
			}
		}

		if (c.empty()) cnt++;
	}

	cout << cnt << endl;
}